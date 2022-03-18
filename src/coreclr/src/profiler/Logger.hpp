#pragma once

#include <stdio.h>

inline void CommonLog(const char* format, ...) 
{
  va_list args;
   va_start(args, format);
   vprintf(format, args);
   va_end(args);
}

#define LOG_INFO(fmt, ...)  { CommonLog("[%s] " fmt "\n", __func__, ##__VA_ARGS__); }