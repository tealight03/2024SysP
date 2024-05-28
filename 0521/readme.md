# 2024.05.21 12주차 강의 내용 정리
<h3><b>텍스트 파일 vs 바이너리 파일</b></h3>
텍스트 파일은 사람이 읽을 수 있는 문자로 구성된 파일이며, 주로 ASCII 또는 유니코드 형식으로 저장된다.<br>
이진 파일은 사람이 읽을 수 없는 형식으로 데이터를 저장하며, 이미지, 비디오, 오디오 등 다양한 유형의 데이터를 포함할 수 있다.<br>
텍스트 파일과 이진 파일은 open함수로 파일을 open할 때 부여하는 옵션 값이 조금 다르다.<br>
텍스트 파일은 'r', 이진 파일은 'rb' 옵션을 주는데, <br>
이는 이진 파일에 대해 특수하게 읽어오라는 read-binary의 의미로 부여하는 옵션 값이 조금 다르다.<br><br>

<b>[참고]</b><br>
<a href="[파이썬] 텍스트 파일과 이진 파일의 차이 (colinch4.github.io)">[파이썬] 텍스트 파일과 이진 파일의 차이</a><br>
<a href="파일 종류 - 텍스트 파일 (Text File), 이진 파일 (바이너리 파일; Binary File) (tistory.com)">
파일 종류 - 텍스트 파일 (Text File), 이진 파일 (바이너리 파일; Binary File)</a><br>

<h3><b>scanf의 버퍼 문제</b></h3>

```
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int numinput;
	char charinput;
	scanf("%d", &numinput);
	printf("%d\n", numinput);
	scanf("%c" ,&charinput);
	printf("%c", charinput);
	//예상 결과는 ??
	return 0;
}
```
<b>scanfex.c</b><br>

<img src="https://github.com/tealight03/2024SysP/assets/138011998/5d5247d8-afb2-4d9a-a554-37184fce36e0" width="400"><br>
<b>[그림 01]</b><br>
scanf는 c언어에서 사용자 입력 데이터를 받아오는 함수이다.<br>
입력 버퍼로부터 읽기 버퍼로 데이터를 읽어와 데이터를 변수에 할당하는 방식으로 동작한다.<br>
이 scanf 함수에는 약간의 문제점이 있다.<br><br>

바로 위에 예제를 실행할 경우, 사용자는 이 예제를 통해 두 번의 입력을 받아와<br>
numinput, charinput에 입력한 데이터를 할당하고, 그 데이터를 읽게하려고 했지만<br>
아이러니하게도 숫자 한 번만 입력하면 즉시 결과값들이 출력되고 프로그램이 종료된다.<br>
이는 숫자를 입력한 후, 엔터키를 누르면 '\n'이 버퍼에 삽입되기 때문에<br>
입력 버퍼에 삽입된 숫자값과 문자값을 순차적으로 읽어와<br>
[그림 01]과 같이 numinput, charinput 변수에 각각 할당한 후 출력, 그리고 프로그램을 종료하게 되는 것이다.<br>
그럼 이를 해결하려면 어떻게 해야할까?<br><br>

방법은 아주 간단하다.<br>

```
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int numinput;
	char charinput;
	scanf("%d\n", &numinput);
	printf("%d\n", numinput);
	scanf("%c" ,&charinput);
	printf("%c", charinput);
	//예상 결과는 ??
	return 0;
}
```
<b>수정한 scanfex.c</b><br>

이렇게 코드를 약간 수정해주면 처음 scanf 함수를 실행할 때<br>
엔터키를 눌렀을 때 입력되는 '\n'을 무시하기 때문에 아까와 같은 불상사가 발생하지 않는다.<br>

<h3><b>Background Process</b></h3>
<img src="https://github.com/tealight03/2024SysP/assets/138011998/735d76c4-0511-46fa-b42d-658ecb63a9bb" width="400"><br>

Background Process(이하 백그라운드 프로세스)는 운영체제의 보이지 않는 부분에서 실행되고 있는 프로세스들을 말한다.<br>
백그라운드 프로세스는 일정 시간 혹은 컴퓨터의 파워가 오프되기 전까지 계속해서 실행된다.<br>
cmd창으로 어떠한 프로세스를 실행시킨 채 다른 명령을 내리고 싶다면 백그라운드 프로세스로 해당 프로세스를 실행시키면 된다.<br>
참고로 실행한 프로세스들은 리눅스 기준 ps 명령어로 확인할 수 있다.<br>

<img src="https://github.com/tealight03/2024SysP/assets/138011998/58c45b2c-5091-4d7b-a2dc-6e786fa992b0" width="250"><br>
<b>[참고]</b><br>
