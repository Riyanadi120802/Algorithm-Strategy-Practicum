#include <iostream>
using namespace std;

class Postest{
	public:
		void merge(int arr[], int l, int m, int r);
		void mergeSort(int arr[], int l, int r);
		void show(int A[], int size);
	private:
		int arr[], l, m, r, i;	

};
void Postest::merge(int arr[], int l, int m, int r){
	    int i, j, k;
	    int n1 = m - l + 1;
	    int n2 = r - m;
	    int L[n1], R[n2];

	    for (i = 0; i < n1; i++)
	        L[i] = arr[l + i];
	    for (j = 0; j < n2; j++)
	        R[j] = arr[m + 1 + j];
	
	    i = 0;
	    j = 0;
	    k = l;
	    while (i < n1 && j < n2){
	        if (L[i] <= R[j]){
	            arr[k] = L[i];
	            i++;
	        }
	        else
	        {
	            arr[k] = R[j];
	            j++;
	        }
	        k++;
	    }
	    while (i < n1){
	        arr[k] = L[i];
	        i++;
	        k++;
	    }
	
	    while (j < n2){
	        arr[k] = R[j];
	        j++;
	        k++;
	    }
	}
void Postest::mergeSort(int arr[], int l, int r){
	    if (l < r){
	        int m = l + (r - l) / 2;
	
	        mergeSort(arr, l, m);
	        mergeSort(arr, m + 1, r);
	
	        merge(arr, l, m, r);
	    }
	}
	
void Postest::show(int A[], int size){
	    cout << "Hasil\n";
	    for (i = 0; i < size; i++)
	        cout << A[i] << " ";
	}
	
	int main(){
		Postest Riyan;
	    int size;
	    cout << "\nMasukan Banyak Data : ";
	    cin >> size;
	    int arr[size];
	
	    for (int i = 0; i < size; ++i){
	        cout << "\nMasukan Data ke- "<<i+1<<" :";
	        cin >> arr[i];
	    }
	    Riyan.mergeSort(arr, 0, size);
	    Riyan.show(arr, size);
	    return 0;
	}
