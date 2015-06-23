//#pragma once
//
//#include<vector>
//#include<string>
//#include<algorithm>
//
//using namespace std;
//
//template <class T, class Iterator>
//T median(Iterator begin, Iterator end){
//	if(begin == end){
//		throw domain_error("median of an empty container");
//	}
//
//	vector<T> temp;
//	while(begin != end){
//		temp.push_back(*begin);
//		++begin;
//	}
//	
//	//≈≈–Ú
//	sort(temp.begin(), temp.end());
//
//	//º∆À„≤¢ ‰≥ˆ
//	size_t mid = temp.size() / 2;
//	return (temp.size() % 2 == 0) ? (temp[mid-1] + temp[mid]) / 2 : temp[mid];
//}