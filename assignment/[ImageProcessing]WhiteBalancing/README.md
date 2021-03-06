# White Balancing

2018 2학기 광운대학교 컴퓨터 소프트웨어학과

디지털 영상처리

Homework #3

## White Balancing

1. 백열등에서 사진 촬영

    - 흰색 종이를 준비하고, 촬영할 때, 같이 촬영
    
2. 흰색 종이 영역의 pixel 값이 (255,255,255)가 되도록 color transformation 함수 정의
    
3. 영상 변환

4. 결과 분석 및 고찰

### Try it!

1. Test Coding을 통하여 BmpToRaw를 이용하여 white376x504.raw 이미지를 생성합니다.

   다음과 같은 이미지를 이용하여 과제를 수행합니다.

   ![image](https://user-images.githubusercontent.com/36066656/49203986-a375b880-f3ed-11e8-9b08-18bdb9702f93.png)

2. 먼저 흰색 종이의 밝기가 달라 흰색 종이에 해당하는 부분에서 가장 어두운 색의 픽셀 값을 그림판에서 추출해냅니다. 얻어낸 픽셀 값은 (137, 88, 34)와 같습니다.

3. 과제를 해결하기 위해 다음과 같은 비를 사용합니다.

   ```c++
   (영상에 들어온 빛) : (반사되어 보이는 빛)
   ```

4. 실제로 흰색 종이에 들어온 빛은 (255, 255, 255)에 해당하므로 추출해 낸 픽셀 값으로 비율을 구해보면 다음과 같습니다.

   ```c++
   (255 / 137, 255 / 88,  255 / 34)
   ```
   
5. 입력 영상으로 얻어낸 R, G, B 픽셀 값은 반사되어 보이는 빛의 값이므로 앞에서 구한 비율을 이용하면 다음 비례식이 성립합니다.

   ```c++
   255 : 137 = (결과 영상의 R) : (입력 영상의 R)
   
   255 : 88 = (결과 영상의 G) : (입력 영상의 G)
   
   255 : 34 = (결과 영상의 B) : (입력 영상의 B)
   ```

6. 위의 비례 식을 적용하여 WhiteBalancing한 결과 영상입니다. 

   ![image](https://user-images.githubusercontent.com/36066656/49207612-c6f23080-f3f8-11e8-8b51-bcc43064525f.png)
