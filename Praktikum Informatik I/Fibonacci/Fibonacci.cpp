#include <iostream>
#define MAX_N 25
using namespace std;

unsigned int fibonacci(unsigned int n){

    int x; //Hilfsvariable!

	if (n == 0 || n == 1 ) {return n;}

	else
	x = fibonacci(n-1) + fibonacci(n-2);
	return x;
     }

int main(void)
{
	cout << "\tfib(n)" << endl;

     for(int n = 0; n <= MAX_N; n++)
	{
		cout << n << "\t" << fibonacci(n) << endl;
	}

	return 0;
}
