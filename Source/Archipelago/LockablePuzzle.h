#pragma once

#include <vector>
#include <string>

const inline std::vector<int> LockablePuzzles{
		0x01983, 0x01987, //Peekaboos

		0x00293, 0x00295, 0x002C2, 0x0A3B5, 0x0A3B2, 0x03629, // Tutorial
		0x0C373, // Tutorial Patio Floor
		0x0C335, // Tutorial Pillar??
		0x0A171, 0x04CA4, // Tutorial Secret back area
		0x0005D, 0x0005E, 0x0005F, 0x00060, 0x00061, // Tutorial Dots Tutorial
		0x018AF, 0x0001B, 0x012C9, 0x0001C, 0x0001D, 0x0001E, 0x0001F, 0x00020, 0x00021,	// Tutorial Stones Tutorial
		0x00086, 0x00087, 0x00059, 0x00062, 0x0005C, // Symmetry Vertical Symmetry Mazes
		0x0008D, 0x00081, 0x00083, 0x00084, 0x00082, 0x0343A, // Symmetry Rotational Symmetry Mazes
		0x00022, 0x00023, 0x00024, 0x00025, 0x00026, // Symmetry Black Dots
		0x0007C, 0x0007E, 0x00075, 0x00073, 0x00077, 0x00079, // Symmetry Colored Dots
		0x00065, 0x0006D, 0x00072, 0x0006F, 0x00070, 0x00071, 0x00076, // Symmetry Fading Lines
		0x009B8, 0x009B8, 0x003E8, 0x00A15, 0x00B8D, // Symmetry Environmental Set
		0x00A52, 0x00A61, 0x00A57, 0x00A64, 0x00A5B, 0x00A68, // Symmetry Dot Reflection Dual Panels (before laser)

		0x17C09, // Quarry Entry Gates
		0x01E59, // Quarry Mill Entry Door
		0x00E0C, 0x01489, 0x0148A, 0x014D9, 0x014E7, 0x014E8, // Quarry Dots
		0x00557, 0x005F1, 0x00620, 0x009F5, 0x0146C, 0x3C12D,0x03686, 0x014E9, // Quarry Stones
		0x0367C, 0x3C125, // Quarry Dots + Stones
		0x034D4, 0x021D5, // Quarry Boathouse Ramp Activation
		0x03852, // Quarry Ramp Height Control
		0x03858, // Quarry Boathouse Horizontal Ramp Control
		0x275FA, // Ramp Hook Control
		0x021B3, 0x021B4, 0x021B0, 0x021AF, 0x021AE, // Quarry Eraser + Shapes
		0x021B5, 0x021B6, 0x021B7, 0x021BB, 0x09DB5, 0x09DB1, 0x3C124, // Quarry + Stars
		0x09DB3, 0x09DB4, 0x0A3CB, 0x0A3CC, 0x0A3D0, // Quarry Eraser + Stars + Shapes
		0x03612, // Quarry Laser
		0x00469, 0x00472, 0x00262, 0x00474, 0x00553, 0x0056F, // Swamp First row
		0x00390, 0x010CA, 0x00983, 0x00984, 0x00986, 0x00985, 0x00987, 0x181A9, // Swamp Second Row
		0x00609, // Swamp Bridge controll
		0x00982, 0x0097F, 0x0098F, 0x00990, 0x17C0D, 0x17C0E, // Swamp Red Panels
		0x00999, 0x0099D, 0x009A0, 0x009A1, // Swamp Disconnected Shapes
		0x00007, 0x00008, 0x00009, 0x0000A, 0x003B2, 0x00A1E, 0x00C2E, 0x00E3A, // Swamp Rotating Shapes
		0x009A6, // Swamp Optional Tetris
		0x009AB, 0x009AD, 0x009AE, 0x009AF, 0x00006, // Swamp Negative Shapes 1
		0x00002, 0x00004, 0x00005, 0x013E6, 0x00596, // Swamp Negative Shapes 2
		0x00001, 0x014D2, 0x014D4, 0x014D1, // Swamp Negative Shapes 3
		0x17C05, 0x17C02, // Swamp Exit Shortcut
		0x02886, // Treehouse Entry door
		0x17D72, 0x17D8F, 0x17D74, 0x17DAC, 0x17D9E, 0x17DB9, 0x17D9C, 0x17DC2, 0x17DC4, // Treehouse Yellow Bridge
		0x17DC8, 0x17DC7, 0x17CE4, 0x17D2D, 0x17D6C, // Treehouse Pink Bridge 1
		0x17D9B, 0x17D99, 0x17DAA, 0x17D97, 0x17BDF, 0x17D91, 0x17DC6, // Treehouse Pink Bridge 2
		0x17DB3, 0x17DB5, 0x17DB6, 0x17DC0, 0x17DD7, 0x17DD9, 0x17DB8, 0x17DDC, 0x17DD1, 0x17DDE, 0x17DE3, 0x17DEC, 0x17DAE, 0x17DB0, 0x17DDB, // Treehouse Orange Bridge 1
		0x17D88, 0x17DB4, 0x17D8C, 0x17CE3, 0x17DCD, 0x17DB2, 0x17DCC, 0x17DCA, 0x17D8E, 0x17DB7, 0x17DB1, 0x17DA2, // Treehouse Orange Bridge 2
		0x17E3C, 0x17E4D, 0x17E4F, 0x17E52, 0x17E5B, 0x17E5F, 0x17E61, // Treehouse Green Bridge
		0x037FF, // Treehouse Shortcut Bridge to Keep
		0x2899C, 0x28A33, 0x28ABF, 0x28AC0, 0x28AC1, 0x28AD9, // Town Full Dots + Shapes
		0x2896A, // Town Rooftop Bridge
		0x28AC7, 0x28AC8, 0x28ACA, 0x28ACB, 0x28ACC, // Town Blue Symmetry
		0x18590, // Town Symmetry start
		0x28A69, // Town Church Star Door
		0x034E3, // Town Soundproof Room
		0x334D8, 0x03C0C, 0x03C08, // Town 3-color Room
		0x0A0C8, // Town Orange
		0x09F98, // Town Redirect
		0x17F89, 0x0A168, 0x33AB2, //Windmill Puzzles
		0x033D4, 0x0CC7B, 0x002A6, 0x00AFB, 0x15ADD, // Vaults
		0x17C34, // Mountain
		0x09E73, 0x09E75, 0x09E78, 0x09E79, 0x09E6C, 0x09E6F, 0x09E6B, // Mountain Orange Row
		0x09E7A, 0x09E71, 0x09E72, 0x09E69, 0x09E7B, // Mountain Green Row
		0x09EAD, 0x09EAF, 0x33AF5, 0x33AF7, 0x09F6E, // Mountain Purple Panels
		0x09FD3, 0x09FD4, 0x09FD6, 0x09FD7, 0x09FD8, // Mountain Rainbow Row
		0x09FCC, 0x09FCE, 0x09FCF, 0x09FD0, 0x09FD1, 0x09FD2, // Mountain multi puzzle
		0x09E86, 0x09E39, 0x09ED8, // Mountain double bridge //might need to be disable if we cant fix the scaling
		0x09EEB, // Mountain Elevator to Giant Puzzle
		0x09EFF, 0x09F01, 0x09FC1, 0x09F8E, 0x09FDA, // Mountain floor
		0x0383D, 0x0383A, 0x0383F, 0x09E56, 0x03859, 0x09E5A, 0x339BB, 0x33961, // Mountain pillar puzzles

		0x17FA2, 0x00FF8, // Caves
		0x01A0D, 0x018A0, 0x009A4, 0x00A72, // Caves Blue Symmetry/Tetris
		0x00190, 0x00558, 0x00567, 0x006FE, 0x008B8, 0x00973, 0x0097B, 0x0097D, 0x0097E, 0x00994, 0x334D5, 0x00995, 0x00996, 0x00998, // Caves riangle Puzzles
		0x32962, 0x32966, 0x01A31, 0x00B71, // Caves First alcove
		0x288EA, 0x288FC, 0x289E7, 0x288AA, // Caves Perspective
		0x0A16B, 0x0A2CE, 0x0A2D7, 0x0A2DD, 0x0A2EA, 0x17FB9, // Caves Full Dots
		0x0008F, 0x0006B, 0x0008B, 0x0008C, 0x0008A, 0x00089, 0x0006A, 0x0006C, 0x00027, 0x00028, 0x00029,	// Caves Invisible Dots
		0x17CF2, 0x021D7, // Caves Exit
		0x09DD5, 0x0A16E, 0x039B4, 0x09E85, // Caves Deep challenge caves
		0x335AB, 0x335AC, 0x3369D, // Caves Elevator

		//0x032FF, //Why a single apple tree?
		/*
		0x00698,	0x0048F, 0x09F92,	0x0A036,	0x09DA6,	0x0A049, 0x0A053, 0x09F94, // Desert Surface
		0x00422, 0x006E3, 0x0A02D, // Desert Light
		0x00C72, 0x0129D,	0x008BB, 0x0078D, 0x18313, // Desert Pond
		0x04D18,	0x01205, 0x181AB, 0x0117A, 0x17ECA, // Desert Flood
		0x18076, 0x0A15C, 0x09FFF, 0x0A15F, 0x012D7 // Desert Final and exit
		*/
		0x033EA, 0x01BE9, 0x01CD3, 0x01D3F, 0x03317, 0x0360E, // Keep PP
		0x01A0F, 0x019E7, 0x019DC, 0x00139, // Keep Hedges
		//0x17F9B,	0x002C4,	0x00767,	0x002C6,	0x0070E,	0x0070F,	0x0087D,	0x002C7, // Jungle Sound waves //Does not contain dots so isnt locked
		0x0026D,	0x0026E,	0x0026F,	0x00C3F,	0x00C41,	0x014B2, // Jungle Dots
		//Doors
		0x01A54, // Glass Factory Entry
		0x000B0, // Symmetry Island Door 1
		0x1C349, // Symmetry Island Door 2.
		0x01E5A, // Mill Entry Door Left
		0x09E57, // Quarry Entry Gate 1
		0x17CAA, // Jungle to Monastery Garden

		0x03678, 0x03679, 0x03675, 0x03676, 0x03677, // Mill Controls

		0x0288C, // Treehouse Door 1&2
		0x0A182, // Treehouse Door 3
		0x2700B, // Treehouse Exterior Door Control
		0x334DB, // Shadows Outer Door Control
		0x334DC, // Shadows Inner Door Control
		0x00B10, // Monastery Left Door
		0x00C92, // Monastery Right Door
		0x09D9B, // Monastery Overhead Door Control
		0x0056E, // Swamp Entry
		0x17C2E, // Bunker Entry Door
		0x09F7D, 0x09FDC, 0x09FF7, 0x09F82, 0x09FF8, 0x09D9F , 0x09DA1, 0x09DA2, 0x09DAF, 0x0A099, 0x0A010, 0x0A01B, 0x0A01F, 0x17E63, 0x17E67, 0x0A079, // Bunker
		0x17CAB, // Jungle Pop-up Wall
		0x0C339, // Desert Surface Door
		0x0A249, // Desert Pond Exit Door
		0x28998, // Town Yellow Door
		0x28A0D, // Town Church Stars
		0x17F5F, // Windmill door
		0x17D02, // Windmill Turn Control
		//Discards
		0x17F93, // Mountain 2 Discard
		0x17CFB, // Outside Tutorial Discard
		0x3C12B, // Glass Factory Discard
		0x17CE7, // Desert Discard
		0x17CF0, // Mill Discard
		0x17FA9, // Treehouse Green Bridge Discard
		0x17FA0, // Treehouse Laser Discard
		0x17D27, // Keep Discard
		0x17D28, // Shipwreck Discard
		0x17D01, // Town Orange Crate Discard
		0x17C71, // Town Rooftop Discard
		0x17F9B, // Jungle Discard
		0x17C42, // Mountainside Discard
		0x17CF7, // Theater Discard
		0x386FA,	0x1C33F,	0x196E2,	0x1972A,	0x19809,	0x19806,	0x196F8,	0x1972F, //shadows avoid
		0x19797,	0x1979A,	0x197E0,	0x197E8,	0x197E5, //Shadow follow
		0x09F7F, // Quary lazer panel
		0x181F5, 0x18488, 0x17E2B, 0x17C0A, 0x17E07, // Swamp bridge controlls

		0x0A332, // Challenge Timer
		0x3D9A9,

		0x09FAA, 0x1C2DF, 0x1831E, 0x1C260, 0x1831C, 0x1C2F3, 0x1831D, 0x1C2B1, 0x1831B, 0x09FA0, 0x09F86, 0x0A015, // Desert Controls
		0x17CC4, // Quarry Elevator
		0x28A79, // Town Maze Panel
		0x00815, // Theater Video Input
		0x17CBC, // Treehouse Door Timer
		0x037FF, // Treehouse Drawbridge
		0x34BC5, 0x34BC6, // Bunker Controls

		0x17CDF, 0x17CC8, 0x17CA6, 0x09DB8, 0x17C95, 0x0A054, // Boats

		// all EPs
		0x0332B, 0x03367, 0x28B8A, 0x037B6, 0x037B2, 0x000F7, 0x3351D, 0x0053C
		, 0x00771, 0x335C8, 0x335C9, 0x337F8, 0x037BB, 0x220E4, 0x220E5, 0x334B9
		, 0x334BC, 0x22106, 0x0A14C, 0x0A14D, 0x03ABC, 0x03ABE, 0x03AC0, 0x03AC4
		, 0x03AC5, 0x03BE2, 0x03BE3, 0x0A409, 0x006E5, 0x006E6, 0x006E7, 0x034A7
		, 0x034AD, 0x034AF, 0x03DAB, 0x03DAC, 0x03DAD, 0x03E01, 0x289F4
		, 0x289F5, 0x0053D, 0x0053E, 0x00769, 0x33721, 0x220A7, 0x220BD, 0x03B22
		, 0x03B23, 0x03B24, 0x03B25, 0x03A79, 0x28ABD, 0x28ABE, 0x3388F, 0x28B29
		, 0x28B2A, 0x018B6, 0x033BE, 0x033BF, 0x033DD, 0x033E5, 0x28AE9, 0x3348F
		, 0x001A3, 0x335AE, 0x000D3, 0x035F5, 0x09D5D, 0x09D5E, 0x09D63, 0x3370E
		, 0x035DE, 0x03601, 0x03603, 0x03D0D, 0x3369A
		, 0x336C8, 0x33505, 0x03A9E, 0x016B2, 0x3365F, 0x03731, 0x036CE, 0x03C07
		, 0x03A93, 0x03AA6, 0x3397C, 0x0105D, 0x0A304, 0x035CB, 0x035CF, 0x28A7B
		, 0x005F6, 0x00859, 0x17CB9, 0x28A4A, 0x334B6, 0x0069D, 0x28A4C, 0x289CF
		, 0x289D1, 0x33692, 0x03E77, 0x03E7C, 0x035C7, 0x01848, 0x03D06, 0x33530
		, 0x33600, 0x28A2F, 0x28A37, 0x334A3, 0x3352F, 0x33857, 0x33879, 0x03C19
		, 0x28B30, 0x035C9, 0x03335, 0x03412, 0x038A6, 0x038AA, 0x03E3F
		, 0x03E40, 0x28B8E, 0x28B91, 0x03BCE, 0x03BCF, 0x03BD1, 0x339B6, 0x33A20
		, 0x33A29, 0x33A2A, 0x33B06, 0x00614,

	// all Obelisks
	0x00367, 0x0A16C, 0x00097, 0x00263, 0x00359, 0x22073,
};

