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
//		//�ҵ����ʿ�ʼλ��
//		while(i != s.size() && isspace(s[i]))
//			++i;
//
//		str_size j = i;
//		//�ҵ����ʽ���λ��
//		while(j != s.size() && !isspace(s[j]))
//			++j;
//
//		//�ҵ�һ�����ʣ����洢
//		if(i != j){
//			ret.push_back(s.substr(i, j-i));
//		    i = j;
//		}
//	}
//
//	return ret;
//}