#include <fcntl.h>   // open 시스템 콜을 사용하기 위한 헤더 파일

int main(void) {
    int fd;  // 파일 디스크립터 변수
    fd = open("filename.txt", O_RDONLY);  
    // open 시스템 콜을 호출하여 파일을 읽기 전용으로 open
    // 이후 파일을 읽거나 다른 작업을 수행할 수 있음
    close(fd);  // 파일 디스크립터를 닫음

    return 0;
}

