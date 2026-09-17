#include "define.h"
#include <iostream>
#include <string>

#if defined(PLAT_WINDOWS)
    #include <windows.h>
#endif

void drawCat();

int main(int argc, char* argv[]) {
    #if defined(PLAT_WINDOWS)
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif

    bool needToDrawCat = false;

    for (int i = 0; i < argc; ++i)
        if (std::string(argv[i]) == "--cat_window")
            needToDrawCat = true;
    
    if (needToDrawCat)
        drawCat();
    
    std::cout << "meow!" << std::endl;
    return 0;
}