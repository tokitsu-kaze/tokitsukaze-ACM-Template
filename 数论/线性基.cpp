//线性基
struct Base
{
	#define type ll
	#define mx 60
	type d[mx+3],p[mx+3],cnt;
	Base()
	{
		memset(d,0,sizeof(d));
		memset(p,0,sizeof(p));
		cnt=0;
	}
	bool insert(type x)
	{
		int i;
		for(i=mx;~i;i--)
		{
			if(!(x&(1LL<<i))) continue;
			if(!d[i])
			{
				cnt++;
				d[i]=x;
				break;
			}
			x^=d[i];
		}
		return x>0;
	}
	type query_max()
	{
		int i;
		type res=0;
		for(i=mx;~i;i--)
		{
			if((res^d[i])>res) res^=d[i];
		}
		return res;
	}
	type query_min()
	{
		for(int i=0;i<=mx;i++)
		{
			if(d[i]) return d[i];
		}
		return 0;
	}
	void rebuild()
	{
		int i,j;
		cnt=0;
		for(i=mx;~i;i--)
		{
			for(j=i-1;~j;j--)
			{
				if(d[i]&(1LL<<j)) d[i]^=d[j];
			}
		}
		for(i=0;i<=mx;i++)
		{
			if(d[i]) p[cnt++]=d[i];
		}
	}
	type kth(type k)//能异或出的第k小的数 使用前先调用rebuild 
	{
		type res=0;
		if(k>=(1LL<<cnt)) return -1;
		for(int i=mx;~i;i--)
		{
			if(k&(1LL<<i)) res^=p[i];
		}
		return res;
	}
	void merge(Base x)
	{
		for(int i=mx;~i;i--)
		{
			if(x.d[i]) insert(x.d[i]);
		}
	}
};
