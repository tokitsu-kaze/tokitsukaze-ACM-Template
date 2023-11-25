struct Base
{
	#define type ll
	#define mx 60
	type d[mx+3];
	void init()
	{
		memset(d,0,sizeof(d));
	}
	bool insert(type x)
	{
		for(int i=mx;~i;i--)
		{
			if(!(x&(1LL<<i))) continue;
			if(!d[i])
			{
				d[i]=x;
				break;
			}
			x^=d[i];
		}
		return x>0;
	}
	type ask_max()
	{
		type res=0;
		for(int i=mx;~i;i--)
		{
			if((res^d[i])>res) res^=d[i];
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
	#undef type
}bs;
