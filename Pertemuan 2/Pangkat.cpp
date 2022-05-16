//Algoritma Pangkat
#include <iostream>
using namespace std;

class pangkat{
	public:
		int a, n;
	
};


int main(){
	pangkat Riyan;
	cout<<"Masukkan bilangan yang akan dipangkatkan : ";
	cin>>Riyan.a;
	cout<<"Masukkan bilangan pemangkat : ";
	cin>>Riyan.n;
	int i, hasil;
	hasil = 1;
	for(i=1; i<=Riyan.n; i++){
		hasil *= Riyan.a;
	}
	cout<<"Hasil dari "<<Riyan.a<<" Pangkat "<<Riyan.n<<" : "<<hasil;
	return 0;
}
