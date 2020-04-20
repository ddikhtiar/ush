#include "ush.h"

// void mx_del_parse_list(t_parse **sep_list) {
//     t_parse *ptr_del = *sep_list;
//     t_parse *ptr_next = NULL;

//     if (ptr_del == NULL)
//         return;
//     else if (ptr_del->next_f == NULL) {
//         mx_strdel(&(ptr_del->frgmnt));
//         free(ptr_del);
//         *sep_list = NULL;
//     }
//     else {
//         ptr_next = ptr_del->next_f;
//         ptr_del->next_f = NULL;
//         mx_strdel(&(ptr_del->frgmnt));
//         free(ptr_del);
//         ptr_del = NULL;
//         mx_del_parse_list(&ptr_next);
//     }
// }

void mx_del_parse_list(t_parse **sep_list) {
    t_parse *ptr = *sep_list;
    t_parse *del = NULL;

    if (ptr) {
        while (ptr) {
            del = ptr;
            ptr = ptr->next_f;
            del->next_f = NULL;
            mx_strdel(&(del->frgmnt));
            free(del);
        }
        *sep_list = NULL;
    }
}
