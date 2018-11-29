# BmpToRaw

2018 2학기 광운대학교 컴퓨터 소프트웨어학과

디지털 영상처리

Homework #3 Test

## bmp 파일을 raw 파일로 변환

Color Slicing 과제를 수행하기 위해 jpg파일을 그림판을 이용해서 bmp파일로 저장 후 해당 영상을 읽기 위해 bmp파일을 raw파일로 변환합니다.

### BMP 파일 구조

**BITMAPFILEHEADER (14 Byte)**

: 비트맵 파일 헤더로서 BMP 파일에 대한 일반 정보를 담고 있습니다.

**BITMAPINFOHEADER (40 Byte)**

: 비트맵 정보 헤더(DIB 헤더)로서 비트맵 그림에 대한 상세한 정보를 담고 있습니다.

**색상 테이블 (색 팔레트)**

: 인덱스 컬러 비트맵에 쓰이는 색의 정의를 담고 있습니다. 이는 픽셀 당 1, 2, 4, 8인 경우에 존재합니다.

**픽셀 데이터(비트맵 데이터)**

: 실제 그림의 데이터를 담고 있습니다.

### Try It!

1. 해당 과제에서는 24비트 비트맵만을 사용하므로 **BITMAPINFOHEADER**에서 biBitCount를 읽어 24의 데이터를 가지는지 확인합니다.

2. biBitCount의 값이 24인 경우에는 색상 테이블을 가지지 않으므로 **BITMAPINFOHEADER** 후에 바로 데이터를 읽습니다.

3. **BITMAPINFOHEADER**에서 biWidth와 biHeight를 읽고, 해당 사이즈를 이용해 R, G, B의 크기를 할당받습니다.

4. 데이터는 B, G, R 순으로 저장되어 있으므로, B, G, R 순으로 데이터를 받아옵니다.

5. 저장한 데이터를 이용하여 raw 파일로 저장합니다.

6. 파일의 이름에는 width  x height 정보를 추가하여 저장시킵니다.
