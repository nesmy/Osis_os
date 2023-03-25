#include "../drivers/screen.h"
#include "util.h"

extern "C" void main() {
    Screen::clear_screen();
   
    /* Fill up the screen */
    int i = 0;
    for (i = 0; i < 24; i++) {
        char str[255];
        //char = "abc";
        Util::int_to_ascii(i, str);
        Screen::kprint_at(str, 0, i);
    }
}
