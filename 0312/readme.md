# 2024.03.12 수업 실습 정리(2주차)
<b>WSL(Windows Subsystem Linux)</b><br>
WSL은 "Windows Subsystem Linux"의 약자로,<br>
Windows 운영체제에서 Linux를 사용할 수 있도록 하는 프로그램이다.<br>

WSL이 출시되기 전에는 Virtual Machine과 같이 따로 응용 프로그램을 설치하거나<br>
디스크에서 파티션을 분할하여 멀티부팅을 이용하여 Linux를 사용하였다.<br>
그러나 이 경우에는 잘못하면 기존의 내용이 날아갈 수도 있다는 위험성이 뒤따른다.<br>

WSL을 사용하면 Windows Terminal에서 Linux Command Line을 사용할 수 있고,<br>
bash shell, bash script 사용 및 Linux 환경에서 VScode를 연동하여 작업할 수 있다.<br>

WSL을 설치하기 위해서는 우선 Windows PowerShell(일명 파워셸)을 설치해야한다.<br>

<img src="https://github.com/tealight03/2024SysP/assets/138011998/a5def831-017d-4392-8d89-7b1a39635ef3" width="650"><br>
PowerShell 설치 후 
```
wsl --install
```
명령어를 실행하면 간단하게 WSL을 설치할 수 있다.<br>

<img src="https://github.com/tealight03/2024SysP/assets/138011998/fe922b7a-c738-4825-af87-55db713f8018" width="800"><br>


<b>[참고 자료]</b><br>
<a href="https://learn.microsoft.com/ko-kr/windows/wsl/install">WSL 설치 | Microsoft Learn</a><br>
<a href="https://m.blog.naver.com/ycpiglet/222406891792">[Linux] 윈도우에서 리눅스(우분투)를 사용하기(1) : WSL2 설치, 환경설정 방법 / 파워셸(PowerShell, Windows Terminal) 다운로드</a><br>
