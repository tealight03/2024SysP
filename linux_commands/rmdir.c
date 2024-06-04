#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int opt;
    int seccess_message = 0;

    while ((opt = getopt(argc, argv, "v")) != -1) {
        switch (opt) {
            case 'v':
                seccess_message = 1;
                break;
            default :
                fprintf(stderr, "사용법 : rmdir [옵션] [파일]\n");
                return 1;
        }
    }

    if (optind >= argc) {
        printf("사용법: %s [디렉토리 경로]\n", argv[0]);
        return 1;
    }

    for (int i = optind; i < argc; i++) {
        char *dirPath = argv[i];

        int result = rmdir(dirPath);
        if (result == 0) {
            if(seccess_message){
                printf("rmdir: removing directory, '%s'\n", argv[i]);
            }
        } else {
            printf("디렉토리 삭제에 실패했습니다.\n");
            return 1;
        }

        return 0;
    }
}