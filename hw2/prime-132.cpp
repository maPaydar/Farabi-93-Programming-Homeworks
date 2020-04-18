#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   
    int num;
    int m_count = 0;
    int count =0;
    bool truePrime;
    cin >> num;
    
    for(int j = 2; j < num; j++)
    {
            truePrime = true;
            for(int i = 2; i <= sqrt(j) ; i++)
            {
              
                     if( j % i == 0)
                       {
                           truePrime = false;
                           break;
                       }
            }
            if(truePrime == true)
            {
                  m_count++;
            }  
    }
    cout << m_count << endl;       
    system("PAUSE");

}
