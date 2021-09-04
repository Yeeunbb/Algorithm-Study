#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> trees; //나무 종을 저장하는 map
string s;
int n;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while(getline(cin, s)){
		trees[s]++;
		n++;
	}

	cout << fixed; //소수점 4째자리로 픽스
	cout.precision(4);

	for(auto iter = trees.begin(); iter!= trees.end(); iter++){
		string name = iter->first;
		double rate = iter->second;

		rate = rate/n*100.0;
		cout << name << " " << rate << endl;
	}

	return 0;
}