#include <iostream>
#include <cmath>

using namespace std;

double P0(const int N, const int K)
{
	double p = 1;
	for (int i = 1; i <= K; i++)
		p *= (sin(i) * sin(i) + cos(1. / i) * cos(1. / i)) / (i * i);
	return p;
}
double P1(const int N, const int K, const int i)
{
	if (i > K)
		return 1;
	else
		return (sin(i) * sin(i) + cos(1. / i) * cos(1. / i)) / (i * i) * P1(N, K, i + 1);
}
double P2(const int N, const int K, const int i)
{
	if (i < N)
		return 1;
	else
		return (sin(i) * sin(i) + cos(1. / i) * cos(1. / i)) / (i * i) * P2(N, K, i - 1);
}
double P3(const int N, const int K, const int i, double t)
{
	t *= (sin(i) * sin(i) + cos(1. / i) * cos(1. / i)) / (i * i);
	if (i >= K)
		return t;
	else
		return P3(N, K, i + 1, t);
}
double P4(const int N, const int K, const int i, double t)
{
	t *= (sin(i) * sin(i) + cos(1. / i) * cos(1. / i)) / (i * i);
	if (i <= N)
		return t;
	else
		return P4(N, K, i - 1, t);
}
int main()
{
	const int K = 15;
	int N;
	cout << "N = "; cin >> N;
	cout << "(iter)        P0 = " << P0(N, K) << endl;
	cout << "(rec up ++)   P1 = " << P1(N, K, N) << endl;
	cout << "(rec up --)   P2 = " << P2(N, K, K) << endl;
	cout << "(rec down ++) P3 = " << P3(N, K, N, 1) << endl;
	cout << "(rec down --) P4 = " << P4(N, K, K, 1) << endl;
	return 0;
}
