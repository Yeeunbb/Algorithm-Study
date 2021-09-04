#include <iostream>

using namespace std;

int dp[1001][1001];

int main(){
	int N, K;

	cin >> N;
	cin >> K;

	for(int i=0; i<=N; i++){
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for(int i=2; i<=N; i++){
		for(int j=1; j<=K; j++){

			dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % 1000000003;
		}
	}

	cout << (dp[N-3][K-1] + dp[N-1][K])% 1000000003;


	return 0;
}