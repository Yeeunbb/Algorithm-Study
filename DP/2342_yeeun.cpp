#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

vector<int> seq; //수열을 저장할 벡터
int dp[100001][5][5];
int seqn; //수열의 길이

int powerCheck(int a, int b);
int dfs(int cur, int l, int r);

int main(){
	int num;

	for(int i=0; i<100000; i++){
		cin >> num;
		if(num == 0){
			break;
		}
		seq.push_back(num);
	}
	seqn = seq.size();

	cout << dfs(0,0,0) << '\n';

	return 0;
}

int powerCheck(int a, int b){ //움직일때 사용되는 힘을 계산
	if(a == 0)	return 2;
	if(abs(a-b)==2)	return 4;
	if(a == b)	return 1;
	return 3;
}

int dfs(int cur, int l, int r){
	if(cur==seqn){ //수열의 마지막일때
		return 0;
	}
	if(dp[cur][l][r] != 0){
		return dp[cur][l][r];
	}
	int left = dfs(cur+1, seq[cur], r) + powerCheck(l, seq[cur]);
	int right = dfs(cur+1, l, seq[cur]) + powerCheck(r, seq[cur]);
	return dp[cur][l][r] = min(left, right);
}

