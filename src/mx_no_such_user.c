#include "ush.h"

void mx_no_such_user(char *str) {
    int len = 0;
    char *ptr = str;
    char *user = NULL;

    while (*ptr && *ptr != ' ' && *ptr != '/') {
        len++;
        ptr++;
    }
    if (len > 0) {
        user = mx_strndup(str, len);
        mx_printerr("u$h: no such user or named directory: ");
        mx_printerr(user);
        mx_printerr("\n");
        mx_strdel(&user);
    }
}
