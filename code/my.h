/*
** EPITECH PROJECT, 2023
** lespoto my.h
** File description:
** ojojojo
*/
#include <stdarg.h>
#include <dirent.h>
#include <time.h>
#include <stddef.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <math.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef MY_H
    #define MY_H
    #define DEFAULT_SIZE 20
    #define DEFAULT_COLOR sfBlack
    #define DEFAULT_HEIGHT 1080
    #define DEFAULT_WIDTH 1920
    #define DEFAULT_BPP 64
    #define GREY sfColor_fromRGB(215, 215, 215)
    #define CACA sfColor_fromRGB(124, 21, 21)
    #define BUFFSIZE 1200

typedef struct button_s {
    sfRectangleShape *rect;
} button_struct;

typedef struct all_buttons {
    button_struct *eraser;
    button_struct *reset;
    button_struct *red;
    button_struct *blue;
    button_struct *green;
    button_struct *yellow;
    button_struct *black;
    button_struct *magenta;
    button_struct *white;
    button_struct *cyan;
    button_struct *size_plus;
    button_struct *size_minus;
    button_struct *file;
    button_struct *edit;
    button_struct *help;
    button_struct *file_save;
    button_struct *file_new;
    button_struct *file_save_as;
    button_struct *edit_s_p;
    button_struct *edit_s_m;
    button_struct *edit_gomme;
    button_struct *pipette;
    button_struct *bucket;
    button_struct *more;
    button_struct *about;
    button_struct *edit_sqr;
    button_struct *edit_brush;
} all_buts;

typedef struct mega {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfEvent event;
    sfImage *draw_sfrc;
    sfTexture *sfrc_texture;
    sfConvexShape *square;
    sfBool eraser;
    sfColor current_color;
    int current_size;
    sfSprite *Pip;
    sfTexture *pipe_text;
    sfSprite *Buck;
    sfTexture *T_bucket;
    sfSprite *draw_sheet;
    sfTexture *T_circle;
    sfSprite *circle;
    sfText *text;
    sfFont *font;
    bool file_but;
    bool edit_but;
    bool help_but;
    bool is_pipette;
    bool is_bucket;
    bool is_square;
    bool is_circle;
    bool is_brush;
    sfText *text2;
    sfImage *cici;
    sfFont *font2;
    sfVector2i pos_mouse_first;
} mgst;

button_struct *init_button(sfVector2f psition, sfVector2f size, sfColor color);
void file_depl(mgst *m, all_buts *buts);
void brush_cursor(sfRenderWindow *window);
void about_test(mgst *m, all_buts *buts);
void more_test(mgst *m, all_buts *buts);
sfSprite *create_circle(mgst *m);
void brush_test(mgst *m, all_buts *buts);
void sqr_test(mgst *m, all_buts *buts);
void is_in_circle(mgst *m, all_buts *but);
sfBool is_button_clicked(button_struct *button, mgst *m);
void create_bucket(mgst *m, all_buts *buts);
sfBool is_hooved(button_struct *button, mgst *m);
void save_button(mgst *m, all_buts *buts);
void bucket(mgst *m, all_buts *buts);
void pipette(mgst *m, all_buts *buts);
void bucket_cursor(sfRenderWindow *window);
void reset_tests(mgst *m, all_buts *buts);
void init_palette(all_buts *but);
void disp_palette(all_buts *but, mgst *m);
void color_test(all_buts *but, mgst *m);
void print_size(mgst *m);
void minus_test(mgst *m, all_buts *buts);
void plus_test(mgst *m, all_buts *buts);
void edit_depl(mgst *m, all_buts *buts);
sfSprite *create_draw_srfc(mgst *m);
void set_texte(mgst *m);
void help_depl(mgst *m, all_buts *buts);
void init_all_buttons(mgst *m, all_buts *buts);
void init_function(mgst *m, all_buts *buts);
void print_img(mgst *m);
void print_buttons(mgst *m, all_buts *buts);
void my_paint(mgst *m, sfSprite *draw_heet, sfBool is_pressed, all_buts *buts);
void set_menu(mgst *m, all_buts *buts);
void eraser_cursor(sfRenderWindow *window);
void open_button(mgst *m, all_buts *buts);
void pipette_cursor(sfRenderWindow *window);
void cursor_tests(mgst *m);
void dessin(mgst *m, sfVector2i pos_ms, sfVector2i pos_ms_prec, sfColor color);
bool clicked_gomme(mgst *m, sfRectangleShape *rect);
void create_pipette(mgst *m, all_buts *buts);
void icone(mgst *m);
sfView *create_view(mgst *m);
void print_a_file(char *filename);
void dropdown_file(mgst *m, char *str);
/* LIB */
int my_float(double f);
char **str_to_word_array(char *str);
char *my_strdup(const char *source);
int my_strcmp(const char *s1, const char *s2);
int my_spaceputallnbr(int nb);
int my_put_binary(long int nb);
int my_spacefloat(double f);
int my_arrondie(int n);
int my_str_to_int(const char *str);
int my_plusexpotentiel(float f, int nbr, int science);
int my_plusexpotentielsupp(float f, int nbr, int science);
int my_plusfloat(double f);
int my_put_plusnbr(int nb);
int my_putallnbr(int nb);
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
