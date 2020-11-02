#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	constexpr unsigned long b = 1 << 31;
	unsigned long N, S, P, Q;
	cin >> N >> S >> P >> Q;

	vector<unsigned long> a (N, 0);
	a[0] = S % b;
	for (unsigned long i = 1; i < N; ++i)
		a[i] = (a[i - 1] * P + Q) % b;

	set<unsigned long> s(a.begin(), a.end());
	cout << s.size();
	return 0;
}
