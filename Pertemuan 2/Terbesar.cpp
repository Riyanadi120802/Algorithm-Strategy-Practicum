//Algoritma Search Elemen terbesar
#include <iostream>
using namespace std;

int main(){
	int bil[10], n, besar, kecil;
	
	cout<<" Masukkan banyak bilangan : ";
	cin>>n;
	
	for(int i=0; i<n; i++){
		cout<<" Masukkan bilangan ke- "<<i+1<<" : ";
		cin>>bil[i];
	}
	cout<<endl;
	for(int j=0; j<n; j++){
		cout<<" bilangan ke-"<<j+1<<" : "<<bil[j]<<endl;
	}
	besar = bil[0];
	kecil = bil[0];
	for(int j=0; j<n; j++){
		if(besar<bil[j]){
			besar = bil[j];
		}else if(kecil > bil[j]){
			kecil = bil[j];
		}
	}
	cout<<"\n Bilangan terbesar : "<<besar<<endl;
	return 0;
}
