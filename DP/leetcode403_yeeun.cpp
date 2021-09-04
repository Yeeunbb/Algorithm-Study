#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main(){
    
    Solution();

    return 0;
}

class Solution {
public:
    map<pair<int,int>,bool>mp; //(<stone위치, unit 값> , 가능성)
    
    bool solve(int curr,int k,set<int>&pos,int end)
    {
        if(curr==end) //마지막 스톤까지 도착하면 true를 반환
            return true;
        if(curr>end||pos.find(curr)==pos.end()) //강 길이를 넘는 경우 반환
            return false;
        if(mp.find({curr,k})!=mp.end()) //stone위치와 unit값이 존재할 경우
           return  mp[{curr,k}]; //true or false 반환
        
        return mp[{curr,k}]=solve(curr+k+1,k+1,pos,end)||solve(curr+k,k,pos,end)||(k-1>0&&solve(curr+k-1,k-1,pos,end));
                             // k-1 / k / k+1 중 하나라도 true인 경우가 있다면, (현재 stone위치, unit 값)은 true가 된다.
        
    }
    bool canCross(vector<int>& stones) {
         mp.clear();
        
         set<int>pos(stones.begin(),stones.end());

        return solve(1,1,pos,stones[stones.size()-1]);
        
    }
};

// 개구리가 점프하는 길이 == unit == k
// unit  k-1  or k  or k+1 
    
// 0 1 3 5 6 8 12 17  1 2 3
//  1 2 2 1 2 ->false
//  1 2 2 3   4  5 ->true   
    