#include <iostream>
#include <string>

using namespace std;

bool isPald(int left, int right);
bool isPPald(int left, int right, bool flag);
string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while(T--)
	{
		cin >> s;
		if(isPald(0, s.size()-1)){
			cout << "0" << endl;;
		}else{
			if(isPPald(0, s.size()-1, false)){
				cout << "1" << endl;
			}
			else{
				cout << "2" << endl;
			}
		}
	}
	return 0;
}

bool isPald(int left, int right){
	int len = right-left;
	for(int i=0; i<=(len/2); i++){
		if(s[i+left] == s[right-i]) continue;
		else{
			return false;
		}
	}
	return true;
}

bool isPPald(int left, int right, bool flag){
	if(flag && left >= right) return true;
	if(flag){
		if(s[left] == s[right]){
			return isPald(left, right);
		}else{
			return false;
		}
	}else{
		if(s[left] == s[right]){
			return isPPald(left+1, right-1, false);
		}else{
			if(isPPald(left+1, right, true) || isPPald(left, right-1, true))
				return true;
			else{
				return false;
			}
		}
	}
}