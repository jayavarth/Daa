//Naive search algorithm using c++ language
#include<iostream>
#include<cstring>
using namespace std;
int main(){
char a[]="Computer Science";
char b[]="Science";
int i,j;
int bl=strlen(b);
int al=strlen(a);
int c;
for(i=0;i<=al-bl;i++){
    for(j=0;j<bl;j++){
            if(a[i+j]!=b[j])
                break;}
    c=j==bl;
    if(c)
        cout<<"pattern found at "<<i<<" index";
}
if(c)
    cout<<"\npattern "<<b<<" is present in the text "<<a;
else
    cout<<"pattern not found";
return 0;
}

