class KMP()
{
	lateinit var nex:IntArray
	lateinit var t:CharArray
	var len=0
	fun get_next(s:String,n:Int)
	{
		len=n
		t=CharArray(n+2)
		nex=IntArray(n+2)
		for(i in 1..len) t[i]=s[i-1]
		t[len+1]='\u0000'
		nex[0]=0
		nex[1]=0
		var j=0
		for(i in 2..len)
		{
			while(j>0 && t[j+1]!=s[i]) j=nex[j]
			if(t[j+1]==s[i]) j++
			nex[i]=j
		}
	}
	fun match(s:String,n:Int)
	{
		var j=0
		for(i in 0..n-1)
		{
			while(j>0 && t[j+1]!=s[i]) j=nex[j]
			if(t[j+1]==s[i]) j++
			if(j==len)
			{
				// begin pos: i-len+1
				j=nex[j]
			}
		}
	}
}
/*
kmp.get_next(t,len); // t[1..len]
kmp.match(s,n); // s[0..n-1]
*/
