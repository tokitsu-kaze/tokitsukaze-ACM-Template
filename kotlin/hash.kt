class hash_table
{
	var m=0
	var ha1=LongArray(1)
	var ha2=LongArray(1)
	var t1=LongArray(1)
	var t2=LongArray(1)
	val p1=1e9.toLong()+9L
	val p2=998244353L
	val sd1=131L
	val sd2=233L
	val offset=1e9.toLong()
	fun init(n:Int)
	{
		t1=LongArray(n+5)
		t2=LongArray(n+5)
		t1[0]=1L
		t2[0]=1L
		m=n
		for(i in 1..m)
		{
			t1[i]=t1[i-1]*sd1%p1
			t2[i]=t2[i-1]*sd2%p2
		}
	}
	fun work(s:String,n:Int)
	{
		require(m>=n)
		ha1=LongArray(n+5)
		ha2=LongArray(n+5)
		ha1[0]=0
		ha2[0]=0
		for(i in 1..n)
		{
			ha1[i]=(ha1[i-1]*sd1+s[i-1].toLong())%p1
			ha2[i]=(ha2[i-1]*sd2+s[i-1].toLong())%p2
		}
	}
	fun get(l:Int,r:Int):Long
	{
		var res1=(ha1[r]-ha1[l-1]*t1[r-l+1])%p1
		if(res1<0) res1+=p1
		var res2=(ha2[r]-ha2[l-1]*t2[r-l+1])%p2
		if(res2<0) res2+=p2
		var res=res1*offset+res2
		return res
	}
}
