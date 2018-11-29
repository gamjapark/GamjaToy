# PLConstrastStretching

2018 2학기 광운대학교 컴퓨터 소프트웨어학과

심화전공실습

Homework #2

## Piecewise-Linear Constrast Stretching

1. 입력 영상에 Piecewise-Linear Constrast Stretching 적용

    - (r1, s1) 및 (r2, s2)는 임의로 적용

2. 입력 영상 : lena512.rgb
    - Format : BGR
    - Height = Width =512
    - ![image](https://user-images.githubusercontent.com/36066656/49239350-e9f70180-f445-11e8-8d15-b09e01feccba.png)

### Try it!

1. lena512.rgb 입력 영상을 R, G, B 각각 읽어옵니다.

2. 임의의 `(r1, s1)` , `(r2, s2)`의 값은 다음과 같이 설정합니다.

   ```c++
   (r1, s1) = (150, 20)
   (r2, s2) = (200, 220)
   ```

   임의의 두 개의 점을 설정한 것을 토대로 그래프를 나타내보면 다음과 같이 같습니다. 

   ![image](https://user-images.githubusercontent.com/36066656/49243291-4e1ec300-f450-11e8-8a86-ca10ffc2fe93.png)

   이에 대한 함수를 정의하면 다음과 같은 식을 정의할 수 있습니다.

   ![image](https://user-images.githubusercontent.com/36066656/49243925-ec5f5880-f451-11e8-894c-371e084b236a.png)

3. 위의 구한 식을 적용하면 Piecewise-Linear Constrast Stretching이 된 영상을 얻을 수 있습니다. 

   yuv player로 확인한 결과 영상 lena512.raw는 다음과 같습니다.

   ![image](https://user-images.githubusercontent.com/36066656/49244086-4cee9580-f452-11e8-9d64-c3f9ffadae34.png)