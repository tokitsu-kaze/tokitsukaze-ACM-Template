struct Fast_Vector
{
	static const int N=;
	static const int M=;
	Fast_Vector &operator[](const int _x){this->x=_x;return *this;}
	int head[N],tot,x;
	struct node{int l,id,nex;} e[M];
	void clear(int n)
	{
		for(int i=0;i<=n;i++) head[i]=0;
		tot=0;
	}
	void push_back(const int &l,const int &id)
	{
		tot++;
		e[tot].l=l;
		e[tot].id=id;
		e[tot].nex=head[x];
		head[x]=tot;
	}
}mp;
//for(int it=mp.head[k];it;it=mp.e[it].nex)
