#include "Printer.h"

Stream_Result Print_char(Stream* stream, char c) {
    return Stream_writeChar(stream, c);
}
Stream_Result Print_str(Stream* stream, const char *str) {
    return Stream_writeStr(stream, str);
}
Stream_Result Print_num(Stream* stream, int num) {
    char buf[12];
    Str_LenType len = Str_parseNum(num, Str_Decimal, STR_NORMAL_LEN, buf);
    return Stream_writeStr(stream, buf);
}
Stream_Result Print_numFix(Stream* stream, int num, Str_Radix base, Str_LenType minLen) {
    char buf[12];
    Str_LenType len = Str_parseNum(num, base, minLen, buf);
    return Stream_writeStr(stream, buf);
}
Stream_Result Print_unum(Stream* stream, unsigned int num) {
    char buf[12];
    Str_LenType len = Str_parseUNum(num, Str_Decimal, STR_NORMAL_LEN, buf);
    return Stream_writeStr(stream, buf);
}
Stream_Result Print_unumFix(Stream* stream, unsigned int num, Str_Radix base, Str_LenType minLen) {
    char buf[12];
    Str_LenType len = Str_parseNum(num, base, minLen, buf);
    return Stream_writeStr(stream, buf);
}

Stream_Result Print_float(Stream* stream, float num) {
    char buf[17];
    Str_LenType len = Str_parseFloat(num, buf);
    return Stream_writeStr(stream, buf);
}
Stream_Result Print_floatFix(Stream* stream, float num, Str_LenType precision) {
    char buf[17];
    Str_LenType len = Str_parseFloatFix(num, buf, precision);
    return Stream_writeStr(stream, buf);
}

#if STR_ENABLE_LONG_NUMBER
Stream_Result Print_long(Stream* stream, long num) {
    char buf[22];
    Str_LenType len = Str_parseLong(num, Str_Decimal, STR_NORMAL_LEN, buf);
    return Stream_writeStr(stream, buf);
}
Stream_Result Print_longFix(Stream* stream, long num, Str_Radix base, Str_LenType minLen) {
    char buf[22];
    Str_LenType len = Str_parseLong(num, base, minLen, buf);
    return Stream_writeStr(stream, buf);
}
Stream_Result Print_ulong(Stream* stream, unsigned long num) {
    char buf[22];
    Str_LenType len = Str_parseULong(num, Str_Decimal, STR_NORMAL_LEN, buf);
    return Stream_writeStr(stream, buf);
}
Stream_Result Print_ulongFix(Stream* stream, unsigned long num, Str_Radix base, Str_LenType minLen) {
    char buf[22];
    Str_LenType len = Str_parseULong(num, base, len, buf);
    return Stream_writeStr(stream, buf);
}
#endif

#if STR_ENABLE_DOUBLE
Stream_Result Print_double(Stream* stream, double num) {
    char buf[33];
    Str_LenType len = Str_parseDouble(num, buf);
    return Stream_writeStr(stream, buf);
}
Stream_Result Print_doubleFix(Stream* stream, double num, Str_LenType precision) {
    char buf[33];
    Str_LenType len = Str_parseDoubleFix(num, buf, precision);
    return Stream_writeStr(stream, buf);
}
#endif
