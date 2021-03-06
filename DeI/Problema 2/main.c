#include <stdio.h>
#include <stdlib.h>

// PROBLEMA 2

struct student
{
    int nr_ordine;
    int h;
};

void interclasare(struct student v[], int st, int mij, int dr,int n)
{
    int i,j,k=0;
    i=st;
    j=mij+1;
    struct student *aux =malloc(sizeof(*aux));
    while ((i<=mij)&&(j<=dr))
        if (v[i].h<=v[j].h)
            {aux[k] = v[i];
            k++;
            i++;}
        else
            {aux[k]=v[j];
            k++;
            j++;}
    while (i<=mij)
        {aux[k]=v[i];
        k++;
        i++;}
    while (j<=dr)
        {aux[k]=v[j];
        k++;
        j++;}
    k = 0;
    for (i=st;i<=dr;i++)
        {v[i]=aux[k];
        k++;}
    free(aux);
}

void mergesort(struct student v[], int st, int dr, int n)
{
    if (st<dr)
    {
        int mij =(st+dr)/2;
        mergesort(v, st, mij,n);
        mergesort(v, mij+1, dr,n);
        interclasare(v, st, mij, dr,n);
    }
}

int main()
{
    int n,inaltime;
    printf("Nr studenti este:");
    scanf("%d",&n);
    struct student *v = (struct student *) malloc (n * sizeof(struct student));
    for (int i=0;i<n;i++) {
        printf("Inaltime student %d este: ",i+1);
        scanf("%d",&inaltime);
        v[i].nr_ordine =i+1;
        v[i].h = inaltime;
        printf("\n");
    }
    mergesort(v,0,n-1,n);
    for (int i=0;i<n;i++)
        printf("%d",v[i].nr_ordine);
    return 0;
}
