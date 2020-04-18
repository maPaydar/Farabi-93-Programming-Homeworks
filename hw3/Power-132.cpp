// The author is Amin Paydar//

#include <iostream>
using namespace std;


int main()
{
	int* power5 = NULL;
	int n;
	int unit = 0;
	int rest;
	cin >> n;
	power5 = new int[n];
	power5[n - 1] = 1;

	for (int i = 0; i < n-1; i++)
	{
		power5[i] = 0;
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			power5[j] *= 5;

			for (int k = n - 1; k >= 0; k--)
			{
				if (power5[k] > 10)
				{
					unit = power5[k] % 10;
					rest = power5[k] / 10;
					power5[k] = unit;
					power5[k - 1] = power5[k - 1] + rest;
				}
			}
		}
	}
	cout << "0.";
	for (int j = 0; j < n; j++)
	{
		cout << power5[j];
	}
	system("PAUSE");
    return 0;
}

