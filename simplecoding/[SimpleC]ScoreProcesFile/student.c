#include "student.h"

double CalTotalScore(const StudentInfo* student ){
	return (double)(student->midtermExamScore*0.3 + student->finalExamScore*0.3 
			+ student->trainingScore * 1.25 * 0.2 
			+ student->assignmentScore * 2.5 *0.2);
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
			
			switch(i)
			{
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
			tempSi->totalScore = tempSi->funcP1(tempSi);

			tempSi->funcP2 = PrintStudentInfo;
			++studentCount;
		}
	}
	return studentCount;

}

void SwapStudent(StudentInfo* a, StudentInfo *b){
	StudentInfo temp = *a;
	*a = *b;
	*b = temp;
}

StudentInfo* SortStudents(StudentInfo* students, int stCount, unsigned char check){
	switch(check){
	case 0: //grade by asc
		for(int i = 0 ; i < stCount; i++){
			int min = i; 
			for(int j = i + 1; j < stCount; j++){
				if(students[min].stNum > students[j].stNum){
					min = j;
				}
			}
			SwapStudent(&students[min], &students[i]);
		}
		break;
	case 1: //total score by desc
		for(int i = 0; i < stCount; i++){
			int max = i;
			for(int j = i + 1; j < stCount; j++){
				if(students[max].totalScore < students[j].totalScore){
					max = j;
				}
			}
			SwapStudent(&students[max], &students[i]);
		}
		break;
	}
	return students;
}

void PrintList(StudentInfo* students, int stCount, const char* printString){
	printf("%s", printString);
	printf("\t   학번\t\t이름\t중간시험점수\t기말시험점수\t   실습점수\t   과제점수\t총점\t학점\n");
	for(int i = 0; i < stCount; i++){
		students[i].funcP2(students + i);
	}

}

void InputGrade(StudentInfo** students, int startIdx, int lastIdx, char grade){
	StudentInfo* st = *students;
	for(int i = startIdx; i < lastIdx; i++){
		StudentInfo* temp = st + i;
		if(temp->totalScore < 60){
			temp->grade = 'F';
		}else{
			temp->grade = grade;
		}
	}
}
