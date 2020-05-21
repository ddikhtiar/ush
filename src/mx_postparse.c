#include "ush.h"

void mx_postparse(t_bin *strct) {
    mx_del_backslash(strct);
    mx_del_quotes(strct);
    // mx_range(strct);
}
