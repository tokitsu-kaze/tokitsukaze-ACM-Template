struct Base
{
	#define type int
	#define mx 30
	type d[mx+1],cnt;
	int p[mx+1];
	void init()
	{
		memset(d,0,sizeof(d));
		memset(p,0,sizeof(p));
		cnt=0;
	}
	bool insert(type x,int pos)
	{
		for(int i=mx;~i;i--)
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
	type ask_max(int pos)
	{
		type res=0;
		for(int i=mx;~i;i--)
		{
			if(p[i]>=pos)
			{
				if((res^d[i])>res) res^=d[i];
			}
		}
		return res;
	}
	void merge(Base x)
	{
		for(int i=mx;~i;i--)
		{
			if(x.d[i]) insert(x.d[i],x.p[i]);
		}
	}
}bs[MAX];
/*
init:
bs[i]=bs[i-1];
bs[i].insert(a[i],i);

ask:
ask(l,r) -> bs[r].ask_max(l);
*/
