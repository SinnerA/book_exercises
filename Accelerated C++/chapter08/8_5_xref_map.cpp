//#include<iostream>
//#include<iterator>
//
//#include"8_5_xref_utils.hpp"
//#include"split.h"
//
//using namespace std;
//
//int main(){
//
//	map<string, vector<int> > ret;
//	xref(cin, split, inserter(ret, ret.begin()));
//	
//	for(map<string, vector<int> >::const_iterator i = ret.begin(); i != ret.end(); ++i){
//		cout << i->first << " occurs on line(s): ";
//
//		vector<int>::const_iterator j = i->second.begin();
//		cout << *j;
//		++j;
//
//		while(j != i->second.end()){
//			cout << ", " << *j;
//			++j;
//		}
//		cout << endl;
//	}
//
//	return 0;
//}