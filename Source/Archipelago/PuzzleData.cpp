#include "PuzzleData.h"
#include "../Memory.h"
#include "../Panel.h"
#include "../Randomizer.h"

void PuzzleData::Read() {
	Memory* memory = Memory::get();

	grid_size_x = memory->ReadPanelData<int>(id, GRID_SIZE_X);
	grid_size_y = memory->ReadPanelData<int>(id, GRID_SIZE_Y);
	path_width_scale = memory->ReadPanelData<float>(id, PATH_WIDTH_SCALE);
	pattern_scale = memory->ReadPanelData<float>(id, PATTERN_SCALE);
	
	int numberOfDots = memory->ReadPanelData<int>(id, NUM_DOTS);
	dot_positions = memory->ReadArray<float>(id, DOT_POSITIONS, numberOfDots * 2);
	dot_flags = memory->ReadArray<int>(id, DOT_FLAGS, numberOfDots);

	int numberOfConnections = memory->ReadPanelData<int>(id, NUM_CONNECTIONS);
	dot_connections_a = memory->ReadArray<int>(id, DOT_CONNECTION_A, numberOfConnections);
	dot_connections_b = memory->ReadArray<int>(id, DOT_CONNECTION_B, numberOfConnections);
	
	int numberOfDecorations = memory->ReadPanelData<int>(id, NUM_DECORATIONS);
	decorations = memory->ReadArray<int>(id, DECORATIONS, numberOfDecorations);
	decoration_flags = memory->ReadArray<int>(id, DECORATION_FLAGS, numberOfDecorations);

	int numberColoredRegions = memory->ReadPanelData<int>(id, NUM_COLORED_REGIONS);
	colored_regions = memory->ReadArray<int>(id, COLORED_REGIONS, numberColoredRegions * 4);

	outer_background_mode = memory->ReadPanelData<int>(id, OUTER_BACKGROUND_MODE);
	outer_background_color = memory->ReadPanelData<float>(id, OUTER_BACKGROUND, 4);
	background_region_color = memory->ReadPanelData<float>(id, BACKGROUND_REGION_COLOR, 4);
	path_color = memory->ReadPanelData<float>(id, PATH_COLOR, 4);
	decorationsColorsPointer = memory->ReadPanelData<__int64>(id, DECORATION_COLORS);

	if (id == 0x01983) {
		hasTetris = true;
		hasStars = true;
		return;
	}
	if (id == 0x01987) {
		hasDots = true;
		hasColoredStones = true;
		return;
	}

	std::vector<float> decorationColors = {};

	if (decorationsColorsPointer) {
		decorationColors = memory->ReadArray<float>(id, DECORATION_COLORS, 4 * numberOfDecorations);
	}

	for (int i = 0; i < numberOfDecorations; i++) {
		if ((decorations[i] & 0x700) == Decoration::Shape::Stone) {
			if (decorationsColorsPointer) {
				std::vector<float> color = { decorationColors[4 * i], decorationColors[4 * i + 1], decorationColors[4 * i + 2], decorationColors[4 * i + 3] };

				if (color[0] == color[1] && color[1] == color[2]) {
					hasStones = true;
				}
				else {
					hasColoredStones = true;
				}
			}
			else if (memory->ReadPanelData<int>(id, PUSH_SYMBOL_COLORS) == 1) { // Quarry type: Symbol_A through Symbol_E are relevant
				std::vector<float> color;
				switch (decorations[i] & 0x00F) {
				case 1:
					color = memory->ReadPanelData<float>(id, SYMBOL_A, 3);
					break;
				case 2:
					color = memory->ReadPanelData<float>(id, SYMBOL_B, 3);
					break;
				case 3:
					color = { 0.0f, 1.0f, 1.0f };
					break;
				case 4:
					color = memory->ReadPanelData<float>(id, SYMBOL_C, 3);
					break;
				case 5:
					color = memory->ReadPanelData<float>(id, SYMBOL_D, 3);
					break;
				case 6:
					color = memory->ReadPanelData<float>(id, SYMBOL_E, 3);
					break;
				default:
					color = { 0.0f, 1.0f, 1.0f };
				}

				if (color[0] == color[1] && color[1] == color[2] || (color[0] < 0.035 && color[1] < 0.05 && color[2] < 0.065)) { // vanilla left pillar 2 lol
					hasStones = true;
				}
				else {
					hasColoredStones = true;
				}
			}
			else {
				if ((decorations[i] & 0x00F) != Decoration::Color::White && (decorations[i] & 0x00F) != Decoration::Color::Black)
					hasColoredStones = true;
				else
					hasStones = true;
			}
		}
		else if ((decorations[i] & 0xF00) == Decoration::Shape::Star) {
			hasStars = true;

			bool sharesColorWithOtherShape = false;

			for (int j = 0; j < numberOfDecorations; j++) {
				if (((decorations[j] & 0xF00) != 0) //check if any other simbol shares its color
					&& ((decorations[j] & 0xF00) != Decoration::Shape::Star)
					&& ((decorations[j] & 0x00F) == (decorations[i] & 0x00F))) {

					sharesColorWithOtherShape = true;
					break;
				}
			}
						
			if (sharesColorWithOtherShape)
				hasStarsWithOtherSymbol = true;
		}
		else if ((decorations[i] & 0x700) == Decoration::Shape::Poly) {
			bool isRotated = (decorations[i] & 0x1000) == Decoration::Can_Rotate;

			if ((decorations[i] & 0x2000) == Decoration::Negative)
				hasTetrisNegative = true;
			else if (!isRotated)
				hasTetris = true;

			if (isRotated)
				hasTetrisRotated = true;
		}
		else if ((decorations[i] & 0x700) == Decoration::Shape::Eraser) {
			hasErasers = true;
		}
		else if ((decorations[i] & 0x700) == Decoration::Shape::Triangle && (decorations[i] & 0x70000) != 0) { //triangle with size 0 are used by arrows
			hasTriangles = true;
		}
		else if ((decorations[i] & 0x700) == Decoration::Shape::Arrow) {
			hasArrows = true;
		}
	}

  	if (memory->ReadPanelData<int>(id, REFLECTION_DATA))
		hasSymmetry = true;

	int dotAmount = 0;
	int pointsToConsider = 0;

	for (int i = 0; i < numberOfDots; i++)	{
		if (dot_flags[i] & DOT) {
			if (dot_flags[i] & DOT_IS_BLUE || dot_flags[i] & DOT_IS_ORANGE)
				hasColoredDots = true;
			else if (dot_flags[i] & DOT_SMALL || dot_flags[i] & DOT_MEDIUM || dot_flags[i] & DOT_LARGE)
				hasSoundDots = true;
			else
				hasDots = true;
		}

		if (dot_flags[i] & GAP || dot_flags[i] & STARTPOINT || dot_flags[i] & ENDPOINT || dot_flags[i] & NO_POINT) {
			continue;
		}
		if ((dot_flags[i] & ROW) && !(dot_flags[i] & COLUMN) || (dot_flags[i] & COLUMN) && !(dot_flags[i] & ROW)) {
			continue;
		}

		pointsToConsider++;

		if (dot_flags[i] & DOT) {
			dotAmount++;
		}
	}

	if (pointsToConsider && ((float) dotAmount / (float) pointsToConsider >= 0.9)) {
		hasFullDots = true;
	}

	else if (id == 0x00A52 || id == 0x00A61 || id == 0x00A57 || id == 0x00A64 || id == 0x00A5B || id == 0x00A68) // These dots seem to get picked up as normal dots, not colored ones. Also, these panels should require Symmetry despite not having Symmetry on them.
	{
		hasDots = false;
		hasColoredDots = true;
		hasSymmetry = true;
	}
	else if (id == 0x15ADD) { // River Vault: The squares are drawn on and validated separately!
		hasStones = true;
	}
	else if (id == 0x0A332) { // Challenge timer (can't lock the individual challenge panels)
		hasDots = true;
		hasColoredDots = true;
		hasStones = true;
		hasColoredStones = true;
		hasTriangles = true;
		hasSymmetry = true;
		hasStars = true;
		hasTetris = true;
		needsChallengeLasers = true;
	}
	else if (id == 0x3D9A9) { // Elevator
		needsMountainLasers = true;
	}
	else if (id == 0x09FDC || id == 0x09FF7 || id == 0x09F82 || id == 0x09FF8 || id == 0x0A01B || id == 0x0A01F || id == 0x17E67 || id == 0x0A079) { // Bunker Panels don't pick up their white squares
		hasColoredStones = true;
		hasStones = true;
	}
	else if (id == 0x09F7D || id == 0x09D9F || id == 0x09DA1 || id == 0x09DA2 || id == 0x09DAF || id == 0x0A010 || id == 0x17E63) {
		hasColoredStones = true;
		hasStones = false;
	}
}

