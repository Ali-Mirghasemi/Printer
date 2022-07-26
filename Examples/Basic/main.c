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


    Print_str(&ostream.Buffer, "[Basic Printer]\n");
    Print_num(&ostream.Buffer, 1024);

    OStream_flush(&ostream);
}

void Printer_transmit(OStream* stream, uint8_t* val, Stream_LenType len) {
    Stream_LenType temp = len;
    while (len-- > 0) {
        putchar(*val++);
    }
    OStream_handle(stream, temp);
}

