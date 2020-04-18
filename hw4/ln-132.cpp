// THE AUTHOR IS AMIN PAYDAR. //

#include <iostream>
#include <math.h>
using namespace std;

long double ln(double n)
{
    double power =  pow(-1, n + 1) /n ;
	if (n == 1)
	{
		return 1;
	}
	if (n > 1)
	{
		return power + ln(n - 1);
	}
}

int main()
{
	cout << "Ln 2 = " << ln(1000.0) << endl;
	system("PAUSE");
	return 0;
}

