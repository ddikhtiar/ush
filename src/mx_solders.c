#include "ush.h"

static int sx_number_of_solders(const char *str);

char **mx_solders(const char *str) {
    char *ptr = (char *) str;
    char **solders = NULL;
    int num = sx_number_of_solders(str);
    int current = 0;

    if (num > 0) {
        solders = (char **) malloc(sizeof(char *) * (num + 1));
        for (int i = 0; i < num; i++) {
            mx_shift_spaces(&ptr);
            current = mx_substr_lenght(ptr);
            solders[i] = mx_strndup(ptr, current);
            ptr = ptr + current;
        }
        solders[num] = NULL;
    }
    return solders;
}

static int sx_number_of_solders(const char *str) {
    int num = 0;
    int sw_space = 1;
    int sw_quote = 0; // = 1 для ' или = 2 для "

    if (str) {
        for (; *str != '\0'; str++) {
            if (mx_quotes(&sw_quote, *str))
                continue;
            if (mx_isspace(*str) && sw_quote == 0) {
                if (sw_space == 1)
                    continue;
                else
                    sw_space = 1;
            }
            else if (*str == 92)
                str++;
            else if (sw_space == 1) {
                num++;
                sw_space = 0;
            }
        }
    }
    return num;
}
