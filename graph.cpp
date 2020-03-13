#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007
#define FT() int t; scanf("%d",&t); while(t--)
#define pb push_back
#define nl printf("\n")
#define fi(i,start,end) for(int i=start; i < end ; ++i)
#define fd(i,end,start) for(int i=end-1;i>=start; --i)
#define ip(n)	scanf("%d",&n)
#define op(n)	printf("%d",n)
#define mz(a) 	memset(a,0,sizeof(a))
#define inpArr(A,n) fi(i,0,n)	ip(A[i]);
#define dispArr(A,n)	fi(i,0,n) printf("%d ",A[i]); nl;
#define Fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
class Graph
{
	int V;
	vector<int> *adj;
public:
	Graph(int v)
	{
		this->V = v;
		adj = new vector<int>[V+1];
	}
	void addEdge(int u,int v,bool bidir);
	void printAdj();
	void bfs(int root);
	void dfs(int root);
	void dfsUtil(int root,bool *visited);
	bool iscycleBFS(int root);
	bool iscycleDFS(int root);
	bool iscycleDFSUtil(int root,int *parent,bool *visited);
};
void Graph::addEdge(int u,int v,bool bidir=true)
{
	adj[u].pb(v);
	if(bidir)
		adj[v].pb(u);
}
void Graph::printAdj()
{
	fi(i,1,V+1)
	{
		cout<<i<<" : ";
		for(auto j : adj[i])
				cout<<j<<" ";
		nl;
	}
}
void Graph::bfs(int root = 1)
{
	bool visited[V+1];
	mz(visited);
	queue<int> q;
	q.push(root);
	visited[root] = 1;
	while(q.size())
	{
		root = q.front();
		cout<<root<<" ";
		q.pop();
		for(auto i : adj[root])
			if(!visited[i])
				q.push(i),visited[i] = 1;
	}
	nl;
}
void Graph::dfsUtil(int root,bool *visited)
{
	cout<<root<<" ";
	visited[root] = true;
	for(auto i : adj[root])
		if(!visited[i])
			dfsUtil(i,visited);
}
void Graph::dfs(int root =1)
{
	bool visited[V+1];
	mz(visited);
	dfsUtil(root,visited);
	nl;
}
bool Graph::iscycleBFS(int root = 1)
{
	bool visited[V+1];
	mz(visited);
	int parent[V+1];
	queue<int> q;
	q.push(root);
	visited[root] = 1;
	parent[root] = root;
	while(q.size())
	{	root = q.front();
		q.pop();
		for(auto i : adj[root])
			{if(visited[i] && parent[root]!=i)
				return 1;
			 else if(!visited[i])
			 	{q.push(i);visited[i] = true;
			 	 parent[i] = root;
			 	}
			}
	}
	return 0;
}
bool Graph::iscycleDFSUtil(int root,int *parent,bool *visited)
{
	for(auto i : adj[root])
	{
		if(visited[i] && parent[root]!=i)
			return 1;
		else if(!visited[i])
		{
			visited[i] = true;
			parent[i] = root;
			return iscycleDFSUtil(i,parent,visited);
		}
	}
	return 0;
}
bool Graph::iscycleDFS(int root=1)
{
	int parent[V+1];
	bool visited[V+1];
	mz(visited);
	parent[root] = root;
	return iscycleDFSUtil(root,parent,visited);
}

int main() {
	Graph g(4);
	g.addEdge(1,2);
	g.addEdge(4,2);
	//g.addEdge(1,3);
	g.addEdge(2,3);
	//g.bfs();
	g.printAdj();nl;
	cout<<g.iscycleDFS();
	
	return 0;
}
