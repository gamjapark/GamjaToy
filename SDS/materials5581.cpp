#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int Test;
	cin >> Test;

	string resultString = "";
	for(int i = 0; i < Test; i++){
		resultString += "#";
		resultString += to_string(i + 1);
		resultString += " ";

		int totalCount;
		cin >> totalCount;
		vector<pair<int, int>> inputInfo;
		for(int j = 0; j < totalCount; j++){
			int x , y;
			cin >> x >> y;
			inputInfo.push_back(pair<int, int>(x, y));
		}

		int *index = new int[totalCount];
		for(int j = 0 ; j < totalCount; j++){
			index[j] = j + 1;
		}

		vector<pair<int,int>>::iterator iter1;
		int idx = 0;
		for(iter1 = inputInfo.begin(); iter1 != inputInfo.end();){
			vector<pair<int, int>>::iterator iter2;
			int deleteCheck = -1;
			for(iter2 = inputInfo.begin(); iter2 != inputInfo.end(); iter2++){
				//cout << iter1->first << " " << iter1->second << endl;
				//cout << iter2->first << " " << iter2->second <<endl;
				if(iter1->first > iter2->first && iter1->second > iter2->second){
					inputInfo.erase(iter1);
					deleteCheck = 1;
					index[idx] = -1;
					break;
				}
				if(iter1->first == iter2->first && iter1->second > iter2->second){
					inputInfo.erase(iter1);
					deleteCheck = 1;
					index[idx] = -1;
					break;
				}
				if(iter1->second == iter2->second && iter1->first > iter2->first){
					inputInfo.erase(iter1);
					deleteCheck = 1;
					index[idx] = -1;
					break;
				}
			}
			if(deleteCheck == -1){
				++iter1;
			}
			idx++;
		}
	
		int j = inputInfo.size() - 1;
		while(inputInfo.size() != 0){
			int min = inputInfo[j].first;
			int minNum = j;
			for(int k = 0; k <inputInfo.size(); k++){
				if( j == k && inputInfo.size() != 1) continue;
				if( min > inputInfo[k].first){
					minNum = k;
					min = inputInfo[k].first;
				}
				else if(min == inputInfo[k].first){
					if(inputInfo[j].second > inputInfo[k].second){
						minNum = k;
					}
				}
				inputInfo.erase(inputInfo.begin() + minNum);
			}
			int Cnt = 0;
			for(int k = 0; k < totalCount; k++){
				if(index[k] != -1){
					++Cnt;	
					if(Cnt == (minNum + 1)){
						resultString += to_string(index[k]);
						index[k] = -1;
						resultString += " ";
					}
				}
			}
			j = inputInfo.size() - 1;
		}
		if( i != Test -1){
			resultString += "\n";
		}
	}
	cout << resultString << endl;


	return 0;
}
