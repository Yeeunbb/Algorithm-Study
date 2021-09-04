#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int getPi(string p){
	int m = (int)p.size();
	int j=0, Max = 0;
	vector<int> pi(m, 0); //0으로초기화된 m개의 원소
	
	for(int i = 1; i< m; i++){
		while(j > 0 && p[i] != p[j])
			j = pi[j-1];
		if(p[i] == p[j])
			Max = max(Max, pi[i] = ++j);
	}
	return Max;
}

int main(){
	string p;
	cin >> p;

	int sl = (int)p.size();
	int Max = 0;

	for(int i=0; i<sl; i++)
		Max = max(Max, getPi(p.substr(i, sl-i)));

	cout << Max;


	return 0;


}