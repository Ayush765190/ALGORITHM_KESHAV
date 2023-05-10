#include<iostream>
using namespace std;

void countingSort(int inp_arr[],int s,int r)
{
	int out_arr[s];
	int count_arr[r+1];
	
	for(int i=0; i<=r; i++){
		count_arr[i]=0;
		
	}
	for(int i=0; i<s; i++){
		count_arr[inp_arr[i]] =count_arr[inp_arr[i]]+1 ;
	}
	for(int i=1; i<=r; i++){
		count_arr[i]=count_arr[i] + count_arr[i-1];
		
	}
	
	for(int i=(s-1); i>=0; i--){
		out_arr[count_arr[inp_arr[i]]-1] = inp_arr[i];
		count_arr[inp_arr[i]]=count_arr[inp_arr[i]]-1;
	}
	for(int i = 0; i<s; i++){
		inp_arr[i]= out_arr[i];
	}
	cout<<endl;
}
int main(){
	int SIZE=100;
	
	int size=0;
	int range;
	cout<<"\nenter the range of the inputs : ";
	cin>>range;
	int array[SIZE];
	cout<<"\nenter positive number in any order "<<endl;
	for(int g=0; g<SIZE; g++){
		if(cin>>array[g]){
			size++;
		}
		else{
			break;
		}
	}

	cout<<"\narray before sorting USING COUNT SORT "<<endl;
		for(int g=0; g<size; g++){
		cout<<array[g]<<" ";
	}
	countingSort(array,size,range);
	cout<<"\nafter sorting "<<endl;
	for(int g=0; g<size; g++){
		cout<<array[g]<<" ";
	}
	
	return 0;
}
