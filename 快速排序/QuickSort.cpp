//无优化版本，当N很大的时候， 这个程序会TLE
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;

int a[N];

void Work(int l, int r) {
	if (l > r) return;
	int key = a[l], ll = l, rr = r;
	while (ll < rr) {
		while (rr > ll && a[rr] >= key) rr--;
		while (ll < rr && a[ll] <= key) ll++;
		if (ll < rr)swap(a[ll], a[rr]);
	}
	swap(a[l], a[ll]);
	Work(l, ll-1);
	Work(ll+1, r);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	Work(1, n);
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	return 0;
}