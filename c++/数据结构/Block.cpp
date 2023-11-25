struct Block
{
	#define type int
	static const int N=;
	static const int size=sqrt(N);
	static const int num=N/size+1;
	
	void init()
	{
		
	}
	void point_modify(int x,type v)
	{
	    int id=(x-1)/size+1;
	    int pos=x%size;
		
	}
	void block_modify(int id,type v)
	{
		
	}
	type point_query(int x)
	{
	    int id=(x-1)/size+1;
	    int pos=x%size;
		
	}
	type block_query(int id)
	{
		
	}
	void upd(int l,int r,type x)
	{
	    while(l<=r&&r%blocks!=0) point_modify(r,x),r--;
	    while(l<=r&&l%blocks!=1) point_modify(l,x),l++;
	    while(l<=r)
		{
		    int id=(l-1)/size+1;
		    block_modify(id,x);
		    l+=size;
		}
	}
	type ask(int l,int r)
	{
	    type ans=0;
	    while(l<=r&&r%blocks!=0) ans+=point_query(r),r--;
	    while(l<=r&&l%blocks!=1) ans+=point_query(l),l++;
	    while(l<=r)
		{
		    int id=(l-1)/size+1;
		    ans+=block_query(id);
		    l+=size;
		}
	    return ans;
	}
	#undef type
}blk;
