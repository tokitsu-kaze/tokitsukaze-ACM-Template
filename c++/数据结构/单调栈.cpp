int st[MAX];
void workl(int *x,int n,int *l)
{
	int i,top;
	top=0;
	for(i=n;i;i--)
	{
		while(top && x[st[top-1]]>x[i]) l[st[--top]]=i;
		st[top++]=i;
	}
	while(top>0) l[st[--top]]=0;
}
void workr(int *x,int n,int *r)
{
	int i,top;
	top=0;
	for(i=1;i<=n;i++)
	{
		while(top && x[st[top-1]]>x[i]) r[st[--top]]=i;
		st[top++]=i;
	}
	while(top>0) r[st[--top]]=n+1;
}
/*
- x[st[top-1]]>x[i]
x[i] is strict min in range l[i]+1 ~ r[i]-1
- x[st[top-1]]<x[i]
x[i] is strict max in range l[i]+1 ~ r[i]-1
*/
