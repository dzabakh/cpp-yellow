template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
	// step 1
	if (range_end - range_begin < 2) return;
	// step 2
	vector<typename RandomIt::value_type> vec(range_begin, range_end);
	cout << endl;
	// step 3
	size_t N = vec.size();
	auto range_head_begin = vec.begin();
	auto range_head_end = vec.begin() + N/3;
	auto range_middle_begin = vec.begin() + N/3;
	auto range_middle_end = vec.begin() + 2 * N/3;
	auto range_tail_begin = vec.begin() + 2 * N/3;
	auto range_tail_end = vec.end();
	// step 4
	MergeSort(range_head_begin, range_head_end);
	MergeSort(range_middle_begin, range_middle_end);
	MergeSort(range_tail_begin, range_tail_end);
	// step 5
	vector<typename RandomIt::value_type> head_and_middle;
	merge(range_head_begin, range_head_end, range_middle_begin, range_middle_end, back_inserter(head_and_middle));
	merge(head_and_middle.begin(), head_and_middle.end(), range_tail_begin, range_tail_end, range_begin);
}