int checkSubstring(int sh[256], int th[256]) {
    char c;
    for (char c = 'A'; c <= 'Z'; ++c)
        if (sh[c] < th[c]) return 0;
    for (char c = 'a'; c <= 'z'; ++c)
        if (sh[c] < th[c]) return 0;
    return 1;
}

char* minWindow(char* s, char* t) {
    int sh[256] = { 0 };
    int th[256] = { 0 };
    char* a, * b, * c;
    int minlen, x;
    for (char* a = t; *a; th[*(a++)]++);
    a = b = s;
    c = NULL;
    minlen = 1000000;
    ++sh[*a];
    while (*b) {
        if ((x = checkSubstring(sh, th)) && (b - a) + 1 < minlen) {
            c = a;
            minlen = (b - a) + 1;
        }
        if (!x || a == b) ++sh[*(++b)];
        else --sh[*(a++)];
    }
    if (!c) c = b;
    else c[minlen] = '\0';
    return c;
}