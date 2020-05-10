#include "ush.h"

static int sx_dollar_length(char **str);

char *mx_dollar(char *str) {
    char *ptr = NULL;
    char *dollar = NULL;
    char *swap = NULL;
    int len = 0;

    if (!str)
        return NULL;
    ptr = str + 1;
    len = sx_dollar_length(&ptr);
    if (len > 0) {
        dollar = mx_strndup(str + 1, len);
        swap = getenv(dollar);
        mx_strdel(&dollar);
        return mx_strjoin(swap, ptr);
    }
    return mx_strdup(str);
}

static int sx_dollar_length(char **str) {
    char *ptr = *str;
    int result = 0;

    while (*ptr && ((*ptr > 64 && *ptr < 91)
            || (*ptr > 96 && *ptr < 123)
            || (*ptr > 47 && *ptr < 58))) {
        result++;
        ptr++;
    }
    *str = ptr;
    return result;
}