class APState;

struct LockablePuzzle
{
public:
	LockablePuzzle(int panelId) {
		id = panelId;
	};

	virtual void Read();
	virtual void UpdateLock(APState state);
	virtual void Restore();

	int id;

	bool hasStones = false;
	bool hasColoredStones = false;
	bool hasStars = false;
	bool hasStarsWithOtherSymbol = false;
	bool hasTetris = false;
	bool hasTetrisRotated = false;
	bool hasTetrisNegative = false;
	bool hasErasers = false;
	bool hasTriangles = false;
	bool hasDots = false;
	bool hasColoredDots = false;
	bool hasSoundDots = false;
	bool hasArrows = false;
	bool hasSymmetry = false;
	bool hasFullDots = false;
	bool needsChallengeLasers = false;
	bool needsMountainLasers = false;
	bool needsHuntEntities = false;
};

struct LockablePanel : LockablePuzzle {
	LockablePanel(int panelId) : LockablePuzzle(panelId) {}

	void Read();
	void UpdateLock(APState state);
	void Restore();

private:
	int grid_size_x;
	int grid_size_y;
	float path_width_scale;
	float pattern_scale;
	std::vector<float> dot_positions;
	std::vector<int> dot_flags;
	std::vector<int> dot_connections_a;
	std::vector<int> dot_connections_b;
	std::vector<int> decorations;
	std::vector<int> decoration_flags;
	std::vector<int> colored_regions;
	__int64 decorationsColorsPointer;

