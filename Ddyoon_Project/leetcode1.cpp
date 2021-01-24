class MedianFinder {
public:

	vector<int> arr;
	/** initialize your data structure here. */
	MedianFinder() {
	}

	void addNum(int num) {

		if (arr.size() == 0)
			arr.push_back(num);
		else {
			arr.insert(lower_bound(arr.begin(), arr.end(), num), num);
		}
	}

	double findMedian() {
		 
		return arr.size() % 2 ? (double)arr[arr.size() / 2] : (double)(arr[arr.size() / 2 - 1] + arr[arr.size() / 2]) / 2.0;
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */