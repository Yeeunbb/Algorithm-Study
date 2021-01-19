#include<iostream>
#include <queue>

using namespace std;

void bfs(int a, int b, int c);
bool isValid(int a, int b, int r);
int A, B, C;
int visited[201][201][201];
int ofC[201];
typedef struct{
	int a;
	int b;
	int c;
}bottle;
int main(){
	cin >> A >> B >> C;

	bfs(0, 0, C);
	for(int i=0; i<=200; i++){
		if(ofC[i]==1){
			cout << i << " ";
		}
	}
	return 0;
}

void bfs(int a, int b, int c){
	queue<bottle> bo;
	bo.push({a,b,c});

	while(!bo.empty()){
		bottle now = bo.front();
		bo.pop();

		int a = now.a;
		int b = now.b;
		int c = now.c;

		if(visited[a][b][c]==1) continue;
		visited[a][b][c] = 1;
		if(a==0) ofC[c] = 1;

		if(isValid(a,b,B)){
			if(a+b > B){
				bo.push({a+b-B, B, c});
			}
			else{
				bo.push({0, a+b, c});
			}
		}
		if(isValid(a,c,C)){
			if(a+c > C){
				bo.push({a+c-C, b, C});
			}
			else{
				bo.push({0,b,a+c});
			}
		}
		if(isValid(b,a,A)){
			if(b+a > A){
				bo.push({A,b+a-A,c});
			}
			else{
				bo.push({b+a,0,c});
			}
		}
		if(isValid(b,c,C)){
			if(b+c > C){
				bo.push({a,b+c-C,C});
			}
			else{
				bo.push({a,0,b+c});
			}
		}
		if(isValid(c,a,A)){
			if(c+a > A){
				bo.push({A,b,c+a-A});
			}
			else{
				bo.push({c+a,b,0});
			}
		}
		if(isValid(c,b,B)){
			if(c+b > B){
				bo.push({a, B, c+b-B});
			}
			else{
				bo.push({a,c+b,0});
			}
		}
	}
}

bool isValid(int a, int b, int r){
	if(a<=0) return false;
	if(b==r) return false;
	return true;
}
