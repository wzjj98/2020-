#include <algorithm>
#include <stack>
#include <istream>
#include <stdio.h>
#include <map>
#include <math.h>
#include <vector>
#include <iostream>
#include <queue>
#include <string.h>
#include <set>
#include<time.h>
#include <cstdio>
#define FR(i,n) for(int i=0;i<n;i++)
#define MAX 2005
#define MAXTIME 28800
#define mkp pair <int,int>
using namespace std;
typedef long long ll;
const int inf = 100000000;
const int maxn = 1e3+5;

using namespace std;


struct node{
int id;
double dis;
bool operator <(const node &a)const{
return dis>a.dis;
}
};
struct node1{
int id,dis;
bool operator <(const node1 &a)const{
return dis>a.dis;
}
};

struct inof{
int y;
double val;
int nxt;
}p[maxn];

struct inof1{
int y;
int nxt;
int huancheng;
int type;
}pp[maxn];
map < string ,  int > mp;
int tot=0;
int head[maxn],cnt;

int head1[maxn],cnt1;


vector < pair<int,int> >  vec[maxn];

map < pair<int,string>, int > mpp; /// pair type & 地点
int temp=0;
int total=0;

void add(string a,string b,int dis,int type){
	/// 第一个图
		 printf("录入信息成功\n");
		 cout<<a<<"到"<<b<<"距离为"<<dis;
		 if(type==1||type==2){
				printf("类型为%d的地铁\n",type);
		 }
		 else if(type==3||type==4){
				printf("类型为%d的公交\n",type);
		 }
		if(!mp[b])
				mp[b]=++tot;
		if(!mp[a])
				mp[a]=++tot;
	int to=mp[b];
	int from=mp[a];
	p[++cnt].y=to;
	if(type==1||type==2)
				p[cnt].val=dis/2.0;/// 花费的时间
	else if(type==3||type==4)
	    p[cnt].val=dis/1.0;
	p[cnt].nxt=head[from];
	head[from]=cnt;
		/// 邻接表

	p[++cnt].y=from;
	if(type==1||type==2)
				p[cnt].val=dis/2.0;/// 花费的时间
	else if(type==3||type==4)
	    p[cnt].val=dis/1.0;
	p[cnt].nxt=head[to];
	head[to]=cnt;/// 0a


	///第二个图 求最小换乘次数
	///第二 第三个 图 共用一个图
//	foor(int i=0;i<siz;i++)
	pair < int , string > t1,t2;//
	t1.first = type ;
		t1.second = a;
	t2.first = type ;
		t2.second = b;
		if(!mpp[t1])
				mpp[t1]=++temp;
		if(!mpp[t2])
				mpp[t2]=++temp;


		int aa = mpp[t1],bb = mpp[t2]; ///  点
 //   cout<<aa<<' '<<bb<<endl;
	pp[++cnt1].y=bb;
	pp[cnt1].huancheng=0;/// 花费的时间
	pp[cnt1].type=type;
	pp[cnt1].nxt=head1[aa];
	head1[aa]=cnt1;

	pp[++cnt1].y=aa;
	pp[cnt1].huancheng=0;/// 花费的时间
	pp[cnt1].nxt=head1[bb];
	pp[cnt1].type=type;
	head1[bb]=cnt1;/// 邻接表

	int siz=vec[to].size(); /// to 地点

	for(int i=0;i<siz;i++){
		if(vec[to][i].second!=type){
		   int hh=vec[to][i].first;
	       pp[++cnt1].y=bb;
	       pp[cnt1].huancheng=1;///
	       pp[cnt1].nxt=head1[hh];
	       pp[cnt1].type=0;
	       if(vec[to][i].second==1||vec[to][i].second==2){
	       	  if(type==1||type==2){
	       	  	     pp[cnt1].type=type;
				 }
		   }
	       head1[hh]=cnt1;

	       pp[++cnt1].y=hh;
	       pp[cnt1].huancheng=1;///
	       pp[cnt1].nxt=head1[bb];
	       pp[cnt1].type=0;
	       if(vec[to][i].second==1||vec[to][i].second==2){
	       	  if(type==1||type==2){
	       	  	     pp[cnt1].type=type;
				 }
		   }
	       head1[bb]=cnt1;
		}
	}

		siz=vec[from].size();
	for(int i=0;i<siz;i++){
		if(vec[from][i].second!=type){
		   int hh=vec[from][i].first;
	       pp[++cnt1].y=aa;
	       pp[cnt1].huancheng=1;/// 花费的时间
	       pp[cnt1].nxt=head1[hh];
		   pp[cnt1].type=0;
	       if(vec[from][i].second==1||vec[from][i].second==2){
	       	  if(type==1||type==2){
	       	  	     pp[cnt1].type=type;
				 }
		   }
	       head1[hh]=cnt1;

	       pp[++cnt1].y=hh;
	       pp[cnt1].huancheng=1;/// 花费的时间
	       pp[cnt1].nxt=head1[aa];
	       if(vec[from][i].second==1||vec[from][i].second==2){
	       	  if(type==1||type==2){
	       	  	     pp[cnt1].type=type;
				 }
		   }
	       head1[aa]=cnt1;
		}
	}
	vec[to].push_back(make_pair(bb,type));
	vec[from].push_back(make_pair(aa,type));
}
void init(){ /// 添加边的信息
	add("北京","上海",4,3);
	 // add("厦门","四川",1,2);
		 add("上海","15",6,3);
add("15","重庆",3,3);
add("重庆","四川",4,3);
add("吉林","浙江",3,4);
add("浙江","13",2,4);
	add("13","12",2,4);
		 add("12","昆明",2,4);
		 add("昆明","湖北",5,4);
		 add("湖北","湖南",4,4);
		 add("厦门","沈阳",2,2);
		 add("沈阳","海南",2,2);
		 add("海南","11",2,2);
		 add("11","15",2,2);
		 add("15","18",2,2);
		 add("18","深圳",2,2);
		 add("哈尔滨","内蒙古",2,1);
		 add("内蒙古","10",2,1);
		 add("10","11",2,1);
		 add("11","12",2,1);
		 add("12","13",2,1);
		 add("13","14",2,1); }
