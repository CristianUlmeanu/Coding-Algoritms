#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>

using namespace std;

struct melodie
{
    int minut;
    int sec;
};

int cmp (const void *a , const void *b)
{
    melodie *x = (melodie *)a;
    melodie *y = (melodie *)b;
    if(x -> sec > y -> sec)
        return 1;
    else if(x -> sec < y -> sec)
        return -1;
        else return 0;
}
/*void randomgen()
{
    ofstream f("date.in");
    int n;
    srand(time(NULL));
    n = rand() % 10 + 3;
    f << n << endl;
    for(int i = 1 ; i <= n ; i++){
        int min = rand() % 5; // melodie de maxim 4 minute
        int sec = rand() % 60; // maxim 59 secunde
        if(min == sec && sec == 0)
            sec++;
        f << min << " " << sec << endl;}
    f.close();
}*/

int main()
{
    //randomgen();
    ifstream f("date.in");
    int n, s;
    f >> n;
    f.get();
    s = rand() % 3600;
    cout << "Secunde alocate " << s << endl;
    melodie *v = new melodie[n];
    for(int i = 0 ; i < n ; i++)
        f >> v[i].minut >> v[i].sec;
    for(int i = 0 ; i < n ; i++)
        if(v[i].minut > 0)
        {
            melodie aux;
            aux.minut = 0;
            aux.sec = v[i].sec + 60*v[i].minut;
            v[i] = aux;
        }
    qsort(v,n,sizeof(v[0]),cmp);
    for(int i = 0 ; i < n ; i++)
        if(v[i].sec <= s)
            {
                s -= v[i].sec;
                melodie aux;
                aux.minut = v[i].sec / 60;
                aux.sec = v[i].sec - 60 * aux.minut;
                v[i] = aux;
                cout << v[i].minut << " " << v[i].sec << endl;

            }
        else break;
    return 0;
}
