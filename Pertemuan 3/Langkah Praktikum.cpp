#include <iostream>
#include <conio.h>
using namespace std;
void sort(int[], int);
int main()
{
        int x[10], i, uang, n, k, hasil[10];
        cout<<("\n Banyak Koin : ");
        cin>>n;
        cout<<("\n \n Masukan Jenis Koin : \n");
        for (i = 1; i <= n; i++){
        	cout<<" ";
            cin>>x[i];
        }
        sort(x, n);
        cout<<("\n Koin yang tersedia : \n");
        for (i = 1; i <= n; i++){
                cout<<x[i];
                cout<<("\n");
        }
        cout<<("\n");
        cout<<("\n Masukan Nilai yang dipecah : ");
        cout<<" ";cin>>uang;
        cout<<("\n");
        for (i = 1; i <= n; i++){
                hasil[i] = uang / x[i];
                uang = uang % x[i];
                k = uang % x[i];
        }
        for (i = 1; i <= n; i++){
                cout<<("Keping %d", x[i]);
                cout<<("-an sebanyak : %d", hasil[i]);
                cout<<("\n \n");
        }
        cout<<("sisanya adalah %d", k);
        getch();
        return 0;
}
void sort(int a[], int size){
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
