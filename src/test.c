#include "ush.h"

void sx_print_result(t_bin *ptr);

int main (int argc, char **argv) {
    t_parse *fragment = NULL;
    t_parse *ptr = NULL;
    t_bin *result = NULL;
    char *copy = NULL;

    if (argc > 1) {
        copy = mx_strdup(argv[1]);
        fragment = mx_separate(copy);
        ptr = fragment;
        while (ptr) {
            result = mx_metamorph(ptr);
            if (!result)
                break;
            mx_postparse(result);
            sx_print_result(result);
            mx_del_struct_bin(&result);
            ptr = ptr->next_f;
        }
        mx_del_parse_list(&fragment);
        mx_strdel(&copy);
    }
    // system ("leaks parser");
    exit(0);
}

void sx_print_result(t_bin *ptr) {
    char **str_arr = NULL;

    if (ptr != NULL) {
        printf("-=***************=-\n");
        printf("PROCESS:   %s\n", ptr->commandor);
        printf("STATUS:    %d\n", ptr->status);
        str_arr = ptr->solders;
        printf("ARGUMENTS: ");
        if (!str_arr)
            printf("(null)\n");
        else {
            while (*str_arr) {
                printf("%s\n", *str_arr);
                str_arr++;
                if (*str_arr)
                    printf("           ");
            }
        }
        printf("-=***************=-\n\n");
    }
}
