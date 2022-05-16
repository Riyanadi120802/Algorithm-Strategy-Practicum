//Algoritma Perkalian 2 buah matriks
#include <iostream>
using namespace std;

void PerkalianMatriks(){
	int matriks1[10][10], matriks2[10][10], hasil[10][10];
  	int i, j, k, m = 2, n = 2, jumlah = 0;
	cout << " Masukkan elemen matriks pertama: \n";
 	for(i = 0; i < m; i++){
      for(j = 0; j < n; j++){
      	cout<<" Masukkan matriks ["<<i<<"]["<<j<<"] : ";
        cin >> matriks1[i][j];
      }
    }
    cout << " Masukkan elemen matriks kedua: \n";
    for(i = 0; i < m; i++){
      for(j = 0; j < n; j++){
        cout<<" Masukkan matriks ["<<i<<"]["<<j<<"] : ";
        cin >> matriks2[i][j];
      }
    }
    for(i = 0; i < m; i++){
      for(j = 0; j < n; j++){
        for(k = 0; k < m; k++){
          jumlah = jumlah + matriks1[i][k] * matriks2[k][j];
        }
        hasil[i][j] = jumlah;
        jumlah = 0;
      }
    }
    cout << " Hasil perkalian matriks: \n";
    for(i = 0; i < m; i++){
      for(j = 0; j < n; j++){
        cout <<" "<< hasil[i][j] << "\t";
      }
      cout << endl;
    }
}


int main(){
	PerkalianMatriks();
	return 0;
}
