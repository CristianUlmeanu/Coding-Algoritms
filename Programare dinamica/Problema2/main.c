#include <stdio.h>
#include <stdlib.h>

// Problema 2

int n,m, t[100], lmax[100], pred[100], a[100];

void afisaresir(int i, FILE* g)
{
 if(i != -1)
 {
 afisaresir(pred[i],g);
 fprintf(g,"%d ", t[i]);
 }
}
void vector(int i)
{
    if(i != -1)
    {
        a[i]=1;
        vector(pred[i]);
    }
}
void afisare(int i, FILE*g)
{
    if(i<n)
    {if(a[i]==0)
        {
            fprintf(g,"%d ",i);
        }
        afisare(i+1,g);
    }
}

int main()
{
 int i, k, pmax;
 FILE* g = fopen("P_2.out", "w");
 FILE* f = fopen("P_2.in", "r");
 fscanf(f, "%d", &n);
 for(i = 0; i < n ; i++)
 fscanf(f, "%d", &t[i]);
 fclose(f);
 for(i = 0; i < n ; i++)
    {a[i]=0;}

 lmax[0] = 1;
 pred[0] = -1;
 for (i = 1; i < n; i++)
 {
 lmax[i] = 1;
 pred[i] = -1;
 for (k = 0; k < i; k++)
 if (t[i] <= t[k] && 1 + lmax[k] > lmax[i])
 {
 lmax[i] = 1 + lmax[k];
 pred[i] = k;
 }
 }

 pmax = 0;
 for (i = 1; i < n; i++)
 if(lmax[i] > lmax[pmax])
 pmax = i;
 vector(pmax);
 fprintf(g,"Subsirul descrescator maximal al copacilor este:");
 afisaresir(pmax,g);
 fprintf(g,"\nCopacii de pe pozitiile marcate cu 1 fac parte din subsirul maximal al copacilor iar cele cu 0 nu: ");
 for(i=0;i<n;i++)
 fprintf(g,"%d ",a[i]);
 fprintf(g,"\nCopacii de pe pozitiile urmatoare trebuite taiati:");
 afisare(0,g);
 /*Am creat subsirul descrescator maximal te copaci deoarece sirul descrescator care contine cei mai multi copaci inseamna ca sunt cei mai putini
 copaci lasati pentru taiere*/
 return 0;
}
