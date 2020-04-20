#include "ush.h"

void mx_push_parse_back(t_parse **sep_list, const char *str) {
    t_parse *ptr = *sep_list;
    t_parse *new = (t_parse *) malloc(sizeof(t_parse));

    if (str && new) {
        new->frgmnt = (char *) str;
        new->next_f = NULL;
        if (*sep_list == NULL)
            *sep_list = new;
        else {
            while (ptr->next_f != NULL)
                ptr = ptr->next_f;
            ptr->next_f = new;
        }
    }
}
