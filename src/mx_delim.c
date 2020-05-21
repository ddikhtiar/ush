#include "ush.h"

int mx_delim(const char *str) {
    if (*str == ';')
        return 1;
    else if (mx_strncmp(str, "&&", 2) == 0)
        return 2;
    else if (mx_strncmp(str, "||", 2) == 0)
        return 2;
    else if (*str == '&')
        return 1;
    else
        return 0;
}
