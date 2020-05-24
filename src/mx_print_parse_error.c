#include "ush.h"

void mx_print_parse_error(const char *str) {
    mx_printerr("u$h: parse error near `");
    mx_printerr(str);
    mx_printerr("'\n");
}
