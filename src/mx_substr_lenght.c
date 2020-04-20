#include "ush.h"

int mx_substr_lenght(const char *str) {
    int lenght = 0;
    int sw_quote = 0;

    while (*str) {
        mx_quotes(&sw_quote, *str);
        if (mx_isspace(*str) && sw_quote == 0)
            break;
        lenght++;
        str++;
    }
    return lenght;
}
