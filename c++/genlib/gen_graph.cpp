
mt19937_64 rd(time(0));
ll rand_next(ll l,ll r)
{
	return (l+(ll(rd()%(r-l+1))));
}

VPII gen_random_graph(int n,int &m)
{
	int i,j;
	set<PII > res;
	VI p;
	for(i=1;i<=n;i++) p.pb(i);
	random_shuffle(all(p));
	for(i=1;i<n;i++)
	{
		res.insert(MP(p[rand_next(0,i-1)],p[i]));
	}
	for(i=100;i<n;i++)
	{
		int mm=rand_next(0,20);
		while(mm--)
		{
			if(sz(res)==m) break;
			res.insert(MP(p[rand_next(0,i-1)],p[i]));
		}
		
	}
	m=sz(res);
	VPII tmp;
	for(auto it:res) tmp.pb(it);
	random_shuffle(all(tmp));
	return tmp;
}

VPII gen_full_graph(int n)
{
	int i,j;
	set<PII > res;
	VI p;
	for(i=1;i<=n;i++) p.pb(i);
	random_shuffle(all(p));
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			res.insert(MP(p[i],p[j]));
		}
	}
	VPII tmp;
	for(auto it:res) tmp.pb(it);
	random_shuffle(all(tmp));
	return tmp;
}

VPII gen_chrysanthemum_graph(int n,int &m)
{
	int i,j;
	set<PII > res;
	VI p;
	for(i=1;i<=n;i++) p.pb(i);
	random_shuffle(all(p));
	for(i=1;i<n;i++) res.insert(MP(p[0],p[i]));
	for(i=2;i<n;i++)
	{
		int mm=rand_next(0,min(20,i-1));
		while(mm--)
		{
			if(sz(res)==m) break;
			res.insert(MP(p[rand_next(0,i-1)],p[i]));
		}
		
	}
	m=sz(res);
	VPII tmp;
	for(auto it:res) tmp.pb(it);
	random_shuffle(all(tmp));
	return tmp;
}


VPII gen_chrysanthemum_tree(int n)
{
	int i,j;
	set<PII > res;
	VI p;
	for(i=1;i<=n;i++) p.pb(i);
	random_shuffle(all(p));
	for(i=1;i<n;i++) res.insert(MP(p[0],p[i]));
	VPII tmp;
	for(auto it:res) tmp.pb(it);
	random_shuffle(all(tmp));
	return tmp;
}

VPII gen_single_chain(int n)
{
	int i,j;
	set<PII > res;
	VI p;
	for(i=1;i<=n;i++) p.pb(i);
	random_shuffle(all(p));
	for(i=1;i<n;i++) res.insert(MP(p[i-1],p[i]));
	VPII tmp;
	for(auto it:res) tmp.pb(it);
	random_shuffle(all(tmp));
	return tmp;
}

VPII gen_random_tree(int n)
{
	int i,j;
	set<PII > res;
	VI p;
	for(i=1;i<=n;i++) p.pb(i);
	random_shuffle(all(p));
	for(i=1;i<n;i++) res.insert(MP(p[rand_next(0,i-1)],p[i]));
	VPII tmp;
	for(auto it:res) tmp.pb(it);
	random_shuffle(all(tmp));
	return tmp;
}

