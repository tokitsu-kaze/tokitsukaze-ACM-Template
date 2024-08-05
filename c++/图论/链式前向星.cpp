struct Fast_Vector
{
	static const int N=2.5e5+10;
	static const int M=8e7+10;
	Fast_Vector &operator[](const int _x){this->x=_x;return *this;}
	int head[N],tot,x;
	struct node{int to,nex;} e[M];
	void clear(int n)
	{
		for(int i=0;i<=n;i++) head[i]=0;
		tot=0;
	}
	void push_back(int y)
	{
		e[tot].to=y;
		e[tot].nex=head[x];
		head[x]=++tot;
	}
}mp;
//for(int it=pos.head[k];it;it=pos.e[it].to)

