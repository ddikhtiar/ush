#include "ush.h"

int mx_del_character(char **str, char c) {
    int index = 0;
    char *ptr = NULL;
    char *begin = NULL;

    if (*str && c != 0) {
        ptr = *str;
        while (*ptr) {
            if (*ptr == c) {
                begin = mx_strndup(*str, index);
                ptr = mx_strdup(ptr + 1);
                mx_strdel(str);
                *str = mx_strjoin(begin, ptr);
                mx_strdel(&begin);
                mx_strdel(&ptr);
                return index;
                break;
            }
            index++;
            ptr++;
        }

    }
    return -1;
}
