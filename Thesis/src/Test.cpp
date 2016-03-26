#include<stdio.h>
int main()
{
    FILE *fp=fopen("form.txt","r");
    if(fp!=NULL)
    {
        char c;
        do
        {
            c = fgetc (fp);
            printf("%c",c);
        }
        while (c != EOF);
    }
    return 0;
}
