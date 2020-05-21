#include "ush.h"

int mx_substr_lenght(const char *str) {
    int lenght = 0;
    int sw_quote = 0;

    while (*str) {
        if (*str == 92 && sw_quote != 1) {
            lenght += 2;
            str += 2;
            continue;
        }
        mx_quotes(&sw_quote, *str);
        if (mx_isspace(*str) && sw_quote == 0)
            break;
        lenght++;
        str++;
    }
    return lenght;
}
