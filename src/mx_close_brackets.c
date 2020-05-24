#include "ush.h"

bool mx_close_brackets(char c, int *r_b, int *f_b, int sw_quote) {
    if (sw_quote == 0) {
        if (c == '(')
            *r_b = 1;
        else if (c == ')') {
            if (*r_b == 1)
                *r_b = 0;
            else {
                mx_print_parse_error(")");
                return false;
            }
        }
        else if (c == '{')
            *f_b = 1;
        else if (c == '}') {
            if (*f_b == 1)
                *f_b = 0;
            else {
                mx_print_parse_error("}");
                return false;
            }
        }
    }
    return true;
}
