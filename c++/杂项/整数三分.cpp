while(l<r)
{
	lm=l+(r-l)/3;
	rm=r-(r-l)/3;
	tl=cal(lm);
	tr=cal(rm);
	// tl>tr:min   tl<tr:max
	if(tl>tr) l=lm+1;
	else r=rm-1;
}
