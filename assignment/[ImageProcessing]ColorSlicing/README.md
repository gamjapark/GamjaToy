# Color Slicing

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

### Try It!

1. Test Coding을 통하여 BmpToRaw를 이용하여 test520x678.raw 이미지를 생성합니다.

   다음과 같은 이미지를 이용하여 과제를 수행합니다.
   
   <p align="center">
    <img width="434" height="630" src="https://user-images.githubusercontent.com/36066656/49152686-ed5f8f80-f356-11e8-84e5-b6a3e5530e80.png"> </p>

2. Test Coding을 통하여 AvgPixelTest에서 얻은 얼굴 부분에 해당하는 RGB 평균 픽셀 값을 이용합니다.

   얻어낸 평균 픽셀 값 : (R, G, B) = (227.486, 191.125, 169.29)

3. 다음 식을 이용하여 얼굴 영역을 추출해낼 수 있습니다.

   <p align="center">
    <img width="841" height="218" src="https://user-images.githubusercontent.com/36066656/49203535-00706f00-f3ec-11e8-9025-23ac5f8a1c0d.png"> </p>

   여기서, 한 픽셀 당 3가지의 색을 사용하므로 i = 3이고, r은 현재의 픽셀 값, a는 추출해 낼 영역의 기준이 되는 중심 픽셀, R은 추출할 범위를 하나의 구로 생각했을 때의 반지름 값에 해당합니다.

   위의 식은 구의 방정식으로 생각하면 간단하게 이해할 수 있습니다.

   현재 픽셀 값을 (R, G, B)라 하고 기준이 되는 픽셀 값을 (R', G', B')라 하고, 반지름을 R0이라고 했을 때 식은 다음과 같습니다.
    
    ![image](https://user-images.githubusercontent.com/36066656/49226344-a393a980-f429-11e8-8e6d-03dd468a7e21.png)

   해당 범위에 있는 영역은 모두 0으로 처리하고 그렇지 않은 영역은 원래의 픽셀값을 유지하는 식으로 처리를 하게 됩니다. R = 0.1878 * 255 을 반지름의 값으로 설정하여 계산하여 얼굴 부분을 추출해 낸 결과입니다.

4. 얼굴 영상 추출 시에 원본 영상에서 추출해 낸 픽셀의 위치를 checkArray에 표시해 놓습니다. 

5. 추출한 얼굴 영역 영상을 저장해 결과를 확인합니다. 

    얼굴 영역을 추출하였지만, 얼굴 영역과 비슷한 픽셀을 가진 다른 영역 또한 추출되었습니다. 
    (아직까지 배운 범위 내에서는 해결하기 어려워 추후에 진행해보겠습니다.)

   <p align="center">
    <img width="523" height="761" src="https://user-images.githubusercontent.com/36066656/49157582-7bda0e00-f363-11e8-9e5d-e7ed4fd2ae4e.png"> </p>

6. 추출해 낸 얼굴 이미지에 Padding을 적용합니다. 

    Padding 함수 : 3 x 3 필터를 사용할 것이므로 넓이, 높이에 각각 2만큼 padding합니다. 

7. Padding한 영상에 Smooth 필터를 적용합니다. 

   Smooth Filter 함수 : checkArray에 표시된 위치에만 Smooth 필터를 적용하고 그렇지 않은 부분은 모두 0으로 설정해 둡니다. 

   후에 필터가 적용된 이미지를 원본 이미지에 overwrite 할 예정이기 때문에 추출되지 않아서 0의 값으로 설정된 부분과 그렇지 않은 부분에 smooth 필터가 적용됐을 경우, 경계의 구분이 발생할 수 있습니다.

   따라서 smooth 필터 적용 시에 필터를 적용할 9개의 value 중 추출하지 않은 영역이 있을 경우, 해당 부분은 현재 처리하고 있는 Pixel 값을 사용하여 처리를 해줍니다. (애초에, Smooth 필터는 얼굴로 추출된 픽셀만 처리를 하기 때문입니다.)

8. 추출한 얼굴 영상에 Smooth Filter를 적용한 영상을 저장해 결과를 확인합니다.

    필터를 적용하기 전과 후의 영상을 비교해 봅니다. 
    
                         <Filter 적용 전>                                <Filter 적용 후>
    
    <p align="center">
    <img width="761" height="510" src="https://user-images.githubusercontent.com/36066656/49229261-74cd0180-f430-11e8-9c0e-31647975dad5.png"> </p>
    
    실제로 육안으로 보기에 큰 차이를 알 수 없어 그림판을 이용해 확인하여 봅니다.
    
                             <Filter 적용 전>                                <Filter 적용 후>

    <p align="center">
    <img width="565" height="370" src="https://user-images.githubusercontent.com/36066656/49231166-b495e800-f434-11e8-87dc-9a7f0c9d5632.png"> </p>
    
    위와 같이 확대 시, 확실히 필터 적용 후에 더 부드러워진 것을 확인할 수 있습니다.
    
9. 원본 영상에 checkArray를 이용하여 추출된 부분의 픽셀 위치에 추출 후 smooth 필터를 적용한 영상을 overwrite합니다.

10. Overwriter한 영상을 저장해 결과를 확인합니다.

    원본 영상과 최종 결과 영상을 비교해 봅니다. 

                            <입력 영상>                                         <결과 영상>

    <p align="center">
    <img width="757" height="577" src="https://user-images.githubusercontent.com/36066656/49231758-f2dfd700-f435-11e8-8eb5-316f958b2908.png"> </p>
    
    마찬가지로 육안으로 보기에 큰 차이를 알 수 없어 그림판으로 이용해 확인하여 봅니다.
    
                             <입력 영상>                                         <결과 영상>        
    <p align="center">
    <img width="781" height="324" src="https://user-images.githubusercontent.com/36066656/49232274-fcb60a00-f436-11e8-8b08-3ae4ed1f90e3.png"> </p>
    
    확대하여 확인했을 때, 확실히 보정된 효과가 보이는 것을 확인할 수 있습니다.
    
