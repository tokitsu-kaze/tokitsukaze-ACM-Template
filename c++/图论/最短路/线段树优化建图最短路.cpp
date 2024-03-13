struct Dijkstra
{
	#define type int
	const type inf=INF;
	struct node
	{
		int id;
		type v;
		friend bool operator <(node a,node b){return a.v>b.v;}
	};
	static const int M=;
	static const int N=2*(MAX<<2)+M+10;
	vector<node> mp[N];
	type dis[N];
	int n,vis[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type v){mp[x].push_back({y,v});}
	void work(int s)
	{
		int i,to;
		type w;
		priority_queue<node> q;
		for(i=0;i<=n;i++)
		{
			dis[i]=inf;
			vis[i]=0;
		}
		dis[s]=0;
		q.push({s,type(0)});
		while(!q.empty())
		{
			node t=q.top();
			q.pop();
			if(vis[t.id]) continue;
			vis[t.id]=1;// this node has already been extended
			for(auto &it:mp[t.id])
			{
				to=it.id;
				w=it.v;
				if(dis[to]>dis[t.id]+w)
				{
					dis[to]=dis[t.id]+w;
					if(!vis[to]) q.push({to,dis[to]}); 
				}
			}
		}
	}
}dij;
struct Segment_Tree
{
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,tot,tot_limt;
	int inid[MAX<<2],outid[MAX<<2],leafid[MAX];
	type dis[MAX];
	void build(int l,int r,int id)
	{
		inid[id]=id;
		outid[id]=id+(n<<2);
		if(l==r)
		{
			leafid[l]=id;
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		dij.add_edge(inid[id],inid[ls],0);
		dij.add_edge(inid[id],inid[rs],0);
		dij.add_edge(outid[ls],outid[id],0);
		dij.add_edge(outid[rs],outid[id],0);
	}
	void get_id(int l,int r,int id,vector<int> &res)
	{
		if(l>=ql&&r<=qr)
		{
			res.push_back(id);
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) get_id(l,mid,ls,res);
		if(qr>mid) get_id(mid+1,r,rs,res);
	}
	void build(int _n,int m)
	{
		int i;
		n=_n;
		tot_limt=2*(n<<2)+m;
		dij.init(tot_limt);
		build(1,n,1);
		for(i=1;i<=n;i++)
		{
			dij.add_edge(inid[leafid[i]],outid[leafid[i]],0);
		}
		tot=2*(n<<2);
	}
	void add_edge(int l1,int r1,int l2,int r2,type w)
	{
		if(l1>r1||l2>r2) return;
		vector<int> res_in,res_out;
		ql=l1,qr=r1;
		get_id(1,n,1,res_out);
		ql=l2,qr=r2;
		get_id(1,n,1,res_in);
		int k=++tot;
		assert(tot<=tot_limt);
		for(auto &it:res_in) dij.add_edge(k,inid[it],w);
		for(auto &it:res_out) dij.add_edge(outid[it],k,0);
	}
	void work(int s)
	{
		int i;
		dij.work(inid[leafid[s]]);
		for(i=1;i<=n;i++) dis[i]=dij.dis[outid[leafid[i]]];
	}
	#undef type
	#undef ls
	#undef rs
}trg;
/*
trg.build(n,m);
trg.add_edge(l1,r1,l2,r2,w);  [l1,r1] -> [l2,r2]
trg.work(s);
*/
