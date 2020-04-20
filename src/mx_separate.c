#include "ush.h"

static int sx_fragment_lenght(char **str, int len);
static bool sx_delim(const char *str);

t_parse *mx_separate(const char *str) {
    char *ptr = (char *) str;
    t_parse *final = NULL;
    int len = 0;

    while (*ptr) {
        len = sx_fragment_lenght(&ptr, len);
        if (len > 0)
            mx_push_parse_back(&final, mx_strndup(ptr, len));
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
        mx_quotes(&sw_quote, *ptr);
        if (sx_delim(ptr) && sw_quote == 0) {
            if (delim == 0 && len != 0)
                delim = 1;
            else
                break;
        }
        counter++;
        ptr++;
    }
    return counter;
}

static bool sx_delim(const char *str) {
    if (*str == ';')
        return true;
    else if (mx_strncmp(str, "&&", 2) == 0)
        return true;
    else if (mx_strncmp(str, "||", 2) == 0)
        return true;
    else
        return false;
}
