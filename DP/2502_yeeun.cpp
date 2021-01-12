#include <iostream>

using namespace std;

struct Day {
	int A;
	int B;
};

Day dp[30];

int main(){

	int D, K;
	int A, B; //A와 B의 갯수
	int rA, rB; //A와 B의 실제 숫자

	cin >> D >> K;

	dp[0].A = 1;
	dp[0].B = 0;
	dp[1].A = 0;
	dp[1].B = 1;

	for(int i=2; i<D; i++){
		dp[i].A = dp[i-2].A + dp[i-1].A;
		dp[i].B = dp[i-2].B + dp[i-1].B;
	}
	A = dp[D-1].A;
	B = dp[D-1].B;

	int i=1;
	int check;

	while(1){
		check = K-A*i;
		if(check % B > 0){
			i++;
			continue;
		}
		else{
			rA = i;
			rB = check / B;
			break;
		}
	}

	cout << rA << endl;
	cout << rB << endl;

	return 0;
}