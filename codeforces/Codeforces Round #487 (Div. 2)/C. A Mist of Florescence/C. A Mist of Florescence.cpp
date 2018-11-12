#include<cstdio>
#include<iostream>
using namespace std;
char choose[501],mp[51][51];
int a,b,c,d,i,j;
int main(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(i=1;i<=25;++i)
		for(j=1;j<=25;++j)
			mp[i][j]='A';
	for(i=1;i<=25;++i)
		for(j=26;j<=50;++j)
			mp[i][j]='B';
	for(i=26;i<=50;++i)
		for(j=1;j<=25;++j)
			mp[i][j]='C';
	for(i=26;i<=50;++i)
		for(j=26;j<=50;++j)
			mp[i][j]='D';
	i=1;j=27;
	while(--a){
		mp[i][j]='A';
		i=(j==49)?(i+2):i;
		j=(j==49)?27:(j+2);
	}
	i=27;j=1;
	while(--b){
		mp[i][j]='B';
		i=(j==25)?(i+2):i;
		j=(j==25)?1:(j+2);
	}
	i=27;j=27;
	while(--c){
		mp[i][j]='C';
		i=(j==49)?(i+2):i;
		j=(j==49)?27:(j+2);
	}
	i=1;j=1;
	while(--d){
		mp[i][j]='D';
		i=(j==25)?(i+2):i;
		j=(j==25)?1:(j+2);
	}
	printf("50 50\n");
	for(int i=1;i<=50;++i){
		for(int j=1;j<=50;++j){
			printf("%c",mp[i][j]);
		}
		printf("\n");
	}
	return 0;
}
