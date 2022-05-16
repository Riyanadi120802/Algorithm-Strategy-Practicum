#include <iostream>
using namespace std;

int main(){
	
	int bil[10],temp, n;
	
	cout<<" Masukkan banyak bilangan : ";
	cin>>n;
	
	for(int i=0; i<n; i++){
		cout<<" Masukkan bilangan ke- "<<i+1<<" : ";
		cin>>bil[i];
	}
	for(int j=0; j<n; j++){
		cout<<" bilangan ke-"<<j+1<<" : "<<bil[j]<<endl;
	}
	
	for(int i=1; i<n; i++){
		int temp = bil[i];
		int j = i-1;
		while(j>=0 && bil[j] > temp){
			bil[j+1] = bil[j];
			j--;
		}
		bil[j+1] = temp;
		cout<<" proses sorting"<<endl;
		for(int m=0;m<n;m++){
		cout<<" "<<bil[m];
	    }
	    cout<<endl;
	}
	cout<<" hasil akhir"<<endl;
	for(int m=0;m<n;m++){
		cout<<" "<<bil[m];
	}
	
	return 0;
}
