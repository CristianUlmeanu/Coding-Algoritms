#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
// PROBLEMA 1

char **v;
int *s;
int n;


int valid (int k)
{
    for(int i = 1 ; i < k ; i++)
        if(s[k] == s[i])
            return 0;
    return 1;
}

void bk(int k, FILE *g)
{
    for(int i = 1 ; i <= n ; i++)
    {
        s[k] = i;
        if(valid(k))
            if(k == 3){
                for(int j = 1 ; j <= 3 ; j++)
                    fprintf(g, "%s ", v[s[j]-1]);
                    fprintf(g,"\n");}
            else bk(k+1,g);
    }
}

int main()
{
    FILE *f=fopen("p1.in","r");
    FILE *g=fopen("p1.out","w");
    fscanf(f,"%d",&n);
    v = (char**)malloc(n*sizeof(char*));
    s = (int*)malloc(n*sizeof(s));
    for(int i = 0 ; i < n ; i++)
    {
        v[i] = (char*)malloc(255*sizeof(char));
        fscanf(f,"%s",v[i]);
    }
    fclose(f);
    bk(1,g);
    fclose(g);
    free(v);
    free(s);
    return 0;
}
