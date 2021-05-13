#include<iostream>
#include<queue>

using namespace std;

const int MAX = 103;
int n, m, t;
int castle[MAX][MAX];
int check[MAX][MAX][2];

int flag = 0;
int ans = 0;

struct coor {
    int y;
    int x;
    int cnt;
    int g;
};

queue <coor> q;
void bfs();
//inside check
bool inside(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < m;
}

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> castle[i][j];
        }
    }

    check[0][0][0] = 1;
    q.push({ 0,0,1,0 });

    bfs();

    if (ans > 0 && ans <= t) cout << ans;
    else cout << "Fail";

    return 0;
}


void bfs() {
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int cnt = q.front().cnt;
        int g = q.front().g;
        q.pop();

        if (castle[y][x] == 2) g = 1;
        if (y == n - 1 && x == m - 1) {
            ans = cnt - 1;
            return;
        }

        int ny, nx;
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if (g == 1) {
                if (inside(ny, nx) && check[ny][nx][g] == 0) {
                    check[ny][nx][g] = cnt + 1;
                    q.push({ ny,nx,cnt + 1,g });
                }
            }
            else {
                if (inside(ny, nx) && check[ny][nx][0] == 0 && castle[ny][nx] != 1) {
                    check[ny][nx][0] = cnt + 1;
                    q.push({ ny,nx,cnt + 1,g});
                }
            }

        }
    }
}