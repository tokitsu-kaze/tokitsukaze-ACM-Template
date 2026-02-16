struct MO_Algorithm
{
	#define type int
	struct query_info{int l,r,id;};
	vector<query_info> qst;
	int n,q,a[MAX];
	type ans[MAX],res;
	void init(int _n,int _q)
	{
		qst.clear();
		n=_n;
		q=_q;
	}
	void add_qst(query_info x){qst.push_back(x);}
	void add(int x)
	{
		
	}
	void del(int x)
	{
		
	}
	void work()
	{
		int i,l,r,sq;
		sq=sqrt(n);
		sort(qst.begin(),qst.end(),[&](query_info a,query_info b){
			if(a.l/sq!=b.l/sq) return a.l/sq<b.l/sq;
			if((a.l/sq)&1) return a.r>b.r;
			else return a.r<b.r;
		});
		l=1;
		r=0;
		res=0;
		for(auto &qq:qst)
		{
			while(l>qs.l) add(--l);
			while(r<qs.r) add(++r);
			while(l<qs.l) del(l++);
			while(r>qs.r) del(r--);
			ans[qs.id]=res;
		}
	}
	#undef type
}mo;
/*
O(n*sqrt(q))
mo.init(n,q);
mo.add_qst({l,r,id});
mo.work();
*/
