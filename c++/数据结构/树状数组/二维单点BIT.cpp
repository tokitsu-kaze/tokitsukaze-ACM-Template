struct Fenwick_Tree
{
	#define type int
	type bit[MAX][MAX];
	int n,m;
	void init(int _n,int _m){n=_n;m=_m;mem(bit,0);}
	int lowbit(int x){return x&(-x);}
	void update(int x,int y,type v)
	{
		int i,j;
		for(i=x;i<=n;i+=lowbit(i))
		{
			for(j=y;j<=m;j+=lowbit(j))
			{
				bit[i][j]+=v;
			}
		} 
	}
	type get(int x,int y)
	{
		type i,j,res=0;
		for(i=x;i>0;i-=lowbit(i))
		{
			for(j=y;j>0;j-=lowbit(j))
			{
				res+=bit[i][j];
			}
		}
		return res;
	}
	type ask(int x1,int x2,int y1,int y2)
	{
		x1--;
		y1--;
		return get(x2,y2)-get(x1,y2)-get(x2,y1)+get(x1,y1);
	}
	#undef type
}tr;