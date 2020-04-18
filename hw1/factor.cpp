#include <iostream>
using namespace std;

int main()
{
	int firstNum;
	cin >> firstNum;
	//"unit" means the parts of number that are seprated...
	//"rest" means the other part of firstNum that are rested...
	int unit1 = firstNum%10;
	int rest1 = firstNum/10;
	int unit2 = rest1%10;
	
	
	int rest2 = rest1/10;
	int unit3 = rest2%10;
	
	
	int rest3 = rest2/10;
	int unit4 = rest3%10;
	
	
	int rest4 = rest3/10;
	int unit5 = rest4%10;

	cout << unit5 << endl;
	cout << unit4 << endl;
	cout << unit3 << endl;
	cout << unit2 << endl;
	cout << unit1 << endl;
	system("PAUSE");
	return EXIT_SUCCESS;
	
}

