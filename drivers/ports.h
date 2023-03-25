

class Ports{
    public:
        static unsigned char port_byte_in (unsigned short port);
        static void port_byte_out (unsigned short port, unsigned char data);
        static unsigned short port_word_in (unsigned short port);
        static void port_word_out (unsigned short port, unsigned short data);
};
