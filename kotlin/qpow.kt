fun qpow(aa:Long,bb:Int,p:Int):Long
{
	var res=1L
	var a=aa
	var b=bb
	while(b>0)
	{
		if((b and 1)==1) res=res*a%p
		a=a*a%p
		b=b shr 1
	}
	return res
}
