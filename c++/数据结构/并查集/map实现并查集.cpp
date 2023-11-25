struct dsu
{
	#define type int
	unordered_map<type,type> pre;
	void init(){pre.clear();}
	type find(type x)
	{
		if(pre.count(x)) pre[x]=find(pre[x]);
		else return x;
		return pre[x];
	}
	bool merge(type a,type b)
	{
		type ra,rb;
		ra=find(a);
		rb=find(b);
		if(ra!=rb)
		{
			pre[ra]=rb;
			return 1;
		}
		return 0;
	}
	#undef type
}dsu;
