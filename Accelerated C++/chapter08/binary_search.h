//#ifndef GUARD_binary_search_h
//#define GUARD_binary_search_h
//
//template<class Ran, class X> bool binary_search(Ran begin, Ran end, const X& x){
//	while(begin != end){
//		Ran mid = begin + (end - begin) / 2;
//		if(*mid < x)
//			begin = mid + 1;
//		else if(*mid > x)
//			end = mid;
//		else
//			return true;
//	}
//	return false;
//}
//
//#endif