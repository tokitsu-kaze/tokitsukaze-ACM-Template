int head[MAX],tot;
struct node{int to,nex;int v} mp[MAXE];
void init()
{
	memset(head,-1,sizeof head);
	tot=0;
}
void add_edge(int x,int y,int v)
{
	mp[tot].v=v;
	mp[tot].to=y;
	mp[tot].nex=head[x];
	head[x]=tot++;
}

