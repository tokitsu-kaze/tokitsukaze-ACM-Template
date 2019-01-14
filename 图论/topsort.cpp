VI mp[MAX];
int degree[MAX];
VI toplist;
bool topsort(int n)
{
	int i,x;
	queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(!degree[i]) q.push(i);
	}
	toplist.clear();
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		toplist.pb(x);
		for(auto to:mp[x])
		{
			degree[to]--;
			if(!degree[to]) q.push(to);
		}
	}
	return !(sz(toplist)==n);
}
