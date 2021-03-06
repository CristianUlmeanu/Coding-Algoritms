#include <iostream>
using namespace std;

// PROBLEMA 1

void divide(int etaj_max, int st, int dr)
{
int mij;
mij=(st+dr)/2;
cout<<mij<<endl;
if(mij==etaj_max)
    cout<<"Asta e etajul maxim de la care poate sa arunce sticla:"<<etaj_max<<endl;
if(mij<etaj_max)
        {cout<<"Se afla prea jos"<<endl;
        divide(etaj_max,mij+1,dr);}
if(mij>etaj_max)
        {cout<<"Se afla prea sus"<<endl;
        divide(etaj_max,st,mij-1);}
}

int main()
{
    int etaj_max;
    int n;
    cin >> n;
    etaj_max = 7;//(rand()*rand()) % n;
    divide(etaj_max, 0, n);
    return 0;
}
