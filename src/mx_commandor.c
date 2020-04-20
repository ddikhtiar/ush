#include "ush.h"

char *mx_commandor(char **str) {
    int lenght = 0;
    char *ptr = NULL;
    char *del = NULL;
    char *commandor = NULL;

    ptr = mx_strtrim(*str);
    mx_strdel(str);
    if (ptr && *ptr != '\0') {
        del = ptr;
        while (*ptr && *ptr != '\0' && !mx_isspace(*ptr)) {
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
