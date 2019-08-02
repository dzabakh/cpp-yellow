template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    const string& prefix){
	auto it1 = lower_bound(range_begin, range_end, prefix);
	string prefix2 = prefix;
	(*(prev(prefix2.end())))++;
	auto it2 = lower_bound(range_begin, range_end, prefix2);
	return make_pair(it1, it2);
}
