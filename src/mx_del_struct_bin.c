#include "ush.h"

void mx_del_struct_bin(t_bin **army) {
    t_bin *ptr = *army;

    if (ptr) {
    mx_strdel(&(ptr->commandor));
    mx_del_strarr(&(ptr->solders));
    free(ptr);
    *army = NULL;
    }
}
