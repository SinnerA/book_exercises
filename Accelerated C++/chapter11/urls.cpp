//#include<algorithm>
//#include"urls.h"
//#include"Vec.h"
//
//using namespace std;
//
////是否url中的字符
//bool not_url_char(char);
//
////url开头
//string::const_iterator
//	url_beg(string::const_iterator b, string::const_iterator e);
//
////url结束
//string::const_iterator
//	url_end(string::const_iterator b, string::const_iterator e);
//
//Vec<string> find_urls(const string& s){
//	Vec<string> ret;
//	typedef string::const_iterator iter;
//	iter b = s.begin(), e = s.end();
//
//	while(b != e){
//		b = url_beg(b, e);
//
//		if(b != e){
//			iter after = url_end(b, e);
//			ret.push_back(string(b, after));
//			b = after;
//		}
//	}
//	return ret;
//}
//
//bool not_url_char(char c){
//	//除字母数字以外，其他可能出现在url中的字符
//	static const string url_ch = "~;/?:@=&$-_.+!*'(),";
//
//	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
//}
//
//string::const_iterator url_beg(string::const_iterator b, string::const_iterator e){
//	static const string sep = "://";
//	typedef string::const_iterator iter;
//	iter i = b;
//
//	while((i = search(i, e, sep.begin(), sep.end())) != e){
//		//分隔符不是本行中唯一的符号
//		if(i != b && i + sep.size() != e){
//			iter beg = i;
//			while(beg != b && isalpha(beg[-1])){
//				--beg;
//			}
//
//			//是否分隔符前面及后面至少一个字符
//			if(beg != i && !not_url_char(i[sep.size()])){
//				return beg;
//			}
//		}
//		i += sep.size();
//	}
//	
//	return e;
//}
//
//string::const_iterator url_end(string::const_iterator b, string::const_iterator e){
//	return find_if(b, e, not_url_char);
//}