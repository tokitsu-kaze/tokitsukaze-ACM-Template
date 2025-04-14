fun gcd(a:Int,b:Int):Int
{
	if(b==0) return a
	return gcd(b,a%b)
}
