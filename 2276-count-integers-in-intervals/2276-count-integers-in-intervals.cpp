const static auto initialize = [] { 
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr); 
    return nullptr; 
}();

class CountIntervals
{
	std::vector<std::pair<int, int>> intervals;
	int total = 0;
public:
	void add(int left, int right)
	{
		++right;

		auto iter = std::lower_bound(std::begin(intervals), std::end(intervals), left,[](auto const& pair, auto x) { return pair.second < x; });
        
		if (iter == std::end(intervals) || right < iter->first){
			intervals.emplace(iter, left, right);
			total += right - left;
		}else{
			auto jter = iter;
			for (; jter != std::end(intervals); ++jter)
			{
				if (jter->first > right) { break; }

				iter->second = jter->second;
				total -= jter->second - jter->first;
			}

			intervals.erase(std::next(iter), jter);

			iter->first = std::min(iter->first, left);
			iter->second = std::max(iter->second, right);
			total += iter->second - iter->first;
		}
	}

	int count(){return total;}
};