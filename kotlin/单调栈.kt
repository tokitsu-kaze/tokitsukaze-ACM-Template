fun workl(x:IntArray,n:Int):IntArray
{
	var st=IntArray(n+1)
	var top=0
	var l=IntArray(n+1){0}
	for(i in n downTo 1)
	{
		while(top>0 && x[st[top-1]]<x[i])
		{
			l[st[top-1]]=i
			top--
		}
		st[top]=i
		top++
	}
	return l
}
fun workr(x:IntArray,n:Int):IntArray
{
	var st=IntArray(n+1)
	var top=0
	var r=IntArray(n+1){n+1}
	for(i in 1..n)
	{
		while(top>0 && x[st[top-1]]<x[i])
		{
			r[st[top-1]]=i
			top--
		}
		st[top]=i
		top++
	}
	return r
}
/*
- x[st[top-1]]>x[i]
x[i] is strict min in range l[i]+1 ~ r[i]-1
- x[st[top-1]]<x[i]
x[i] is strict max in range l[i]+1 ~ r[i]-1
*/
