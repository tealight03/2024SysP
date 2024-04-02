# 2024.03.26 강의 실습 정리(4주차)

```
#include <stdio.h>
#include <string.h>
#define MAXLINE 100

void copy(char from[], char to[]);

char line[MAXLINE];
char longest[MAXLINE];

int main(){
        int len;
        int max;
        max = 0;
        while (gets(line) != NULL){
                len = strlen(line);
                if (len > max){
                        max = len;
                        copy(line, longest);
                }
        }
        if (max > 0)
                printf("%s", longest);

        return 0;
}
```
<b>long.c</b><hr>

```
#include <stdio.h>
#include <string.h>
#include "copy.h"

char line[MAXLINE]; // 입력 줄
char longest[MAXLINE]; // 가장 긴 줄
/* 입력 줄 가운데 가장 긴 줄 프린트 */

int main(void){
        int len;
        int max;
        max = 0;
        while (gets(line) != NULL) {
                len = strlen(line);
                if (len > max){
                        max = len;
                        copy(line, longest);
                }
        }
        if (max > 0) // 입력 줄이 있었다면
                printf("%s", longest);

        return 0;
}
```
<b>main.c</b><br>

```
#include <stdio.h>
#include "copy.h"

/* copy: from을 to에 복사; to가 충분히 크다고 가정 */

void copy(char from[], char to[]){
        int i;
        i = 0;
        while ((to[i] = from[i]) != '\0')
                ++i;
}
```
<b>copy.c</b><br>

```
#define MAXLINE 100
void copy(char from[], char to[]);
```

<b>copy.h</b><br><br>

<b>[실행 결과]</b><br>
<img width="216" alt="image" src="https://github.com/tealight03/2024SysP/assets/138011998/7706020a-3c31-494f-9fbf-cd0024e0bd5a"><br>
