#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>

// name : Park Yeonji

int main()
{
    char input[100], output[100];
    int i = 0;
    int strCount = 0;
    int totalCount = 0;
    int k = 0;
    
    while(1){
        printf("문자열을 입력:"); scanf("%s",input);
        if(input[0] == '0' && input[1] =='\0'){
            break;
        }
        int j = 0;
        while(input[j] != '\0'){
            output[i] = input[j];
            ++j;
            ++i;
        }
        output[i] = '\0';
        ++i;
        ++strCount;
    }

    for(int i = 0; i < strCount; i++){
        int cnt = 0;
        while(output[k] != '\0'){
            printf("%c",output[k]);
            ++cnt;
            ++k;
        }
        totalCount += cnt;
        printf(" %d\n", cnt);
        ++k;
    }
    
    printf("문자열의 수: %d\n", strCount);
    printf("문자의 수: %d\n", totalCount);
    return 0;
}