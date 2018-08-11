#include<iostream>
using namespace std;

bool isPowerOfThree(int n)
{
	long long int p = 1;
	while (p <= n)
	{
		if (p == n)
			return true;
		else
			p = p * 3;
	}
	return false;
}

bool isPowerOfTwo(int n) {
	long long int p = 1;
	while (p <= n)
	{
		if (p == n)
			return true;
		else
			p = p * 2;
	}
	return false;
}

int main()
{
	int x;
	while (cin >> x)
	{
		cout << x;
		if (isPowerOfThree(x))
			cout << " is ";
		else
			cout << " isn't ";
		cout<< "power of three." << endl;

		cout << x;
		if (isPowerOfTwo(x))
			cout << " is ";
		else
			cout << " isn't ";
		cout << "power of two." << endl;
	}
	system("pause");
}
