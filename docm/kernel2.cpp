#include "../drivers/screen.h"

extern "C" void main() {
    Screen screen;
    screen.clear_screen();
    //Screen::clear_screen();
    screen.kprint_at("X", 1, 6);
    screen.kprint_at("This text spans multiple lines", 75, 10);
    screen.kprint_at("There is a line\nbreak", 0, 20);
    screen.kprint("There is a lineS\nbreak");
    screen.kprint_at("What happens when we run out of space?", 45, 24);
}
