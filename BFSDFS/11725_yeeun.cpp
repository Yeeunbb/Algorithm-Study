#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;
int N;
bool visited[MAX];
int parent[MAX];
vector<int> tree[MAX];

void dfs(int nodeNum);

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); //cin 속도 향상 위해

	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
			 int n1, n2;

			 cin >> n1 >> n2;

			 tree[n1].push_back(n2);
			 tree[n2].push_back(n1);
	}

	dfs(1); //root부터

	//endl 사용 시 시간 초과
	for (int i = 2; i <= N; i++)
		cout << parent[i] << "\n";

	return 0;
}

void dfs(int nodeNum)
{
	visited[nodeNum] = true; //방문한 노드 표시
     
	for(int i = 0; i<tree[nodeNum].size(); i++)
	{
		 int next = tree[nodeNum][i];

		 if (!visited[next])
		 {
				 parent[next] = nodeNum; //next의 parent는 nodeNum
				 dfs(next);
		 }
	}
}