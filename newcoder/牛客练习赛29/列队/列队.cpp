#include<cstdio>
#include<iostream>
using namespace std;
const int MANX=1e5+5;
int n,ans=0,temp;
int m[10][10];
int up[5][5],down[5][5],l[5][5],r[5][5];
int upb[5][5],dob[5][5],lb[5][5],rb[5][5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		for(int x=1;x<=4;++x)
			for(int y=1;y<=4;++y){ 
				scanf("%d",&m[x][y]);
				if(m[x][y]) ans=1;
			}
		if(ans!=2){
			for(int x=1;x<=4;++x)
				for(int y=1;y<=4;++y)
					if(m[x][y]&&(m[x+1][y]||m[x][y+1])) ans=2;
		}
		for(int x=1;x<=4;++x){
			int cnt=0;
			for(int y=1;y<=4;++y){
				if(m[x][y]==1) ++cnt;
				if(m[x][y]==0||y==4){
					++l[x][cnt];
					lb[x][cnt]=i;
					break;
				}
			}
			cnt=0;
			for(int y=4;y>=1;--y){
				if(m[x][y]==1) ++cnt;
				if(m[x][y]==0||y==1){
					++r[x][cnt];
					rb[x][cnt]=i;
					break;
				}
			}
		}
		for(int x=1;x<=4;++x){
			int cnt=0;
			for(int y=1;y<=4;++y){
				if(m[y][x]==1) ++cnt;
				if(m[y][x]==0||y==4){
					++up[x][cnt];
					upb[x][cnt]=i;
					break;
				}
			}
			cnt=0;
			for(int y=4;y>=1;--y){
				if(m[y][x]==1) ++cnt;
				if(m[y][x]==0||y==1){
					++down[x][cnt];
					dob[x][cnt]=i;
					break;
				}
			}
		}
	}
	for(int i=0;i<=4;++i){
		for(int j=0;j<=4;++j)
			cout<<upb[i][j]<<" ";
		cout<<"fuck"<<endl;
	}
	for(int i=0;i<=4;++i){
		for(int j=0;j<=4;++j)
			cout<<dob[i][j]<<" ";
		cout<<"mucj"<<endl;
	}
	for(int i=1;i<=4;++i){
		temp=up[i][4]*4;
		for(int j1=3;j1>=0;--j1){
			bool flag=false;
			if(up[i][j1]==0) continue;
			for(int j2=3;j2>=0;--j2){
				if(down[i][j2]==0) continue;
				cout<<i<<" "<<j1<<" "<<j2<<" "<<up[i][j1]<<" "<<upb[i][j1]<<" "<<down[i][j2]<<" "<<dob[i][j2]<<endl;
				if(down[i][j2]>1){
					temp+=(j1+j2);
					flag=true;
					break;
				}
				else{
					if(up[i][j1]>1||upb[i][j1]!=dob[i][j2]){
						temp+=(j1+j2);
						flag=true;
						break;
					}
				}
			}
			if(flag) break;
		}
		cout<<temp<<endl;
		ans=max(ans,temp);
	}
	for(int i=1;i<=4;++i){
		temp=l[i][4]*4;
		for(int j1=3;j1>=0;--j1){
			bool flag=false;
			if(l[i][j1]==0) continue;
			for(int j2=3;j2>=0;--j2){
				if(r[i][j2]==0) continue;
				if(r[i][j2]>1){
					temp+=(j1+j2);
					flag=true;
					break;
				}
				else{
					if(l[i][j1]>1||lb[i][j1]!=rb[i][j2]){
						temp+=(j1+j2);
						flag=true;
						break;
					}
				}
			}
			if(flag) break;
		}
		ans=max(ans,temp);
	}
	printf("%d",ans);
	return 0;
}
