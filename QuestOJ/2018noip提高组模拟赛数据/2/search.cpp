#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int a[5000][200];
int n, m, tot;
int prsss[4100000], x[4100000], y[4100000];
int lasth[999983], prsssh[4100000];
int fa[100001], last[100001], used[100001], que[100001];

int eadd(int a, int b)
{
    x[++tot] = a;
    y[tot] = b;
    prsss[tot] = last[a];
    last[a] = tot;
    int h = (a * 30000 + b) % 999983;
    prsssh[tot] = lasth[h];
    lasth[h] = tot;
    return 0;
}

int findh(int a, int b)
{
    int h = (a * 30000 + b) % 999983;
    int i = lasth[h];
    while (i != 0) {
        if ((a == x[i]) && (b == y[i])) {
            return 1;
        } else {
            i = prsssh[i];
        }
    }
    return 0;
}

int fin(int i, int j, int k)
{
    int s;
    if (j > k) {
        s = j;
        j = k;
        k = s;
    }
    if (i > j) {
        s = i;
        i = j;
        j = s;
    }
    if (j > k) {
        s = j;
        j = k;
        k = s;
    }
    printf("%d %d %d\n", i, j, k);
}

int alg1()
{
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n / 30; j++)
            if ((a[x[2 * i - 1]][j] & a[y[2 * i - 1]][j]) != 0) {
                int s = a[x[2 * i - 1]][j] & a[y[2 * i - 1]][j];
                int k = 0;
                while (s > 0) {
                    s = s / 2;
                    k++;
                }
                fin(x[2 * i - 1], y[2 * i - 1], j * 30 + k - 1);
                return 0;
            }
    }
    return 0;
}

int alg2()
{
    int round = 0;
    while (1 != 0) {
        round++;
        int p = 1;
        int q = 0;
        for (int i = 1; i <= n; i++) {
            if (used[i] != round) {
                que[++q] = i;
                fa[i] = i;
            }
            while (p <= q) {
                int ptr = last[que[p]];
                while (ptr != 0) {
                    if (used[y[ptr]] != round) {
                        que[++q] = y[ptr];
                        used[y[ptr]] = round;
                        fa[y[ptr]] = que[p];
                    }
                    ptr = prsss[ptr];
                }
                p++;
            }
        }
        for (int i = 1; i <= tot; i++)
            if ((x[i] != fa[x[i]]) && (y[i] != fa[x[i]]) && (findh(y[i], fa[x[i]]) == 1)) {
                fin(x[i], fa[x[i]], y[i]);
                return 0;
            }
    }
    return 0;
}

int main()
{
    scanf("%d %d\n", &n, &m);
    tot = 0;
    for (int i = 1; i <= m; i++) {
        int p, q;
        scanf("%d %d\n", &p, &q);
        eadd(p, q);
        eadd(q, p);
        if (n <= 5000) {
            int c = q / 30;
            int d = q % 30;
            a[p][c] += (1 << d);
        }
    }
    if (n <= 5000) {
        alg1();
    } else {
        alg2();
    }
    return 0;
}
