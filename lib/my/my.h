/*
** EPITECH PROJECT, 2023
** lespoto my.h
** File description:
** ojojojo
*/
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#ifndef MY_H
    #define MY_H

int my_float(double f);
char **str_to_word_array(char *str);
char *my_strdup(const char *source);
int my_strcmp(const char *s1, const char *s2);
int my_spaceputallnbr(int nb);
int my_put_binary(long int nb);
int my_spacefloat(double f);
int my_arrondie(int n);
int my_plusexpotentiel(float f, int nbr, int science);
int my_plusexpotentielsupp(float f, int nbr, int science);
int my_plusfloat(double f);
int my_put_plusnbr(int nb);
int my_putallnbr(int nb);
int my_str_to_int(const char *str);
int counter(double f, int *science);
int my_spaceputmanychar(int i, int i2, float *f2);
int formatquadris(char type, va_list argp, int *where);
int formatquentis(char type, va_list argp, int *where);
int my_putmanynegchar0(int i, int i2, double *f2, int science);
int my_putmanychar0(int i, int i2, double *f2, int science);
int my_otherchoice(int i, int i2, float f2, int science);
int my_otherchoicesupp(int i, int i2, float f2, int science);
int my_putmanychar(int i, int i2, float *f2);
int my_putmanynegchar(int i, int i2, float *f2);
int expo_format(char type, va_list argp);
int digits_formatbis(char type, va_list argp, int *where);
int digits_formatbisbis(char type, va_list argp, int *where);
int formattris(char type, va_list argp, int *where);
int my_float_hexa(float f);
int hexal_format(char type, va_list argp);
int my_putchar(char c);
int my_strcmp(char const *s1, char const *s2);
int my_expotentiel(float f, int nbr, int science);
int my_spaceexpotentiel(float f, int nbr, int science);
int my_spaceexpotentielsupp(float f, int nbr, int science);
int my_expotentielsupp(float f, int nbr, int science);
int my_compute_speit(int nb, int p);
int my_nbr_hexasupp(int nb);
int my_precise_float(float f, int n);
int count0(float *f, int *science);
int my_nbr_octal(long long int nb);
int my_nbr_hexa(int nb);
int my_printf(char *format, ...);
int string_format(char type, va_list argp);
int digits_format(char type, va_list argp);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char my_strncpy(char *dest, const char *src, int n);
char *my_strcat(char *dest, char const *src);

#endif
