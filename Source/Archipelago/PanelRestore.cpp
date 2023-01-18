#include "PanelRestore.h"
#include "OriginalPanelData.h"
#include "../Randomizer.h"

void PanelRestore::RestoreOriginalPanelData(std::shared_ptr<Memory> memory) {
	for (auto& [key, value] : originalBackgroundModes) {
		memory->WritePanelData<int>(key, OUTER_BACKGROUND_MODE, { value });
	}

	for (auto& [key, value] : originalPathColors) {
		memory->WritePanelData<float>(key, PATH_COLOR, value);
	}

	for (auto& [key, value] : originalOuterBackgroundColors) {
		memory->WritePanelData<float>(key, OUTER_BACKGROUND, value);
	}

	for (auto& [key, value] : originalBackgroundRegionColors) {
		if (key == 0x64 || key == 0x182) continue; //important info is stored on these

		memory->WritePanelData<float>(key, BACKGROUND_REGION_COLOR, value);
	}

	return;
}

std::vector<float> PanelRestore::GetPositions(int id) {
	return correctPosition[id];
}

bool PanelRestore::HasPositions(int id) {
	return correctPosition.count(id);
}