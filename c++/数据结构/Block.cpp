struct Block
{
	#define type int
	static const int N=MAX;
	static const int SZ=sqrt(N);
	static const int B=N/SZ+10;
	int n,bl[B],br[B],bid[N];
	type a[N],sum[B],tag[B];
	void build(int _n)
	{
		int i,j,id;
		n=_n;
		id=0;
		for(i=1;i<=n;i+=SZ)
		{
			bl[++id]=i;
			br[id]=min(n,i+SZ-1);
			tag[id]=0;
			for(j=bl[id];j<=br[id];j++)
			{
				bid[j]=id;
				
			}
		}
	}
	void pushdown(int id)
	{
		int i;
		if(tag[id])
		{
			
		}
	}
	void upd_point(int x,type v)
	{
		
	}
	void upd_block(int id,type v)
	{
		
	}
	void upd(int l,int r,type v)
	{
		int i;
	    if(bid[l]==bid[r])
	    {
	    	pushdown(bid[l]);
	    	for(i=l;i<=r;i++) upd_point(i,v);
	    	return;
		}
		pushdown(bid[l]);
		pushdown(bid[r]);
		for(i=l;i<=br[bid[l]];i++) upd_point(i,v);
		for(i=bl[bid[r]];i<=r;i++) upd_point(i,v);
		for(i=bid[l]+1;i<=bid[r]-1;i++) upd_block(i,v);
	}
	type res;
	void ask_point(int x)
	{
		
	}
	void ask_block(int id)
	{
		
	}
	type ask(int l,int r)
	{
	    int i;
	    res=0;
	    if(bid[l]==bid[r])
	    {
	    	pushdown(bid[l]);
	    	for(i=l;i<=r;i++) ask_point(i);
	    	return res;
		}
		pushdown(bid[l]);
		pushdown(bid[r]);
		for(i=l;i<=br[bid[l]];i++) ask_point(i);
		for(i=bl[bid[r]];i<=r;i++) ask_point(i);
		for(i=bid[l]+1;i<=bid[r]-1;i++) ask_block(i);
		return res;
	}
	#undef type
}blk;
