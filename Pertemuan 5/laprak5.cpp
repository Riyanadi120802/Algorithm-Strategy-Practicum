#include <bits/stdc++.h>
#define maks 20
using namespace std;

class Postest{
	public :
		int arr[maks], n;
		void swap(int * , int *); 
		void Input();
		void selectionSort(int arr[], int );
		void printArray(int arr[], int size);
};
void Postest::swap(int *xp, int *yp){
    int temp = *xp; *xp = *yp; *yp = temp;
}

void Postest::Input(){
	cout<<"Masukkan batas Array : "; cin>>n;
	for(int i=0; i<n; i++){
		cout<<"Masukkan array indeks ke-"<<i<<" : ";
		cin>>arr[i];
	}
}
void Postest::selectionSort(int arr[], int n){
    int i, j, min_idx;
    // Satu per satu batas gerakan dari subarray yang tidak disortir
    for (i = 0; i < n-1; i++){
        // Mencari elemen minimum dalam array yang tidak disortir
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
        min_idx = j;
        // Tukar elemen minimum yang ditemukan dengan elemen pertama
        swap(&arr[min_idx], &arr[i]);
    }
}
/* fungsi untuk mencetak array */
void Postest::printArray(int arr[], int size){
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
        cout << endl;
}

// Program utama untuk menguji fungsi-fungsi di atas
int main(){
	Postest Riyan;
	Riyan.Input();
	Riyan.selectionSort(Riyan.arr, Riyan.n);
	Riyan.printArray(Riyan.arr, Riyan.n);
    return 0;
}
