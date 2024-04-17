#include <stdio.h>
#include <string.h>  // strlen 함수를 사용하기 위한 헤더 파일 인클루드

int main(void) {
    char str[] = "Hello, World!";  // 문자열을 저장하는 배열 선언
    int length;  // 문자열의 길이를 저장할 변수

    // strlen 함수를 사용하여 문자열의 길이를 계산
    length = strlen(str);

    // 결과 출력
    printf("문자열의 길이: %d\n", length);

    return 0;
}
