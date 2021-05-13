#include <iostream>

using namespace std;

char map[10001][505];
int visited[10001][505];
int dir[3][2] = {{-1,1},{0,1},{1,1}}; //우위, 우, 우아래
int R,C,res;

bool dfs(int y, int x);
bool isInside(int y, int x){
	return (y>=0 && y<R) && (x>=0 && x<C);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;

	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin >> map[i][j];
		}
	}

	for(int i=0; i<R; i++){
		dfs(i,0);
	}

	cout << res;
	return 0;
}
bool dfs(int y, int x){
	visited[y][x] = 1;

	if(x == C-1){
		res++;
		return true;
	}

	for(int i=0; i<3; i++){
		int dy = y + dir[i][0];
		int dx = x + dir[i][1];

		if(!isInside(dy, dx) || map[dy][dx] == 'x' || visited[dy][dx]==1)
			continue;

		if(dfs(dy,dx))
			return true;
	}
	return false;
}