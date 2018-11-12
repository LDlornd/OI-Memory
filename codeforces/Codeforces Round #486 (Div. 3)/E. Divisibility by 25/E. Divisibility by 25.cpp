#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=20;
const int INF=2147483647;
char s[MAXN];
int len,ans=INF,tempans=0;
int p2=0,p5=0,p7=0,p0=0,p00=0;
int main(){
	scanf("%s",s+1);
	len=strlen(s+1);
	for(int i=1;i<=len;++i){
		if(s[i]=='2') p2=i;
		if(s[i]=='5') p5=i;
		if(s[i]=='7') p7=i;
		if(s[i]=='0'){
			if(p0==0) p0=i;
			else {p00=p0;p0=i;}
		}
	}
	if(p2&&p5){
		tempans=(len-p5)+(len-1-p2);
		if(p2>p5) ++tempans;
		if(p2==1||p5==1){
			for(int i=2;i<=len;++i){
				if(s[i]=='0') ++tempans;
				else break;
			}
		}
		ans=min(ans,tempans);
		//cout<<"1 "<<tempans<<endl;
	}
	if(p7&&p5){
		tempans=(len-p5)+(len-1-p7);
		if(p7>p5) ++tempans;
		if(p7==1||p5==1){
			for(int i=2;i<=len;++i){
				if(s[i]=='0') ++tempans;
				else break;
			}
		}
		ans=min(ans,tempans);
		//cout<<"1 "<<tempans<<endl;
	}
	if(p0&&p5){
		tempans=(len-p0)+(len-1-p5);
		if(p5>p0) ++tempans;
		ans=min(ans,tempans);
		//cout<<"2 "<<tempans<<endl;
	}
	if(p0&&p00){
		tempans=(len-p0)+(len-1-p00);
		ans=min(ans,tempans);
		//cout<<"3 "<<tempans<<endl;
	}
	if(ans==INF) printf("-1");
	else printf("%d",ans);
}
