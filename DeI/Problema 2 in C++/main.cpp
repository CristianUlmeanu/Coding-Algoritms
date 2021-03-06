#include <iostream>
#include <cstdlib>
using namespace std;

//PROBLEMA 2

struct student
{
    int nr_ordine;
    int h;
};

void interclasare(student v[], int st, int mij, int dr)
{
    int i,j,k=0;
    i=st;
    j=mij+1;
    student *aux=new student[dr-st+1];
    while ((i<=mij)&&(j<=dr))
        if (v[i].h<=v[j].h)
            {aux[k]=v[i];
            k++;
            i++;}
        else
        {aux[k]=v[j];
        k++;
        j++;}
    while (i<=mij)
        aux[k]=v[i];
        {k++;
        i++;}
    while (j<=dr)
        {aux[k]=v[j];
        k++;
        j++;}
    k=0;
    for (i=st;i<=dr;i++)
        {v[i]=aux[k];
        k++;}
    free(aux);
}

void mergesort(student v[], int st, int dr)
{
    if (st<dr)
    {
        int mij = (st + dr)/2;
        mergesort(v, st, mij);
        mergesort(v, mij+1, dr);
        interclasare(v, st, mij, dr);
    }
}

int main()
{
    int n,inaltime;
    cin >> n;
    student *v = new student[n];
    for (int i=0;i<n;i++) {
        cout << "Inaltime student "<<i+1<<" ";
        cin >> inaltime;
        v[i].nr_ordine = i+1;
        v[i].h =inaltime;
        cout << endl;
    }
    mergesort(v,0,n-1);
    for (int i = 0;i<n;i++)
        cout <<v[i].nr_ordine<<" ";
    return 0;
}
