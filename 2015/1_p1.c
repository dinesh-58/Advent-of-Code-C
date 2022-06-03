#include<stdio.h>
#include<string.h>
void main()
{
    int i,floor=0;
    char a[7009]; //in hindsight, no need to declare an array this large. use
    // while(a=fgetc(fp)!=EOF) as used in 2_p1.c
    FILE *f=fopen("1input.txt","r");
    fgets(a,7001,f);  
    for(i=0;i<strlen(a);i++){
        if(a[i]=='(') floor++;
        else if(a[i]==')') floor--;
    }           
    printf("Santa arrives at floor %d",floor);
    fclose(f);
}