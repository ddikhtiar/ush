#include "ush.h"

static void sx_del_backslash(char **str);

void mx_del_backslash(t_bin *strct) {
    char **ptr = NULL;

    ptr = &(strct->commandor);
    sx_del_backslash(ptr);
    ptr = strct->solders;
    if (ptr && *ptr) {
        while (*ptr) {
            sx_del_backslash(ptr);
            ptr++;
        }
    }
}

static void sx_del_backslash(char **str) {
    int cycle = 1;

    if (*str && **str != 34 && **str != 39) {
        while (cycle >= 0)
            cycle = mx_del_character(str, 92);
    }
}
