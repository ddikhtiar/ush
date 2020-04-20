#include "ush.h"

void mx_shift_spaces(char **str) {
    char *ptr = *str;

    if (ptr) {
        while (*ptr) {
            if (!mx_isspace(*ptr))
                break;
            ptr++;
        }
        *str = ptr;
    }
}
