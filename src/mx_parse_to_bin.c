#include "ush.h"

t_bin *mx_parse_to_bin(const char *str) {
    char *ptr = (char *)str;
    t_bin *node = (t_bin *)malloc(sizeof(t_bin));

    if (node) {
        node->status = mx_status(&ptr);
        node->commandor = mx_commandor(&ptr);
        node->solders = mx_solders(ptr);
        node->next_c = NULL;
    }
    return node;
}
