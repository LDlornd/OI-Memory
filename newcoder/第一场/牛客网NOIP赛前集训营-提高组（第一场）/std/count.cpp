#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int co[10][10];
ll l,r,l1,r1, pw[10][100];

inline int merge(int i, int cr, int b)
{
	return (cr > b ? 2 : (cr == b ? i : 0));
}

ll calc_no_zero(ll x)
{
	if (x <= 0) return 0;
	static ll f[2][3][60][38][27][22];
	memset(f,0,sizeof f);
	int cr = 0;
	f[0][1][0][0][0][0] = 1;
	ll ans = 0, val;
	for(;x;x /= 10, cr ^= 1)
	{
		int bit = x % 10;
		memset(f[cr ^ 1], 0, sizeof f[cr]);
		for(int i = 0;i < 3;i ++)
			for(int n_2 = 0;n_2 < 60;n_2 ++)
				for(int n_3 = 0;n_3 < 38;n_3 ++)
					for(int n_5 = 0;n_5 < 27;n_5 ++)
						for(int n_7 = 0;n_7 < 22;n_7 ++)
							if (val = f[cr][i][n_2][n_3][n_5][n_7])
							{
								ll q1 = r1 / pw[2][n_2] / pw[3][n_3] / pw[5][n_5] / pw[7][n_7];
								ll p1 = (l1 - 1) / pw[2][n_2] / pw[3][n_3] / pw[5][n_5] / pw[7][n_7];
								if (q1 >= 1 && p1 <= 0) ans += val;
								if (q1 <= 0) continue;
								for(int p = 1;p < 10;p ++)
								{
									int ni = merge(i, p, bit);
									int c_2 = n_2 + co[p][2];
									int c_3 = n_3 + co[p][3];
									int c_5 = n_5 + co[p][5];
									int c_7 = n_7 + co[p][7];
									if (c_2 >= 60 || c_3 >= 38 || c_5 >= 27 || c_7 >= 22) continue;
									f[cr ^ 1][ni][c_2][c_3][c_5][c_7] += val;
								}
							}
	}
	for(int i = 0;i < 2;i ++)
		for(int n_2 = 0;n_2 < 60;n_2 ++)
				for(int n_3 = 0;n_3 < 38;n_3 ++)
					for(int n_5 = 0;n_5 < 27;n_5 ++)
						for(int n_7 = 0;n_7 < 22;n_7 ++)
							if (val = f[cr][i][n_2][n_3][n_5][n_7])
							{
								ll q1 = r1 / pw[2][n_2] / pw[3][n_3] / pw[5][n_5] / pw[7][n_7];
								ll p1 = (l1 - 1) / pw[2][n_2] / pw[3][n_3] / pw[5][n_5] / pw[7][n_7];
								if (q1 >= 1 && p1 <= 0) ans += val;
							}
	return ans;
}

ll calc_with_zero(ll x)
{
	if (l1) return 0;
	static ll g[2][3][2][2];
	memset(g,0,sizeof g);
	int cr = 0;
	ll ans = 0;
	g[0][1][0][0] = 1;
	for(;x;x /= 10, cr ^= 1)
	{
		int bit = x % 10;
		memset(g[cr ^ 1], 0, sizeof g[cr]);
		for(int i = 0;i < 3;i ++)
			for(int j = 0;j < 2;j ++)
				for(int hd = 0;hd < 2;hd ++)
					if (g[cr][i][j][hd])
					{
						if (hd && j) ans += g[cr][i][j][hd];
						for(int p = 0;p < 10;p ++)
						{
							int ni = merge(i, p, bit);
							int nj = (j | (p == 0));
							int hdt = (p > 0);
							g[cr ^ 1][ni][nj][hdt] += g[cr][i][j][hd];
						}
					}
	}
	return ans + g[cr][0][1][1] + g[cr][1][1][1];
}

ll calc(long long x)
{
	return calc_no_zero(x) + calc_with_zero(x);
}

int main()
{
	freopen("count.in","r",stdin),freopen("count.out","w",stdout);
	for(int i = 1;i < 10;i ++)
	{
		for(int j = 2;j < 10;j ++)
			for(int k = i;k % j == 0;k /= j) co[i][j] ++;
		pw[i][0] = 1;
		for(int j = 1;j <= 60;j ++) pw[i][j] = pw[i][j - 1] * i;
	}
	cin >> l >> r >> l1 >> r1;
	ll ans = 0;
	if (!l) ans += (l1 == 0), ++ l;
	if (l <= r) ans += calc(r) - calc(l - 1);
	cout << ans << endl;
	return 0;
}
