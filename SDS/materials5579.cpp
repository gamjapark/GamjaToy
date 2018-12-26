#include <iostream>
#include <map>
using namespace std;

int main(){

	int Test;
	cin >> Test;

	int* saveResult = new int[Test];

	for(int i = 0; i < Test; i++){
		saveResult[i] = 0;
		int asTotal;
		int mNum;
		int shield;
		cin >> asTotal >> mNum >> shield;

		map<int, int> m;
		for(int j = 0; j < mNum; j++){
			int mPower;
			int mCount;
			cin >> mPower >> mCount;

			m[mPower] = mCount;
		}


		map<int, int>::iterator it;
		int sum = 0;
		int count = 0;
		for(it = m.begin(); it != m.end(); it++){
			while(it->second != 0){
				++count;
				//cout << "count : " << count << Test <<endl;
				if(count > asTotal){
					saveResult[i] = -1;
					break;
				}
				sum += it->first;
				m[it->first] = (--it->second);

				//cout << "sum : " << sum << ", shield : " << shield <<endl;
				if(sum >= shield){
					saveResult[i] += sum;
					sum = 0;
					count = 0;
					--asTotal;
					if(asTotal == 0){
						break;
					}
				}
			}
			if( count > asTotal){
				break;
			}
			m.erase(it->first);
			if(asTotal == 0){
				break;
			}
		}
	}

	for(int i = 0; i < Test; i++){
		cout << "#" << (i + 1) << " " << saveResult[i] << endl;
	}
	return 0;
}

