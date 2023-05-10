#include <bits/stdc++.h>

using namespace std;


void insertion_sort(int *arr,int size){

    for(int i=1;i<size;i++){
        int curr =arr[i];
        int j = i-1;
        int k=i;

        while(j>=0 && arr[j] > curr){
            //if current is larger smaller than previous than
            //shift previous  to current
            arr[k] = arr[j];
            k--;
            j--;

        }
        arr[k] = curr;


    }

}


class bucket{
int *buc;
int n;
int curr;

public:
    bucket(){
    }


    bucket(int s){ //size of 1 bucket
      n=s;
      buc = new int[n];
      curr=0;
    }


    void print(){

    for(int i=0;i<curr;i++){
        cout<<buc[i]<<" , ";
    }
    }

    void sort_me(){
        if(curr>1)
        insertion_sort(buc,curr);
    }

    void set_data(int s){
        n=s;
      buc = new int[n];
      curr=0;

    }

    void add(int data){
    buc[curr] =data;
    curr++;
    }

    int *get_arr(){
    return buc;
    }

    int no_of_data_entered(){
    return curr;
    }





};





int max(int *arr,int size){
   int ans = arr[0];
   for(int i=1;i<size;i++){
    if(ans<arr[i]){
        ans = arr[i];
    }
   }
   return ans;
}

int min(int *arr,int size){
   int ans = arr[0];
   for(int i=1;i<size;i++){
    if(ans>arr[i]){
        ans = arr[i];
    }
   }
   return ans;
}


void print(bucket *buckets,int no_bucket){

for(int i=0,j=0;i<no_bucket;i++){

    cout<<"bucket no. "<<i<<"contains : ";
    buckets[i].print();
    cout<<endl;

}

}

void print_arr(int *arr,int size){
for(int i=0;i<size;i++){
    cout<<arr[i]<<" , ";
}
}

void bucket_sort(int *arr,const int size,bucket *buckets,int size_of_bucket,int no_bucket,int start){


for(int i=0;i<size;i++){
    buckets[ ((arr[i]-start)/size_of_bucket)].add(arr[i]);
}

for(int i=0;i<no_bucket;i++){
    buckets[i].sort_me();
}


print(buckets,no_bucket);

//conqour all the buckets

int countt=0;
for(int i=0;i<no_bucket;i++){
      const  int *temp = buckets[i].get_arr(); //

    for(int j=0;j<buckets[i].no_of_data_entered();j++){
        arr[countt] = temp[j];
        countt++;
    }
}
cout<<endl;
cout<<"RESULT : ";
print_arr(arr,size);

cout<<endl;


}






int main()
{

   cout<<"enter the number of buckets to be used : ";
   int no_bucket=0;
   cin>>no_bucket;

   cout<<"Enter the number of elements to be sorted : ";
   int size=0;
   cin>>size;


   int *arr = new int[size];

   for(int i=0;i<size;i++){
    cout<<"enter the element:  ";
    cin>>arr[i];
   }


   int start =min(arr,size);
    int size_of_bucket = ceil((max(arr,size) - min(arr,size) +1)*1.0 /no_bucket*1.0);

    cout<<"size of bucket : "<<size_of_bucket<<endl;

   bucket *arr_bucket = new bucket[no_bucket];

   for(int i=0;i<no_bucket;i++){
    arr_bucket[i].set_data(size_of_bucket);
   }

   bucket_sort(arr,size,arr_bucket,size_of_bucket,no_bucket,start);



    return 0;
}
