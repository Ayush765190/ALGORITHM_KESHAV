#include <iostream>

using namespace std;

class interval{

public:

    int weight;
    int start;
    int finish;
    int number;

    interval(){
    start =0;
    finish = 0;
    weight = 0;
    number = 0;
    }

    void set_data(int s,int f,int w,int num){

    start =s;
    finish = f;
    weight = w;
    number = num;

    }
};
int memoization(int j,int *m ,int size){

    if(j=0){
        return 0;
    }else if(m[j] != 0){

    return m[j];
    }else{

    }

}

int p(int i, int size,interval *interval_list){

    for(int j=i-1;j>=0;j--){

        if(interval_list[j].finish <= interval_list[i].start ){
                     return j;
        }
    }
    return 0;

}
void weighted_interval_scheduling(int size,interval *interval_list){

int *m = new int[size+1];  
int *pp = new int[size+1];  

for(int j=1;j<=size;j++){

    pp[j] =p(j, size, interval_list);
    m[j] = max(interval_list[j].weight + m[pp[j]] , m[j-1]);
}

for(int j=size;j>=1;){ 

    if( interval_list[j].weight+ m[pp[j]] >= m[j-1]){
        cout<<" item added to optimal solution is : "<<j<<endl;
         j = pp[j];
    }else{
         j--;
    }
}
}

int  weighted_interval_recursive(int size,interval *interval_list,int n){

int *pp = new int[size+1];  
for(int j=1;j<=size;j++){

    pp[j] =p(j, size, interval_list);
}

if(n==0){
    return 0;
}
  return max( interval_list[n].weight + weighted_interval_recursive(size,interval_list,pp[n]),weighted_interval_recursive(size,interval_list,n-1));

}

int mm[100];

int  weighted_interval_recursive(int size,interval *interval_list,int n, int *pp){


if(n==0){
    return 0;
}

if(mm[n]==-1)
  return  mm[n] = max( interval_list[n].weight + weighted_interval_recursive(size,interval_list,pp[n],pp),weighted_interval_recursive(size,interval_list,n-1,pp));
else
    return mm[n];
}
int main()
{

    int size =0;

    cout<<"enter the number of intervals : ";
    cin>>size;

    interval *interval_list = new interval[size+1];

    for(int i=1;i<=size;i++){

        cout<<"enter start time,end time and finish time : ";
        int s=0,f=0,w=0;
        cin>>s>>f>>w;

        interval_list[i].set_data(s,f,w,1);
    }
    weighted_interval_scheduling(size,interval_list);
    
    return 0;
}
