#include<stdio.h>
#include<string.h>
void main()
{
    signed char c;     //signed needed for EOF to work properly
    FILE *fp=fopen("2 input.txt","r");
    unsigned int n[3]={0,0,0},perimeter[3]={0,0,0},i,j=0,temp;
    unsigned int total=0;
    while((c=fgetc(fp))!=EOF) //while loop works as long as last line of 
    //"2 input.txt" is blank
    //if not, last line's values will not be counted towards total 
    //either add blank line at end or use do-while & initialize c=fgetc(fp)
    //once before loop
    {
        if(c=='x'|| c==' ')
        {
            j++;
            continue;
        }
        else if(c=='\n')
        {
            perimeter[0]=2*(n[0]+n[1]), perimeter[1]=2*(n[1]+n[2]), perimeter[2]=2*(n[2]+n[0]);
            for(i=0;i<2;i++) //sorting perimeters in ascending order 
            {
                for(j=0;j<2;j++)
                {
                    if(perimeter[j]>perimeter[j+1]){
                        temp=perimeter[j];
                        perimeter[j]=perimeter[j+1];
                        perimeter[j+1]=temp;
                    }
                }
            }
            total+=perimeter[0]+(n[0]*n[1]*n[2]);
            n[0]=0, n[1]=0, n[2]=0, j=0;
        }
        else
        {
            n[j]=n[j]*10+((int)c-48);
        }        
    } 
    printf("The elves need a total of %d feet of ribbon",total);
    fclose(fp);
}