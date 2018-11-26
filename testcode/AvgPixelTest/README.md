# AvgPixelTest

2018 2학기 광운대학교 컴퓨터 소프트웨어학과

디지털 영상처리

Homework #3 Test

## 픽셀 값 평균 계산 테스트

Color Slicing 과제를 수행하기 위해 얼굴 영역을 추출하기 위한 center(R, G, B)를 선정해야 합니다.

### How?

실제로 복잡한 영상처리 알고리즘을 통해서 center 값을 예측할 수 있지만 현재까지 배운 내용을 토대로 해결하기는 쉽지 않습니다. 따라서, 단순하게 값을 찾아 과제를 수행할 수 있는 방법 두 가지가 있습니다.

1. 얼굴의 특정 영역을 추출해서 해당 영역의 평균 값을 구해서 center값으로 사용한다.
2. 임의로 특정 영역의 값들을 포토샵이나 그림판을 이용해 추출하여 통계를 보고 한 쪽으로 집중된 Pixel 값을 center 값으로 사용한다.

### Try To

1. Color Slicing 과제를 수행하기 위해 다음 이미지(256 x 256)를 사용할 예정입니다.
<p align="center">
  <img width="256" height="256" src="https://user-images.githubusercontent.com/36066656/49044000-e712cb80-f20f-11e8-9693-5e5e4c7a423c.png">
</p>

2. 다음과 같이 해당 이미지의 얼굴 영역을 잘라낸 이미지를 이용하여 픽셀의 평균값을 계산해 보는 테스트를 시도합니다.
<p align="center">
  <img width="62" height="81" src="https://user-images.githubusercontent.com/36066656/49044162-538dca80-f210-11e8-8683-4bd3a08a8d1c.png">
</p>

3. 해당 이미지의 사이즈는 62 x 81이며, 평균값 계산시 흰색에 해당하는 (R, G, B) = (255, 255, 255)는 제외하고 계산합니다.
