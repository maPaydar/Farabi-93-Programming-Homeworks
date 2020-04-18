#include <iostream>
using namespace std;

int main() 
{
	int x,y,z,n;
	float ave;
	int max;
	int min;	
	cin >> x >> y >> z >> n;	
	ave = (x+y+z+n)/4.0;	

	cout << x+y+z+n << endl;
	cout << x*y*z*n << endl;
	cout << ave << endl;
    
    min = x;
	if(y<min){
		min = y;
	}
    if(z<min){		
		min = z;
	}
	if(n<min){
		min = n;
	}	
	cout << min << endl;	

	max = x;
	if(y>max){
		max = y;
	}
    if(z>max){		
		max = z;
	}
	if(n>max){
		max = n;
	}	
	cout << max << endl;			
	system("PAUSE");
	return EXIT_SUCCESS;
}
