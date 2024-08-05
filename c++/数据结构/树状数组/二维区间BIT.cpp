struct Fenwick_Tree
{
	#define type int
	type bit[MAX][MAX][4];
	int n,m;
	void init(int _n,int _m)
	{
		int i,j;
		n=_n;
		m=_m;
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=m;j++)
			{
				memset(bit[i][j],0,sizeof bit[i][j]);
			}
		}
	}
	int lowbit(int x){return x&(-x);}
	void _insert(int x,int y,type v)
	{
		int i,j;
		for(i=x;i<=n;i+=lowbit(i))
		{
			for(j=y;j<=m;j+=lowbit(j))
			{
				bit[i][j][0]+=v;
				bit[i][j][1]+=v*x;
				bit[i][j][2]+=v*y;
				bit[i][j][3]+=v*x*y;
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
				res+=bit[i][j][0]*(x*y+x+y+1)
					-bit[i][j][1]*(y+1)
					-bit[i][j][2]*(x+1)
					+bit[i][j][3];
			}
		}
		return res;
	}
	void upd(int x1,int y1,int x2,int y2,type v)
	{
		_insert(x1,y1,v);
		_insert(x1,y2+1,-v);
		_insert(x2+1,y1,-v);
		_insert(x2+1,y2+1,v);
	}
	type ask(int x1,int y1,int x2,int y2)
	{
		if(x1>x2||y1>y2) return 0;
		x1--;
		y1--;
		return get(x2,y2)-get(x1,y2)-get(x2,y1)+get(x1,y1);
	}
	#undef type
}tr;
