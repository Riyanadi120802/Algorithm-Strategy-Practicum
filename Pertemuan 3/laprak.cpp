#include <iostream>
using namespace std;

class Postest{
public:
	int himp_koin[100], banyak;
    void urutan(int a[], int size);
    void input();
    void output();
    void tukar();
private:
	int hasil[20], nilai_tukar, nilai_sisa;
};
void Postest::urutan(int a[], int size){
    int koin, simpan, j;
    for (koin = 1; koin <= size - 1; koin++){
        for (j = 0; j <= size - 2; j++){
            if (a[j + 1] < a[j + 2]){
                simpan = a[j + 1];
                a[j + 1] = a[j + 2];
                a[j + 2] = simpan;
            }
        }
    }
}
void Postest::input(){

    cout << " Masukkan banyak Koin : ";
    cin >> banyak;
    for (int i = 1; i <= banyak; i++){
        cout << " Masukkan tipe koin : ";
        cin >> himp_koin[i];
    }
}
void Postest::output(){
    int j = 1;
    while (j <= banyak){
        cout << " Koin " << j << " " << himp_koin[j] << endl;
        j++;
    }
}
void Postest::tukar(){
    cout << ("\n Masukan Nilai yang dipecah : ");
    cout << " ";
    cin >> nilai_tukar;
    cout << ("\n");
    for (int i = 1; i <= banyak; i++){
        hasil[i] = nilai_tukar / himp_koin[i];
        nilai_tukar = nilai_tukar % himp_koin[i];
        nilai_sisa = nilai_tukar % himp_koin[i];
    }
    for (int i = 1; i <= banyak; i++){
        cout << " Keping " << himp_koin[i] << "-an sebanyak :" << hasil[i];
        cout << "\n \n";
    }
    cout << " kurangnya adalah : " << nilai_sisa;
}

int main(int argc, char const *argv[]){

    Postest Riyan;
    Riyan.input();
    Riyan.urutan(Riyan.himp_koin, Riyan.banyak);
    Riyan.output();
    Riyan.tukar();
    return 0;
}
