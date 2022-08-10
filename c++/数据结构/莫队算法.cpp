struct MO_Algorithm
{
	#define type int
	struct query_info{int id,l,r;type v;};
	vector<query_info> qst;
	int n,q;
	type ans[MAX],res;
	void init(int _n,int _q)
	{
		qst.clear();
		n=_n;
		q=_q;
	}
	void add_query(int id,int l,int r,int v=0) {qst.pb(query_info{id,l,r,v});}
	int a[MAX];
	void add(int x,int k)
	{
		
	}
	void del(int x,int k)
	{
		
	}
	void work()
	{
		int i,l,r,sq;
		sq=sqrt(n);
		sort(all(qst),[&](query_info a,query_info b){
			if(a.l/sq!=b.l/sq) return a.l/sq<b.l/sq;
			return a.r<b.r;
		});
		
		for(i=1;i<=q;i++) ans[i]=0;
		l=1;
		r=0;
		res=0;
		for(auto q:qst)
		{
			while(l<q.l) del(l++);
			while(l>q.l) add(--l);
			while(r<q.r) add(++r);
			while(r>q.r) del(r--);
			ans[q.id]+=res;
		}
	}
	#undef type
}mo;// mo.init(n,q)