void PuzzleData::Restore() {
	Memory* memory = Memory::get();

	memory->WritePanelData<int>(id, GRID_SIZE_X, { grid_size_x });
	memory->WritePanelData<int>(id, GRID_SIZE_Y, { grid_size_y });
	memory->WritePanelData<float>(id, PATH_WIDTH_SCALE, { path_width_scale });
	memory->WritePanelData<float>(id, PATTERN_SCALE, { pattern_scale });
	memory->WritePanelData<int>(id, NUM_DOTS, { static_cast<int>(dot_flags.size()) }); //amount of intersections
	memory->WriteArray<float>(id, DOT_POSITIONS, dot_positions); //position of each point as array of x,y,x,y,x,y so this vector is twice the suze if sourceIntersectionFlags
	memory->WriteArray<int>(id, DOT_FLAGS, dot_flags); //flags for each point such as entrance or exit
	memory->WritePanelData<int>(id, NUM_CONNECTIONS, { static_cast<int>(dot_connections_a.size()) }); //amount of connected points, for each connection we specify start in sourceConnectionsA and end in sourceConnectionsB
	memory->WriteArray<int>(id, DOT_CONNECTION_A, dot_connections_a); //start of a connection between points, contains position of point in sourceIntersectionFlags
	memory->WriteArray<int>(id, DOT_CONNECTION_B, dot_connections_b); //end of a connection between points, contains position of point in sourceIntersectionFlags
	memory->WritePanelData<int>(id, NUM_DECORATIONS, { static_cast<int>(decorations.size()) });
	memory->WriteArray<int>(id, DECORATIONS, decorations);
	memory->WriteArray<int>(id, DECORATION_FLAGS, decoration_flags);
	memory->WritePanelData<int>(id, NUM_COLORED_REGIONS, { static_cast<int>(colored_regions.size() / 4) });
	memory->WriteArray<int>(id, COLORED_REGIONS, colored_regions, true);
	memory->WritePanelData<float>(id, OUTER_BACKGROUND, outer_background_color);
	memory->WritePanelData<int>(id, OUTER_BACKGROUND_MODE, { outer_background_mode });
	memory->WritePanelData<int>(id, NEEDS_REDRAW, { 1 });
	memory->WritePanelData<float>(id, BACKGROUND_REGION_COLOR, background_region_color);
	memory->WritePanelData<float>(id, PATH_COLOR, path_color);
	memory->WritePanelData<__int64>(id, DECORATION_COLORS, { decorationsColorsPointer });
}
