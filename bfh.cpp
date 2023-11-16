#include<iostream>
using namespace std;
#define nchar 256

void badmatch(string pattstr,int pattsize,int badchar[nchar]){
    int i;
    for(i=0;i<nchar;i++)
        badchar[i]=-1;
    for(i=0;i<pattsize;i++)
        badchar[(int)pattstr[i]]=i;//ASCII conversion
}

void search(string text,string pattern){
    int m=pattern.size(),n=text.size();

    int badchar[nchar];

    badmatch(pattern,m,badchar);//functional call to find the bad match table for given text and pattern

    int s=0;

    while(s<=(n-m)){
        int j=m-1;

        while(j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0)
        {
            cout << "pattern occurs at shift = " <<  s << endl;

            s += (s + m < n)? m-badchar[text[s + m]] : 1;
        }
        else{
            s += max(1, j - badchar[text[s + j]]);
        }
    }
}
int main(){
string text="TRUSTHARDTOOTHBRUSHES";//declaring the text and pattern initializing the string value to them
string pattern="TOOTH";

search(text,pattern);
return 0;
}
