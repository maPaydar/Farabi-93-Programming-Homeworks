// THE AUTHOR IS AMIN PAYDAR//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string* inter = new string[n];
	for (int m = 0; m < n; m++)
	{
		cin >> inter[m];
	}
	string sw[100];
	string hw[100];
	string it[100];
	ifstream finSw;
	ifstream finHw;
	ifstream finIt;
	int examiner1;
	int examiner2;
	int examiner3;
	finSw.open("software.txt");
	finHw.open("hardtware.txt");
	finIt.open("IT.txt");
	
	int i = 0, j = 0, k = 0;

	while (finSw >> sw[i])
	{
		i++;
	}
	
	while (finHw >> hw[j])
	{
		j++;
	}

	while (finIt >> it[k])
	{
		k++;
	}	
	
	for (int z = 0; z < n; z++)
	{
		examiner1 = 0;
	    examiner2 = 0;
		examiner3 = 0;

		for (int y = 0; y < 100; y++)
		{
			if (inter[z] == sw[y])
			{
				cout << "Software" << endl;
				examiner1++;
				break;
			}
		}

		for (int y = 0; y < 100; y++)
		{
			if (inter[z] == hw[y])
			{
				cout << "Hordware" << endl;
				examiner2++;
				break;
			}
		}

		for (int y = 0; y < 100; y++)
		{
			if (inter[z] == it[y])
			{
				cout << "IT" << endl;
				examiner3++;
				break;
			}
		}
		if (examiner1 == 0 && examiner2 == 0 && examiner3 == 0)
		{
			cout << "Not found" << endl;
		}		
	}
	system("PAUSE");
	return 0;
}

