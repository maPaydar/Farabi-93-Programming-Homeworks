#include <iostream>
using namespace std;

int main()
{
    double pi1 = 0;
    double pi2 = 0;
    double pi;
    double i;
    double j;
    int temp ;
    double temp2;
    for( i = 1.0 ;i < 10000000.0  ;i = i + 4.0)
    {
            pi1 = pi1 + (4.0/i);
            
    }
    for( j = 3.0;j < 10000000.0 ;j = j + 4.0)
    {
            pi2 = pi2 - (4.0/j);
    }
    pi = pi1 + pi2;
    temp = pi*10000;
    temp2 = temp / 10000.0;

    cout << temp2 << endl;
    system("PAUSE");
}
