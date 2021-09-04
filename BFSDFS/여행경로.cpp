#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<bool> visited; //사용한 티켓인지 확인하는 벡터
vector<string> answer;
vector<string> temp; //티켓 사용 경로를 저장하는 벡터

bool dfs(string departure, vector<vector<string>> &tickets, int finishCnt) {
    temp.push_back(departure);

    if(finishCnt == tickets.size()) { //티켓을 모두 탐색했을 때
        answer = temp;
        return true;
    }

    for(int i = 0; i < tickets.size(); i++) {
        if(tickets[i][0] == departure && !visited[i]) {
            visited[i] = true;
            bool success = dfs(tickets[i][1], tickets, finishCnt+1);
            if(success)
                return true;
            visited[i] = false;
        }
    }
//for문이 끝났다 == tickets를 모두 확인했지만 매칭되는게 없었다.
    temp.pop_back(); //최근에 넣은 티켓을 다시 제거해준다.
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    visited.resize(tickets.size());

    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, 0);

    return answer;
}