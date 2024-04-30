# 2024.04.16 7주차 실습 내용 정리
```
#include <stdio.h>

 int main(void){
     printf("Hello, C World!!!");

     return 0;
 }
```
<b>test.c</b><br>

<h3><b>파일 열기 예제</b></h3>
<img src="https://github.com/tealight03/2024SysP/assets/138011998/2a056a57-fd71-4534-a88d-922a581e560a" width="350"><br>

```
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd;
    if ((fd = open(argv[1], O_RDWR)) == -1)
        printf("파일 열기 오류\n");
    else
        printf("파일 %s 열기 성공 : %d\n", argv[1], fd);
    close(fd);
    exit(0);
}
```
<b>fopen.c</b><br>

<h3><b>파일 크기 계산 예제</b></h3>
<img src="https://github.com/tealight03/2024SysP/assets/138011998/a40eec83-a616-4671-9652-4da3f1570ce6" width="350"><br>

```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFSIZE 512

/* 파일 크기를 계산 한다 */
int main(int argc, char *argv[])
{
    char buffer[BUFSIZE];
    int fd;
    ssize_t nread;
    long total = 0;
    if ((fd = open(argv[1], O_RDONLY)) == -1)
        perror(argv[1]);
    /* 파일의 끝에 도달할 때까지 반복해서 읽으면서 파일 크기 계산 */
    while ((nread = read(fd, buffer, BUFSIZE)) > 0)
        total += nread;
    close(fd);
    printf("%s 파일 크기 : %ld 바이트 \n", argv[1], total);
    exit(0);
}
```
<b>fsize.c</b><br>

<h3><b>파일 복사 예제</b></h3>
<img src="https://github.com/tealight03/2024SysP/assets/138011998/892b5454-470e-48e7-b49c-6c656095f951" width="350"><br>

```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/* 파일 복사 프로그램 */
main(int argc, char *argv[])
{
    int fd1, fd2, n;
    char buf[BUFSIZ];
    if (argc != 3)
    {
        fprintf(stderr, "사용법: %s file1 file2\n",
                argv[0]);
        exit(1);
    }
    if ((fd1 = open(argv[1], O_RDONLY)) == -1)
    {
        perror(argv[1]);
        exit(2);
    }
    if ((fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
    {
        perror(argv[2]);
        exit(3);
    }
    while ((n = read(fd1, buf, BUFSIZ)) > 0)
        write(fd2, buf, n); // 읽은 내용을 쓴다.
    exit(0);
}
```
<b>copy.c</b><br>

<h3><b>파일 복제 예</b></h3>

<img src="https://github.com/tealight03/2024SysP/assets/138011998/b66cd975-1c84-4efb-b399-829aa4f45b0a" width="350"><br>

```
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int fd1, fd2;
    if ((fd1 = creat("myfile", 0600)) == -1)
        perror("myfile");
    write(fd1, "Hello! Linux", 12);
    fd2 = dup(fd1);
    write(fd2, "Bye! Linux", 10);
    exit(0);
}
```
<b>dup.c</b><br>

<h3><b>student 구조체 생성 및 활용 예제</b></h3>
<ul>
  <li>학생 정보 입력받아 DB에 저장(dbcreate.c)</li>
  <li>학번 입력받아 해당 학생의 레코드를 파일에서 읽어 출력하는 쿼리 처리(dbquery.c)</li>
  <li>학번을 입력받아 해당 학생의 레코드 수정(dbupdate.c)</li>
</ul>

```
#define MAX 24
#define START_ID 1401001

struct student
{
    char name[MAX];
    int id;
    int score;
};
```
<b>student.h</b><br>

```
#include <stdio.h>
#include <stdlib.h>
// #include <unistd.h>
#include <fcntl.h>
#include "student.h"
/* 학생 정보를 입력받아 데이터베이스 파일에 저장한다. */
int main(int argc, char *argv[]){
    int fd;
    struct student record;
    if (argc < 2){
        fprintf(stderr, "사용법 : %s file\n", argv[0]);
        exit(1);
    }
    if ((fd = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, 0640)) == -1){
        perror(argv[1]);
        exit(2);
    }
    printf("%-9s %-8s %-4s\n", "학번", "이름", "점수");
    while (scanf("%d %s %d", &record.id, record.name, &record.score) == 3){
        lseek(fd, (record.id - START_ID) * sizeof(record), SEEK_SET);
        write(fd, (char *)&record, sizeof(record));
    }
    close(fd);
    exit(0);
}
```
<b>dbcreate.c</b><br>

```
#include <stdio.h>
#include <stdlib.h>
// #include <unistd.h>
#include <fcntl.h>
#include "student.h"
/* 학번을 입력받아 해당 학생의 레코드를 파일에서 읽어 출력한다. */
int main(int argc, char *argv[]){
    int fd, id;
    char c;
    struct student record;
    if (argc < 2){
        fprintf(stderr, "사용법 : %s file\n", argv[0]);
        exit(1);
    }
    if ((fd = open(argv[1], O_RDONLY)) == -1){
        perror(argv[1]);
        exit(2);
    }
    do {
        printf("\n검색할 학생의 학번 입력:");
        if (scanf("%d", &id) == 1){
            lseek(fd, (id - START_ID) * sizeof(record), SEEK_SET);
            if ((read(fd, (char *)&record, sizeof(record)) > 0) && (record.id != 0))
                printf("이름:%s\t 학번:%d\t 점수:%d\n", record.name, record.id, record.score);
            else
                printf("레코드 %d 없음\n", id);
        }
        else
            printf("입력 오류");
        printf("계속하겠습니까?(Y/N)");
        scanf(" %c", &c);
    } while (c == 'Y');
    close(fd);
    exit(0);
}
```
<b>dbquery.c</b><br>

```
#include <stdio.h>
#include <stdlib.h>
// #include <unistd.h>
#include <fcntl.h>
#include "student.h"
/* 학번을 입력받아 해당 학생 레코드를 수정한다. */
int main(int argc, char *argv[]){
    int fd, id;
    char c;
    struct student record;
    if (argc < 2){
        fprintf(stderr, "사용법 : %s file\n", argv[0]);
        exit(1);
    }
    if ((fd = open(argv[1], O_RDWR)) == -1){
        perror(argv[1]);
        exit(2);
    }
    do{
        printf("수정할 학생의 학번 입력: ");
        if (scanf("%d", &id) == 1){
            lseek(fd, (long)(id - START_ID) * sizeof(record), SEEK_SET);
            if ((read(fd, (char *)&record, sizeof(record)) > 0) && (record.id != 0)){
                printf("학번:%8d\t 이름:%4s\t 점수:%4d\n", record.id, record.name, record.score);
                printf("새로운 점수: ");
                scanf("%d", &record.score);
                lseek(fd, (long)-sizeof(record), SEEK_CUR);
                write(fd, (char *)&record, sizeof(record));
            }
            else
                printf("레코드 %d 없음\n", id);
        }
        else
            printf("입력오류\n");
        printf("계속하겠습니까?(Y/N)");
        scanf(" %c", &c);
    } while (c == 'Y');
    
    close(fd);
    exit(0);
}
```
<b>dbupdate.c</b><br>
