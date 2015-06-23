//#include<stdexcept>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//double median(vector<double>::const_iterator begin, vector<double>::const_iterator end){
//	if(begin == end){
//		throw domain_error("median of an empty vector");
//	}
//
//	sort(begin, end);
//
//	int size = end - begin;
//	int mid = size / 2;
//	return (size%2 == 0) ? (*(begin + mid-1) + *(begin + mid))/2 : *(begin + mid);
//}