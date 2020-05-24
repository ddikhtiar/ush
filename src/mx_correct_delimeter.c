#include "ush.h"

bool mx_correct_delimeter(const char *str) {
    char *delim = NULL;
    int r_bracket = 0; // "(" = 1, ")" = 2;
    int f_bracket = 0; // "{" = 1, "}" = 2;
    int sw_quote = 0;  // = 1 для ' или = 2 для "
    int sw_words = 0;

    while (*str) {
        if (*str == 92 && sw_quote != 1) {
            str += 2;
            continue;
        }
        mx_quotes(&sw_quote, *str);
        if (!mx_close_brackets(*str, &r_bracket, &f_bracket, sw_quote))
            return false;
        if (mx_delim(str) > 0) {
            if (sw_words == 0 && sw_quote == 0 && *str != ';') {
                delim = mx_strndup(str, mx_delim(str));
                mx_print_parse_error(delim);
                mx_strdel(&delim);
                return false;
            }
            sw_words = 0;
            str += mx_delim(str);
            continue;
        }
        if (mx_isspace(*str) && f_bracket == 1)
            f_bracket = 0;
        if (!mx_isspace(*str))
            sw_words = 1;
        str++;
    }
    if (sw_quote != 0 || r_bracket == 1) {
        mx_printerr("Odd number of quotes.\n");
        return false;
    }
    return true;
}
