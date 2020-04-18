#include <iostream>
using namespace std;

int main()
{	
	int firstNum;
	int unit1;///////////////////////unit is any part of fristNum.
	int rest1;//////////////////////rest is reminded number after mod and devide by 10.
	int unit2;
	int rest2;
	int unit3;
	int rest3;
	int unit4;
	int rest4;
	int unit5;
	int rest5;
	int unit6;
	
	cin>>firstNum;	
	unit1=firstNum%10;	
	
	rest1=firstNum/10;
	unit2=rest1%10;	
	
	rest2=rest1/10;
	unit3=rest2%10;	
	
	rest3=rest2/10;
	unit4=rest3%10;

	rest4=rest3/10;
	unit5=rest4%10;
	
	rest5=rest4/10;
	unit6=rest5%10;
	
    int temp1 = unit1*1;
	int temp2 = unit2*7;
	int temp3 = unit3*7*7;
	int temp4 = unit4*7*7*7;
	int temp5 = unit5*7*7*7*7;
	int temp6 = unit6*7*7*7*7*7;
	
	cout << temp1+temp2+temp3+temp4+temp5+temp6 << endl ;	
	
	system("PAUSE");
	return EXIT_SUCCESS;
	
}
