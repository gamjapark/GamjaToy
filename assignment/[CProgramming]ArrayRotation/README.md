# ArrayRotation

2018 2학기 광운대학교 컴퓨터 소프트웨어학과

고급 C 프로그래밍 및 설계

Homework #1

## 배열에 숫자 넣기

**Step 1.**

다음과 같이 숫자가 입력되도록 배열을 만든다. 키보드로부터 정수를 입력받아 배열의 사이즈를 조절될 수 있도록 한다. 배열을 출력하는 루틴을 넣도록 한다.아래는 5 x 5 배열의 경우에 예상되는 결과값이다. 

![image](https://user-images.githubusercontent.com/36066656/48489552-ac4f8180-e866-11e8-95b8-f1ca4ab17c2b.png)

**Step 2.**

배열을 회전 시키는 함수 introtateArray(int x[][NUMCOLS], int degree)를 작성하라. 이후, Step 1 에서 만든 배열을 입력 매개변수로 해서 함수를 호출한 다음 그 결과를 출력하시오.함수는 degree 의 값이 90, 180, 270 인 경우 회전시킬 수 있으며 이때의 함수는 1 을 반환한다. degree 에 3 개 이외의 값이 전달되는 경우 배열을 회전시킬 수 없으며, 이때 함수는 회전기능을 하지 않고, 0 을 반환한다. 아래는 Step 1 예제를 90 도 회전시킨 배열의 모습입니다. (즉,degree = 90) 

![image](https://user-images.githubusercontent.com/36066656/48489682-e7ea4b80-e866-11e8-9ebe-5e2f8899c629.png)