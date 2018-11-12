#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
const int MAXN=100010;
int T,len,num=1,numw;
int Start[MAXN];
bool flag;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		flag=true;num=1;numw=0;
		cin>>s;
		len=s.length();
		if(s[0]!='z'||s[len-1]!='b') flag=false;
		Start[1]=0;
		for(int i=0;i<len-1;++i)
			if(s[i]=='b'&&s[i+1]=='z') Start[++num]=i+1;
		Start[num+1]=len;
		//for(int i=1;i<=num+1;++i) cout<<Start[i]<<" ";cout<<endl;
		for(int i=1;i<=num;++i){
			if(((Start[i+1]-Start[i])&1)==0){
				flag=false;break;
			}
			for(int j=Start[i];j<Start[i+1];++j){
				if(((j-Start[i])&1)&&s[j]!='w'){
					flag=false;
					break;
				}
			}
		}
		if(flag==false) cout<<"Yes"<<endl;
		else {
			cout<<"No"<<endl;
			for(int i=0;i<len-1;++i)
				if(s[i]=='w') ++numw;
			cout<<numw-num<<endl;
		}
	}
	return 0;
}
