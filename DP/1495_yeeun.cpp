#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N,S,M;
int V[101];
int dp[1001][101]; //[볼륨][노래 번호]
int maxVolume(int v, int n);

int main(){

	cin >> N >> S >> M;

	for(int i=1; i<=N; i++){
		cin >> V[i];
	}

	memset(dp, -1, sizeof(dp));
	int res = maxVolume(S, 0);
	if(res == -100) cout << -1 << endl;
	else cout << res << endl;

	return 0;
}

int maxVolume(int v, int n){ //v는 volume, n은 노래 번호
	if(v < 0 || v > M) return -100;
	if(n == N) return v;
	int &result = dp[v][n]; //&참조자를 써주는것과 안써주는것의 차이는 무엇일까?
	if(result != -1) return result;

	return result = max(maxVolume(v + V[n+1], n+1), maxVolume(v - V[n+1], n+1));
}

