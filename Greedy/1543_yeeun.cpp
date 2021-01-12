#include <iostream>
#include <stdio.h>

using namespace std;

string docs;
string word;
int k, dl, wl;
int cnt;
//부르토포스
int main(){

	getline(cin, docs);
	getline(cin, word);

	dl = docs.length();
	wl = word.length();

	if(dl<wl){
		cout << 0 << endl;
	}
	else{
		for(k=0; k<dl-wl+1; k++){
			bool same = true;
			for(int i=0; i<wl; i++){
				if(word[i]!=docs[k+i]){
					same = false;
					break;
				}
			}
			if(same){
				cnt++;
				k += wl - 1;
			}
		}
		cout << cnt;
	}

	return 0;
}



