#include <iostream>

using namespace std;

int Tarr[101];
int btn[5];
//+60, +10, -10, +1, -1
int main(){
	int T, time;
	
	cin >> T;
	
	for(int i=0; i<T; i++){
		cin >> time;
		
		btn[0] = time / 60;
		time = time % 60;
		
		if(time > 35){
			btn[0]++;
			time = 60 - time;
			if((time % 10) > 5){
				btn[2] = (time / 10) + 1;
				btn[3] = 10 - (time % 10);
			} else{
				btn[2] = time / 10;
				btn[4] = time % 10;
			}
		}else{
			if((time % 10) > 5){
				btn[1] = (time / 10) + 1;
				btn[4] = 10 - (time % 10);
			}else{
				btn[1] = time / 10;
				btn[3] = time % 10;
			}
		}
		
		for(int j=0; j<5; j++){
			cout << btn[j] << " ";
			btn[j] = 0;
		}
		cout << endl;
	}
	
	return 0;
}