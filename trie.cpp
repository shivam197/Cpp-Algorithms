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
class node
{
	public:
	char data;
	bool terminal;
	map<char,node*> children;

	node(char ch)
	{
		this->data = ch;
		this->terminal = false;
	}
};
class trie
{
	node *root;
	int count;
public:
	trie()
	{
		this->root = new node('\0');
		this->count = 0;
	}
	void addWord(string s)
	{	node *temp = root;
		for(auto i : s)
		{
			if(temp->children.count(i))
				{ temp = temp->children[i];}
			else
			{
				node *p = new node(i);
				temp->children[i] = p;
				temp = p;
			}
		}
		count++;
		temp->terminal = true;
	}
	bool search(string s)
	{
		node *temp = root;
		for(auto i : s)
		{
			if(temp->children.count(i))
				temp = temp->children[i];
			else
				return false;
		}
		return temp->terminal;
	}
	void showUtil(node *root, char *a,int i)
	{
		if(root->terminal)
			{	for(int j=0;j<i;j++)
					cout<<a[j];
				cout<<"\n";
			}
		if(root->children.size())
		{
			for(auto tp : root->children)
			{
				a[i] = tp.first;
				showUtil(tp.second,a,i+1);
			}
		}
		else
			return;
	}
	void show(string s)
	{
		char a[10000];
		memset(a,'a',sizeof(a));
		int ind=0;
		node *temp = root;
		for(auto i : s)
		{
			if(temp->children.count(i))
				{a[ind++]=i;
				 temp = temp->children[i];
				}
			else
			{
				addWord(s);
				cout<<"No suggestions\n";
				return;
			}
		}

		showUtil(temp,a,ind);
	}
};
void solve()
{
	trie t;
	int n;cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		t.addWord(s);
	}
	int q;
	cin>>q;
	while(q--)
	{
		string s;
		cin>>s;
		t.show(s);
	}
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	//FT()
		solve();
	return 0;
}
