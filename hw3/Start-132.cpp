// The author is Amin Paydar//


#include <iostream>
using namespace std;

int maxAndis(int n, int arr[])
{
	int max = arr[0];
	int maxAndis = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			maxAndis = i;
		}
	}
	return maxAndis;
}
void sorting(int n,int arr1[],int arr2[],int arr3[])
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		if (arr2[i] < arr1[i])
		{
			temp = arr2[i];
			arr2[i] = arr1[i];
			arr1[i] = temp;
		}
		if (arr3[i] < arr1[i])
		{
			temp = arr3[i];
			arr3[i] = arr1[i];
			arr1[i] = temp;
		}
		if (arr3[i] < arr2[i])
		{
			temp = arr3[i];
			arr3[i] = arr2[i];
			arr2[i] = temp;
		}
	}
}


 void relocating(int n,int arr1[],int arr2[])
 {
	 int temp;
	 for (int i = 0; i < n; i++)
	 {
		 temp = arr2[i];
		 arr2[i] = arr1[i];
		 arr1[i] = temp;
	 }
 }


int main()
{
    system("PAUSE");
	return 0;
}

