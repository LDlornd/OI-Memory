#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAX 501

int Dfn[MAX],vis[MAX],Low[MAX];
bool cut[MAX];
long long Num,Cut,Time,root,rs,m,n,Ans1,Ans2,Case,Group;

void Init();//????,??? 

struct Node  //??? 
{
       int v,next;
}e[MAX*MAX];

int h[MAX],cnt;

void Add(int u,int v)  //??? 
{
      e[cnt]=(Node){v,h[u]};
      h[u]=cnt++;
}

void Tarjan(int u,int f)  //Tarjan?????? 
{
       int v;
       Dfn[u]=Low[u]=++Time;   

       for(int i=h[u];i!=-1;i=e[i].next)//?????????? 
       {
                v=e[i].v;
                if(!Dfn[v])  //???????,??v?u???? 
                {
                       Tarjan(v,u);
                       Low[u]=min(Low[u],Low[v]); //??Low? 
                       if(Low[v]>=Dfn[u])  //??v????u??u??? 
                       {
                               if(u!=root)    //??u???????? 
                                   cut[u]=true; //u??? 
                               else 
                                   rs++;      //????????? 
                       }
                }
                else
                   if(v!=f)    //??v??u????,??v????? 
                      Low[u]=min(Low[u],Dfn[v]);  //????????Low 
       }
}

void DFS(int u)//DFS??????? 
{
        int v;

        vis[u]=Group; //??? 
        Num++;        //???? 

        for(int i=h[u];i!=-1;i=e[i].next)//????? 
        {
               v=e[i].v;
               if(cut[v]&&vis[v]!=Group) //??v?????v???????????? 
               {
                        Cut++;         //????? 
                        vis[v]=Group;  //???? 
               }
               if(!vis[v])     //??vis????? 
                   DFS(v);     //??v 
        }
}

int main()
{
       long long u,v;       
       Case=1;

       while(cin>>m&&m)
       {
              Init(); //??? 

           for(int i=1;i<=m;++i)//??? 
           {
                   cin>>u>>v;
                   Add(u,v);
                   Add(v,u);
                   n=max(n,v);
                   n=max(n,u);
           }

           for(int i=1;i<=n;++i)//Tarjan????? 
           {
                     if(!Dfn[i])
                     {
                              root=i;
                              rs=0;
                              Tarjan(i,i);
                              if(rs>=2)       //??????????????2?,?????????? 
                                  cut[i]=true;
                     }
           }

           for(int i=1;i<=n;++i)//?????????? 
           {
                    if(!vis[i]&&!cut[i])//??i?????????????? 
                    {
                            ++Group;  //?????? 
                            Num=Cut=0;
                            DFS(i);   //?????? 

                            if(Cut==0)//?????? 
                            {
                                      Ans1+=2;//?????????? 
                                      Ans2*=(Num-1)*Num/2;//???????????????? 
                            }

                            if(Cut==1)//???????????? 
                            {
                                Ans1+=1;  //????????????? 
                                Ans2*=Num;//??????????????? 
                            }

                            if(Cut>=2)//???????????,?????,??????????? 
                            {
                                ; 
                        } 
                    }
           }

           cout<<"Case "<<Case++<<": "<<Ans1<<" "<<Ans2<<endl;//????     
       }

       return 0; 
}

void Init()
{
       memset(h,-1,sizeof(h));
       memset(Dfn,0,sizeof(Dfn));
       memset(Low,0,sizeof(Low));
       memset(cut,0,sizeof(cut));
       memset(vis,0,sizeof(vis));
       Time=cnt=n=Ans1=Group=0;
       Ans2=1;
}
