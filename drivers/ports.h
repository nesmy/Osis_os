#ifndef PORTS_H
#define PORTS_H

#include "../cpu/types.h"

class Ports{
    public:
        static unsigned char port_byte_in (u16 port);
        static void port_byte_out (u16 port, u8 data);
        static unsigned short port_word_in (u16 port);
        static void port_word_out (u16 port, u16 data);
};

#endif
