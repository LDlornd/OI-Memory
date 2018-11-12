#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;

int a[maxn], n, L;

bool test(int z)
{
	static int b[maxn];
	for(int i = 1;i <= n;i ++)
		if (a[i] >= z) b[i] = 1; else b[i] = -1;
	for(int i = 1, mi = (1 << 30);i <= n;i ++)
	{
		if (i >= L) mi = min(mi, b[i - L]);
		b[i] += b[i - 1];
		if (i >= L && b[i] - mi > 0) return 1;
	}
	return 0;
}

int main()
{
	freopen("median.in","r",stdin),freopen("median.out","w",stdout);
	scanf("%d%d", &n, &L);
	for(int i = 1;i <= n;i ++) scanf("%d", &a[i]);
	int l = 0, r = int(1e9), tmp;
	for(int mid;l <= r;)
	{
		mid = l + r >> 1;
		if (test(mid)) tmp = mid, l = mid + 1; else r = mid - 1;
	}
	printf("%d\n", tmp);
	return 0;
}
