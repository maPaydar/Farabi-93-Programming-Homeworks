// The author is Amin Paydar//


#include <iostream>
using namespace std;

void khayam(int n, int* &zarib)
{ 

	zarib = new int[n];
	int newtemp, temp;
	zarib[0] = 1;
	for (int j = 1; j<n; j++)
	{
		temp = zarib[0];
		for (int k = 1; k < j;k++)
		{
			newtemp = zarib[k];
			zarib[k] = temp + zarib[k];
			temp = newtemp;
		}
		zarib[j] = 1;
	}
}
void states()
{
	int n;
	cin >> n;
	int * array = new int[n + 1];
	khayam(n + 1, array);
	int a = n;
	int b = 0;
	for (int k = 0; k < n+1; k++)
	{
			cout << array[k];
			if (b == 0)
			{
				cout << 'a' << a << '+';
			}
			else if (a == 0)
			{
				cout << 'b' << b << endl;
			}
			else 
			{
				cout << 'a' << a << 'b' << b << '+';
			}
			a--;
			b++;
	}
}
int main()
{	
	states();
	system("PAUSE");
	return 0;
}

