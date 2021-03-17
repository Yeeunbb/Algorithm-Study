#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

vector<string> num;

int main(){
	int t, n;
	bool possible = true;
	string number;
	cin >> t;

	for(int i=0; i<t; i++){
		cin >> n;
		for(int j=0; j<n; j++){
			cin >> number;
			num.push_back(number);
		}
		sort(num.begin(), num.end());

		for(int j=0; j<n-1; j++){
			if(num[j].length() >= num[j+1].length()) continue;
			if(num[j+1].substr(0, num[j].size()) == num[j]){
				cout << "NO" << endl;
				possible = false;
				break;
			}
		}
		if(possible){
			cout << "YES" << endl;
		}
		else{
			possible = true;
		}
		num.clear();
	}
	return 0;
}