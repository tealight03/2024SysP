#include <stdio.h>
#include <unistd.h>

int main() {
    char cwd[4096];

    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd);
    } else {
        printf("현재 작업 디렉토리 경로를 얻을 수 없습니다.\n");
        return 1;
    }

    return 0;
}