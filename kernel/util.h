
#include "../cpu/types.h"

class Util
{
    public:
        static void memory_copy(char* source, char* dest, int nbytes);
        static void int_to_ascii(int n, char str[]);
        static void  memory_set(u8 *dest, u8 val, u32 len);
};


