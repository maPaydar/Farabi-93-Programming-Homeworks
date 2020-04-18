
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int num;
	cin >> num;
	int temp = num;
	int count = 0;
	int unit;
	
	for (int i =1;i >= 1;i++)
	{
        temp /= 10;
        count++;
        if(temp == 0)
        {
                break;
        }
    }
    int arr[count];
    
    for(int j = 0;j < count;j++)
    {
        unit = num % 10;
        num /= 10;
        arr[j] = unit;
        if(num == 0)
           break;    
    }
    for(int k = 0;k < (count/2);k++)
    {
            if(arr[k]==arr[count - k - 1])
            {    
                cout << "Yes" << endl;
                break;
            }    
            else
            {
                cout << "No" << endl;
                break;    
            }
    }
	system("PAUSE");
}

