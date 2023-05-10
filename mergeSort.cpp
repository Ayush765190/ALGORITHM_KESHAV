#include<iostream>
using namespace std;

int count=0;


void merge(int arr[],int l,int m,int r,int size){
	int i=l;
	int j=m+1;
	int k=l;
	
	
	//int size=r-l+1;
	
	int temp[size];
	
	while(i<=m && j<=r){
		if(arr[i]<=arr[j]){
			temp[k]=arr[i];
			i++;
			k++;
			count++;
		}
		else{
			
			temp[k]=arr[j];
			j++;
			k++;
			count++;
		}
	}
	while(i<=m){
		temp[k]=arr[i];
		i++;
		k++;
		//count++;	
	}
		
	while(j<=r){
		temp[k]=arr[j];
		j++;
		k++;
		//count++;	
	}
		
	for(int g=l; g<=r; g++){
		arr[g]=temp[g];
	}
}

void mergeSort(int arr[],int l,int r,int size){
	
	if(l<r){
		
		int m=(l+r)/2;
		mergeSort(arr,l,m,size);
		mergeSort(arr,m+1,r,size);
		merge(arr,l,m,r,size);
	}
}

int main(){
	
	int SIZE=100;
	
	int size=0;
//	cout<<"enter the size of array : ";
//	cin>>size;
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
	cout<<"before sorting "<<endl;
	for(int i=0; i<size; i++){
		cout<<array[i]<<" ";
	}
	
	cout<<endl;
	
	mergeSort(array,0,(size-1),size);
	
	cout<<"after sorting USING MERGE SORT "<<endl;
	
	for(int i=0; i<size; i++){
		cout<<array[i]<<" ";
	}
	cout<<"\ntotal number of comparison : "<<count;
	return 0;
	
}




