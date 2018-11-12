#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=100001;
int T,len;
int place[27],last[MAXN];
string s;
int flag;
inline int getlast(int x)
{
	return (last[x]==-1)?x:getlast(last[x]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		memset(place,-1,sizeof(place));
		flag=0;
		cin>>len>>s;
		for(int i=0;i<len;++i){
			last[i]=place[s[i]-'a'];
			place[s[i]-'a']=i;
		}
		for(int i=0;i<len-1;++i)
			if(last[i]>=last[i+1]) ++flag;
		if(len==2&&s[0]!=s[1]) cout<<1<<endl;
		else if(len==3&&s[0]!=s[2]) cout<<1<<endl;
		else{
			if(flag<2) cout<<-1<<endl;
			else{
				int mid=(len-1)>>2,i;
				for(i=0;i<=mid;++i)
					if(s[i]!=s[len-1-i]) break;
				if(i==mid+1) cout<<2<<endl;
				else cout<<1<<endl;
			}
		}
	}
	return 0;
}
