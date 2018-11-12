#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

template <class T>
inline bool tense(T &a, const T &b)
{
	if (b <= a)
	{
		a = b;
		return true;
	}
	return false;
}

const int MaxN = 300005;
const int MaxM = 300005;

int nT, n, m, vS, vT;
int eu[MaxM], ev[MaxM], ew[MaxM];

struct halfEdge
{
	int v, w;
	halfEdge *next;
};
halfEdge adj_pool[MaxM * 2], *adj_tail = adj_pool;
halfEdge *adj[MaxN];

inline void addEdge(const int &u, const int &v, const int &w)
{
	adj_tail->v = v, adj_tail->w = w, adj_tail->next = adj[u], adj[u] = adj_tail++;
	adj_tail->v = u, adj_tail->w = w, adj_tail->next = adj[v], adj[v] = adj_tail++;
}
inline halfEdge *oppo(halfEdge *e)
{
	return adj_pool + ((e - adj_pool) ^ 1);
}

inline void adj_init(const int &n)
{
	adj_tail = adj_pool;
	memset(adj + 1, 0, sizeof(halfEdge*) * n);
}

int dfsCur;
int dfn[MaxN], low[MaxN];

int sta_n, sta[MaxN];
int nBcc, bccNum[MaxN];

void dfs_init(const int &u, halfEdge *prevE)
{
	dfn[u] = low[u] = ++dfsCur;
	sta[++sta_n] = u;

	for (halfEdge *e = adj[u]; e; e = e->next)
		if (e != prevE)
		{
			if (!dfn[e->v])
			{
				dfs_init(e->v, oppo(e));
				tense(low[u], low[e->v]);
			}
			else
				tense(low[u], dfn[e->v]);
		}

	if (dfn[u] == low[u])
	{
		++nBcc;

		int v = u;
		do
		{
			bccNum[v] = nBcc;
			v = sta[sta_n--];
		}
		while (u != v);
	}
}

int val[MaxN];
int fa[MaxN];

void dfs(const int &u)
{
	for (halfEdge *e = adj[u]; e; e = e->next)
		if (e->v != fa[u])
		{
			fa[e->v] = u;
			val[e->v] |= e->w;
			dfs(e->v);
		}
}

inline void lock_screen()
{
	int v = bccNum[vT];
	while (v)
	{
		if (val[v])
		{
			puts("YES");
			return;
		}
		v = fa[v];
	}
	puts("NO");
}

int main()
{
	freopen("testdata.in", "r", stdin);
	freopen("baoli.out", "w", stdout);

	cin >> nT;
	while (nT--)
	{
		cin >> n >> m;

		adj_init(n);
		for (int i = 1; i <= m; ++i)
		{
			eu[i] = getint(), ev[i] = getint(), ew[i] = getint();
			addEdge(eu[i], ev[i], ew[i]);
		}

		cin >> vS >> vT;

		dfsCur = sta_n = nBcc = 0;
		for (int u = 1; u <= n; ++u)
		{
			dfn[u] = low[u] = 0;
			bccNum[u] = 0, val[u] = 0;
			fa[u] = 0;
		}

		for (int u = 1; u <= n; ++u)
			if (!dfn[u])
				dfs_init(u, NULL);

		adj_init(n);
		for (int i = 1; i <= m; ++i)
		{
			int u = bccNum[eu[i]];
			int v = bccNum[ev[i]];
			if (u != v)
				addEdge(u, v, ew[i]);
			else
				val[u] |= ew[i];
		}

		dfs(bccNum[vS]);

		lock_screen();
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
