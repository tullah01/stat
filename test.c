#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <math.h>

// Sorry this is late, I'm sick and I've had a lot of college apps to deal with...

int main() {
    printf("stats of test.c, this C file.\n\n");
    struct stat *a = malloc(sizeof(struct stat));
    stat("test.c", a);
    printf("size: %d B\n", a->st_size);
    int permissions = a->st_mode - 0100000;
    char perms[] = "----------";
    int i;
    int t = 0;
    double exp;
    for (exp = 2; exp >= 0; exp--) {
        i = permissions / pow(8, exp);
        if (i - 4 >= 0) {
            i -= 4;
            perms[1+t] = 'r';
        }
        if (i - 2 >= 0) {
            i -= 2;
            perms[2+t] = 'w';
        }
        if (i - 1 >= 0) perms[3+t] = 'x';
        t+=3;
        permissions %= (int) pow(8, exp);
    }
    
    i = permissions / 64;
    if (i - 4 >= 0) {
        i -= 4;
        perms[1] = 'r';
    }
    if (i - 2 >= 0) {
        i -= 2;
        perms[2] = 'w';
    }
    if (i - 1 >= 0) perms[3] = 'x';
    
    printf("permissions: %s\n", perms);
    printf("%s", ctime(&a->st_atime));
 }
