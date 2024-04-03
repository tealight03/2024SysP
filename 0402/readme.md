# 2024.04.02 강의 주요 내용 정리(5주차)
<b>시스템 호출(system call)</b><br>
<p>
  시스템 호출(system call)이란 운영체제의 커널이 제공하는 서비스에 대해<br>
  응용 프로그램의 요청에 따라 커널에 접근하기 위한 인터페이스를 말한다.<br>
  흔히 시스템 콜, 시스템 호출이라고 칭한다.<br><br>
  커널(kernel)이란 영어로 "알맹이", "핵심" 이라는 의미이다.<br>
  단어의 의미로 커널의 역할을 정의하자면<br>
  <b>운영체제의 핵심으로써 하드웨어와 응용 프로그램을 이어주는 인터페이스를 제공하고</b><br>
  <b>CPU, 메모리 등의 컴퓨터 리소스를 관리하는 역할을 하는 것이다.</b><br><br>
  우리가 일반적으로 사용하는 프로그램들은 "응용 프로그램"이기에<br>
  유저레벨의 함수들만으로는 다양한 기능을 구현하기가 어렵기 때문에<br>
  커널의 도움을 받아 기능을 구현해야한다.<br>
  이때, 커널에 접근하기 위해 유저모드에서 커널모드로 전환해야하기 때문에<br>
  이를 위해 <b>시스템 콜</b>을 수행해야한다.<br><br>
  <img src="https://github.com/tealight03/2024SysP/assets/138011998/0fd3d514-dc0a-4ec3-92e5-bbdd4d548c09"  width="450">
</p>
<b>[참고 자료]</b><br>
<a href="https://fjvbn2003.tistory.com/306">[운영체제] 시스템 콜 (System Call)</a><br>
<a href="https://hotpeng.tistory.com/78">[용어 정리] 운영체제(OS)와 커널(Kernel)</a><br>
<a href="https://minkwon4.tistory.com/295">[OS] 커널(Kernel)이란</a><br><br>

<b>printf()의 프로토타입</b>
<p>
  printf() 함수는 원래 int형 return value를 반환하는 함수이다.<br>
  그렇지만 우리는 printf()의 return value를 굳이 사용할 필요가 없었기 때문에<br>
  그동안 잘 사용해오지 않았을 뿐 프로토타입은 이러하다는 것을 알고 있어야한다.<br>
  참고로 printf()는 자신이 출력한 char의 개수를 카운트하여 반환한다.<br><br>
  <img src="https://github.com/tealight03/2024SysP/assets/138011998/b4880ec9-4f87-4b84-8dae-cc9b553fdaf2" width="500">
</p>
<b>[참고 자료]</b><br>
<a href="https://stackoverflow.com/questions/20402382/prototype-of-printf-and-implementation">Prototype of printf and implementation-Stackoverflow</a><br>
<a href="https://blog.naver.com/PostView.nhn?blogId=sinmukain&logNo=80101935741">printf() 함수 원형</a><br><br>

<b>실습</b><br>
파일 open 예제를 하나 작성한다.<br><br>

```
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
    int fd;
    if ((fd = open(argv[1], O_RDWR)) == -1)
        printf("파일 열기 오류\n");
    else printf("파일 %s 열기 성공 : %d\n", argv[1], fd);
    close(fd);
    exit(0);
}
```
    
<img src="https://github.com/tealight03/2024SysP/assets/138011998/245ba784-ad73-415d-9297-ad28d180d7fb" width="700"><br>
실행 결과, 안전성 문제로 인해 warning이 마구 뜨는 것을 확인할 수 있다.<br>
warning이 발생하지 않도록 하기 위해 코드를 일부 수정해주자.<br><br>

```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    int fd;
    if ((fd = open(argv[1], O_RDWR)) == -1)
        printf("파일 열기 오류\n");
    else printf("파일 %s 열기 성공 : %d\n", argv[1], fd);
    close(fd);
    exit(0);
}
```

<img src="https://github.com/tealight03/2024SysP/assets/138011998/f873c3bd-0aa9-45b1-868f-4545028c7826" width="600"><br>
그러면 warning 없이 안정적으로 파일이 생성되는 것을 확인할 수 있다.<br>

<b>[참고사항]</b><br>
<b>return</b> : 자기 자신을 호출한 곳으로 돌아간다.<br>
<b>exit</b> : 실행 중인 프로그램 자체를 종료한다.
