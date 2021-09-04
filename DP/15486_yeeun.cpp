#include <iostream>
#include <vector>
#include <algorithm>
//boj 15486

using namespace std;

int dp[1500051];
int T[1500001]; //소요되는 상담 일 수 저장하는 배열
int P[1500001]; //얻게되는 이득을 저장하는 배열
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; 
    
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> T[i] >> P[i];
    }
 
    for (int i = 1; i <= n; i++) {        
 
        dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);        
 
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }
 
    cout << dp[n + 1] << '\n';
}