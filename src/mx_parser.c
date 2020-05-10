#include "ush.h"

t_bin *mx_parser(const char *str) {
    char *dup = mx_strdup(str);
    t_bin *result = NULL;
    t_parse *separate = NULL;

    mx_replacement(&dup);
    separate = mx_separate(dup);
    mx_metamorph(&result, separate);
    mx_del_parse_list(&separate);
    mx_strdel(&dup);
    return result;
}
