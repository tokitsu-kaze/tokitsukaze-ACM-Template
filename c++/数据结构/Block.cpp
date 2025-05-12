struct Block
{
	#define type int
	static const int N=MAX;
	static const int SZ=sqrt(N);
	static const int B=N/SZ+5;
	struct bnode{type v;}valp[N],valb[B],qv,res,null_node;
	int n,bl[B],br[B],bid[N];
	type tag[B];
	void set_null_node(){null_node={0};} // init
	void init_point(int x){valp[x]=null_node;}
	void init_block(int id){valb[id]=null_node;}
	void build(int _n)
	{
		int i,j,id,sq;
		n=_n;
		sq=sqrt(n);
		id=0;
		set_null_node();
		for(i=1;i<=n;i+=sq)
		{
			bl[++id]=i;
			br[id]=min(n,i+sq-1);
			init_block(id);
			tag[id]=0;
			for(j=bl[id];j<=br[id];j++)
			{
				bid[j]=id;
				init_point(j);
			}
		}
	}
	void maintain(bnode &now,bnode x)
	{
		now.v+=x.v;
	}
	void pushup(int id){maintain(valb[id],qv);}
	void pushdown(int id)
	{
		int i;
		if(tag[id])
		{
			for(i=bl[id];i<=br[id];i++)
			{
				// pushdown
			}
			tag[id]=0;
		}
	}
	void upd_tag(int id)
	{
		// upd_tag
		
	}
	void upd_point(int x){maintain(valp[x],qv);pushup(bid[x]);}
	void upd_block(int id){maintain(valb[id],qv);upd_tag(id);}
	void upd(int l,int r,type v)
	{
		qv={v};
		int i;
	    if(bid[l]==bid[r])
	    {
	    	pushdown(bid[l]);
	    	for(i=l;i<=r;i++) upd_point(i);
	    	return;
		}
		pushdown(bid[l]);
		pushdown(bid[r]);
		for(i=l;i<=br[bid[l]];i++) upd_point(i);
		for(i=bl[bid[r]];i<=r;i++) upd_point(i);
		for(i=bid[l]+1;i<=bid[r]-1;i++) upd_block(i);
	}
	void ask_point(int x){maintain(res,valp[x]);}
	void ask_block(int id){maintain(res,valb[id]);}
	type ask(int l,int r)
	{
		if(l>r) return null_node.v;
		res=null_node;
	    int i;
	    if(bid[l]==bid[r])
	    {
	    	pushdown(bid[l]);
	    	for(i=l;i<=r;i++) ask_point(i);
		}
		else
		{
			pushdown(bid[l]);
			pushdown(bid[r]);
			for(i=l;i<=br[bid[l]];i++) ask_point(i);
			for(i=bl[bid[r]];i<=r;i++) ask_point(i);
			for(i=bid[l]+1;i<=bid[r]-1;i++) ask_block(i);
		}
		return res.v;
	}
	#undef type
}blk;
