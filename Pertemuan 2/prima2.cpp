#include <iostream>
using namespace std;

class Prima{
	public :
		int prima = 0, batas;
		int MencariPrima(int n);
		void JumlahPrima();
};

int Prima::MencariPrima(int n){
	for(int i=1;i<=n;i++){
		int bil=0;
		for(int j=1;j<=i;j++){
			if(i%j==0){
				bil=bil+1;
			}
		}
		if (bil==2){
			cout<<i<<" ";
			Prima::prima +=1;
		}
	}
}

void Prima :: JumlahPrima(){
	cout<<"\nJumlah Bilangan Prima : " <<Prima::prima;
}
int main(){
	Prima Riyan;
	cout<<"Masukkan batas yang akan dicari : ";
	cin>>Riyan.batas;
	Riyan.MencariPrima(Riyan.batas);
	Riyan.JumlahPrima();
	return 0;
}
