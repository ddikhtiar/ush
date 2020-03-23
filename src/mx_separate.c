#include "ush.h"

t_parse *mx_separate(const char *str) {
    char *ptr = NULL;
    t_parse *final = NULL;
    int len = 0;

    while () {
        len = mx_(ptr, len);
        mx_push_parse_back(&final, mx_strndup(ptr, len));
    }
    return final;
}
