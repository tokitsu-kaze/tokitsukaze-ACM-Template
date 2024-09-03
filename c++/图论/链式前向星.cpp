struct Fast_Vector
{
	static const int N=;
	static const int M=;
	Fast_Vector &operator[](const int _x){this->x=_x;return *this;}
	int head[N],tot,x;
	struct node{int to,nex;} e[M];
	void clear(int n)
	{
		for(int i=0;i<=n;i++) head[i]=0;
		tot=0;
	}
	void push_back(const int &to)
	{
		tot++;
		e[tot].to=to;
		e[tot].nex=head[x];
		head[x]=tot;
	}
};
//for(i=mp.head[x];i;i=mp.e[i].nex) to=mp.e[i].to;
