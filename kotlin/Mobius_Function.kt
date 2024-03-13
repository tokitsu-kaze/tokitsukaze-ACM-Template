var flag=IntArray(MAX)
var mo=IntArray(MAX)
var prime=IntArray(MAX)
var tot=0
fun initmo(n:Int)
{
	tot=0
	mo[1]=1
	for(i in 2..n)
	{
		if(flag[i]==0)
		{
			prime[tot++]=i
			mo[i]=-1
		}
		for(j in 0..tot-1)
		{
			if(prime[j]*i>n) break
			flag[i*prime[j]]=1
			if(i%prime[j]==0)
			{
				mo[prime[j]*i]=0
				break
			}
			mo[prime[j]*i]=-mo[i]
		}
	}
}
