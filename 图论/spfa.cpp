//最长路 dis变为-INF 松弛改成< 
struct node
{
	int id;
	int v;
	node(){}
	node(int a,int b) :id(a),v(b){}
};
vector<node> mp[MAX];
int dis[MAX];
bool flag[MAX]; 
void spfa(int s)
{
	queue<node> q;
	node t,to;
	mem(dis,0x3f);
	mem(flag,0);
	dis[s]=0;
	flag[s]=1;
	q.push(node(s,dis[s]));
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		flag[t.id]=0;
		for(int i=0;i<sz(mp[t.id]);i++)
		{
			to=mp[t.id][i];
			if(dis[to.id]>dis[t.id]+to.v)
			{
				dis[to.id]=dis[t.id]+to.v;
				if(!flag[to.id])
				{
					q.push(node(to.id,dis[to.id]));
					flag[to.id]=1;
				}
			}
		}
	}
}
