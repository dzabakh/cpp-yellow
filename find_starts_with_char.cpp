template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    char prefix){
	string str;
	str+=prefix;
	auto it1 = lower_bound(range_begin, range_end, str);
	str[0]++;
	auto it2 = upper_bound(range_begin, range_end, str);
	return make_pair(it1, it2);
}
