#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("사용법: %s [퍼미션] [파일 경로]\n", argv[0]);
        return 1;
    }

    char *permissionString = argv[1];
    char *filePath = argv[2];

    int permission = strtol(permissionString, NULL, 8);

    if (chmod(filePath, permission) == -1) {
        return 1;
    }

    return 0;
}