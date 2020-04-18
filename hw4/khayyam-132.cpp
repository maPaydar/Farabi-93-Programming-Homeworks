// THE AUTHOR IS AMIN PAYDAR //
#include <iostream>
using namespace std;

int khayyam(int n,int i)
{
	
    if (n == 2)
    {
        return 1;
    }
    if (i == 1 || i == n)
	{
		return 1;
	}
	
	if (i > 1)
	{
		return khayyam(n - 1, i - 1) + khayyam(n - 1, i);
	}

}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << khayyam(n, i) << " ";
	}
	system("PAUSE");
	return 0;
}

