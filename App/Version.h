#pragma once

#define TO_STRING2(s) #s
#define TO_STRING(s) TO_STRING2(s)

#define MAJOR 4
#define MINOR 2
#define PATCH 0

#define VERSION_STR     "4.2.0 Beta 10"
#define VERSION			MAJOR, MINOR, PATCH

#define AP_VERSION_STR	"0.4.5"
#define AP_VERSION_STR_BACKCOMPAT  "0.4.4"

#define PRODUCT_NAME L"Witness Random Puzzle Generator for Archipelago.gg"
