#include "ush.h"

char *mx_commandor(char **str) {
    int lenght = 0;
    char *ptr = mx_strtrim(*str);
    char *commandor = NULL;

    mx_strdel(str);
    *str = ptr;
    if (ptr) {
        while (*ptr && !mx_isspace(*ptr)) {
            lenght++;
            ptr++;
        }
    }
    if (lenght > 0) {
        ptr = *str;
        commandor = mx_strndup(*str, lenght);
        *str = mx_strdup(ptr + lenght);
        mx_strdel(&ptr);
    }
    return commandor;
}
