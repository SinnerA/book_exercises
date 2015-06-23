//#include<iostream>
//#include<sstream>
//#include<map>
//#include<vector>
//#include<algorithm>
//#include"chapter5\split.h"
//
//#define LINE_LENGTH 80
//
//using namespace std;
//
////查找指向输入中每一个单词的全部行
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
//			if(find(ret[*iter].begin(), ret[*iter].end(), line_num) == ret[*iter].end())
//				ret[*iter].push_back(line_num);
//		}
//	}
//	return ret;
//}
//
//int main(){
//	//默认使用split来调用xref
//	map<string, vector<int> > ret = xref(cin);
//
//	//输出结果
//	for(map<string, vector<int> >::const_iterator iter = ret.begin(); iter != ret.end(); ++iter){
//		//暂存输出
//		stringstream ss;
//		ss << iter->first << " occurs on line(s): ";
//
//		vector<int>::const_iterator i = (iter->second).begin();
//		ss << *i;
//		++i;
//
//		while(i != (iter->second).end()){
//			ss << "," << *i;
//			++i;
//		}
//
//		string output = ss.str();
//		for(string::size_type i = 0; i != output.size(); ++i){
//			cout << output[i];
//			if((i+1) % LINE_LENGTH == 0)
//				cout << endl;
//		}
//		cout << endl;
//	}
//
//	return 0;
//}