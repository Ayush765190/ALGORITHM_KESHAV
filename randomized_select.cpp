#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;



void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int *arr,int s ,int l){ //


 int random_index =  (rand() % (l - s + 1)) + s ;

    swap(arr[random_index],arr[l]);

    int x = arr[l];
    int i = s-1;

    for(int j=s;j<l;j++){              // 1 2 3 4 5 6 7
        if(arr[j]<=x){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[l]);

    return i+1;

}


int randomized_select(int *arr,int s,int l,int k){

    if(s==l){
        return arr[l];
    }

  int position_of_pivot =  partition(arr,s ,l);
  int rel =  position_of_pivot-s+1;


  if(k == rel){

    return arr[position_of_pivot];

  }else if(rel>k){

  //left subarray
  return randomized_select(arr,s,position_of_pivot-1,k);

  }else{
  return randomized_select(arr,position_of_pivot+1,l,k-rel);
  //right subarray
  }


}


int main()
{


  cout<<"Enter the number of elements to be entered : ";
  int n=0;
  cin>>n;

  int *arr = new int[n];

  for(int i=0;i<n;i++){
    cout<<"enter the value : ";
    int temp=0;
    cin>>temp;

    arr[i]=temp;

  }
   srand(time(NULL));



cout<<"enter the k : ";
int k=0;
cin>>k;
 cout<<"result : "<<randomized_select(arr,0,n-1,k-1);


    return 0;
}

