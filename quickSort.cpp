#include<iostream>
#include<stdlib.h>
using namespace std;

void swap(int *x,int *y){
	int temp;
	temp = *x;
	*x=*y;
	*y=temp;
	
}
int count =0;


int partition(int arr[],int s,int e){
	int pivot=arr[e];
	int Pindex=s;
	
	for(int i=s; i<e; i++){
		if(arr[i]<pivot){
			//swap(&arr[i],&arr[pivot]);
			int temp= arr[i];
			arr[i]=arr[Pindex];
			arr[Pindex]=temp;
			Pindex++;
			count++;
		}
	}
	//sawp(&arr[e] , &arr[Pindex]);
	int temp= arr[e];
	arr[e]=arr[Pindex];
	arr[Pindex]=temp;
	count++;
	return Pindex;
	
	
}
randomPartition(int arr[],int s,int e){
	int pvt,n;
	n=rand();
//	cout<<"\nn is:"<<n;
	pvt=s + n%(e-s+1);
	
	//swap(&arr[e],&arr[pvt]);
	
	int temp= arr[e];
	arr[e]=arr[pvt];
	arr[pvt]=temp;
	//cout<<"\nyour random pivot is : "<<pvt<<endl;
	return partition(arr,s,e);
	
}

void quickSort(int arr[],int s,int e){
	if(s<e){
		int p = randomPartition(arr,s,e);
		quickSort(arr,s,(p-1));
		quickSort(arr,(p+1),e);
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
	cout<<"\narray before sorting USING QUICK SORT "<<endl;
		for(int g=0; g<size; g++){
		cout<<array[g]<<" ";
	}
	quickSort(array,0,(size-1));
	cout<<"\nafter sorting "<<endl;
		for(int g=0; g<size; g++){
		cout<<array[g]<<" ";
	}
	
	cout<<"\ntotal number of comparison is : "<<count;
	return 0;
	
}
