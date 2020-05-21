#include "ush.h"

static bool sx_username(char **str);

char *mx_tilda(char *str) {
    char *ptr = NULL;
    char *home = NULL;

    if (!str)
        return NULL;
    ptr = str + 1;
    if (sx_username(&ptr) || *ptr == ' ' || *ptr == '/' || *ptr == '\0') {
        home = getenv("HOME");
        return mx_strjoin(home, ptr);
    }
    else if (*ptr == '+' || *ptr == '-') {
        if (*(ptr + 1) == '/' || *(ptr + 1) == '\0') {
            home = getenv("PWD");
            return mx_strjoin(home, ptr + 1);
        }
        else if (*ptr == '+')
            return mx_strdup(str);
    }
    return NULL;
}

static bool sx_username(char **str) {
    char *username = getenv("USER");
    char *ptr = *str;
    int userlen = mx_strlen(username);

    if (mx_strncmp(ptr, username, userlen) == 0) {
        ptr += userlen;
        if (*ptr == '/' || *ptr == ' ' || *ptr == '\0') {
            *str = ptr;
            return true;
        }
    }
    return false;
}
