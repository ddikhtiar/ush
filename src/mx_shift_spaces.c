#include "ush.h"

void mx_shift_spaces(char **str) {
    char *ptr = *str;
    int sw_quote = 0;

    if (ptr) {
        while (*ptr) {
            if (*ptr == 34) {
                if (sw_quote == 0)
                    sw_quote = 2;
                else if (sw_quote == 2)
                    break;
            }
            if (*ptr == 39) {
                if (sw_quote == 0)
                    sw_quote = 1;
                else if (sw_quote == 1)
                    break;
            }
            if (!mx_isspace(*ptr) && sw_quote == 0)
                break;
            ptr++;
        }
        *str = ptr;
    }
}
