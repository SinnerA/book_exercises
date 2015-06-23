//#include "median.h"
//#include<stdexcept>
//#include<algorithm>
//
//using std::vector;
//using std::domain_error;
//
//double median(vector<double> homeworks){
//	typedef vector<double>::size_type vc_size;
//	vc_size size = homeworks.size();
//
//	if(size == 0){
//		throw domain_error("median of an empty vector");
//	}
//
//	sort(homeworks.begin(), homeworks.end());
//
//	vc_size mid = size/2;
//	return (size%2 == 0) ? (homeworks[mid-1] + homeworks[mid])/2 : homeworks[mid];
//}