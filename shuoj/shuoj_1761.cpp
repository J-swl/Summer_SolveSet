////#include<iostream>
////#include<algorithm>
////#include<vector>
////#include<queue>
////#include<vector>
////#include<cmath>
////#include<cstdio>
////#include<cstring>
////#include<string>
////#include<stack>
////#include<map>
////#include<set>
////using namespace std;
////
//////thanks to pyf ...
////
////#define INF 0x3f3f3f3f
////#define CLR(x,y) memset(x,y,sizeof(x))
////#define mp(x,y) make_pair(x,y)
////typedef pair<int, int> PII;
////typedef long long ll;
////
////const int N = 1e6 + 5;
////
////struct Edge
////{
////	int u, v, next;
////} edge[N * 2];
////struct Query
////{
////	int id, u, v, lca, next;
////	bool if_out;
////} Q[N * 2];
////
////int tot = 0;
////int q_tot = 0;
////int head[N];
////int qhead[N];
////int vis[N];
////int anc[N];
////int fa[N];
////int indeg[N];
////int ans[N];
////void init()
////{
////	CLR(ans, 0);
////	CLR(anc, 0);
////	CLR(indeg, 0);
////	CLR(Q, 0);
////	CLR(edge, 0);
////	CLR(vis, 0);
////	CLR(head, -1);
////	CLR(qhead, -1);
////	tot = 0;
////	q_tot = 0;
////	for (int i = 0; i < N; i++)
////		fa[i] = i;
////}
////void add_edge(int u, int v)
////{
////	edge[tot].u = u;
////	edge[tot].v = v;
////	edge[tot].next = head[u];
////	head[u] = tot ++;
////}
////void add_q(int u, int v, int id)
////{
////	Q[q_tot].if_out = 0;
////	Q[q_tot].u = u;
////	Q[q_tot].v = v;
////	Q[q_tot].next = qhead[u];
////	Q[q_tot].id = id;
////	qhead[u] = q_tot ++;
////}
////int find(int x)
////{
////	if (x != fa[x])
////		fa[x] = find(fa[x]);
////	return fa[x];
////}
////void merge(int u, int v)
////{
////	u  = find(u);
////	v = find(v);
////	if (u != v)
////		fa[u] = v;
////}
////void lca(int u)
////{
////	fa[u] = u;
////	for (int i = head[u]; i != -1; i = edge[i].next)
////	{
////		int v = edge[i].v;
////		lca(v);
////		fa[v] = u;
////		// merge(u, v);
////		// anc[find(u)] = u;
////	}
////	vis[u] = 1;
////	for (int i = qhead[u]; i != -1; i = Q[i].next)
////	{
////		int v = Q[i].v;
////		if (vis[v])
////		{
////			Q[i].if_out = 1;
////			//	ans[Q[i].id] = anc[find(v)];
////			ans[Q[i].id] = find(v);
////		}
////	}
////}
////int main()
////{
////	int T;
////	scanf("%d", &T);
////	int ka = 0;
////	while (T--)
////	{
////		int n;
////		init();
////		scanf("%d", &n);
////		for (int i = 0; i < n; i++)
////		{
////			int u, v;
////			scanf("%d%d", &u, &v);
////			add_edge(u, v);
////			indeg[v] ++ ;
////		}
////		int m;
////		scanf("%d", &m);
////		for (int i = 0; i < m; i++)
////		{
////			int q_u, q_v;
////			scanf("%d%d", &q_u, &q_v);
////			add_q(q_u, q_v, i);
////			add_q(q_v, q_u, i);
////		}
////		for (int i = 0; i <= n; i++)
////			if (!indeg[i])
////				lca(i);
////		int cnt = 0;
////		printf("Case %d:\n", ++ka);
////		for (int i = 0; i < m; i++)
////		{
////			printf("%d", ans[i]);
////			i == m - 1 ? printf("\n") : printf(" ");
////		}
////		// for (int i = 0; i < q_tot; i++)
////		// {
////		// 	if (Q[i].if_out)
////		// 	{
////		// 		cnt ++ ;
////		// 		printf("%d", Q[i].lca);
////		// 		if (cnt == m)
////		// 		{
////		// 			printf("\n");
////		// 			break;
////		// 		}
////		// 		else	printf(" ");
////		// 	}
////		// }
////	}
////}
//
//#include<bits/stdc++.h>
//
//using namespace std;
//
////thanks to pyf ...
////thanks to qhl ...
//
//
//const int N = 1e5 + 5;
//
//struct Edge
//{
//	int u,v,next;
//}edge[N*2];
//
//struct Query
//{
//	int u,v;
//	int id;
//	int next;
//}Q[N*2];
//
//
//int vis[N];
//int ans[N];
//int fa[N];
//int head[N];
//int qhead[N];
//int tot  = 0;
//int q_tot = 0;
//void init()
//{
//	memset(vis,0,sizeof(vis));
//	memset(ans,0,sizeof(ans));
//	memset(head,-1,sizeof(head));
//	memset(qhead,-1,sizeof(qhead));
//	tot = 0;
//	q_tot =0;
//
//}
//void add_edge(int u,int v)
//{
//	edge[tot].u = u;
//	edge[tot].v = v;
//	edge[tot].next = head[u];
//	head[u] = tot ++;
//}
//void add_q(int u,int v,int id)
//{
//	Q[q_tot].u = u;
//	Q[q_tot].v = v;
//	Q[q_tot].id = id;
//	Q[q_tot].next = qhead[u];
//	qhead[u] = q_tot++;
//}
//int find(int x)
//{
//	if(fa[x] != x)
//		fa[x] = find(fa[x]);
//	return fa[x];
//}
//void lca(int u,int Fa)
//{
//	fa[u] = u;
//	vis[u] = 1;
//	for(int i =head[u];i!=-1;i=edge[i].next)
//	{
//		int v = edge[i].v;
//		if(v==Fa)
//			continue;
//		lca(v,u);
//		fa[v] = u;
//	}
//	for(int i = qhead[u];i!=-1;i=Q[i].next)
//	{
//		int v = Q[i].v;
//		if(vis[v])
//			ans[Q[i].id] = find(v);
//	}
//}
//int root[N];
//int main()
//{
//	int T;
//	scanf("%d",&T);
//	while(T--)
//	{
//		init();
//		int n;
//		scanf("%d",&n);
//		int cnt_root = 0;
//		for(int i = 0;i<n;i++)
//		{
//			int u,v;
//			scanf("%d%d",&u,&v);
//			add_edge(u,v),add_edge(v,u);
//		}
//		int m;
//		scanf("%d",&m);
//		for(int i =0 ;i<m;i++)
//		{
//			int u,v;
//			scanf("%d%d",&u,&v);
//			add_q(u,v,i);
//			add_q(v,u,i);
//		}
//		lca(0,0);
//		for(int i =0;i<m;i++) {
//			if (i) printf(" ");
//			printf("%d", ans[i]);
//		}
//		printf("\n");
//	}
//}
//
#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5+7;

