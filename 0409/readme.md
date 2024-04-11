# 2024.04.09 강의 주요 내용 정리(6주차)
<h3><b>void형 포인터</b></h3>
Object처럼 모든 자료형의 포인터를 받을 수 있는 자료형이다<br>
C언어에서 malloc(), calloc(), realloc() 등의 함수가<br>
반환되는 데이터의 자료형으로 void형 포인터를 사용한다<br><br>

<img src="https://github.com/tealight03/2024SysP/assets/138011998/e8307dd1-fb9e-46e1-9331-4c8d7f1405d5" width="400"><br>
<b>malloc() 함수의 시그니처</b><br><br>

<img src="https://github.com/tealight03/2024SysP/assets/138011998/61a3509e-ec98-4b4f-9f30-497367c6e843" width="350"><br>
<b>calloc() 함수의 시그니처</b><br><br>

<img src="https://github.com/tealight03/2024SysP/assets/138011998/2e07eb02-0a7c-411a-9e3c-b6bca855d147" width="400"><br>
<b>realloc() 함수의 시그니처</b><br>

void형 포인터를 그냥 사용하면 메모리에서 얼마만큼의 크기를 읽어와야하는지<br>
컴퓨터가 알 수 없다 따라서 캐스팅하지 않은 채 사용하려고 하면<br>
컴파일러가 아래와 같은 경고 메시지를 보여준다<br>

<img src="https://github.com/tealight03/2024SysP/assets/138011998/4e734b27-a853-467c-8a59-842fbc759b16" width="500"><br>


그래서 char, int, long 등의 일반적인 자료형에 대한 포인터로 이걸 캐스팅해줘야 정확한 크기만큼 메모리를 읽도록 할 수 있다

<b>[참고]</b><br>
<a href="https://reakwon.tistory.com/19">[C언어] VOID 포인터(VOID POINTER)개념과 자유로운 형변환, MALLOC 반환형</a>

<h3><b>정보의 단위</b></h3>
컴퓨터 내에서는<br><br>

<b>bit < nibble < byte < word < field < record < table < DB</b><br><br>
의 순서대로 단위가 구성되어 있다<br>

DB에서 다루는 데이터인 튜플들은 record이다<br>
record를 구분하기 위해서는 그 하위 단계인 field를 이용하는 것이다<br>
따라서 우리가 DB에서 말하는 키(key)는 유일하게 record를 구분할 수 있는 field를 지칭하는 것이라고 이해할 수 있다

<h3><b>ADT(추상 자료형)</b></h3>
ADT는 Abstract Data Type의 약자로, 우리말로 "추상 자료형"이라고 번역한다<br>
자료형을 구현하기 이전, 이론적으로 이 자료형이 어떠한 구조로 생겼는지<br>
이 자료형을 운용하기 위해 어떤 메소드를 만들어서 사용할 수 있는지 등등<br>
실제 언어에 기본적으로 구현되어있는 primitive data type(원시 자료형) 이외에<br>
자료형에 대한 이론 개념이라고 이해하면 된다<br>
Stack, Queue, Deque, Heap 등이 해당한다<br>
언어에 따라 primitive data type(원시 자료형) 이외에 선언되어 있는 경우도 있다.<br><br>
ex) Java, Python, ...<br><br>


<b>[참고]</b><br>
C에서 레코드를 struct를 이용하여 구조체 형식으로 정의할 수 있다

```
#include <stdio.h>

// 학생 레코드를 정의하는 구조체
struct StudentRecord {
    int studentID;
    char name[50];
    int age;
    float GPA;
};

int main() {
    // 학생 레코드 변수 생성
    struct StudentRecord student1;

    // 데이터 할당
    student1.studentID = 1234;
    strcpy(student1.name, "John Doe");
    student1.age = 20;
    student1.GPA = 3.8;

    // 레코드 출력
    printf("Student ID: %d\n", student1.studentID);
    printf("Name: %s\n", student1.name);
    printf("Age: %d\n", student1.age);
    printf("GPA: %.2f\n", student1.GPA);

    return 0;
}
```
