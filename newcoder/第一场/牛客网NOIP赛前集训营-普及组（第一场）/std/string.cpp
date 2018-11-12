//N * K * S(9,K)
#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;
typedef long long ll;

char s[maxn][1005];
ll has[1005], inc[maxn][15], nw[maxn][15];
int n,l, k, bel[10], ord[maxn], ans;

ll Ra()
{
	return rand() * rand() * 1ll * rand() * rand(); //WIN
	return rand() * 1ll * rand(); //LINUX
}

bool cmp(int a,int b)
{
	for(int i = 0;i < k;i ++)
		if (nw[a][i] < nw[b][i]) return 1; else
			if (nw[a][i] > nw[b][i]) return 0;
	return 0;
}

int check()
{
	for(int i = 1;i <= n;i ++)
	{
		memset(nw[i], 0, sizeof nw[i]);
		for(int j = 0;j < 8;j ++) nw[i][bel[j]] ^= inc[i][j];
		ord[i] = i;
	}
	sort(ord + 1, ord + n + 1, cmp);
	int ans = 0, siz = 1;
	for(int i = 2;i <= n;i ++)
		if (!cmp(ord[i - 1], ord[i]) && !cmp(ord[i], ord[i - 1])) ++ siz; else
			ans += siz * (siz - 1) / 2, siz = 1;
	ans += siz * (siz - 1) / 2;
	return ans;
}

void dfs(int now,int m)
{
	if (now >= 8)
	{
		if (m != k) return;
		ans = max(ans, check());
		return;
	}
	for(int i = 1;i <= m;i ++)
		bel[now] = i - 1,dfs(now + 1,m);
	bel[now] = m, dfs(now + 1, m + 1);
}

int main()
{
	freopen("string.in","r",stdin),freopen("string.out","w",stdout);
	scanf("%d%d%d", &n, &l, &k);
	k = max(1, 8 - k);
	for(int i = 1;i <= n;i ++) scanf("%s", s[i] + 1);
	for(int i = 1;i <= l;i ++)
		has[i] = Ra();
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= l;j ++) inc[i][s[i][j] - 'a'] ^= has[j];
	dfs(0,0);
	printf("%d\n", ans);
	return 0;
}
