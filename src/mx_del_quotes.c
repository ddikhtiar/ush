#include "ush.h"

static void sx_del_quotes(char **str);

void mx_del_quotes(t_bin *strct) {
    char **ptr = NULL;

    ptr = &(strct->commandor);
    sx_del_quotes(ptr);
    ptr = strct->solders;
    if (ptr && *ptr) {
        while (*ptr) {
            sx_del_quotes(ptr);
            ptr++;
        }
    }
}

static void sx_del_quotes(char **str) {
    char *ptr = NULL;
    int lenght = 0;

    if (*str) {
        ptr = *str;
        if (*ptr == 34 || *ptr == 39) {
            lenght = mx_strlen(*str);
            *str = mx_strndup(ptr + 1, lenght - 2);
            mx_strdel(&ptr);
        }
    }
}