double dis[maxn];
int solveA(){
		string a,b;
		printf("请输入两地名称\n");
		cin>>a>>b;
	int s=mp[a];
	int ans=mp[b];
	for(int i=0;i<=tot;i++)
				dis[i]=2147483647;
	priority_queue<node>st;
	dis[s]=0;
	st.push((node){s,0});
	while(!st.empty()){
		struct node f=st.top();
				st.pop();
		int u=f.id;
		int d=f.dis;
		if(d!=dis[u])
						continue;
		for(int i=head[u];i;i=p[i].nxt){
			if(dis[p[i].y]>d+p[i].val){
				dis[p[i].y]=d+p[i].val;
				st.push((node){p[i].y,dis[p[i].y]});
			}
		}
	}
		cout<<dis[ans]<<endl;
}/// 堆优化的dij nlogn   最短时间



int dis1[maxn];
int getans(int a,int b){     //换乘次数
	int s=a;
	int ans=b;
	for(int i=0;i<=maxn;i++)
				dis1[i]=2147483647;
	priority_queue<node1>st;
	dis1[s]=0;
	st.push((node1){s,0});
	while(!st.empty()){
		struct node1 f=st.top();st.pop();
		int u=f.id;int d=f.dis;
		if(d!=dis1[u])continue;
		for(int i=head1[u];i;i=pp[i].nxt){
			if(dis1[pp[i].y]>d+pp[i].huancheng){
				dis1[pp[i].y]=d+pp[i].huancheng;
				st.push((node1){pp[i].y,dis1[pp[i].y]});
			}
		}
	}
	//for(int i=1;i<=n;i++)
	return dis1[ans];
}
void solveB(){       //最小换乘次数
		string a,b;
		printf("请输入两地名称\n");
		cin>>a>>b;
		 int id1=mp[a],id2=mp[b];
	 int s1=vec[id1].size(),s2=vec[id2].size();
	 int ans=0xfffff;
	 for(int i=0;i<s1;i++){
	 	for(int j=0;j<s2;j++){
	 		ans=min(ans,getans(vec[id1][i].first,vec[id2][j].first));
		 }
	 }
	 cout<<ans<<endl;
}

