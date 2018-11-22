//kruskal
int pre[MAX],ans;
struct node
{
	int x,y,v;
	node(){}
	node(int a,int b,int c):x(a),y(b),v(c){}
	friend bool operator<(node a,node b)
	{
		return a.v<b.v;
	}
}a[MAX];
void init(int n)
{
	for(int i=1;i<=n;i++) pre[i]=i;
}
int find(int x)
{
	if(pre[x]!=x) pre[x]=find(pre[x]);
	return pre[x];
}
void merge(node s)
{
	int rx,ry;
	rx=find(s.x);
	ry=find(s.y);
	if(rx!=ry)
	{
		pre[rx]=ry;
		ans+=s.v;
	}
}
void kruskal(int n,int m,node *s)
{
	init(n);
	ans=0; 
	sort(s,s+m);
	for(int i=0;i<m;i++) merge(s[i]);
} 
