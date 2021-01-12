#include <iostream>

using namespace std;

char road[5][5];
int visited[5][5];
int dist;
int R,C,K;
int dy[4] = {1, 0, 0, -1};
int dx[4] = {0, 1, -1, 0};

int dfs(int x, int y, int dist);

int main(){

	cin >> R >> C >> K;

	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin >> road[i][j];
		}
	}
	cout << dfs(R-1, 0, 1);

	return 0;
}

int dfs(int y, int x, int dist){
	if(dist == K){
		if(y==0 && x==C-1){
			return 1;
		}
		return 0;
	}
	visited[y][x] = 1;
	int cnt = 0;

	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(nx>=0 && nx<C && ny>=0 && ny<R){
			if(visited[ny][nx] == 0 && road[ny][nx] != 'T'){
				cnt += dfs(ny, nx, dist+1);
			}
		}
	}
	visited[y][x] = 0;
	return cnt;
}
