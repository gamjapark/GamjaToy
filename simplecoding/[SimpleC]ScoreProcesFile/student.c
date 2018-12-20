#include "student.h"

double CalTotalScore(int mid, int fin, int train, int assign){
	return (double)(mid * 0.3 + fin * 0.3 + train * 0.2 + assign * 0.2);
}

int GetStandardStCount(int stCount, double ratio, int originStandard){
	return (int)(stCount * ratio) + originStandard;
}

int GetStInfoFromFile(const char* fileName, StudentInfo** students){

	FILE* fp = fopen(fileName, "r");
	if(NULL == fp){
		puts("파일 오픈 실패");
		return -1;
	}

	StudentInfo* si = *students;
	char oneLine[LINE_BUFFER_SIZE];
	int studentCount = 0;
	char* token = NULL;

	while(!(feof(fp))){
		fgets(oneLine, sizeof(oneLine), fp);
	
		int finishCheck = -1;
		token = strtok(oneLine, " \t\n");

		StudentInfo* tempSi = si + studentCount;
		for(int i = 0; i < ST_INFO_COUNT; i++){
			if(NULL == token){
				finishCheck = 0;
				break;
			}
			
			switch(i){
				case 0:
					tempSi->stNum = atoi(token);
					break;
				case 1:
					tempSi->stName = (char *)malloc(sizeof(char) * 30);
					strcpy(tempSi->stName, token);
					break;
				case 2:
					tempSi->midtermExamScore = atoi(token);
					break;
				case 3:
					tempSi->finalExamScore = atoi(token);
					break;
				case 4:
					tempSi->trainingScore = atoi(token);
					break;
				case 5:
					tempSi->assignmentScore = atoi(token);
					break;
			}
			token = strtok(NULL, " \t\n");
		}

		if(!finishCheck){
			break;
		}else{
			tempSi->funcP1 = CalTotalScore;
			tempSi->totalScore = tempSi->funcP1(tempSi->midtermExamScore,
				       	tempSi->finalExamScore, tempSi->trainingScore, 
					tempSi->assignmentScore);
			tempSi->funcP2 = PrintStudentInfo;
			++studentCount;
		}
	}
	return studentCount;

}

void PrintStudentInfo(const StudentInfo* student){
	printf("\t%d", student->stNum);
	printf("\t%s", student->stName);
	printf("\t\t%d", student->midtermExamScore);
	printf("\t\t%d", student->finalExamScore);
	printf("\t\t%d", student->trainingScore);
	printf("\t\t%d", student->assignmentScore);
	printf("\t%g", student->totalScore);
	printf("\t %c", student->grade);
	printf("\n");
}






