#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;


// PROBLEMA 1

struct film{
    int inceput;
    int final;
};

int cmp (const void *a , const void *b)
{
    film *filma = (film *)a;
    film *filmb = (film *)b;
    if(filma -> final > filmb -> final)
        return 1;
    else if(filma -> final < filmb -> final)
        return -1;
        else return 0;
}


int main()
{
    int n;
    film *v;
    ifstream f("in.txt");
    f >> n;
    v = new film[n];
    for(int i = 0 ; i < n ; i++)
        f >> v[i].inceput >> v[i].final;
    qsort(v,n,sizeof(v[0]),cmp);
    film ant = v[0];
    cout << v[0].inceput << " " << v[0].final << endl;
    for(int i = 1 ; i < n ; i++)
         if(v[i].inceput >= ant.final)
             {
                cout << v[i].inceput << " " << v[i].final << endl;
                ant = v[i];
             }
    return 0;
}
