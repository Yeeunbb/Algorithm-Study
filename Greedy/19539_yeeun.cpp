#include <iostream>

using namespace std;

int tree[100001];

int main(){

	int N, total=0;
	int d=0; //2로 나눈 몫(2의 갯수)
	int r=0; //2로 나눈 나머지(1의 갯수)
	int result;
	cin >> N;

	for(int i=0; i<N; i++){
		cin >> tree[i];
		d += tree[i]/2;
		r += tree[i]%2;
		total += tree[i];
	}

	if(total % 3){
		cout << "NO";
		return 0;
	}

	result = (d-r)/3;
	if(result >= 0) cout << "YES";
	else { cout << "NO";}


	return 0;
}

