#include <iostream>
#include <vector>
#include <algorithm>
//저울
using namespace std;

vector<int> weight;

int main(){
	int num, w;
	int s=0;
	int result=0;

	cin >> num;

	for(int i=0; i<num; i++){
		cin >> w;
		weight.push_back(w);
	}
	sort(weight.begin(), weight.end());

	for(int i=0; i<num; i++){
		if(s+1 < weight[i]) break;
		s += weight[i];

	}

	cout << s+1;

	return 0;
}
