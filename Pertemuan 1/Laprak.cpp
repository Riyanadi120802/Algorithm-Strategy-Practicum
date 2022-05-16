#include <iostream>
using namespace std;

int main(){
	
	int bil[10], pembagi, temp, n, tampung = 0, besar, kecil, temp1;
	
	cout<<" Masukkan banyak bilangan : ";
	cin>>n;
	
	for(int i=0; i<n; i++){
		cout<<" Masukkan bilangan ke- "<<i+1<<" : ";
		cin>>bil[i];
	}
	for(int j=0; j<n; j++){
		cout<<" bilangan ke-"<<j+1<<" : "<<bil[j]<<endl;
	}
	
	for(int j=0; j<n; j++){
		tampung += bil[j];
	}
	float rata = tampung/n;
	cout<<" Rata-rata dari bilangan diatas : "<<rata;
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
	cout<<" Bilangan terkecil : "<<kecil<<endl;
	cout<<" Urutan secara Ascending : "<<endl;
	for(int i=0; i<n; i++){
		temp = i;
		for (int j=i; j<n; j++){
			if(bil[temp]>bil[j]){
				temp = j;
			}
		}
		temp1 = bil[i];
		bil[i] = bil[temp];
		bil[temp] = temp1;
	}
	
	for(int i=0; i<n; i++){
		cout<<" "<<bil[i]<<" ";
	}
	cout<<endl;
	cout<<" Urutan secara Descending : "<<endl;
	for(int i=0; i<n; i++){
		temp = i;
		for (int j=i; j<n; j++){
			if(bil[temp]<bil[j]){
				temp = j;
			}
		}
		temp1 = bil[i];
		bil[i] = bil[temp];
		bil[temp] = temp1;
	}
	
	for(int i=0; i<n; i++){
		cout<<" "<<bil[i]<<" ";
	}
	
	return 0;
}
