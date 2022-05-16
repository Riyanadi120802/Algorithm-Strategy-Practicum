#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <math.h>
using namespace std;

int isPrime(int p){
	float sqrtp = sqrt(p);
	if(p<2) return 0; // 2 bilangan prima pertama
	if(p==2) return 1;
	if(p%2==0) return 0;
	for(int d=3; d<=sqrtp; d+=2)
		if(p%d==0) return 0;
	return 1;
	
}
int main(){
	for (int n=1; n<50; n++){
		if(isPrime(n)){
			cout<<n<<" ";
			getch();
		}
		
	}
	cout<<endl;
	return 0;
}


