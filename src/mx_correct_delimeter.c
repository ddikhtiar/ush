#include "ush.h"

bool mx_correct_delimeter(const char *str) {
    char *delim = NULL;
    int sw_quote = 0; // = 1 для ' или = 2 для "
    int sw_words = 0;

    while (*str) {
        if (*str == 92 && sw_quote != 1) {
            str += 2;
            continue;
        }
        mx_quotes(&sw_quote, *str);
        if (mx_delim(str) > 0) {
            if (sw_words == 0) {
                if (sw_quote == 0 && *str != ';') {
                    delim = mx_strndup(str, mx_delim(str));
                    mx_printerr("u$h: parse error near `");
                    mx_printerr(delim);
                    mx_printerr("'\n");
                    mx_strdel(&delim);
                    return false;
                }
            }
            sw_words = 0;
            str += mx_delim(str);
            continue;
        }
        if (!mx_isspace(*str))
            sw_words = 1;
        str++;
    }
    return true;
}
