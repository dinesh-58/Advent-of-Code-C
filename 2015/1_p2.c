#include<stdio.h>
#include<string.h>
void main()
{
    int i,floor=0;
    char a[7009];
    FILE *f=fopen("1input.txt","r");
    fgets(a,7001,f);   
    for(i=0;i<strlen(a);i++){
        if(a[i]=='(') floor++;
        else if(a[i]==')') floor--;
        if (floor==-1) break;
    }            
    printf("Santa arrives at floor %d at position %d",floor,i);
    fclose(f);
}