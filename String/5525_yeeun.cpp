#include <iostream>
#include <string>

using namespace std;

int main(){

	int N, M, res=0;
	string S;

	cin >> N >> M;
	cin >> S;


	for(int i=0; i<M-2; i++){
		if(S[i+1] == 'O' && S[i+2] == 'I'){
			int O=0;
			while(S[i]=='I' && S[i+1] == 'O'){
				i+=2;
				O++;
				if(S[i]=='I' && O==N){
					O--;
					res++;
				}
			}
		}
	}
	cout << res;
	return 0;
}
