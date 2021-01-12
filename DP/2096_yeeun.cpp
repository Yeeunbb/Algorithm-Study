#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int arr[3];
int befmax[3];
int befmin[3];
int MAX[3];
int MIN[3];

int main(){

	int N;

	cin >> N;

	for(int i=0; i<N; i++){
		for(int j=0; j<3; j++){
			cin >> arr[j];
			if(i==0){
				MAX[j] = arr[j];
				MIN[j] = arr[j];
				befmax[j] = arr[j];
				befmin[j] = arr[j];
			}
			else{
				if(j==0){
					MAX[j] = arr[j] + max(befmax[0], befmax[1]);
					MIN[j] = arr[j] + min(befmin[0], befmin[1]);
				}
				else if(j==1){
					MAX[j] = arr[j] + max(max(befmax[0], befmax[1]), befmax[2]);
					MIN[j] = arr[j] + min(min(befmin[0], befmin[1]), befmin[2]);
				}
				else{
					MAX[j] = arr[j] + max(befmax[1], befmax[2]);
					MIN[j] = arr[j] + min(befmin[1], befmin[2]);
				}
			}
		}
		befmax[0] = MAX[0];
		befmax[1] = MAX[1];
		befmax[2] = MAX[2];
		befmin[0] = MIN[0];
		befmin[1] = MIN[1];
		befmin[2] = MIN[2];
	}
	cout << max(max(MAX[0],MAX[1]), MAX[2]) << " " << min(min(MIN[0], MIN[1]), MIN[2]);

	return 0;
}
