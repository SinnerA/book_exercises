//#include"split.h"
//
//using namespace std;
//
//vector<string> split(const string& s){
//
//	vector<string> ret;
//	typedef string::size_type str_size;
//	str_size i = 0;
//
//	while(i != s.size()){
//		
//		//找到单词开始位置
//		while(i != s.size() && isspace(s[i]))
//			++i;
//
//		str_size j = i;
//		//找到单词结束位置
//		while(j != s.size() && !isspace(s[j]))
//			++j;
//
//		//找到一个单词，并存储
//		if(i != j){
//			ret.push_back(s.substr(i, j-i));
//		    i = j;
//		}
//	}
//
//	return ret;
//}