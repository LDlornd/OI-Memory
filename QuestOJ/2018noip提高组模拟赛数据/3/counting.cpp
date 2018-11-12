#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int T = 1501, M = 100001;
int n;
double d[T], md[T], ds[T], mds[T], id[T],
    pr[T][T], ty[T][T], bl[T][T],
    s[T], as[T],
    du[M], mdu[M], dsu[M], mdsu[M], idu[M];
int num[M], used[M];
int add(int a, int b, int v, double p, int l) {
    pr[a][b] = p;
    ty[a][b] = v;
    bl[a][b] = l;
    return 0;
}
int main() {
    /*
	freopen("counting.in","r",stdin);
	freopen("counting.out","w",stdout);
	*/
    scanf("%d\n", &n);
    for (int i = 1; i <= (n * (n - 1) / 2); i++) {
        int a, b, v, l;
        double p;
        scanf("%d %d %d %lf", &a, &b, &v, &p);
        if (v == 3) {
            p = 1 - p;
        }
        d[a] += p;
        ds[a] += p * p;
        md[a] += (1 - p);
        mds[a] += (1 - p) * (1 - p);
        id[a] += p * (1 - p);
        d[b] += p;
        ds[b] += p * p;
        md[b] += (1 - p);
        mds[b] += (1 - p) * (1 - p);
        id[b] += p * (1 - p);
        if (v == 3) {
            p = 1 - p;
        }
        if (v > 1) {
            scanf("%d\n", &l);
            add(a, b, v, p, l);
            add(b, a, v, p, l);
        }
    }
    for (int i = 1; i <= n; i++) {
        s[i] = 0.5 * (d[i] * d[i] - ds[i] + md[i] * md[i] - mds[i]);
        as[i] = d[i] * md[i] - id[i];
        for (int j = 1; j <= n; j++) {
            if ((i != j) && (ty[i][j] > 1)) {
                int l = bl[i][j];
                double p = pr[i][j];
                num[l]++;
                du[l] += p;
                dsu[l] += p * p;
                mdu[l] += 1 - p;
                mdsu[l] += (1 - p) * (1 - p);
                idu[l] += p * (1 - p);
            }
        }

        for (int j = 1; j <= n; j++) {
            if (i != j) {
                if (ty[i][j] > 1) {
                    int l = bl[i][j];
                    if ((!used[l]) && (num[l] > 1)) {
                        s[i] -= 0.5 * (du[l] * du[l] - dsu[l] + mdu[l] * mdu[l] - mdsu[l]);
                        s[i] += 0.5 * double(num[l] - 1) * double(num[l] - 2) * du[l] + (1 - du[l]) * 0.5 * double(num[l]) * double(num[l] - 1);
                        as[i] -= (du[l] * mdu[l] - idu[l]);
                        as[i] += double(num[l] - 1) * du[l];
                        used[l] = true;
                    }
                }
            }
        }

        for (int j = 1; j <= n; j++)
            if (i != j) {
                if (ty[i][j] > 1) {
                    int l = bl[i][j];
                    used[l] = false;
                    du[l] = 0;
                    dsu[l] = 0;
                    mdu[l] = 0;
                    mdsu[l] = 0;
                    idu[l] = 0;
                    num[l] = 0;
                }
            }
    }
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += s[i] / 3;
        ans -= as[i] / 6;
    }

    printf("%.2lf\n", ans);
    return 0;
}
