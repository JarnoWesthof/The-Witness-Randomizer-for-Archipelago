#pragma once

#include "../DateTime.h"
#include "../Generate.h"
#include "../HUDManager.h"
#include "../Watchdog.h"
#include "APGameData.h"
#include "APState.h"
#include "PanelLocker.h"
#include "nlohmann\json.hpp"

#include <chrono>
#include <map>


class APWatchdog : public Watchdog {
public:
	APWatchdog(APClient* client, std::map<int, int> mapping, int lastPanel, PanelLocker* p, HWND skipButton1, HWND availableSkips1, std::map<int, std::pair<std::string, int64_t>> a, std::map<int, std::set<int>> o, bool ep, bool hard, APState* s) : Watchdog(0.1f) {
		generator = std::make_shared<Generate>();
		ap = client;
		panelIdToLocationId = mapping;
		finalPanel = lastPanel;
		skipButton = skipButton1;
		availableSkips = availableSkips1;
		panelLocker = p;
		audioLogMessages = a;
		state = s;
		EPShuffle = ep;
		obeliskHexToEPHexes = o;

		for (auto [key, value] : obeliskHexToEPHexes) {
			obeliskHexToAmountOfEPs[key] = (int)value.size();
		}

		Hard = hard;

		panelsThatHaveToBeSkippedForEPPurposes = {
			0x09E86, 0x09ED8, // light controllers 2 3
			0x033EA, 0x01BE9, 0x01CD3, 0x01D3F, // Pressure Plates
		};

		if (hard) {
			panelsThatHaveToBeSkippedForEPPurposes.insert(0x181F5);
			panelsThatHaveToBeSkippedForEPPurposes.insert(0x334D8);
		}

		lastFrameTime = std::chrono::system_clock::now();
		hudManager = std::make_shared<HudManager>(_memory);
	}

	int skippedPuzzles = 0;
	int foundPuzzleSkips = 0;

	HWND skipButton;
	HWND availableSkips;

	APState* state;

	virtual void action();

	void MarkLocationChecked(int locationId, bool collect);
	void ApplyTemporarySpeedBoost();
	void ApplyTemporarySlow();
	void TriggerPowerSurge();
	void ResetPowerSurge();

	void AddPuzzleSkip();
	void SkipPuzzle();
	void SkipPreviouslySkippedPuzzles();

	void UnlockDoor(int id);
	void SeverDoor(int id);

	void DoubleDoorTargetHack(int id);

	void SetItemReward(const int& id, const APClient::NetworkItem& item);

	bool CheckPanelHasBeenSolved(int panelId);

	void HandleLaserResponse(const std::map<std::string, nlohmann::json> response, bool collect);

	void InfiniteChallenge(bool enable);

	bool processingItemMessages = false;
	bool newItemsJustIn = false;

	void QueueReceivedItem(const APClient::NetworkItem& item, int realitem);

	HudManager* getHudManager() const { return hudManager.get(); }

private:
	APClient* ap;
	PanelLocker* panelLocker;
	std::shared_ptr<Generate> generator;
	std::map<int, int> panelIdToLocationId;
	int finalPanel;
	bool isCompleted = false;

	std::chrono::system_clock::time_point lastFrameTime;
	float halfSecondCountdown = 0.f;

	int halfSecondCounter = 0;

	std::shared_ptr<HudManager> hudManager;

	bool EPShuffle = false;
	bool Hard = false;

	bool FirstEverLocationCheckDone = false;

	bool hasPowerSurge = false;
	std::chrono::system_clock::time_point powerSurgeStartTime;

	const float baseSpeed = 2.0f;

	bool laserRequirementMet = false;

	std::set<int> disableCollisionList;

	std::set<int> severedDoorsList;
	std::map<int,int> collisionsToRefresh;
	std::map<int, std::vector<float>> collisionPositions;

	int storageCheckCounter = 6;

	float speedTime = 0.0f;

	void HandleKeyTaps();
	
	void CheckEPSkips();

	void QueueItemMessages();

	void DisableCollisions();

	void AudioLogPlaying();

	void RefreshDoorCollisions();

	void CheckSolvedPanels();
	void HandleMovementSpeed(float deltaSeconds);
	void HandlePowerSurge();

	void CheckLasers();

	void CheckImportantCollisionCubes();

	void SetStatusMessages();

	std::map<std::string, int> laserIDsToLasers;
	std::list<std::string> laserIDs;

	int currentAudioLog = -1;

	std::map<int, std::pair<std::string, int64_t>> audioLogMessages = {};
	std::map<int, std::set<int>> obeliskHexToEPHexes = {};
	std::map<int, int> obeliskHexToAmountOfEPs = {};

	CollisionCube bonsaiCollisionCube = CollisionCube(18, -31.6f, 14, 21, -29, 17);
	CollisionCube riverVaultUpperCube = CollisionCube(52, -51, 19, 44, -47, 23);
	CollisionCube riverVaultLowerCube = CollisionCube(40, -56, 16, 46, -47, 20.5f);
	CollisionCube bunkerPuzzlesCube = CollisionCube(161.2f, -96.3f, 5.8f, 172.3f, -101.1f, 11.5f);
	CollisionCube tutorialPillarCube = CollisionCube(-152, -150.9f, 5, -148, -154.8f, 9);
	CollisionCube quarryLaserPanel = CollisionCube(-59, 90, 17, -67, 100, 21);
	CollisionCube symmetryUpperPanel = CollisionCube(-180, 31, 12.6f, -185, 37, 17);

	std::set<int> panelsThatHaveToBeSkippedForEPPurposes = {};

	bool metaPuzzleMessageHasBeenDisplayed = false;

	std::queue<std::pair<const APClient::NetworkItem&, int>> queuedItems;

	std::string puzzleSkipInfoMessage;


	int CheckIfCanSkipPuzzle();

	int GetActivePanel() {
		try {
			return _memory->GetActivePanel();
		}
		catch (std::exception& e) {
			OutputDebugStringW(L"Couldn't get active panel");
		}
	}

	void WriteMovementSpeed(float currentSpeed) {
		try {
			return _memory->WriteMovementSpeed(currentSpeed);
		}
		catch (std::exception& e) {
			OutputDebugStringW(L"Couldn't get active panel");
		}
	}
};

class APServerPoller : public Watchdog {
public:
	APServerPoller(APClient* client) : Watchdog(0.1f) {
		ap = client;
	}

	virtual void action() {
		ap->poll();
	}

private:
	APClient* ap;
};