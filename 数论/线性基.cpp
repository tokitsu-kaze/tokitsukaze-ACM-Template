struct Base
{
	#define type ll
	#define mx 60
	type d[mx+3];
	int p[mx+3],cnt;
	void init()
	{
		memset(d,0,sizeof(d));
		cnt=0;
	}
	bool insert(type x,int pos=0)
	{
		int i;
		for(i=mx;~i;i--)
		{
			if(!(x&(1LL<<i))) continue;
			if(!d[i])
			{
				cnt++;
				d[i]=x;
				p[i]=pos;
				break;
			}
			if(p[i]<pos)
			{
				swap(d[i],x);
				swap(p[i],pos);
			}
			x^=d[i];
		}
		return x>0;
	}
	type query_max(int pos=-1)
	{
		int i;
		type res=0;
		for(i=mx;~i;i--)
		{
			if(p[i]>=pos)
			{
				if((res^d[i])>res) res^=d[i];
			}
		}
		return res;
	}
	type query_min(int pos=-1)
	{
		for(int i=0;i<=mx;i++)
		{
			if(d[i]&&p[i]>=pos) return d[i];
		}
		return 0;
	}
	void merge(Base x)
	{
		if(cnt<x.cnt)
		{
			swap(cnt,x.cnt);
			swap(d,x.d);
			swap(p,x.p);
		}
		for(int i=mx;~i;i--)
		{
			if(x.d[i]) insert(x.d[i]);
		}
	}
	//kth min
	//first use rebuild()
	type tp[mx+3];
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
			if(d[i]) tp[cnt++]=d[i];
		}
	}
	type kth(type k)
	{
		type res=0;
		if(k>=(1LL<<cnt)) return -1;
		for(int i=mx;~i;i--)
		{
			if(k&(1LL<<i)) res^=tp[i];
		}
		return res;
	}
};
