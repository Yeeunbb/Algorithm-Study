#include<iostream>
#include <queue>

using namespace std;

void bfs(int a, int b, int c);
bool isValid(int a, int b);
int A, B, C;
int visited[201][201][201];
int c[201];
typedef struct{
	int a;
	int b;
	int c;
}bottle;
int main(){
	cin >> A >> B >> C;

	bfs(0, 0, C);
	return 0;
}

void bfs(int a, int b, int c){
	queue<bottle> bo;
	bo.push({a,b,c});
	visited[a][b][c] = 0;
	
	while(!bo.empty()){
		bottle now = bo.front();
		bo.pop();
		int a = now.a;
		int b = now.b;
		int c = now.c;
		
		if(isValid(a,b)){
			if(a+b > B){
				if(visited[a+b-B,B,c]!=1){
					bo.push({a+b-B, B, c});
					visited[a+b-B,B,c] = 1;
				}
			}
			else{ 
				if(visited[0, a+b, c]!=1){
					bo.push({0, a+b, c});
					visited[0,a+b,c] = 1;
				}
			}
			c[c] = 1;
		}
		if(isValid(a,c)){
			if(a+c > C){
				if(visited[a+c-C, b, C]!=1){
					bo.push({a+c-C, b, C});
					visited[a+c-C,b,C];
					c[C]=1;
				}
			}
			else{
				if(visited[0,b,a+c]!=1){
					bo.push({0,b,a+c});
					visited[0,b,a+c];
					c[a+c]=1;
				}
			}
		}
		if(isValid(b,a)){
			if(b+a > A){
				if(visited[A,b+a-A,c]!=1){
					bo.push({A,b+a-A,c});
					visited[A,b+a-A,c];
				}
			}
			else{
				if(visited[b+a, 0, c]!=1){
					bo.push({b+a,0,c});
					visited[b+a,0,c];
				}
			}
			c[c]=1;			
		}
		if(isValid(b,c)){
			
		}
		if(isValid(c,a)){
			
		}
		if(isValid(c,b)){
			
		}
	}
}

bool isValid(int a, int b){
	if(a<=0) return false;
	if(b==B) return false;
	return true;
}
