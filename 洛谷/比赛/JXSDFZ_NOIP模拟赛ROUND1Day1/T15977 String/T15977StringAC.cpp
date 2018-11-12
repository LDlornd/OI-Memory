#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=500001;
char s[MAXN];
bool flag[55],stop=false;
int num[55],tot=0,exp=0;
inline int change(char c)
{
	if(c>='A'&&c<='Z') return c-'A'+1;
	else return c-'a'+27;
}
int main()
{
	freopen("testdata.in","r",stdin);
	//freopen("ACout.out","w",stdout);
	memset(flag,0,sizeof(flag));
	memset(num,0,sizeof(num));
	int n,ans=MAXN;
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;++i)
	{
		int k=change(s[i]);
		if(flag[k]==false) {flag[k]=true;++exp;}
	}
	int head=1,tail=1;
	while(head!=n+1)
	{
		while(tot!=exp)
		{
			int k=change(s[tail]);
			++num[k];
			if(num[k]==1) ++tot;
			++tail;
			if(tail>n+1) stop=true;
		}
		cout<<tot<<" "<<exp<<" "<<head<<" "<<tail<<endl;
		if(tot==exp) ans=min(ans,tail-head);
		int k=change(s[head]);
		--num[k];
		if(num[k]==0) --tot;
		++head;
		if(stop) break;
	}
	printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
