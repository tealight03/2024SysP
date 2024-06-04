#include <stdio.h>

void printNumberedLines(FILE *file) {
    char line[BUFSIZ];
    int lineNumber = 1;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (line[0] == '\n') {
            printf("\n");
        } else {
            printf("%6d  %s", lineNumber, line);
            lineNumber++;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("사용법: %s [파일 경로]\n", argv[0]);
        return 1;
    }

    char *filePath = argv[1];

    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    printNumberedLines(file);

    fclose(file);

    return 0;
}