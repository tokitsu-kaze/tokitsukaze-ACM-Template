int fib[MAX],tot;
void init_fib(ll limt)
{
	assert(limt>=0);
	tot=1;
	fib[0]=fib[1]=1;
	for(int i=2;;i++)
	{
		if(fib[i-1]>limt-fib[i-2])
		{
			tot=i-1;
			break;
		}
		fib[i]=fib[i-1]+fib[i-2];
	}
}
//S(0)="0", S(1)="1", S(i)=S(i-1)+S(i-2)
//FibString: S(i) [i>=1]
int get_kth_FibString(ll k)
{
	int i;
	for(i=tot;i>=2;i--)
	{
		if(k>fib[i]) k-=fib[i];
	}
	return k==1;
}
int is_fib(ll x)
{
	for(int i=1;i<=tot;i++)
	{
		if(x==fib[i]) return 1;
	}
	return 0;
}
