var p=IntArray(1)
var prime=IntArray(1)
var tot=0
fun init_prime(n:Int)
{
	tot=0
	p=IntArray(n+1)
	prime=IntArray(n+1){0}
	prime[1]=1;
	for(i in 2..n)
	{
		if(prime[i]==0)
		{
			prime[i]=i
			p[tot++]=i
		}
		for(j in 0..tot-1)
		{
			if(p[j]*i>n) break
			prime[i*p[j]]=p[j]
			if(i%p[j]==0) break
		}
	}
}
