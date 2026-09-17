#include <iostream>
#include <string>

void drawCat();

int main(int argc, char* argv[]) {
    bool needToDrawCat = false;

    for (int i = 0; i < argc; ++i)
        if (std::string(argv[i]) == "--cat_window")
            needToDrawCat = true;
    
    if (needToDrawCat)
        drawCat();
    
    std::cout << "meow!" << std::endl;
    return 0;
}