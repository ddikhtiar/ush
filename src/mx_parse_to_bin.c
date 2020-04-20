#include "ush.h"

t_bin *mx_parse_to_bin(char **str) {
    t_bin *node = (t_bin *)malloc(sizeof(t_bin));

    if (node && str) {
        node->status = mx_status(str);
        node->commandor = mx_commandor(str);
        node->solders = mx_solders(*str);
        node->next_c = NULL;
    }
    if (node->commandor == NULL)
        node->status = 0;
    return node;
}
