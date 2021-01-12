#include <iostream>
#include <string>

using namespace std;

int main(){
	string L, R;
	int cnt=0;
	cin >> L >> R;

	if(R.size() > L.size()){
		cout << 0 << endl;
		return 0;
	}
	for(int i=0; i<R.size(); i++){
		if(R[i] == L[i] && R[i] == '8'){
			cnt++;
			continue;
		}
		if(R[i] != L[i]){
			break;
		}
	}
	cout << cnt << endl;
	return 0;
}
