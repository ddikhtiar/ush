#include "ush.h"

t_bin *mx_parser(const char *str) {
    t_bin *result = NULL;
    t_parse *separate = NULL;

    // mx_replacement(&str);
    separate = mx_separate(str);
    mx_metamorph(&result, separate);
    mx_del_parse_list(&separate);
    return result;
}
