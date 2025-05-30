// kstdarg.h
// Created by Fred Nora.

#ifndef __LIBK_STDARG_H
#define __LIBK_STDARG_H    1

// Credits: 
// kinguio, by Nelson Cole.
typedef __builtin_va_list  va_list;
#define va_start(v,l)  __builtin_va_start(v,l)
#define va_arg(v,l)    __builtin_va_arg(v,l)
#define va_end(v)      __builtin_va_end(v)
#define va_copy(d,s)   __builtin_va_copy(d,s)

#endif    

