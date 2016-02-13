#include <iostream>
using namespace std;

#include <iomanip>

void procedimiento(int num);

void procedimiento(int num)
{
	int contador = 0;

	cout << endl;

	for (int i = 1; i <= num; i++)
	{ 
		contador = 0;
		for (int j = i; j <= i * num ; j += i )
		{
			cout << setw(3) << j << "  " ; contador += j;
		}
		cout << setw(3) << contador;
		cout << endl;
	}
}

int main()
{
	int num; 

	cin >> num ;

	procedimiento(num);
	return 0;
}