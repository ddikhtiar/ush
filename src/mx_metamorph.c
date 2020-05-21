#include "ush.h"

t_bin *mx_metamorph(t_parse *puzzle) {
    t_bin *army = NULL;

    if (puzzle) {
        mx_replacement(&(puzzle->frgmnt));
        if (puzzle->frgmnt != NULL)
            army = mx_parse_to_bin(&(puzzle->frgmnt));
    }
    return army;
}
