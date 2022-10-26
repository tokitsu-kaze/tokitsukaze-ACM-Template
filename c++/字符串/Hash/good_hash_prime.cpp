VL good_hash_prime={50331653,100663319,201326611,402653189,805306457,1610612741};
VL get_hash_prime(int cnt=2)
{
	assert(cnt<=sz(good_hash_prime));
	srand(time(0));
	random_shuffle(all(good_hash_prime));
	return VL(good_hash_prime.begin(),good_hash_prime.begin()+cnt);
}