	std::vector<float> outer_background_color;
	std::vector<float> path_color;
	std::vector<float> background_region_color;
	int outer_background_mode;

	void addMissingSymbolsDisplay(std::vector<float>& newIntersections, std::vector<int>& newIntersectionFlags, std::vector<int>& newConnectionsA, std::vector<int>& newConnectionsB, int id);
	void createText(std::string text, std::vector<float>& intersections, std::vector<int>& intersectionFlags, std::vector<int>& connectionsA, std::vector<int>& connectionsB, float left, float right, float top, float bottom);
	void createCenteredText(std::string text, std::vector<float>& intersections, std::vector<int>& intersectionFlags, std::vector<int>& connectionsA, std::vector<int>& connectionsB, float top, float bottom);
	int addPuzzleSymbols(const APState& state, std::vector<float>& intersections, std::vector<int>& intersectionFlags, std::vector<int>& connectionsA, std::vector<int>& connectionsB, std::vector<int>& decorations, std::vector<int>& decorationsFlags, std::vector<int>& polygons, int id);
};

struct LockableEP : LockablePuzzle {
	LockableEP(int panelId) : LockablePuzzle(panelId) {}

	void Read();
	void UpdateLock(APState state);
	void Restore();
	void DisableEP(bool recolor, bool disableEndPoint);
	void LockEP(bool disable, bool recolor, bool disableEndPoint);
};

struct LockableObelisk : LockablePuzzle {
	LockableObelisk(int panelId) : LockablePuzzle(panelId) {}

	std::vector<float> original_orientation;

	void Read();
	void UpdateLock(APState state);
	void Restore();
};