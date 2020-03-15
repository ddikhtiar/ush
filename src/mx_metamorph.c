#include "ush.h"

void mx_metamorph(t_bin **army, t_parse *puzzle) {
    t_bin *current = NULL;

    if (puzzle) {
        while (puzzle) {
            current = mx_parse_to_bin(puzzle->frgmnt);
            mx_push_army_back(army, current);
            puzzle = puzzle->next_f;
        }
    }
}
