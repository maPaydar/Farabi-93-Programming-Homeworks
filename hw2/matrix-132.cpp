#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a = "----";
    string b = "|";
    int row;
    int column;
    int k;
    cin >> row >> column;
    for( k =1; k <= row ; k++)
    {
        for(int i = 0 ; i < column  ; i++)
        {
                cout << a ; 
        }
        cout << "-";
        cout << endl;
        
        for(int j = 0 ; j < column + 1 ; j++)
        {
                cout << b << "   " ;
                    
        }
        
        if(k < row)
        {
             cout << endl;
             continue;
        } 
           
        else
        {  
            cout << endl;   
            
            for(int n = 0 ; n < column  ; n++)
            {
                      cout << a ; 
            }
            cout << "-";
        }
        cout << endl;
    }       
    system("PAUSE");
}
