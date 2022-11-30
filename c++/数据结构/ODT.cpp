struct ODT
{
	#define type int
	#define init_val 0
	struct ODT_node
	{
		int l,r,id;
		mutable type v;
		ODT_node(const int &il,const int &ir,const type &iv): l(il),r(ir),v(iv){}
		inline bool operator<(const ODT_node &o)const {return l<o.l;}
	};
	int n;
	set<ODT_node> odt;
	typedef set<ODT_node>::iterator odt_iter;
	set<int> mp[MAX];
	void init(int _n)
	{
		n=_n;
		odt.clear();
		odt.insert(ODT_node(1,n,init_val));
		for(int i=1;i<=n;i++) mp[i].clear();
	}
	odt_iter find(int x){return --odt.upper_bound((ODT_node){x,0,init_val});}
	odt_iter split(int x)
	{
		if(x>n) return odt.end();
		odt_iter it=find(x);
		if(it->l==x) return it;
		int l=it->l,r=it->r;
		type v=it->v;
		odt.erase(it);
		odt.insert(ODT_node(l,x-1,v));
		return odt.insert(ODT_node(x,r,v)).first;
	}
	void assign(int l,int r,type v)
	{
		odt_iter itr=split(r+1),itl=split(l);
		odt.erase(itl,itr);
		odt.insert(ODT_node(l,r,v));
	}
	int work(int pos,int v)
	{
		auto it=find(pos);
		if(it->v <= v) return sz(odt);
		int pre=pos;
		for(;it!=odt.end();it++)
		{
			if(it->v>=v) pre=it->r;
			else break;
		}
		assign(pos,pre,v);
		return sz(odt);
	}
	#undef init_val
	#undef type
}odt;
