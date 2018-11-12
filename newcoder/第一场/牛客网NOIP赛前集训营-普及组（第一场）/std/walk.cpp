#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;

char s[maxn];
int dx,dy,T,q,n,m;

int main()
{
	freopen("walk.in","r",stdin),freopen("walk.out","w",stdout);
	scanf("%d%d%d", &n, &m, &T);
	scanf("%s", s);
	for(int i = 0,l = strlen(s);i < l;i ++)
	{
		if (s[i] == 'L') dy --;
		if (s[i] == 'R') dy ++;
		if (s[i] == 'U') dx --;
		if (s[i] == 'D') dx ++; 
	}
	dx = (dx % n + n) % n, dy = (dy % m + m) % m;
	dx = (dx * 1ll * T) % n, dy = (dy * 1ll * T) % m;
	int q;
	scanf("%d", &q);
	for(int i = 1,x,y;i <= q;i ++)
	{
		scanf("%d%d", &x, &y);
		x --,y --;
		x = (x + dx) % n + 1, y = (y + dy) % m + 1;
		printf("%d %d\n", x , y);
	}
	return 0;
}
