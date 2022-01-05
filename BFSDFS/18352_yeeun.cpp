#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> city;
int visited[300010]; //노드 방문 체크
int N, M, K, X, A, B, res;
void DFS(int now, int move);
void BFS(int start);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K >> X;

	city.resize(N+10);

	for(int i=0; i<M; i++){
		cin >> A >> B;
		city[A].push_back(B);
	}

	DFS(X, 0);
	//BFS(X);

	for(int i=1; i<=N; i++){
		if(i==X) continue;
		if(visited[i] == K){
			res++;
			cout << i << endl;
		}
	}
	if(res==0) cout << "-1";

	return 0;
}

void DFS(int now, int move){
	if(move >= K) return;

	for(int i=0; i<city[now].size(); i++){
		if(city[now][i] == X) continue;
		if(visited[city[now][i]] == 0 || visited[city[now][i]] > visited[now] + 1){
			visited[city[now][i]] = visited[now] + 1;
			DFS(city[now][i], move+1);
		}
	}
}

void BFS(int start){
	queue<int> q;
	q.push(start);

	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int i=0; i<city[now].size(); i++){
			if(visited[city[now][i]] == 0){
				visited[city[now][i]] = visited[now] + 1;
				q.push(city[now][i]);
			}
		}
	}
}