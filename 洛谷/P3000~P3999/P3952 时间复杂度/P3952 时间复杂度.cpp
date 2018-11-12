#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=200;
int T;
int len[105],Start[105],End[105];
int Stack[MAXN],top;
char s[105][MAXN];
bool used[MAXN];
void get_basic_information(int &cnt,int &w){
	int place;
	for(int i=1;i<=len[0];++i){
		if(s[0][i]>='0'&&s[0][i]<='9') cnt=(cnt<<3)+(cnt<<1)+s[0][i]-'0';
		if(s[0][i]=='O') {place=i;break;}
	}
	if(s[0][place+2]>='0'&&s[0][place+2]<='9') w=0;
	else{
		for(int i=place+4;i<=len[0];++i){
			if(s[0][i]<'0'||s[0][i]>'9') break;
			w=(w<<3)+(w<<1)+s[0][i]-'0';
		}
	}
}
void init(){
	memset(used,0,sizeof(used));
	top=0;
}
int get_num(int key,int Start,int End){
	if(Start==End&&s[key][Start]=='n') return 1000;
	int temp=0;
	for(int i=Start;i<=End;++i) temp=(temp<<3)+(temp<<1)+s[key][i]-'0';
	return temp;
}
bool grammar(int key){
	if(key&1) return false;
	init();
	for(int i=1;i<=key;++i){
		if(s[i][1]=='E'){
			if(top==0) return false;
			used[Stack[top]]=false;--top;
		}
		else{
			if(used[(int)s[i][3]]) return false;
			used[(int)s[i][3]]=true;
			Stack[++top]=(int)s[i][3];
		}
	}
	if(top!=0) return false;
	return true;
}
int complexity(int key){
	int tmp=0,maxtmp=0;
	top=0;
	for(int w=1;w<=key;++w){
		if(s[w][1]=='E'){
			if(End[Stack[top]]==1000&&Start[Stack[top]]!=1000) --tmp;
			--top;
			continue;
		}
		int place[4]={0};
		for(int i=1;i<=len[w];++i)
			if(s[w][i]==' '){
				if(place[1]==0) place[1]=i;
				else if(place[2]==0) place[2]=i;
				else if(place[3]==0) place[3]=i;
			}
		Start[w]=get_num(w,place[2]+1,place[3]-1);
		End[w]=get_num(w,place[3]+1,len[w]);
		if(Start[w]<=End[w]){
			Stack[++top]=w;
			if(End[w]==1000&&Start[w]!=1000){
				maxtmp=max(maxtmp,++tmp);
			}
		}
		else{
			int sum=1;
			for(w=w+1;w<=key&&sum;++w)
				if(s[w][1]=='F') ++sum;
				else --sum;
			--w;
		}
	}
	return maxtmp;
}
void read(int place){
	len[place]=0;char c=getchar();
	for(;c!='\n'&&c!=EOF;c=getchar()) s[place][++len[place]]=c;
	s[place][len[place]+1]=0;
}
int main(){
	scanf("%d\n",&T);
	while(T--){
		read(0);
		int cnt=0,w=0;
		get_basic_information(cnt,w);
		for(int i=1;i<=cnt;++i) read(i);
		if(grammar(cnt)==false) printf("ERR\n");
		else{
			if(complexity(cnt)==w) printf("Yes\n");
			else printf("No\n"); 
		}
	}
	return 0;
}
