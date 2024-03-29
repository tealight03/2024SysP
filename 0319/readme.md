# 2024.03.19 수업 내용(3주차)

<h3><b>리눅스 tree 명령어</b></h3>
리눅스에서 tree 명령어는 현재 작업중인 디렉토리(pwd 명령어로 확인가능)를 기준으로<br>
디렉토리의 하위 디렉토리, 파일들을 트리 형태로 구조화하여 보여주는 역할을 한다.<br>
사용자는 이 명령어를 이용하여 데이터 관리 작업을 보다 용이하게 할 수 있다.<br>
OS 설치 시 기본적으로 포함되어 있는 명령어이다. 만약 설치되어 있지 않다면<br><br>

<b>[Ubuntu, Debian 계열]</b><br>
sudo apt-get update<br>
sudo apt-get install tree<br>

<b>[Red Hat 계열]</b><br>
sudo yum install tree<br>

<b>[Fedora, CentOS 계열]</b><br>
sudo dnf install tree<br>

등등 각 Linux의 OS 계열에 맞추어 패키지 관리자를 이용한 설치를 진행한 후 사용할 수 있다.<br>
참고로 Snap 패키지 관리자 명령어를 이용하면 계열 무관하게 설치할 수 있다.<br><br>

<b>[계열 무관]</b><br>
sudo snap install tree<hr>

<h3><b>Tree 명령어 실습</b></h3>
<img width="194" alt="image" src="https://github.com/tealight03/2024SysP/assets/138011998/4b708205-779c-4398-b454-e46a9e5640e5"><br>
Tree 명령어 실습을 위하여 위와 같은 형태의 디렉토리 구조를 구성해보자.<br><br>

sudo snap install tree // home 폴더에서<br>
mkdir 0319<br>
mkdir 0319/chang<br>
mkdir 0319/chang/doc<br>
mkdir 0319/chang/test<br>
touch 0319/chang/test/cs1.txt<br>

mkdir 0319/choi<br>
mkdir 0319/choi/cs101<br>

cd 0319/chang/test/<br>
mv cs1.txt cssw.txt<br>
cp cs2.txt /home/0319/choi/cs101<br>

cd ~/0319<br>
tree<br><br>

위 명령어를 순차적으로 실행하면 예시 이미지와 동일한 구조의 트리를 만들어낼 수 있다.<hr>

<h3><b>WSL에서 VScode로 연동하기</b></h3>
WSL의 폴더들을 윈도우 상에서 작업하기 위해서는 다음과 같은 단계를 거쳐 VScode로 연동해주면 된다.<br><br>

<b>1. Remote - WSL 확장 설치</b><br>
VSCode의 확장(Extenstions) 탭을 열어 'Remote - WSL' 확장을 검색하여 설치한다.<br>
이 확장은 WSL과 VSCode를 통합하여 리눅스 환경에서 VSCode를 실행하고 사용할 수 있도록 해준다.<br><br>

<b>2. WSL에서 VScode로 연결</b><br>
WSL에서 code . 명령어로 현재 디렉토리를 VScode에서 열도록(open) 하는 명령어이다.<br>
명령어를 실행하면 방금 내가 작업 중이던 디렉토리가 VScode에서 열리는 것을 확인할 수 있다.<br><br>

※ code 명령어는 VScode가 윈도우 PATH에 등록되어있어야 사용할 수 있다.

<b>[실습]</b><br>
<img width="205" alt="image" src="https://github.com/tealight03/2024SysP/assets/138011998/ab3f40d7-2bda-4a5b-8ee2-fd73e71df8aa"><br>
<img width="958" alt="image" src="https://github.com/tealight03/2024SysP/assets/138011998/582bd865-af3c-487a-8b09-da043be9a9a7"><br>