struct Edge
{
	int u,v,next;
}edge[N*2];

int head[N];
int fa[N][21],deep[N];
int tot = 0;
void init()
{
	memset(head,-1,sizeof(head));
	tot = 0;
}
void add_edge(int u,int v)
{
	edge[tot] = {u,v,head[u]};
	head[u] = tot ++;
}
void dfs(int u,int d,int Fa)
{
	deep[u] = d,fa[u][0] = Fa;
	for(int i = 1;i<=20;i++)
		fa[u][i] = fa[fa[u][i-1]][i-1];
	for(int i = head[u];~i;i=edge[i].next)
	{
		int v = edge[i].v;
		if(v == Fa)
			continue;
		dfs(v,d+1,u);
	}
}
int lca(int x,int y)
{
	if(deep[x] < deep[y])
		swap(x,y);
	for(int i = 20;i>=0;i--)
		if(deep[fa[x][i]] >= deep[y])
			x = fa[x][i];
	if(x == y)
		return x;
	for(int i = 20;i>=0;i--)
		if(fa[x][i] != fa[y][i])
			x = fa[x][i],y = fa[y][i];
	return fa[x][0];
}
int main()
{
	int T;
	scanf("%d",&T);
	int n;
	int ka = 0;
	while(T--)
	{
		init();
		scanf("%d",&n);
		for(int i = 0;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add_edge(u,v);
			add_edge(v,u);
		}
		int q;
		scanf("%d",&q);
		printf("Case %d:\n",++ka);
		dfs(0,0,0);
		for(int i = 0;i<q;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			if(i)
				printf(" ");	
			printf("%d",lca(u,v));
		}
		printf("\n");
	}
}