int cost=0;
int anscost=100000000;
int dp[maxn];
int vis[maxn];
map < pair <int ,int > , int > visi;
void dfs(int u,int d,int last,int lasttype,int costnow){         //最小花费
	 if(u==last){
				if(d){
						if(d>=7)
								costnow+=7;
						else
								costnow+=4;
				}
				if(costnow==0)
						return ;
	 	anscost=min(anscost,costnow);
	 	return ;
	 }
	 for(int i=head1[u];i;i=pp[i].nxt){
	 	 int ty = pp[i].type;
	 	 int v = pp[i].y;
	     if(lasttype==0){
					 if(d){
							if(d>=7)
									costnow+=7;
							else
									costnow+=4;/// 换乘 由 地铁下车 做公交或者由公交下车坐地铁
							d=0;
						}
						if(ty==0){
								if(lasttype==0&&ty==0){
										pair <int ,int > tmp;
										tmp.first=u,tmp.second=v;
										if(visi[tmp])
												continue;
										visi[tmp]=1;
								}
								if(dp[v]>costnow){
								dp[v]=costnow;
								dfs(v,d,last,ty,costnow);
								}
						}
						if(ty==1||ty==2){
								dfs(v,d+1,last,ty,costnow);
						}
						else {
								dfs(v,d,last,ty,costnow+2);
						}///做公交

	     }
					else {
	 	 if(ty==1||ty==2){
	 	 	if(lasttype!=1&&lasttype!=2){/// 公交换地铁
	 	 		// cost+=2;///
	 	 		 if(dp[v]>costnow+2){
	 	 		   dp[v]=costnow+2;
				   dfs(v,d,last,ty,costnow+2);
		      	}
			  }
			else {
				if(dp[v]>costnow){
				dp[v] = costnow;
			    dfs(v,d+1,last,ty,costnow);
		//		d++;
	     		}
			}
		  }
		  else if(ty==3||ty==4){
		  	if(lasttype!=3&&lasttype!=4){///  地铁换公交
		  	     int h;
		  		 if(d>=7)
										h=costnow+7;
		  		 else
		  		    h=costnow+4;
		  		 d=0;
		  		 if(dp[v]>h){
		  		 	dp[v]=h;
		  		 	dfs(v,d,last,ty,h);
				   }
			  }
			  else {
			  	 /// 公交继续做公交
				  if(dp[v]>costnow){
				  	dp[v]=costnow;
				  	dfs(v,d,last,ty,costnow);
				  }
			  }
		  }
					}
				 //dfs(pp[i].y,)
	 }
}
void solveC() {
		string a,b;
		printf("请输入两地名称\n");
		cin>>a>>b;
		 cost=anscost=100000;
		 memset(dp,127/3,sizeof(dp));
		 int id1=mp[a],id2=mp[b];
		 dfs(id1,0,id2,0,0);
		 cout<<anscost<<endl;
}
int choice;
void show(){
		 printf("欢迎来到沈阳公共交通出行路线推荐系统\n");
		 printf("1 选择两点之间的最小时间\n");
		 printf("2 选择两点之间的最小换乘次数\n");
		 printf("3 选择两点之间的最小花费\n");
		 printf("请输入选择");
		 cin>>choice;
}
int main() {
	init();
	while(1){
				show();
				if(choice==1)
						solveA();/// solvea  求最小时间路径
				else if(choice==2)
						solveB() ;/// 求最小换乘次数
				else if(choice==3)
						solveC();
				else break;
	}
	return 0;
}