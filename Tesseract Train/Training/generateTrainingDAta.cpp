#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	freopen("training.txt","w",stdout);
	for(int i=1;i<=2;i++)
	{
		for(int j=0;j<26;j++)
		{
			char C='A'+j;
			char S='a'+j;
			string CAP="";
			string SMALL="";
			for(int k=1;k<=i;k++)
			{
				CAP+=C;
				SMALL+=S;
			}
			cout<<CAP<<" "<<SMALL<<" ";
			if((j+1)%13==0)cout<<endl;
		}
		for(int j=0;j<10;j++)
		{
			char X='0'+j;
			string Y="";
			for(int k=1;k<=1;k++)
			{
				Y+=X;
			}
			cout<<Y<<" ";
		}
		char X=':';
		string Y="";
		for(int k=1;k<=i;k++)
		{
				Y+=X;
		}
		cout<<Y<<endl;
	}
	return 0;	
}
