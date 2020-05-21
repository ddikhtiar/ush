#include "ush.h"

char *mx_commandor(char **str) {
    int lenght = 0;
    int sw_quote = 0;
    char *ptr = NULL;
    char *del = NULL;
    char *commandor = NULL;

    ptr = mx_strtrim(*str);
    mx_strdel(str);
    if (ptr) {
        del = ptr;
        while (*ptr) {
            if (*ptr == 92 && sw_quote != 1) {
                lenght += 2;
                ptr += 2;
                continue;
            }
            mx_quotes(&sw_quote, *ptr);
            if (mx_isspace(*ptr) && sw_quote == 0)
                break;
            lenght++;
            ptr++;
        }
        if (lenght > 0) {
            commandor = mx_strndup(del, lenght);
            *str = mx_strdup(ptr);
        }
        mx_strdel(&del);
    }
    return commandor;
}
