#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
int T,n,A,B;
int MAP1[2][2]={1,2,4,3};
int MAP2[4][4]={1,4,5,6,2,3,8,7,15,14,9,10,16,13,12,11};
int MAP3[8][8]={1,2,15,16,17,20,21,22,4,3,14,13,18,19,24,23,5,8,9,12,31,30,25,26,6,7,10,11,32,29,28,27,59,58,55,54,33,36,37,38,60,57,56,53,34,35,40,39,61,62,51,52,47,46,41,42,64,63,50,49,48,45,44,43,};
int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main(){
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
	T=read();
	while(T--){
		n=read();A=read();B=read();
		int ax,ay,bx,by;
		if(n==1){
			for(int i=0;i<2;++i)
				for(int j=0;j<2;++j){
					if(MAP1[i][j]==A) {ax=i;ay=j;}
					if(MAP1[i][j]==B) {bx=i;by=j;}
				}
		}
		if(n==2){
			for(int i=0;i<4;++i){
				for(int j=0;j<4;++j){
					//cout<<MAP2[i][j]<<" ";
					if(MAP2[i][j]==A) {ax=i;ay=j;}
					if(MAP2[i][j]==B) {bx=i;by=j;}
				}
				//cout<<endl;
			}
				
		}
		if(n==3){
			for(int i=0;i<8;++i)
				for(int j=0;j<8;++j){
					if(MAP3[i][j]==A) {ax=i;ay=j;}
					if(MAP3[i][j]==B) {bx=i;by=j;}
				}
		}
		double temp=sqrt((ax-bx)*(ax-bx)*100+(ay-by)*(ay-by)*100);
		printf("%d\n",(temp-(int)temp>=0.5)?((int)temp+1):((int)temp));
	}
	return 0;
}
