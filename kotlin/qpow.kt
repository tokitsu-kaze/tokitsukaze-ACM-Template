fun qpow(aa:Long,bb:Int):Long
{
	var res=1L
	var a=aa
	var b=bb
	while(b>0)
	{
		if((b and 1)==1) res=res*a%mod
		a=a*a%mod
		b=b shr 1
	}
	return res
}
