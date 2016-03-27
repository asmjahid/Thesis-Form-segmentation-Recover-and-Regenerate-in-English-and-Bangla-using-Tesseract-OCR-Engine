#include<stdio.h>
#include<map>
#include<iostream>
using namespace std;
int main(int argc,char *argv[])
{
     wprintf (L"Character: %lc %lc \n", L'ঈ', 2440);
     return 0;
    map<char,int>Freq;
    FILE *fp=fopen(argv[1],"r");
    char ch[200];
    while(!feof(fp))
    {
        fgets(ch,150,fp);
        for(auto x:ch)
        {
            Freq[x]++;

        }
    }
    for(auto x:Freq)
    {
        if(x.first==' ' or x.first=='\n')continue;
        char ch[2];
        ch[0]=x.first;
        ch[1]=NULL;
        printf("\'%s\'",ch);
    }
    cout<<endl;
    for(auto x:Freq)
    {
        cout<<"_  , "<<x.second<<";\n";
    }
    cout<<endl;
    return 0;
}
