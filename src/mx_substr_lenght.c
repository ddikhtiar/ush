#include "ush.h"

int mx_substr_lenght(const char *str) {
    int lenght = 0;
    int sw_quote = 0;

    while (*str) {
        if (*str == 34) {
            if (sw_quote == 0)
                sw_quote = 2;
            else if (sw_quote == 2)
                sw_quote = 0;
            continue;
        }
        if (*str == 39) {
            // sw_quote = (sw_quote == 0 ? 1 : (sw_quote == 1 ? 0 : void));
            if (sw_quote == 0)
                sw_quote = 1;
            else if (sw_quote == 1)
                sw_quote = 0;
            continue;
        }
        if (mx_isspace(*str) && sw_quote == 0)
            break;
        lenght++;
        str++;
    }
    return lenght;
}
