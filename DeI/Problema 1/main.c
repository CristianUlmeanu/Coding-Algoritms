#include <stdio.h>
#include <stdlib.h>

// PROBLEMA 1

void divide(int etaj_max, int st, int dr)
{
    int mij;
    mij=(st+dr)/2;
    if (mij==etaj_max)
        {printf("Sticla poate fi aruncata de la etajul:\n");
        printf("%d",mij);}
    if (mij<etaj_max)
        {printf("Arunca de prea de jos\n");
        divide(etaj_max,mij+1,dr);}
    if (mij>etaj_max)
        {printf("Arunca de prea de sus\n");
        divide(etaj_max,st,mij-1);}

}

int main()
{
    int etaj_max,st,dr;
    int n;
    printf("Numarul de etaje este:");
    scanf("%d",&n);
    etaj_max =(rand()*rand()) % n ;
    printf("Etajul maxim ar trebui sa fie: %d\n",etaj_max);
    divide(etaj_max, 0, n);
    return 0;
}
