

#include "define.h"
#include "console_size.h"

#if defined(PLAT_LINUX)
    #include <sys/ioctl.h>
    #include <unistd.h>
#elif defined(PLAT_WINDOWS)
    #include <windows.h>
#endif

void consoleSize(int &width, int &height) {
#if defined(PLAT_LINUX)
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
        width = w.ws_col;
        height = w.ws_row;
    }
#elif defined(PLAT_WINDOWS)
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }
#endif
}