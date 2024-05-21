# 2024.05.21 12주차 강의 내용 정리
<h3><b>텍스트 파일 vs 바이너리 파일</b></h3>

<b>[참고]</b><br>


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
scanf는 c언어에서 사용자 입력 데이터를 받아오는 함수이다.<br>

<h3><b>Background Process</b></h3>
<img src="https://github.com/tealight03/2024SysP/assets/138011998/735d76c4-0511-46fa-b42d-658ecb63a9bb" width="400"><br>
