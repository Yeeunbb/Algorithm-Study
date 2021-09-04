#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_set<string> us;
		int s = phone_book.size();
    
    sort(phone_book.begin(), phone_book.end());

		for(int i=0; i<s; i++){
			int nl = phone_book[i].size();
			for(int j=0; j<nl; j++){ //i번째 번호의 길이만큼 확인. "123"이면 "1","12","123" 확인
				string ns = phone_book[i].substr(0, j);
				if(us.find(ns) != us.end()){ //해시테이블에 접두어가 이미 있다면, false
					answer = false;
					break;
				}
			}
			if(!answer)
				break;
			else{
				us.insert(phone_book[i]);
			}
		}    
    return answer;
}