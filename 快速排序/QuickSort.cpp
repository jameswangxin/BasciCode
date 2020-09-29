#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N];
int n;

void quicksort(int l, int r) {
    if(l >= r) return;
    int val = a[(l+r)>>1], L = l-1, R = r + 1;
    while (L < R) {
        do L++; while (a[L] < val);
        do R--; while (a[R] > val);
        if (L < R) {
            swap(a[L], a[R]);
        }
    }
    quicksort(l,R);
    quicksort(R+1,r);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    quicksort(1, n);
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    return 0;
}