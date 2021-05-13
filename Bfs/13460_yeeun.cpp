#include<iostream>
 
#define MAX 10

using namespace std;
 
int N, M, Answer = 987654321;
char MAP[MAX][MAX]; //board. 공을 넣는 상자
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
pair<int, int> Red, Blue;
 
int Min(int A, int B) { if (A < B) return A; return B; }
 
void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 'R')
            {
                Red.first = i;
                Red.second = j;
                MAP[i][j] = '.';
            }
            else if (MAP[i][j] == 'B')
            {
                Blue.first = i;
                Blue.second = j;
                MAP[i][j] = '.';
            }
        }
    }
}
 
//이동한 거리를 계산하는 함수(두 공이 같은 위치에 있는 경우)
int Move_Dist(int x, int y, int xx, int yy) 
{
    return abs(x - xx) + abs(y - yy);
}
 
 //다음으로 진행할 방향을 정하는 함수.(왼->오 였다면, 위,아래만)
int Inverse_Direction(int Cur_D)
{
    if (Cur_D == 0) return 1;
    else if (Cur_D == 1) return 0;
    else if (Cur_D == 2) return 3;
    else if (Cur_D == 3) return 2;
}
 
//board를 기울이는 함수.
void Move(int Rx, int Ry, int Bx, int By, int Cnt, int dir)
{
    if (Cnt >= Answer) return;
    if (Cnt > 10) return;
 
    bool Red_Flag = false;
    bool Blue_Flag = false;
 
    int nRx = Rx + dx[dir];
    int nRy = Ry + dy[dir];
    while (1)
    {
        if (MAP[nRx][nRy] == '#') break;
        if (MAP[nRx][nRy] == 'O') //구멍에 빠진다면 체크해줌.
        {
            Red_Flag = true;
            break;
        }
        nRx = nRx + dx[dir]; //이동가능한 경우 이동해준다.
        nRy = nRy + dy[dir];
    }
    nRx = nRx - dx[dir];
    nRy = nRy - dy[dir];
 
    int nBx = Bx + dx[dir];
    int nBy = By + dy[dir];
    while (1)
    {
        if (MAP[nBx][nBy] == '#') break;
        if (MAP[nBx][nBy] == 'O') //구멍에 빠진다면 체크해줌
        {
            Blue_Flag = true;
            break;
        }
        nBx = nBx + dx[dir];
        nBy = nBy + dy[dir];
    }
    nBx = nBx - dx[dir];
    nBy = nBy - dy[dir];
 
		//B가 빠지면, 해당 함수는 더이상 안봐도됨.
    if (Blue_Flag == true) return; 
    else
		{   //R이 구멍에 빠졌다면, 현재 기울인 값과, 역대 기울인값 비교
        if (Red_Flag == true)
        {
            Answer = Min(Answer, Cnt); 
            return;
        }
    }

		//두개가 겹쳐있다면 이동한 거리를 비교해서, 더 멀리서 온 공을 한 칸 다시 이동
    if (nRx == nBx && nRy == nBy)
    {
        int Red_Dist = Move_Dist(Rx, Ry, nRx, nRy); //이동한 거리 계산
        int Blue_Dist = Move_Dist(Bx, By, nBx, nBy);
 
        if (Red_Dist > Blue_Dist)
        {
            nRx = nRx - dx[dir];
            nRy = nRy - dy[dir];
        }
        else
        {
            nBx = nBx - dx[dir];
            nBy = nBy - dy[dir];
        }
    }
 
		//의미있는 방향으로 더 기울이기
    for (int i = 0; i < 4; i++)
    {
        if (i == dir) continue; //이미 진행한 방향은 continue
        if (i == Inverse_Direction(dir)) continue; //내가 온 방향도 continue
 
        Move(nRx, nRy, nBx, nBy, Cnt + 1, i);
    }
}
 
void Solution()
{
    for (int i = 0; i < 4; i++)
    {
        int x = Red.first;
        int y = Red.second;
        int xx = Blue.first;
        int yy = Blue.second;
 
        Move(x, y, xx, yy, 1, i); //시작위치에서 상하좌우의 경우를 살핀다.
    }
 
    if (Answer > 10 || Answer == 987654321) Answer = -1;
    cout << Answer << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    Solve();

    return 0;
}