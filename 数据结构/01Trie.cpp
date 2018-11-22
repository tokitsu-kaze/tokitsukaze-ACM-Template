/*
数组大小(x+1)*MAX:插入的值的最大值<2^x<MAX
Trie.Insert(1,x,v);
Trie.Delete(1,x,v);
Trie.query(1,x,v); 
Trie.clear(1,x);
*/
struct Trie
{
	int cnt[32*MAX],val[32*MAX];
	void Insert(int x,int pos,int v)
	{
		if(pos<0)
		{
			cnt[x]++;
			val[x]=v;
			return;
		}
		Insert((x<<1)|((v>>pos)&1),pos-1,v);
		cnt[x]=cnt[x<<1]+cnt[x<<1|1];
	}
	void Delete(int x,int pos,int v)
	{
		if(pos<0)
		{
			cnt[x]--;
			return;
		}
		Delete((x<<1)|((v>>pos)&1),pos-1,v);
		cnt[x]=cnt[x<<1]+cnt[x<<1|1];
	}
	void clear(int x,int pos)
	{
		cnt[x]=0;
		val[x]=0;
		if(pos<0) return;
		clear(x<<1,pos-1);
		clear(x<<1|1,pos-1);
	}
	int query(int x,int pos,int v)//查询与v异或的最大值 并返回 
	{
		if(pos<0) return val[x];
		int temp=(v>>pos)&1;
		temp|=x<<1;
		if(cnt[temp^1]) return query(temp^1,pos-1,v);
		return query(temp,pos-1,v);
	}
}tr;
