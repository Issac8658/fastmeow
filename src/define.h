#pragma once

#if defined(_WIN32) || defined(_WIN64)
    #define PLAT_WINDOWS
#elif defined(__APPLE__) || defined(__MACH__)
    #define PLAT_MACOS
#elif defined(__linux__)
    #define PLAT_LINUX
#else
    #define PLAT_UNKNOWN
#endif