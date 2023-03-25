#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80
#define WHITE_ON_BLACK 0x0f
#define RED_ON_WHITE 0xf4

/* Screen i/o ports */
#define REG_SCREEN_CTRL 0x3d4
#define REG_SCREEN_DATA 0x3d5
#include "ports.h"

/* Public kernel API */
class Screen {
    public:
    static void clear_screen();
    static void kprint_at(char *message, int col, int row);
    static void kprint(char *message);
    private:
    static int get_cursor_offset();
    static void set_cursor_offset(int offset);
    static int print_char(char c, int col, int row, char attr);
    static int get_offset(int col, int row);
    static int get_offset_row(int offset);
    static int get_offset_col(int offset);

};
