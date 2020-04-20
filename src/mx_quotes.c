#include "ush.h"

bool mx_quotes(int *q, char c) {
    if (c == 34) {
        if (*q == 0)
            *q = 2;
        else if (*q == 2)
            *q = 0;
        return true;
    }
    if (c == 39) {
        if (*q == 0)
            *q = 1;
        else if (*q == 1)
            *q = 0;
        return true;
    }
    return false;
}

// void mx_quotes(int *q, char c) {
//     int sw_quote = *q;

//     if (c == 34) {
//         if (sw_quote == 0)
//             sw_quote = 2;
//         else if (sw_quote == 2)
//             sw_quote = 0;
//     }
//     if (c == 39) {
//         if (sw_quote == 0)
//             sw_quote = 1;
//         else if (sw_quote == 1)
//             sw_quote = 0;
//     }
//     *q = sw_quote;
// }
