int mx_strlen(const char *s) {
    int result = 0;

    if (s) {
        while (*s) {
            result++;
            s++;
        }
    }
    return result;
}
