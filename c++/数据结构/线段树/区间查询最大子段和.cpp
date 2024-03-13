struct node
{
	type sum,lmx,rmx,mx;
	void init(){sum=0;lmx=rmx=mx=-inf;}
}t[MAX<<2],null_node;
node merge_node(node x,node y)
{
	node res;
	res.sum=x.sum+y.sum;
	res.lmx=max(x.lmx,x.sum+y.lmx);
	res.rmx=max(y.rmx,y.sum+x.rmx);
	res.mx=max({x.mx,y.mx,x.rmx+y.lmx});
	return res;
}
