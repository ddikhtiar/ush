#include "ush.h"

int mx_status(char **str) {
    char *ptr = *str;
    int status = 2;

    if (*ptr == ';') {
        *str = mx_strdup(ptr + 1);
        mx_strdel(&ptr);
    }
    else if (mx_strncmp(ptr, "&&", 2) == 0) {
        status = 1;
        *str = mx_strdup(ptr + 2);
        mx_strdel(&ptr);
    }
    else if (mx_strncmp(ptr, "||", 2) == 0) {
        status = -1;
        *str = mx_strdup(ptr + 2);
        mx_strdel(&ptr);
    }
    return status;
}
