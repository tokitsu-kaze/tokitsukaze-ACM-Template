vector<pair<int,int>> gen_random_graph(int n,int m)
{
	int i,j;
	set<pair<int,int>> res;
	vector<int> p;
	for(i=1;i<=n;i++) p.push_back(i);
	random_shuffle(p.begin(),p.end());
	for(i=1;i<n;i++)
	{
		j=rand_next(0,i-1);
		if(p[i]<p[j]) res.insert({p[i],p[j]});
		else res.insert({p[j],p[i]});
	}
	while(res.size()<m)
	{
		int a,b;
		a=rand_next(1,n);
		b=rand_next(1,n);
		if(a==b) continue;
		if(a>b) swap(a,b);
		if(res.count({a,b})) continue;
		res.insert({a,b});
	}
	vector<pair<int,int>> tmp;
	for(auto it:res)
	{
		if(rand_next(0,1)) tmp.push_back({it.second,it.first});
		else tmp.push_back(it);
	}
	random_shuffle(tmp.begin(),tmp.end());
	return tmp;
}
vector<pair<int,int>> gen_full_graph(int n,int m)
{
	int i,j;
	set<pair<int,int>> res;
	vector<int> p;
	for(i=1;i<=n;i++) p.push_back(i);
	random_shuffle(p.begin(),p.end());
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			res.insert({p[i],p[j]});
		}
	}
	vector<pair<int,int>> tmp;
	for(auto it:res) tmp.push_back(it);
	random_shuffle(tmp.begin(),tmp.end());
	return tmp;
}
vector<pair<int,int>> gen_chrysanthemum_graph(int n,int m)
{
	int i,j;
	set<pair<int,int>> res;
	vector<int> p;
	for(i=1;i<=n;i++) p.push_back(i);
	random_shuffle(p.begin(),p.end());
	for(i=1;i<n;i++) res.insert({p[0],p[i]});
	for(i=2;i<n;i++)
	{
		int mm=rand_next(0,min(20,i-1));
		while(mm--)
		{
			if(res.size()==m) break;
			res.insert({p[rand_next(0,i-1)],p[i]});
		}
	}
	vector<pair<int,int>> tmp;
	for(auto it:res) tmp.push_back(it);
	random_shuffle(tmp.begin(),tmp.end());
	return tmp;
}
vector<pair<int,int>> gen_chrysanthemum_tree(int n,int m)
{
	int i,j;
	set<pair<int,int>> res;
	vector<int> p;
	for(i=1;i<=n;i++) p.push_back(i);
	random_shuffle(p.begin(),p.end());
	for(i=1;i<n;i++) res.insert({p[0],p[i]});
	vector<pair<int,int>> tmp;
	for(auto it:res) tmp.push_back(it);
	random_shuffle(tmp.begin(),tmp.end());
	return tmp;
}
vector<pair<int,int>> gen_single_chain(int n,int m)
{
	int i,j;
	set<pair<int,int>> res;
	vector<int> p;
	for(i=1;i<=n;i++) p.push_back(i);
	random_shuffle(p.begin(),p.end());
	for(i=1;i<n;i++) res.insert({p[i-1],p[i]});
	vector<pair<int,int>> tmp;
	for(auto it:res) tmp.push_back(it);
	random_shuffle(tmp.begin(),tmp.end());
	return tmp;
}
vector<pair<int,int>> gen_random_tree(int n,int m)
{
	int i,j;
	set<pair<int,int>> res;
	vector<int> p;
	for(i=1;i<=n;i++) p.push_back(i);
	random_shuffle(p.begin(),p.end());
	for(i=1;i<n;i++) res.insert({p[rand_next(0,i-1)],p[i]});
	vector<pair<int,int>> tmp;
	for(auto it:res) tmp.push_back(it);
	random_shuffle(tmp.begin(),tmp.end());
	return tmp;
}
vector<pair<int,int>> gen_circle_tree_based_on_single_chain(int n,int m)
{
	int i,j;
	set<pair<int,int>> res;
	vector<int> p;
	for(i=1;i<=n;i++) p.push_back(i);
	random_shuffle(p.begin(),p.end());
	for(i=1;i<n;i++) res.insert({p[i-1],p[i]});
	res.insert({p[n-1],p[0]});
	vector<pair<int,int>> tmp;
	for(auto it:res) tmp.push_back(it);
	random_shuffle(tmp.begin(),tmp.end());
	return tmp;
}
vector<pair<int,int>> gen_circle_tree_based_on_random_tree(int n,int m)
{
	int i,j;
	set<pair<int,int>> res;
	vector<int> p;
	for(i=1;i<=n;i++) p.push_back(i);
	random_shuffle(p.begin(),p.end());
	for(i=1;i<n;i++) res.insert({p[rand_next(0,i-1)],p[i]});
	while(res.size()<n)
	{
		int a=rand_next(1,n);
		int b=rand_next(1,n);
		if(a==b) continue;
		if(res.count({a,b}) || res.count({b,a})) continue;
		res.insert({a,b});
	}
	assert(res.size()==n);
	vector<pair<int,int>> tmp;
	for(auto it:res) tmp.push_back(it);
	random_shuffle(tmp.begin(),tmp.end());
	return tmp;
}
