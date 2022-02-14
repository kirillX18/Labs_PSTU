#include <iostream>
#include <cmath>
using namespace std;
int step(int a, int n)
{
	return pow(a, n);
}

double step(double a, double n)
{
	return pow(a,1/n);
}

int main()
{
	int a = 34;
	int n = 5;
	int d = step(a, n);
	
	double y = 34;
	double u = 6;
	double s = step(y, u);
	cout << d << " " << s << endl;
	return 0;

}
