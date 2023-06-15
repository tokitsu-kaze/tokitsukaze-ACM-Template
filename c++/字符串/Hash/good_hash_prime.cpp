vector<ll> good_hash_prime={50331653,100663319,201326611,402653189,805306457,1610612741};
vector<ll> get_hash_prime(int cnt=2)
{
	assert(cnt<=good_hash_prime.size());
	srand(time(0));
	random_shuffle(good_hash_prime.begin(),good_hash_prime.end());
	return vector<ll>(good_hash_prime.begin(),good_hash_prime.begin()+cnt);
}
