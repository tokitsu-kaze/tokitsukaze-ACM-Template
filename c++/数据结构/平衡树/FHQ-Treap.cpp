struct FHQ_Treap
{
	#define type int
	static const type inf=INF;
	struct node
	{
		int ls,rs,fix,sz,cnt;
		type v;
		node(){}
		node(type x,int _sz)
		{
			v=x;
			fix=rand();
			sz=cnt=_sz;
			ls=rs=0;
		}
	}t[MAX];
	int rt,tot;
	void init()
	{
		rt=0;
		srand(time(0));
		tot=0;
		t[0].sz=t[0].cnt=0;
		t[0].ls=t[0].rs=0;
	}
	int newnode(type v,int sz)
	{
		t[++tot]=node(v,sz);
		return tot;
	}
	void pushup(int id)  
	{  
		t[id].sz=t[t[id].ls].sz+t[t[id].rs].sz+t[id].cnt;
	}
	void split(int id,type v,int &x,int &y)
	{
		if(!id)
		{
			x=y=0;
			return;
		}
		if(t[id].v<=v)
		{
			x=id;
			split(t[id].rs,v,t[id].rs,y);
		}
		else
		{
			y=id;
			split(t[id].ls,v,x,t[id].ls);
		}
		pushup(id);
	}
	int merge(int x,int y)
	{
		if(!x||!y) return x|y;
		if(t[x].fix<t[y].fix)
		{
			t[x].rs=merge(t[x].rs,y);
			pushup(x);
			return x;
		}
		else
		{
			t[y].ls=merge(x,t[y].ls);
			pushup(y);
			return y;
		}
	}
	void insert(type v,int sz=1)
	{
		int ra,rb,rc;
		split(rt,v,ra,rc);
		split(ra,v-1,ra,rb);
		if(!rb) rb=newnode(v,sz);
		else
		{
			t[rb].cnt+=sz;
			t[rb].sz+=sz;
		}
		rt=merge(merge(ra,rb),rc);
	}
	void erase(type v,int sz=1)
	{
		int ra,rb,rc;
		split(rt,v,ra,rc);
		split(ra,v-1,ra,rb);
		if(rb)
		{
			t[rb].cnt-=sz;
			if(t[rb].cnt<=0) rb=0;
			else t[rb].sz-=sz;
		}
		rt=merge(merge(ra,rb),rc);
	}
	int _find(type key,int f)
	{
		int id=rt,res=0;
		while(id)
		{
			if(t[id].v<=key)
			{
				res+=t[t[id].ls].sz+t[id].cnt;
				if(f&&key==t[id].v) res-=t[id].cnt;
				id=t[id].rs;
			}
			else id=t[id].ls;
		}
		return res;
	}
	type find_by_order(int k)//k small
	{
		int id=rt;
		if(id==0) return 0;
		while(id)
		{
			if(t[t[id].ls].sz>=k) id=t[id].ls;
			else if(t[t[id].ls].sz+t[id].cnt>=k) return t[id].v;
			else
			{
				k-=t[t[id].ls].sz+t[id].cnt;
				id=t[id].rs;
			}
		}
	}
	int count(type key)
	{
		int id=rt;
		while(id)
		{
			if(t[id].v<key)
			{
				if(key==t[id].v) return t[id].cnt;
				id=t[id].rs;
			}
			else id=t[id].ls;
		}
		return 0;
	}
	type find_pre(type key)
	{
		type res=-inf;
		int id=rt;
		while(id)
		{
			if(t[id].v<key)
			{
				res=t[id].v;
				id=t[id].rs;
			}
			else id=t[id].ls;
		}
		return res;
	}
	type find_nex(type key)
	{
		type res=inf;
		int id=rt;
		while(id)
		{
			if(t[id].v>key)
			{
				res=t[id].v;
				id=t[id].ls;
			}
			else id=t[id].rs;
		}
		return res;
	}
	int upper_bound_count(type key){return _find(key,0);}//the count <=key
	int lower_bound_count(type key){return _find(key,1);}//the count <key
	int order_of_key(type key){return lower_bound_count(key)+1;}
	int size(){return t[rt].sz;}
	#undef type
}tr;
