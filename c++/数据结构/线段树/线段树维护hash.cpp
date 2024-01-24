struct node{type len,ha;}t[MAX<<2];
node merge(node x,node y)
{
	node res;
	res.len=x.len+y.len;
	res.ha=x.ha*qpow(bs,y.len)+y.ha;
	return res;
}
