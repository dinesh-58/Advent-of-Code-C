#include<stdio.h>
#include<string.h>
void main()
{
    signed char c;     //signed needed for EOF to work properly
    FILE *fp=fopen("2 input.txt","r");
    unsigned int n[3]={0,0,0},surface[3]={0,0,0},i,j=0,temp;
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
            surface[0]=n[0]*n[1], surface[1]=n[1]*n[2], surface[2]=n[2]*n[0];
            for(i=0;i<2;i++) //sorting areas in ascending order because we 
            //multiply smallest area by 3 & other areas by 2.
            {
                for(j=0;j<2;j++)
                {
                    if(surface[j]>surface[j+1]){
                        temp=surface[j];
                        surface[j]=surface[j+1];
                        surface[j+1]=temp;
                    }
                }
            }
            total+=(3*surface[0])+(2*surface[1])+(2*surface[2]);
            n[0]=0, n[1]=0, n[2]=0, j=0;
        }
        else
        {
            n[j]=n[j]*10+((int)c-48);
        }        
    } 
    printf("s1:%d\ts2:%d\ts3:%d",surface[0],surface[1],surface[2]);
    printf("The elves need a total of %d sq. feet of wrapping paper",total);
    fclose(fp);
}