#include "ush.h"

void mx_replacement(char **str) {
    int counter = 0;
    char *begin = NULL;
    char *end = NULL;
    char *ptr = *str;
    int sw_quote = 0; // = 1 для ' или = 2 для "

    while (*ptr) {
        if (*ptr == 92 && sw_quote != 1) {
            counter += 2;
            ptr += 2;
            continue;
        }
        if (mx_quotes(&sw_quote, *ptr)) {
            counter++;
            ptr++;
            continue;
        }
        if (*ptr == '~' && sw_quote == 0) {
            end = mx_tilda(ptr);
            if (!end) {
                ptr++;
                mx_no_such_user(ptr);
                mx_strdel(str);
                break;
            }
            begin = mx_strndup(*str, counter);
            mx_strdel(str);
            *str = mx_strjoin(begin, end);
            mx_strdel(&begin);
            mx_strdel(&end);
            ptr = *str + counter;
        }
        if (*ptr == '$' && sw_quote != 1 && *(ptr + 1) != ' ') {
            end = mx_dollar(ptr);
            begin = mx_strndup(*str, counter);
            mx_strdel(str);
            *str = mx_strjoin(begin, end);
            mx_strdel(&begin);
            mx_strdel(&end);
            ptr = *str + counter;
        }
        counter++;
        ptr++;
    }
}
