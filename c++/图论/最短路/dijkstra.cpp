struct node
{
	int id;
	int v;
	node(){}
	node(int a,int b) :id(a),v(b){}
	friend bool operator <(node a,node b){return a.v>b.v;}
};
vector<node> mp[MAX];
bool flag[MAX];
int dis[MAX];
void dij(int s)
{
	priority_queue<node> q;
	node t,to;
	mem(dis,0x3f);
	mem(flag,0);
	dis[s]=0;
	q.push(node(s,0));
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(flag[t.id]) continue;
		flag[t.id]=1;
		for(int i=0;i<sz(mp[t.id]);i++)
		{
			to=mp[t.id][i];
			if(dis[to.id]>dis[t.id]+to.v)
			{
				dis[to.id]=dis[t.id]+to.v;
				q.push(node(to.id,dis[to.id]));
			}
		}
	}
}
