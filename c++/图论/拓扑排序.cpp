vector<int> topsort(vector<int> &node,vector<int> mp[],int *in)
{
	queue<int> q;
	for(auto &it:node)
	{
		if(!in[it]) q.push(it);
	}
	vector<int> toplist;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		toplist.push_back(x);
		for(auto &to:mp[x])
		{
			in[to]--;
			if(!in[to]) q.push(to);
		}
	}
	return toplist;
}
