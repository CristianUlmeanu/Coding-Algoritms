#include <stdio.h>
#include <stdlib.h>
//PROBLEMA 3

int n , *s;

int valid(int k)
{
    for(int i = 1 ; i < k ; i++)
        if(s[i] == s[k])
            return 0;
    return 1;
}

int OK(int k)
{
    for(int i = 1 ; i < k ; i++)
        if(abs(s[i]-s[i+1]) < 2)
            return 0;
    return 1;
}

void bk(int k, FILE *g)
{
    for(int i = 1 ; i <= n ; i++)
        {
            s[k] = i;
            if(valid(k))
                if(k == n && OK(k)){
    for(int i = 1 ; i <= k ; i++)
         fprintf(g,"%d ",s[i]);
         fprintf(g,"\n");}
                else bk(k+1,g);
        }
}

int main()
{
    FILE *f=fopen("p3.in","w");
    FILE *g=fopen("p3.out","w");
    fprintf(f,"%d",rand()*rand()%6 + 4);
    fclose(f);
    f=fopen("p3.in","r");
    fscanf(f,"%d",&n);
    fclose(f);
    s = (int*)malloc((n+1)*sizeof(int));
    bk(1,g);
    fclose(g);
    return 0;
}
