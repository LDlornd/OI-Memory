#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=1e5+5;
int T,lens,lent,len=0,cnt;
char res[MAXN],opt[MAXN],simplify[MAXN],temp[MAXN];
int main(){
	scanf("%d",&T);
	while(T--){
		memset(simplify,0,sizeof(simplify));len=0;
		scanf("%s%s",res+1,opt+1);
		lens=strlen(res+1);lent=strlen(opt+1);
		for(int i=1;i<=lens;++i)
			if(res[i]!=res[i-1]) simplify[++len]=res[i];
		for(int i=1;i<=lent;++i)
			opt[i]=(opt[i]=='F')?'R':'B';
		while(lent){
			int maxopt=0;
			for(int i=1;i<=lent;++i)
				if(opt[i]!=opt[i-1]) ++maxopt;
			maxopt=maxopt*2-1;
			if(opt[1]=='R'){
				if(simplify[1]=='R'){
					if(maxopt>=len) {len=0;break;}
					else{
						for(int i=1;i+maxopt<=len;++i)
							simplify[i]=simplify[i+maxopt];
						len-=maxopt;
					}
				}
				else{
					for(int i=2;i+maxopt<=len;++i)
						simplify[i]=simplify[i+maxopt];
					len-=maxopt;
				}
			}
			else{
				if(simplify[1]=='B'){
					if(maxopt+1>=len) {len=0;break;}
					else{
						for(int i=1;i+maxopt<=len;++i)
							simplify[i]=simplify[i+maxopt];
						len-=maxopt;
					}
			 	}
				else{
					for(int i=2;i+maxopt<=len;++i)
						simplify[i]=simplify[i+maxopt];
					len-=maxopt;
				}
			}
			cnt=0;
			for(int i=2;i<=lent;++i)
				if(opt[i]==opt[i-1]) temp[++cnt]=opt[i];
			for(int i=1;i<=cnt;++i) opt[i]=temp[i];
			lent=cnt;
		}
		if(len==0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
