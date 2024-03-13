struct ODT
{
	#define type int
	#define init_val 0
	struct ODT_node
	{
		int l,r;
		mutable type v;
		inline bool operator<(const ODT_node &o)const {return l<o.l;}
	};
	int n;
	set<ODT_node> odt;
	typedef set<ODT_node>::iterator odt_iter;
	void init(int _n)
	{
		n=_n;
		odt.clear();
		odt.insert({1,n,init_val});
	}
	odt_iter find(int x){return --odt.upper_bound({x,0,init_val});}
	odt_iter split(int x)
	{
		if(x>n) return odt.end();
		odt_iter it=find(x);
		if(it->l==x) return it;
		int l=it->l,r=it->r;
		type v=it->v;
		odt.erase(it);
		odt.insert({l,x-1,v});
		return odt.insert({x,r,v}).first;
	}
	void assign(int l,int r,type v)
	{
		odt_iter itr=split(r+1),itl=split(l);
		odt.erase(itl,itr);
		odt.insert({l,r,v});
	}
	#undef init_val
	#undef type
}odt;
