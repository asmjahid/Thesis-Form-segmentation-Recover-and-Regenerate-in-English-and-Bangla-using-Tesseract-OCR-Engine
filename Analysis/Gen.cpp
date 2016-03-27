#include<stdio.h>
#include<map>
#include<iostream>
using namespace std;
int main(int argc,char *argv[])
{
    map<char,int>Freq;
    FILE *fp=fopen(argv[1],"r");
    char c=fgetc(fp);
    while(c!=EOF)
    {
        Freq[c]++;
        c=fgetc(fp);
    }
    for(auto x:Freq)
    {
        if(x.first==' ' or x.first=='\n')continue;
        cout<<"'"<<x.first<<"',";
    }
    cout<<endl;
    for(auto x:Freq)
    {
        if(x.first==' ' or x.first=='\n')continue;
        cout<<"_  , "<<x.second<<";\n";
    }
    cout<<endl;
    return 0;
}
