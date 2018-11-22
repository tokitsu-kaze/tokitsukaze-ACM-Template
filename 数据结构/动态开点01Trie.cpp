/*
数组大小(x+1)*MAX:插入的值的最大值<2^x<MAX
Trie.Insert(1,x,v);
Trie.Delete(1,x,v);
Trie.query(1,x,v); 
Trie.clear(1,x);
*/
struct Trie
{
	int root,tot,ls[MAX*31],rs[MAX*31],val[MAX*31],cnt[MAX*31];
	void init()
	{
		root=0;
		ls[0]=rs[0]=0;
		val[0]=cnt[0]=0; 
		tot=1;
	}
	int newnode()
	{
		ls[tot]=rs[tot]=0;
		val[tot]=0;
		return tot++;
	}
	void Insert(int &x,int pos,int v)
	{
		if(!x) x=newnode();
		if(pos<0)
		{
			cnt[x]++;
			val[x]=v;
			return;
		}
		if((v>>pos)&1) Insert(rs[x],pos-1,v);
		else Insert(ls[x],pos-1,v);
		cnt[x]=cnt[ls[x]]+cnt[rs[x]];
	}
	void Delete(int x,int pos,int v)
	{
		if(pos<0)
		{
			cnt[x]--;
			return;
		}
		if((v>>pos)&1) Delete(rs[x],pos-1,v);
		else Delete(ls[x],pos-1,v);
		cnt[x]=cnt[ls[x]]+cnt[rs[x]];
	}
	int query(int x,int pos,int v)
	{
		if(pos<0) return val[x];
		int temp=(v>>pos)&1;
		if(temp)
		{
			if(cnt[rs[x]]) return query(rs[x],pos-1,v);
			else return query(ls[x],pos-1,v);
		}
		else
		{
			if(cnt[ls[x]]) return query(ls[x],pos-1,v);
			else return query(rs[x],pos-1,v);
		}
	}
}tr;
