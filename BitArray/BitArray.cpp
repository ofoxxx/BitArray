#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long Num;
constexpr Num B = 1 << 31;

Num A(Num a, Num P, Num Q)
{
	return (a*P + Q) % B;
}

Num Brent(Num N, Num S, Num P, Num Q)
{
	Num a0 = S % B;
	Num m = 0, l = 1, p = 1;
	Num t = a0, h = A(a0, P, Q);

	while (t != h)
	{
		if (p == l)
		{
			t = h;
			p *= 2;
			l = 0;
		}
		h = A(h, P, Q);
		if (++l == N)
			return N;
	}

	t = h = a0;
	for (Num i = 0; i < l; ++i)
		h = A(h, P, Q);

	while (t != h)
	{
		t = A(t, P, Q);
		h = A(h, P, Q);
		++m;
	}
	return m + l;
}

int main()
{
	unsigned long N, S, P, Q;
	cin >> N >> S >> P >> Q;

	cout << Brent(N, S, P, Q);

	return 0;
}
