Color Slicing

2018 2학기 광운대학교 컴퓨터 소프트웨어학과

디지털 영상처리

Homework #3

## Color Slicing

1. 얼굴사진을 촬영하고 color slicing을 통해서 살짝 영역 추출
    -  본인 혹은 동양인 얼굴을 가지고 수행할 것
2. 추출된 영역과 추출되지 않은 영역에 대한 정보를 matrix 형태로 map 보관해야 함
3. 추출된 영상에 대해서, smoothing filter 적용
4. 위의 map을 이용하여, 얼굴 영역에 대해서 smoothing된 영상을 overwrite
5. 결과 분석 및 고찰

### Try it!

1. Test Coding을 통하여 BmpToRaw를 이용하여 test520x678.raw 이미지를 생성합니다.

   다음과 같은 이미지를 이용하여 과제를 수행합니다.

   ![image](https://user-images.githubusercontent.com/36066656/49152686-ed5f8f80-f356-11e8-84e5-b6a3e5530e80.png)

2. Test Coding을 통하여 AvgPixelTest에서 얻은 얼굴 부분에 해당하는 RGB 평균 픽셀 값을 이용합니다.

   얻어낸 평균 픽셀 값 : (R, G, B) = (227.486, 191.125, 169.29)

3. 다음 식을 이용하여 얼굴 영역을 추출해낼 수 있습니다.

   ![1543410463182](C:\Users\kryj9\AppData\Roaming\Typora\typora-user-images\1543410463182.png)

   여기서, 한 픽셀 당 3가지의 색을 사용하므로 i = 3이고, r은 현재의 픽셀 값, a는 추출해 낼 영역의 기준이 되는 중심 픽셀, R은 추출할 범위를 하나의 구로 생각했을 때의 반지름 값에 해당합니다.

   위의 식은 구의 방정식으로 생각하면 간단하게 이해할 수 있습니다.

   현재 픽셀 값을 (R, G, B)라 하고 기준이 되는 픽셀 값을 (R', G', B')라 하고, 반지름을 R0이라고 했을 때 식은 다음과 같습니다.
   $$
   (R - R')^2 + (G - G')^2 + (B - B')^2 > R0^2
   $$
   해당 범위에 있는 영역은 모두 0으로 처리하고 그렇지 않은 영역은 원래의 픽셀값을 유지하는 식으로 처리를 하게 됩니다. 

4. R = 0.1878 * 255 을 반지름의 값으로 설정하여 계산하여 얼굴 부분을 추출해 낸 결과입니다.

![image](https://user-images.githubusercontent.com/36066656/49157582-7bda0e00-f363-11e8-9e5d-e7ed4fd2ae4e.png)