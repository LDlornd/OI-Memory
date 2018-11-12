#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[1000000],flag[21][1000000];
int Search(int x,int y)
{
    int k=0;
    while((1<<k+1)<=y-x+1) ++k;
    return min(flag[k][x],flag[k][y-(1<<k)+1]);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    for(int i=0;i<n;++i) flag[0][i]=a[i];
    for(int i=1;(1<<i)<=n;++i)
        for(int j=0;j+(1<<i)-1<n;++j)
            flag[i][j]=min(flag[i-1][j],flag[i-1][j+(1<<(i-1))]);
    cout<<0<<endl;
    for(int i=1;i<=m;++i)
        printf("%d\n",Search(0,i-1));
    for(int i=m+1;i<n;++i)
        printf("%d\n",Search(i-m,i-1));
    return 0;
}
