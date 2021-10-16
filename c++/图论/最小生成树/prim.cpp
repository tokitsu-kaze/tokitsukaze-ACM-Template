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
int prim()
{
	int res=0;
	node t,to;
	priority_queue<node> q;
	mem(dis,0x3f);
	mem(flag,0);
	dis[1]=0;
	q.push(node(1,dis[1]));
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(flag[t.id]) continue;
		flag[t.id]=1;
		res+=dis[t.id];
		for(int i=0;i<sz(mp[t.id]);i++)
		{
			to=mp[t.id][i];
			if(!flag[to.id]&&dis[to.id]>to.v)
			{
				dis[to.id]=to.v;
				q.push(node(to.id,dis[to.id]));
			}
		}
	}
	return res;
}
