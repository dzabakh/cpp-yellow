template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
	// step 1
	if (range_end - range_begin < 2) return;
	// step 2
	vector<typename RandomIt::value_type> vec(range_begin, range_end);
	cout << endl;
	// step 3
	size_t N = vec.size();
	auto range_fhalf_begin = vec.begin();
	auto range_fhalf_end = vec.begin() + N/2;
	auto range_shalf_begin = vec.begin() + N/2;
	auto range_shalf_end = vec.end();
	// step 4
	MergeSort(range_fhalf_begin, range_fhalf_end);
	MergeSort(range_shalf_begin, range_shalf_end);
	// step 5
	merge(range_fhalf_begin, range_fhalf_end, range_shalf_begin, range_shalf_end, range_begin);
}