#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;
char map[100][100];
int visited[100][100];
int dir[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
void bfs(int i, int j);
void bfs2(int i, int j);

int main() {
	int cnt=0;

	cin >> N;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> map[i][j];
		}
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(visited[i][j]==1) continue;
			else{
				bfs(i,j);
				cnt++;
			}
		}
	}
	cout << cnt << " ";
	cnt = 0;

	memset(visited, 0, sizeof(visited)); //색약을 위한 bfs를 실행시키기 전 visited 초기화

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(visited[i][j]==1) continue;
			else{
				bfs2(i,j);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}

//일반인을 위한 bfs
void bfs(int i, int j){
	queue<pair<int, int>> q;
	q.push(make_pair(i,j));
	visited[i][j] = 1;

	while(!q.empty()){
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for(int k=0; k<4; k++){
			int nr = r + dir[k][0];
			int nc = c + dir[k][1];

			if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if(visited[nr][nc] == 1) continue;
			else {
				if(map[r][c] == map[nr][nc]){
					q.push(make_pair(nr,nc));
					visited[nr][nc] = 1;
				}
			}
		}
	}
}

//색약을 위한 bfs
void bfs2(int i, int j){
	queue<pair<int, int>> q;
	q.push(make_pair(i,j));
	visited[i][j] = 1;

	while(!q.empty()){
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for(int k=0; k<4; k++){
			int nr = r + dir[k][0];
			int nc = c + dir[k][1];

			if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if(visited[nr][nc] == 1) continue;
			else {
				if(map[r][c] == map[nr][nc]){
					q.push(make_pair(nr,nc));
					visited[nr][nc] = 1;
				}
				else if(map[r][c] == 'R' && map[nr][nc] == 'G'){ //R과 G를 같게 본다.
					q.push(make_pair(nr,nc));
					visited[nr][nc] = 1;
				}
				else if(map[r][c] == 'G' && map[nr][nc] == 'R'){
					q.push(make_pair(nr,nc));
					visited[nr][nc] = 1;
				}
			}
		}
	}
}