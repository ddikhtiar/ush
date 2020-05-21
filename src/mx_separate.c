#include "ush.h"

static int sx_fragment_lenght(char **str, int len);

t_parse *mx_separate(char *str) {
    char *ptr = NULL;
    t_parse *final = NULL;
    int len = 0;

    if (str) {
        if (mx_correct_delimeter(str)) {
            ptr = str;
            while (*ptr && len >= 0) {
                len = sx_fragment_lenght(&ptr, len);
                if (len > 0)
                    mx_push_parse_back(&final, mx_strndup(ptr, len));
                if (len == 0 && *ptr == ';')
                    ptr++;
            }
        }
    }
    return final;
}

static int sx_fragment_lenght(char **str, int len) {
    char *ptr = *str;
    int counter = 0;
    int delim = 0;
    int sw_quote = 0; // = 1 для ' или = 2 для "

    if (*ptr == '\0' || ptr == NULL)
        return -1;
    ptr += len;
    *str = ptr;
    while (*ptr) {
        if (*ptr == 92 && sw_quote != 1) {
            counter += 2;
            ptr += 2;
            continue;
        }
        mx_quotes(&sw_quote, *ptr);
        if (mx_delim(ptr) > 0 && sw_quote == 0) {
            if (delim == 0 && len != 0) {
                delim = 1;
                counter += mx_delim(ptr);
                ptr += mx_delim(ptr);
                continue;
            }
            else
                break;
        }
        counter++;
        ptr++;
    }
    return counter;
}
