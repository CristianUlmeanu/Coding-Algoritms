#include <stdio.h>
#include <stdlib.h>

// Problema 1

int n,m, t[100][100], lmax[100], pred[100];

void afisare(int i, int j, FILE* g)
{
 if(i != -1)
 {
 afisare(pred[i],j,g);
 fprintf(g,"%d ", t[i][j]);
 }

}

int main()
{
 int i, j, k, pmax;
 FILE* g = fopen("P_1.out", "w");
 FILE* f = fopen("P_1.in", "r");
 fscanf(f, "%d %d", &n, &m);
 for(i = 0; i < n ; i++)
    {for(j=0;j<m;j++)
 fscanf(f, "%d", &t[i][j]);}
 fclose(f);
for(j=0;j<m;j++)
 {if(j)
 fprintf(g,"\n");
 lmax[0] = 1;
 pred[0] = -1;
 for (i = 1; i < n; i++)
 {
 lmax[i] = 1;
 pred[i] = -1;
 for (k = 0; k < i; k++)
 if (t[i][j] >= t[k][j] && 1 + lmax[k] > lmax[i])
 {
 lmax[i] = 1 + lmax[k];
 pred[i] = k;
 }
 }
 pmax = 0;
 for (i = 1; i < n; i++)
 if(lmax[i] > lmax[pmax])
 pmax = i;
 fprintf(g,"Subsirul crescator pe coloana %d maxim este:\n",j);
 afisare(pmax,j,g);
 }

 return 0;
}
