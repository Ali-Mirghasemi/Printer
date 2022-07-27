#include "Printer.h"

static const char ENDLINE[] = PRINTER_ENDLINE;

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

/**
 * @brief print a empty line
 * 
 * @param stream 
 * @return Stream_Result 
 */
Stream_Result Print_line(Stream* stream) {
    return Stream_writeBytes(stream, (uint8_t*) ENDLINE, sizeof(ENDLINE) - 1);
}
/**
 * @brief print single char and end line
 * 
 * @param stream 
 * @param c 
 * @return Stream_Result 
 */
Stream_Result Println_char(Stream* stream, char c) {
    Stream_Result result = Print_char(stream, c);
    if (result == Str_Ok) {
        result = Print_line(stream);
    }
    return result;
}
/**
 * @brief print string and end line
 * 
 * @param stream 
 * @param str 
 * @return Stream_Result 
 */
Stream_Result Println_str(Stream* stream, const char *str) {
    Stream_Result result = Print_str(stream, str);
    if (result == Str_Ok) {
        result = Print_line(stream);
    }
    return result;
}
/**
 * @brief print number and end line
 * 
 * @param stream 
 * @param num 
 * @return Stream_Result 
 */
Stream_Result Println_num(Stream* stream, int num) {
    Stream_Result result = Print_num(stream, num);
    if (result == Str_Ok) {
        result = Print_line(stream);
    }
    return result;
}
/**
 * @brief print num and end line
 * 
 * @param stream 
 * @param num 
 * @param base 
 * @param minLen 
 * @return Stream_Result 
 */
Stream_Result Println_numFix(Stream* stream, int num, Str_Radix base, Str_LenType minLen) {
    Stream_Result result = Print_numFix(stream, num, base, minLen);
    if (result == Str_Ok) {
        result = Print_line(stream);
    }
    return result;
}
/**
 * @brief print unsigned number and end line
 * 
 * @param stream 
 * @param num 
 * @return Stream_Result 
 */
Stream_Result Println_unum(Stream* stream, unsigned int num) {
    Stream_Result result = Print_unum(stream, num);
    if (result == Str_Ok) {
        result = Print_line(stream);
    }
    return result;
}
/**
 * @brief print unsigned number and end line
 * 
 * @param stream 
 * @param num 
 * @param base 
 * @param minLen 
 * @return Stream_Result 
 */
Stream_Result Println_unumFix(Stream* stream, unsigned int num, Str_Radix base, Str_LenType minLen) {
    Stream_Result result = Print_unumFix(stream, num, base, minLen);
    if (result == Str_Ok) {
        result = Print_line(stream);
    }
    return result;
}
/**
 * @brief print float and end line
 * 
 * @param stream 
 * @param num 
 * @return Stream_Result 
 */
Stream_Result Println_float(Stream* stream, float num) {
    Stream_Result result = Print_float(stream, num);
    if (result == Str_Ok) {
        result = Print_line(stream);
    }
    return result;
}
/**
 * @brief print float and end line
 * 
 * @param stream 
 * @param num 
 * @param precision 
 * @return Stream_Result 
 */
Stream_Result Println_floatFix(Stream* stream, float num, Str_LenType precision) {
    Stream_Result result = Print_floatFix(stream, num, precision);
    if (result == Str_Ok) {
        result = Print_line(stream);
    }
    return result;
}

#if STR_ENABLE_LONG_NUMBER
/**
 * @brief print long number and end line
 * 
 * @param stream 
 * @param num 
 * @return Stream_Result 
 */
Stream_Result Println_long(Stream* stream, long num) {
    Stream_Result result = Print_long(stream, num);
    if (result == Str_Ok) {
        result = Print_line(stream);
    }
    return result;
}
/**
 * @brief print long number and end line
 * 
 * @param stream 
 * @param num 
 * @param base 
 * @param minLen 
 * @return Stream_Result 
 */
Stream_Result Println_longFix(Stream* stream, long num, Str_Radix base, Str_LenType minLen) {
    Stream_Result result = Print_longFix(stream, num, base, minLen);
    if (result == Str_Ok) {
        result = Print_line(stream);
    }
    return result;
}
/**
 * @brief print unsigned long number and end line
 * 
 * @param stream 
 * @param num 
 * @return Stream_Result 
 */
Stream_Result Println_ulong(Stream* stream, unsigned long num) {
    Stream_Result result = Print_ulong(stream, num);
    if (result == Str_Ok) {
        result = Print_line(stream);
    }
    return result;
}
/**
 * @brief print unsigned long number and end line
 * 
 * @param stream 
 * @param num 
 * @param base 
 * @param minLen 
 * @return Stream_Result 
 */
Stream_Result Println_ulongFix(Stream* stream, unsigned long num, Str_Radix base, Str_LenType minLen) {
    Stream_Result result = Print_ulongFix(stream, num, base, minLen);
    if (result == Str_Ok) {
        result = Print_line(stream);
    }
    return result;
}
#endif

#if STR_ENABLE_DOUBLE
/**
 * @brief print double and end line
 * 
 * @param stream 
 * @param num 
 * @return Stream_Result 
 */
Stream_Result Println_double(Stream* stream, double num) {
    Stream_Result result = Print_double(stream, num);
    if (result == Str_Ok) {
        result = Print_line(stream);
    }
    return result;
}
/**
 * @brief print double and end line
 * 
 * @param stream 
 * @param num 
 * @param precision 
 * @return Stream_Result 
 */
Stream_Result Println_doubleFix(Stream* stream, double num, Str_LenType precision) {
    Stream_Result result = Print_doubleFix(stream, num, precision);
    if (result == Str_Ok) {
        result = Print_line(stream);
    }
    return result;
}
#endif


