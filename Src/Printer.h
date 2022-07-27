/**
 * @file Printer.h
 * @author Ali Mirghasemi (ali.mirghasemi1376@gmail.com)
 * @brief This Library help you to print your data in Stream.
 * @version 0.1
 * @date 2022-07-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _PRINTER_H_
#define _PRINTER_H_


#ifdef __cplusplus
extern "C" {
#endif

#define PRINTER_ENDLINE                     "\r\n"


#include "Str.h"
#include "StreamBuffer.h"

Stream_Result Print_char(Stream* stream, char c);
Stream_Result Print_str(Stream* stream, const char *str);
Stream_Result Print_num(Stream* stream, int num);
Stream_Result Print_numFix(Stream* stream, int num, Str_Radix base, Str_LenType minLen);
Stream_Result Print_unum(Stream* stream, unsigned int num);
Stream_Result Print_unumFix(Stream* stream, unsigned int num, Str_Radix base, Str_LenType minLen);

Stream_Result Print_float(Stream* stream, float num);
Stream_Result Print_floatFix(Stream* stream, float num, Str_LenType precision);

#if STR_ENABLE_LONG_NUMBER
    Stream_Result Print_long(Stream* stream, long num);
    Stream_Result Print_longFix(Stream* stream, long num, Str_Radix base, Str_LenType minLen);
    Stream_Result Print_ulong(Stream* stream, unsigned long num);
    Stream_Result Print_ulongFix(Stream* stream, unsigned long num, Str_Radix base, Str_LenType minLen);
#endif

#if STR_ENABLE_DOUBLE
    Stream_Result Print_double(Stream* stream, double num);
    Stream_Result Print_doubleFix(Stream* stream, double num, Str_LenType precision);
#endif

Stream_Result Print_line(Stream* stream);

Stream_Result Println_char(Stream* stream, char c);
Stream_Result Println_str(Stream* stream, const char *str);
Stream_Result Println_num(Stream* stream, int num);
Stream_Result Println_numFix(Stream* stream, int num, Str_Radix base, Str_LenType minLen);
Stream_Result Println_unum(Stream* stream, unsigned int num);
Stream_Result Println_unumFix(Stream* stream, unsigned int num, Str_Radix base, Str_LenType minLen);

Stream_Result Println_float(Stream* stream, float num);
Stream_Result Println_floatFix(Stream* stream, float num, Str_LenType precision);

#if STR_ENABLE_LONG_NUMBER
    Stream_Result Println_long(Stream* stream, long num);
    Stream_Result Println_longFix(Stream* stream, long num, Str_Radix base, Str_LenType minLen);
    Stream_Result Println_ulong(Stream* stream, unsigned long num);
    Stream_Result Println_ulongFix(Stream* stream, unsigned long num, Str_Radix base, Str_LenType minLen);
#endif

#if STR_ENABLE_DOUBLE
    Stream_Result Println_double(Stream* stream, double num);
    Stream_Result Println_doubleFix(Stream* stream, double num, Str_LenType precision);
#endif


#ifdef __cplusplus
};
#endif

#endif // _PRINTER_H_
