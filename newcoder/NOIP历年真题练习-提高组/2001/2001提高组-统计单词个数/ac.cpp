#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
const int ran=233;
int n,k,s;
char ch[300];
char f[9][100],t[300];
int ok[9],ll[9];
int map[300][300];
int dp[300][300];
int haxi(char c[]){
    int le=strlen(c);
    int an=0;
    for(int i=0;i<le;i++)an=(an*ran+c[i])%mod;
    return an;
}
bool ha(int x,int y){
    for(int i=1;i<=s;i++){
    memset(t,0,sizeof(t));
    strncpy( t, ch+x , min( ll[i] , y-x+1 ) );//????? 
    if(haxi( t )==ok[i])return 1;
    }
    return 0;
}
int main(){
	freopen("testdata.in","r",stdin);
	//freopen("ac.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>ch+(i*20-20);
    cin>>s;
    for(int i=1;i<=s;i++)cin>>f[i];
    for(int i=1;i<=s;i++)ll[i]=strlen(f[i]);
    for(int i=1;i<=s;i++)ok[i]=haxi( f[i] );
    int len=strlen(ch);
    for(int i=len-1;i>=0;i--){
        for(int j=i;j>=0;j--){
            map[j][i]+=map[j+1][i];
            if(ha(j,i))map[j][i]++;
        }
    }
    cout<<len<<endl;
    for(int i=0;i<len;i++)
    for(int j=1;j<=k;j++){
        if(j==1)dp[i][j]=map[0][i];
        else{
            for(int l=0;l<i;l++){
                if(dp[l][j-1])
                dp[i][j]=max(dp[i][j],dp[l][j-1]+map[l+1][i]);
            }
        }
    }
    cout<<dp[len-1][k];
    return 0;
}
