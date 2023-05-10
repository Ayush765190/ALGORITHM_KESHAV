#include <iostream>
using namespace std;

int count=0;


void insertionSort(int arr[],int size) {
  int key;
  int j = 0;
  for (int i = 1; i <size; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
      count++;
    }
    arr[j + 1] = key;
  }

}

int main() {
    int SIZE=100;
	
	int size=0;
	int array[SIZE];
    cout<<"\nenter elements in any order "<<endl;
    for(int g=0; g<SIZE; g++){
            if(cin>>array[g]){
                size++;
            }
            else{
                break;
            }
        }

    cout<<"\narray before sorting USING QUICK SORT "<<endl;
		for(int g=0; g<size; g++){
		cout<<array[g]<<" ";
	}

    insertionSort(array,size);

    cout<<"\nafter sorting "<<endl;
		for(int g=0; g<size; g++){
		cout<<array[g]<<" ";
	}
    cout<<"\ntotal number of comparison is : "<<count;

  return 0;
}