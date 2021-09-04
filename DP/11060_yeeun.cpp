#include <iostream>
#include <cstring>

using namespace std;

int N;
int arr[1001];
int dp[1001];
int solution(int now);

int main(){

	cin >> N;

	for(int i=0; i<N; i++){
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));

	int result = solution(0);

	if(result == 1000){
		cout << -1;
	}else{
		cout << result;
	}
	return 0;
}

int solution(int now){
	if(now == N-1) return 0;
	if(now >= N) return 1000;

	int &result = dp[now];

	if(result != -1) return result;

	result = 1000;

	for(int i=1; i<=arr[now]; i++){
		result = min(result, 1 + solution(now+i));
	}

	return result;
}