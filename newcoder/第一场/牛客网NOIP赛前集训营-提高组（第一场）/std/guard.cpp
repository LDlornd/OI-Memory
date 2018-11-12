#include <bits/stdc++.h>

using namespace std;

const int maxn = 200005;

struct node
{
	int l,r,cnt;
}T[maxn * 100];

vector<int> lk[maxn];
int fa[maxn][20],dep[maxn],ord[maxn],cnt,n,m,ans[maxn];

void dfs(int now,int pre)
{
	dep[now] = dep[pre] + 1;
	fa[now][0] = pre;
	for(int i = 1;(1 << i) <= dep[now];i ++) fa[now][i] = fa[fa[now][i - 1]][i - 1];
	for(int i = 0;i < lk[now].size();i ++)
		if (lk[now][i] != pre)
			dfs(lk[now][i], now);	
}

void insert(int l,int r,int p,int &jd)
{
	if (!jd) jd = ++ cnt;
	T[jd].cnt ++;
	if (l == r) return;
	int mid = l + r >> 1;
	if (p <= mid) insert(l,mid,p,T[jd].l); else insert(mid + 1,r,p, T[jd].r);
}

int merge(int l,int r,int a,int b)
{
	if ((!a) || (!b)) return a + b;
	int jd = ++ cnt;
	T[jd].cnt = T[a].cnt + T[b].cnt;
	if (l == r) return jd;
	int mid = l + r >> 1;
	T[jd].l = merge(l,mid,T[a].l,T[b].l);
	T[jd].r = merge(mid + 1,r,T[a].r, T[b].r);
	return jd;
}

int find_k(int l,int r,int k,int jd)
{
	if (T[jd].cnt < k) return (1 << 30);
	if (l == r) return l;
	int mid = l + r >> 1;
	if (T[T[jd].l].cnt >= k) return find_k(l,mid,k,T[jd].l);
	return find_k(mid + 1,r,k - T[T[jd].l].cnt, T[jd].r);	
}

void dfs_w(int now,int pre)
{
	for(int i = 0;i < lk[now].size();i ++)
		if (lk[now][i] != pre) 
		{
			dfs_w(lk[now][i], now);
			ord[now] = merge(1,n,ord[now], ord[lk[now][i]]);
		}
}

int get_lca(int u,int v)
{
	if (dep[u] > dep[v]) swap(u,v);
	for(int i = 18;i + 1;i --)
		if (dep[fa[v][i]] >= dep[u]) v = fa[v][i];
	if (u == v) return u;
	for(int i = 18;i + 1;i --)
		if (fa[v][i] != fa[u][i]) v = fa[v][i], u = fa[u][i];
	return fa[u][0];
}

int main()
{
	freopen("guard.in","r",stdin),freopen("guard.out","w",stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1,u,v;i < n;i ++)
	{
		scanf("%d%d", &u, &v);
		lk[u].push_back(v), lk[v].push_back(u);
	}
	dfs(1,0);
	for(int i = 1,u,v;i <= m;i ++)
	{
		scanf("%d%d", &u, &v);
		int p = get_lca(u,v);
		insert(1,n,dep[p],ord[u]),insert(1,n,dep[p],ord[v]);
	}
	dfs_w(1,0);
	int q;
	scanf("%d", &q);
	for(int i = 1;i <= q;i ++)
	{
		int u,k;
		scanf("%d%d", &u, &k);
		printf("%d\n", max(0, dep[u] - find_k(1,n,k,ord[u])));
	}
	return 0;
}
