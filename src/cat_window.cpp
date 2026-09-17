#include <string>
#include <iostream>

#include "console_size.h"

// Symbols
#define TOP_SYM "_" // "⎽"
#define BOTTOM_SYM "ˉ" // "⎺"
#define LEFT_DIAG_SYM "\\"
#define RIGHT_DIAG_SYM "/"
#define SIDE_SYM "|" // "⎮"
#define SEPARATOR_SYM "|" // "⎮"
#define PAW "\\||/"
#define MOUTH_CENTER "^"

// Titlebar
#define ICON ":3"
#define TITLE "Cat Window :3"
#define CLOSE_BUTTON "X"
#define HIDE_BUTTON "_"
#define OVERLOAD "..."

// Parameters

#define EARS_SIZE 6
#define PAWS_HEIGHT 3

/*
______________________________________
\    |:3|     Cat Window    |_|X|    /
 \   |ˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉˉ|   /
  \  |                          |  /
   \ |         \      /         | /
    \|       ___\    /___       |/
     |          _    _          |
     |          \_/\_/          |
     |                          |
     |  |    |          |    |  |
     ˉˉˉ|    |ˉˉˉˉˉˉˉˉˉˉ|    |ˉˉˉ
         \||/            \||/ 
*/

/*
─────┲━━━┯━━━━━━━━━━━━━━━━┯━━━┯━━━┱─────
╲    ┃>ω<│ Cat Window :3  │ _ │ X ┃    ╱
 ╲   ┡━━━┷━━━━━━━━━━━━━━━━┷━━━┷━━━┩   ╱
  ╲  │                            │  ╱
   ╲ │          ╲      ╱          │ ╱
    ╲│        ___╲    ╱___        │╱
     │           _    _           │
     │           ╲_╱╲_╱           │
     │                            │
     │  │    │            │    │  │
     ╰──┤    ├────────────┤    ├──╯
         ╲||╱              ╲||╱ 
*/

void drawCat() {
    int width = -1, height = -1;
    consoleSize(width, height);
    if (width == -1 || height == -1) {
        std::cout << "Unable to get console size";
        width = 80;
        height = 24;
    }
    if (width < 36 || height < 15)
    {
        std::cout << "Cat-Window: i won't fit in here!\nCat-Window: anyway, ";
        return;
    }

    height -= 3; // bcz input line

    std::string result = "";

    std::string title = ICON;
    title += SEPARATOR_SYM;
    std::string title_text = TITLE;
    std::string title_end = SEPARATOR_SYM;
    title_end += HIDE_BUTTON;
    title_end += SEPARATOR_SYM;
    title_end += CLOSE_BUTTON;


    int title_length = title_text.length();

    int avaiableTitleZone = width - EARS_SIZE * 2 - 2 - title.size() - title_end.size();
    if (title_length <= avaiableTitleZone) {
        int spaces_zone = avaiableTitleZone - title_length;
        int spaces_count = spaces_zone / 2;
        std::string spaces = std::string("");
        spaces.resize(spaces_count, ' ');
        title += spaces + title_text + spaces + (spaces_zone % 2 == 0 ? "" : " ") + title_end;
    }


    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x)
        {
            // top line
            if (y == 0)
            {
                result += TOP_SYM;
                continue;
            }

            std::string target_sym = " ";

            // eyes
            if (y == height / 2 - 1 && (x == width / 2 - 7 || x == width / 2 - 6 || x == width / 2 - 5 || x == width / 2 + 4 || x == width / 2 + 5 || x == width / 2 + 6)){
                target_sym = TOP_SYM;
            }
            if (y == height / 2 - 1 && x == width / 2 - 4 || y == height / 2 - 2 && x == width / 2 - 5){
                target_sym = LEFT_DIAG_SYM;
            }
            if (y == height / 2 - 1 && x == width / 2 + 3 || y == height / 2 - 2 && x == width / 2 + 4){
                target_sym = RIGHT_DIAG_SYM;
            }

            // mouth
            if (y == height / 2 + 1 && (x == width / 2 - 2 || x == width / 2 + 1)
             || y == height / 2 && (x == width / 2 - 3 || x == width / 2 + 2)){
                target_sym = TOP_SYM;
            }
            if (y == height / 2 + 1 && (x == width / 2 - 3 || x == width / 2)){
                target_sym = LEFT_DIAG_SYM;
            }
            if (y == height / 2 + 1 && (x == width / 2 + 2 || x == width / 2 - 1)){
                target_sym = RIGHT_DIAG_SYM;
            }

            // ears
            if (x == y - 1 && y <= EARS_SIZE)
                target_sym = LEFT_DIAG_SYM;

            if (width - x - 1 == y - 1 && y <= EARS_SIZE)
                target_sym = RIGHT_DIAG_SYM;
            
            // sides
            if (y < height - PAWS_HEIGHT + 1 && (x == EARS_SIZE || width - x - 1 == EARS_SIZE))
                target_sym = SIDE_SYM;
            
            // bottom
            if (y == height - PAWS_HEIGHT + 1 && (x >= EARS_SIZE && width - x - 1 >= EARS_SIZE))
                target_sym = BOTTOM_SYM;

            // titlebar line
            if (x >= EARS_SIZE + 1 && width - x - 2 >= EARS_SIZE){
                if (y == 1)
                    target_sym = x == EARS_SIZE + 1 ? title : "";
                if (y == 2)
                    target_sym = BOTTOM_SYM;
            } 
            
            // paws
            if (y > height - PAWS_HEIGHT - 1 && y < height - 1 && (
                (x == EARS_SIZE + 3 || x == EARS_SIZE + 8)
             || (x == width - EARS_SIZE - 4 || x == width - EARS_SIZE - 9))
             || y >= height - 1 && ((x == EARS_SIZE + 5 || x == EARS_SIZE + 6) || (x == width - EARS_SIZE - 6 || x == width - EARS_SIZE - 7)))
                target_sym = SIDE_SYM;

            if (y == height - PAWS_HEIGHT + 1 && ((x > EARS_SIZE + 3 && x < EARS_SIZE + 8) || (x < width - EARS_SIZE - 4 && x > width - EARS_SIZE - 9)))
                target_sym = " ";

            if (y >= height - 1 && (x == EARS_SIZE + 4 || x == width - EARS_SIZE - 8))
                target_sym = LEFT_DIAG_SYM;

            if (y >= height - 1 && (x == EARS_SIZE + 7 || x == width - EARS_SIZE - 5))
                target_sym = RIGHT_DIAG_SYM;

            result += target_sym;
        }
        if (y != height - 1)
            result += "\n";
    }

    std::cout << result << std::endl;
}