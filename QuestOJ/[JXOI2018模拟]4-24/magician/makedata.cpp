#include<ctime>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int u,v,c;
bool used=false,flag[1001][1001];
int main(){
    freopen("testdata.in","w",stdout);
    srand(time(0));
    int T=rand()%10;
    cout<<T<<endl;
    while(T--){
    	memset(flag,0,sizeof(flag));
        used=false;
        int n,m;
        n=rand()%20+1;
        while(n==1||n==0) n=rand()%20+1;
		m=rand()%((n)*(n-1)/2)+1;
        cout<<n<<" "<<m<<endl;
        while(m--){
            u=rand()%n+1;v=rand()%n+1;
            while(flag[u][v]||u==v) {u=rand()%n+1;v=rand()%n+1;}
            flag[u][v]=flag[v][u]=true;
            if(used==false){c=1;used=true;}
            else c=0;
            cout<<u<<" "<<v<<" "<<c<<endl;
        }
        u=rand()%n+1;v=rand()%n+1;
        cout<<u<<" "<<v<<endl<<endl;
    }
    fclose(stdout);
    return 0;
}
