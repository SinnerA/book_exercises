//#include<iostream>
//#include<map>
//#include<vector>
//#include"chapter5\split.h"
//#include"urls.h"
//
//using namespace std;
//
////����ָ��������ÿһ�����ʵ�ȫ����
//map<string, vector<int> > xref(istream& in, vector<string> find_words(const string& s) = split){
//	map<string, vector<int> > ret;
//	string s;
//	int line_num = 0;
//
//	while(getline(in, s)){
//		++line_num;
//		
//		vector<string> words = find_words(s);
//		for(vector<string>::const_iterator iter = words.begin(); iter != words.end(); ++iter){
//			ret[*iter].push_back(line_num);
//		}
//	}
//	return ret;
//}
//
//int main(){
//	//Ĭ��ʹ��split������xref
//	map<string, vector<int> > ret = xref(cin, find_urls);
//
//	//������
//	for(map<string, vector<int> >::const_iterator iter = ret.begin(); iter != ret.end(); ++iter){
//		cout << iter->first << " occurs on line(s): ";
//
//		vector<int>::const_iterator i = (iter->second).begin();
//		cout << *i;
//		++i;
//
//		while(i != (iter->second).end()){
//			cout << "," << *i;
//			++i;
//		}
//		cout << endl;
//	}
//
//	return 0;
//}