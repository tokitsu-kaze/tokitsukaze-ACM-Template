class Discretization<T:Number>()
{
	var a=mutableListOf<Long>()
	fun add(x:T){a.add(x.toLong())}
	fun work(){
		a.sort()
		var tmp=mutableListOf<Long>()
		var pre=-1L
		if(a.size>0) pre=a[0]-1L;
		for(it in a){
			if(it!=pre) {tmp.add(it)}
			pre=it
		}
		a=tmp
	}
	fun get_pos(x:T):Int{return upper_bound_pos(a,x.toLong())}
	fun get_val(pos:Int):T {return a[pos-1] as T}
	fun size():Int{return a.size}
}
