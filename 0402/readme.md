# 2024.04.02 강의 주요 내용 정리(5주차)
<ul>
  <li>
    <b>시스템 호출(system call)</b><br>
    <p>
      시스템 호출(system call)이란 운영체제의 커널이 제공하는 서비스에 대해<br>
      응용 프로그램의 요청에 따라 커널에 접근하기 위한 인터페이스를 말한다.<br>
      커널(kernel)이란 영어로 "알맹이", "핵심" 이라는 의미이다.<br><br>
      단어의 의미로 커널의 역할을 정의하자면<br>
      <b>운영체제의 핵심으로써 하드웨어와 응용 프로그램을 이어주는 인터페이스를 제공하고</b><br>
      <b>CPU, 메모리 등의 컴퓨터 리소스를 관리하는 역할을 하는 것이다.</b><br><br>
      우리가 일반적으로 사용하는 프로그램들은 "응용 프로그램"이기에<br>
      유저레벨의 함수들만으로는 다양한 기능을 구현하기가 어렵기 때문에<br>
      커널의 도움을 받아 기능을 구현해야한다.<br>
      이때, 커널에 접근하기 위해 유저모드에서 커널모드로 전환해야하기 때문에<br>
      이를 위해 <b>시스템 콜</b>을 수행해야한다.<br><br>
      ![image](https://github.com/tealight03/2024SysP/assets/138011998/0fd3d514-dc0a-4ec3-92e5-bbdd4d548c09)
    </p>
    <b>[참고 자료]</b><br>
    <a href="https://fjvbn2003.tistory.com/306">[운영체제] 시스템 콜 (System Call)</a><br>
    <a href="https://hotpeng.tistory.com/78">[용어 정리] 운영체제(OS)와 커널(Kernel)</a><br>
    <a href="https://minkwon4.tistory.com/295">[OS] 커널(Kernel)이란</a>
  </li>
  <li>
    <b>printf()의 프로토타입</b>
  </li>
  <li>
    <b>실습</b>
  </li>
</ul>
