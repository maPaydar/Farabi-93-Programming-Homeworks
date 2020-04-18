//THE AUTHOR IS AMIN PAYDAR//
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	int arr[1000];
	int k = 0;
	int size = 0;
	int temp;

	while (fin >> arr[k])
	{
		size++;
		k++;
	}
	
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[i]<arr[j])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	
	for (int j = 0; j < size; j++)
	{
		fout << arr[j] << endl;
	}
	fout.close();
    system("PAUSE");
	return 0;
}

