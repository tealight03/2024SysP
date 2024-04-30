# 2024.04.30 9주차 실습 내용 정리
<h3><b>파일 타입 검사 예제</b></h3>

```
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* 파일 타입을 검사한다. */
int main(int argc, char *argv[])
{
    int i;
    struct stat buf;
    for (i = 1; i < argc; i++)
    {
        printf("%s: ", argv[i]);
        if (lstat(argv[i], &buf) < 0)
        {
            perror("lstat()");
            continue;
        }
        if (S_ISREG(buf.st_mode))
            printf("%s \n", "일반 파일");
        if (S_ISDIR(buf.st_mode))
            printf("%s \n", "디렉터리");
        if (S_ISCHR(buf.st_mode))
            printf("%s \n", "문자 장치 파일");
        if (S_ISBLK(buf.st_mode))
            printf("%s \n", "블록 장치 파일");
        if (S_ISFIFO(buf.st_mode))
            printf("%s \n", "FIFO 파일");
        if (S_ISLNK(buf.st_mode))
            printf("%s \n", "심볼릭 링크");
        if (S_ISSOCK(buf.st_mode))
            printf("%s \n", "소켓");
    }
    exit(0);
}
```
<b>ftype.c</b><br>

<h3><b>파일 사용권한 변경 예제</b></h3>

```
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

/* 파일 사용권한을 변경한다. */
main(int argc, char *argv[])
{
    long strtol();
    int newmode;
    newmode = (int)strtol(argv[1], (char **)NULL, 8);
    if (chmod(argv[2], newmode) == -1)
    {
        perror(argv[2]);
        exit(1);
    }
    exit(0);
}
```
<b>fchmod.c</b><br>

<h3><b>파일 접근/수정 시간 복사 예제</b></h3>

```
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <utime.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    struct stat buf; // 파일 상태 저장을 위한 변수
    struct utimbuf time;
    if (argc < 3)
    {
        fprintf(stderr, "사용법: cptime file1 file2\n");
        exit(1);
    }
    if (stat(argv[1], &buf) < 0)
    { // 상태 가져오기
        perror("stat()");
        exit(-1);
    }
    time.actime = buf.st_atime;
    time.modtime = buf.st_mtime;
    if (utime(argv[2], &time)) // 접근, 수정 시간 복사
        perror("utime");
    else
        exit(0);
}
```
<b>cptime.c</b><br>

<h3><b>디렉토리 내의 파일 이름을 리스트하는 예제</b></h3>

```
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

/* 디렉터리 내의 파일 이름들을 리스트한다. */
int main(int argc, char **argv){
    DIR *dp;
    char *dir;
    struct dirent *d;
    struct stat st;
    char path[BUFSIZ+1];
    if (argc == 1)
        dir = "."; // 현재 디렉터리를 대상으로
    else dir = argv[1];

    if ((dp = opendir(dir)) == NULL) // 디렉터리 열기
        perror(dir);

    while ((d = readdir(dp)) != NULL) // 각 디렉터리 엔트리에 대해
        printf("%s \n", d->d_name); // 파일 이름 프린트

    closedir(dp);
    exit(0);
}
```
<b>list1.c</b><br>

<h3><b>디렉토리 내용을 자세히 리스트하는 예제</b></h3>

```
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>

char type(mode_t);
char *perm(mode_t);
void printStat(char*, char*, struct stat*);

/* 디렉터리 내용을 자세히 리스트한다. */
int main(int argc, char **argv){
    DIR *dp;
    char *dir;
    struct stat st;
    struct dirent *d;
    char path[BUFSIZ+1];
    if (argc == 1)
        dir = ".";
    else dir = argv[1];

    if ((dp = opendir(dir)) == NULL) // 디렉터리 열기
        perror(dir);

    while ((d = readdir(dp)) != NULL) { // 디렉터리의 각 파일에 대해
        sprintf(path, "%s/%s", dir, d->d_name); // 파일경로명 만들기
        if (lstat(path, &st) < 0) // 파일 상태 정보 가져오기
            perror(path);
        printStat(path, d->d_name, &st); // 상태 정보 출력
    putchar('\n');
    }

    closedir(dp);
    exit(0);
}

/* 파일 상태 정보를 출력 */
void printStat(char *pathname, char *file, struct stat *st) {
    printf("%5d ", st->st_blocks);
    printf("%c%s ", type(st->st_mode), perm(st->st_mode));
    printf("%3d ", st->st_nlink);
    printf("%s %s ", getpwuid(st->st_uid)->pw_name,
    getgrgid(st->st_gid)->gr_name);
    printf("%9d ", st->st_size);
    printf("%.12s ", ctime(&st->st_mtime)+4);
    printf("%s", file);
}

/* 파일 타입을 리턴 */
char type(mode_t mode) {
    if (S_ISREG(mode))
        return('-');
    if (S_ISDIR(mode))
        return('d');
    if (S_ISCHR(mode))
        return('c');
    if (S_ISBLK(mode))
        return('b');
    if (S_ISLNK(mode))
        return('l');
    if (S_ISFIFO(mode))
        return('p');
    if (S_ISSOCK(mode))
        return('s');
}

/* 파일 사용권한을 리턴 */
char* perm(mode_t mode) {
    int i;
    static char perms[10] = "---------";

    for (i=0; i < 3; i++) {
        if (mode & (S_IREAD >> i*3))
            perms[i*3] = 'r';
        if (mode & (S_IWRITE >> i*3))
            perms[i*3+1] = 'w';
        if (mode & (S_IEXEC >> i*3))
            perms[i*3+2] = 'x';
    }
    return(perms);
}
```
<b>list2.c</b><br>

<h3><b>링크를 생성하는 예제</b></h3>

```
#include <unistd.h>

int main(int argc, char *argv[]){
    if (link(argv[1], argv[2]) == -1){
        exit(1);
    }
    
    exit(0);
}
```
<b>link.c</b><br>

<h3><b>링크를 해제하는 예제</b></h3>

```
#include <unistd.h>

main(int argc, char *argv[]){
    int unlink();
    if (unlink(argv[1]) == -1 {
        perror(argv[1]);
        exit(1);
    }

    exit(0);
}
```
<b>unlink.c</b><br>

<h3><b>링크 확인 예제</b></h3>

```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    char buffer[1024];
    int nread;
    nread = readlink(argv[1], buffer, 1024);

    if (nread > 0){
        write(1, buffer, nread);
        exit(0);
    }
    else {
        fprintf(stderr, "오류 : 해당 링크 없음\n");
        exit(1);
    }
}
```
<b>rlink.c</b><br>
