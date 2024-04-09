#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    // 파일 열기
    int fd = open("example.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("파일 열기 실패");
        exit(EXIT_FAILURE);
    }

    // 파일에 데이터 쓰기
    const char *data = "Hello, World!";
    ssize_t bytes_written = write(fd, data, strlen(data));
    if (bytes_written == -1) {
        perror("파일 쓰기 실패");
        exit(EXIT_FAILURE);
    }
    printf("파일에 쓴 데이터 크기: %zd\n", bytes_written); // %zd는 ssize_t를 출력하기 위한 서식 지정자

    // 파일 닫기
    close(fd);

    // 파일 다시 열기
    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("파일 열기 실패");
        exit(EXIT_FAILURE);
    }

    // 파일에서 데이터 읽기
    char buffer[20]; // 충분한 크기로 버퍼를 할당해야 합니다.
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("파일 읽기 실패");
        exit(EXIT_FAILURE);
    }
    printf("파일에서 읽은 데이터: %.*s\n", (int)bytes_read, buffer); // %.*s는 길이가 지정된 문자열 출력

    // 파일 닫기
    close(fd);

    return 0;
}