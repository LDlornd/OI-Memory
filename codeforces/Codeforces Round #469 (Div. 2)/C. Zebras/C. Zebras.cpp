#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
const int MAXN=200001;
int len,tot=0,now=0;
char s[MAXN];
vector<int> ans[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin>>(s+1);
	len=strlen(s+1);
	for(int i=1;i<=len;++i){
		if(s[i]=='0'){
			ans[++now].push_back(i);
		}
		else{
			if(now==0){
				cout<<-1;return 0;
			}
			ans[now--].push_back(i);
		}
		tot=max(tot,now);
	}
	if(tot!=now) cout<<-1;
	else{
		cout<<tot<<endl;
		for(int i=1;i<=tot;++i){
			int Size=ans[i].size();
			cout<<Size;
			for(int j=0;j<Size;++j)
				cout<<" "<<ans[i][j];
			cout<<endl;
		}
	}
	return 0;
}
