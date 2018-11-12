#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define inf 0x3f3f3f3f
#define lson l , mid , x << 1
#define rson mid + 1 , r , x << 1 | 1
using namespace std;
struct data
{
    int x , y;
    data(int a = 0 , int b = -inf) {x = a , y = b;}
    data operator+(const data &a)const {return data(max(-inf , x + a.x) , max(y + a.x , a.y));}
    data operator*(const data &a)const {return data(max(x , a.x) , max(y , a.y));}
}ntag[N << 2] , ptag[N << 2];
int nmax[N << 2] , pmax[N << 2];
char str[5];
inline void pushup(int x)
{
    nmax[x] = max(nmax[x << 1] , nmax[x << 1 | 1]);
    pmax[x] = max(pmax[x << 1] , pmax[x << 1 | 1]);
}
inline void pushdown(int x)
{
    int l = x << 1 , r = x << 1 | 1;
    ptag[l] = ptag[l] * (ntag[l] + ptag[x]);
    ntag[l] = ntag[l] + ntag[x];
    pmax[l] = max(pmax[l] , max(nmax[l] + ptag[x].x , ptag[x].y));
    nmax[l] = max(nmax[l] + ntag[x].x , ntag[x].y);
    ptag[r] = ptag[r] * (ntag[r] + ptag[x]);
    ntag[r] = ntag[r] + ntag[x];
    pmax[r] = max(pmax[r] , max(nmax[r] + ptag[x].x , ptag[x].y));
    nmax[r] = max(nmax[r] + ntag[x].x , ntag[x].y);
    ptag[x] = ntag[x] = data();
}
void build(int l , int r , int x)
{
    ntag[x] = ptag[x] = data();
    if(l == r)
    {
        scanf("%d" , &nmax[x]) , pmax[x] = nmax[x];
        return;
    }
    int mid = (l + r) >> 1;
    build(lson) , build(rson);
    pushup(x);
}
void update(int b , int e , data a , int l , int r , int x)
{
    if(b <= l && r <= e)
    {
        ptag[x] = ptag[x] * (ntag[x] + a);
        ntag[x] = ntag[x] + a;
        pmax[x] = max(pmax[x] , max(nmax[x] + a.x , a.y));
        nmax[x] = max(nmax[x] + a.x , a.y);
        return;
    }
    pushdown(x);
    int mid = (l + r) >> 1;
    if(b <= mid) update(b , e , a , lson);
    if(e > mid) update(b , e , a , rson);
    pushup(x);
}
int query(int b , int e , bool flag , int l , int r , int x)
{
    if(b <= l && r <= e) return flag ? pmax[x] : nmax[x];
    pushdown(x);
    int mid = (l + r) >> 1 , ans = -inf;
    if(b <= mid) ans = max(ans , query(b , e , flag , lson));
    if(e > mid) ans = max(ans , query(b , e , flag , rson));
    return ans;
}
int main()
{
	freopen("testdata.in","r",stdin);
	freopen("ac.out","w",stdout);
    int n , m , x , y , z;
    scanf("%d" , &n);
    build(1 , n , 1);
    scanf("%d" , &m);
    while(m -- )
    {
        scanf("%s%d%d" , str , &x , &y);
        if(str[0] == 'Q') printf("%d\n" , query(x , y , 0 , 1 , n , 1));
        if(str[0] == 'A') printf("%d\n" , query(x , y , 1 , 1 , n , 1));
        if(str[0] == 'P') scanf("%d" , &z) , update(x , y , data(z , -inf) , 1 , n , 1);
        if(str[0] == 'C') scanf("%d" , &z) , update(x , y , data(-inf , z) , 1 , n , 1);
    }
    return 0;
}
