#include<iostream>
using namespace std;

int main(){
int arr[10]={1,2,3,4,5,6,7,8,9,11};
int key;
cout<<"Key :";
cin>>key;
int l=0,r=9,m;
while(l<=r){
    m=(l+r)/2;
    if(arr[m]==key){
        cout<<"Value found";
    }
    else if(arr[m]>key){
        r=m-1;
    }
    else if(arr[m]<key){
        l=m+1;
    }
}
return 0;
}
