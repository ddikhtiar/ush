#include "ush.h"

static void sx_print_parse(t_bin *ptr);

int main(int argc, char **argv) {
    t_bin *par = NULL;

    if (argc > 1) {
        par = mx_parser(argv[1]);
        printf("\nInput string: %s\nXXXXXXXXXXXX\n", argv[1]);
        sx_print_parse(par);
    }
    // system ("leaks parser");
    exit(0);
}

static void sx_print_parse(t_bin *ptr) {
    char **arr = NULL;

    while (ptr) {
        printf("Process:   %s\n", ptr->commandor);
        printf("Status:    %d\n", ptr->status);
        printf("Arguments: ");
        if (ptr->solders == NULL)
            printf("NULL\n------------\n");
        else {
            arr = ptr->solders;
            while (*arr != NULL) {
                printf("%s\n", *arr);
                arr++;
                if (*arr != NULL)
                    printf("           ");
                else
                    printf("------------\n");
            }
        }
        ptr = ptr->next_c;
    }
}
