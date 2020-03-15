#include "ush.h"

void mx_push_army_back(t_bin **nest, t_bin *chick) {
    t_bin *ptr = *nest;

    if (chick) {
        if (!ptr)
            *nest = chick;
        else {
            while (ptr->next_c)
                ptr = ptr ->next_c;
            ptr->next_c = chick;
        }
    }
}
