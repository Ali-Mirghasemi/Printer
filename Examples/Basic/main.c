#include <stdio.h>

#include "StreamBuffer.h"
#include "OutputStream.h"
#include "Printer.h"

void Printer_transmit(OStream* stream, uint8_t* val, Stream_LenType len);

int main()
{
    char buff[100];
    OStream ostream;

    OStream_init(&ostream, Printer_transmit, (uint8_t*) buff, sizeof(buff));


    Println_str(&ostream.Buffer, "[Basic Printer]");
    Println_num(&ostream.Buffer, 1024);
    Println_floatFix(&ostream.Buffer, 2.145f, 3);
    Println_float(&ostream.Buffer, 2.125f);
    Println_ulong(&ostream.Buffer, 4000000);
    Println_numFix(&ostream.Buffer, 124, Str_Binary, 8);
    Println_numFix(&ostream.Buffer, 0x45, Str_Hex, 8);

    OStream_flush(&ostream);
}

void Printer_transmit(OStream* stream, uint8_t* val, Stream_LenType len) {
    Stream_LenType temp = len;
    while (len-- > 0) {
        putchar(*val++);
    }
    OStream_handle(stream, temp);
}

