#include "APAudioPlayer.h"

#include "windows.h"
#include "mmsystem.h"

#include "../../App/resource.h"

APAudioPlayer* APAudioPlayer::_singleton = nullptr;

APAudioPlayer::APAudioPlayer() : Watchdog(0.1f) {

}

void APAudioPlayer::action() {
	if (!QueuedAudio.size()) return;

	std::pair<APJingle, bool> nextAudio = QueuedAudio.front();

	PlayAppropriateJingle(nextAudio.first, nextAudio.second, false);

	QueuedAudio.pop();
}

void APAudioPlayer::create() {
	if (_singleton == nullptr) {
		_singleton = new APAudioPlayer();
		_singleton->start();
	}
}

APAudioPlayer* APAudioPlayer::get() {
	create();
	return _singleton;
}

void APAudioPlayer::PlayAudio(APJingle jingle, APJingleBehavior queue, bool epicVersion) {
	if (queue == APJingleBehavior::PlayImmediate) {
		PlayAppropriateJingle(jingle, epicVersion, true);
	}

	if (queue == APJingleBehavior::Queue){
		QueuedAudio.push({ jingle, epicVersion });
	}

	if (queue == APJingleBehavior::DontQueue) {
		if (!QueuedAudio.size()) QueuedAudio.push({ jingle, epicVersion });
	}
}

void APAudioPlayer::PlayJingle(int resource, bool async) {
	if (async) PlaySound(MAKEINTRESOURCE(resource), NULL, SND_RESOURCE | SND_ASYNC);
	else PlaySound(MAKEINTRESOURCE(resource), NULL, SND_RESOURCE);
}

void APAudioPlayer::PlayAppropriateJingle(APJingle jingle, bool epicVersion, bool async) {
	auto now = std::chrono::system_clock::now();
	
	if ((now - lastPanelJinglePlayedTime) > std::chrono::seconds(60)) {
		panelChain = -1;
	}
	if ((now - lastEPJinglePlayedTime) > std::chrono::seconds(60)) {
		epChain = -1;
	}

	int versionToPlay = 0;

	if (panelJingles.count(jingle)) {
		versionToPlay = panelChain;
		lastPanelJinglePlayedTime = now;
		panelChain++;
	}
	else if (epJingles.count(jingle)) {
		versionToPlay = epChain;
		lastEPJinglePlayedTime = now;
		epChain++;
	}

	if (epicVersion) {
		lastPanelJinglePlayedTime = now; // Epic doesn't interrupt a panel chain. Also, Epic should still advance the counter by one.

		int resource = jingleEpicVersions[jingle];
		PlayJingle(resource, async);
		return;
	}

	if (versionToPlay < 0) versionToPlay = 0;
	if (versionToPlay > jingleVersions[jingle].size() - 1) versionToPlay = jingleVersions[jingle].size() - 1;

	int resource = jingleVersions[jingle][versionToPlay];

	PlayJingle(resource, async);
}