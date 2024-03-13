struct node
{
	type len,ha;
	void init(){len=ha=0;}
}t[MAX<<2],null_node;
node merge_node(node x,node y)
{
	node res;
	res.len=x.len+y.len;
	res.ha=x.ha*qpow(bs,y.len)+y.ha;
	return res;
}
