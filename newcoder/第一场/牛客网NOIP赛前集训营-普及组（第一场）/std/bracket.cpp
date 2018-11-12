#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005,mo = int(1e9) + 7;

char s[maxn];
int f[2][maxn],n;

int main()
{
	freopen("bracket.in","r",stdin),freopen("braket.out","w",stdout);
	scanf("%d", &n);
	scanf("%s", s + 1);
	f[0][0] = 1;
	int cr = 0;
	for(int i = 1;i <= n;i ++, cr ^= 1)
	{
		memset(f[cr ^ 1], 0, sizeof f[cr]);
		for(int j = 0;j <= i;j ++)
		{
			f[cr ^ 1][j] = (f[cr ^ 1][j] + f[cr][j]) % mo;
			if (s[i] == '(') f[cr ^ 1][j + 1] = (f[cr ^ 1][j + 1] + f[cr][j]) % mo;
			if (s[i] == ')' && j) f[cr ^ 1][j - 1] = (f[cr ^ 1][j - 1] + f[cr][j]) % mo;
		}
	}
	printf("%d\n", (f[cr][0] + mo - 1) % mo);
	return 0;
}
