//#include<list>
//#include<string>
//#include<iostream>
//#include<iterator>
//#include <cstdlib>
//
//#include"8_5_grammer_utils.hpp"
//
//using namespace std;
//
//int main(){
//
//	list<string> sentence;
//	gen_sentence(read_grammar(cin), back_inserter(sentence));
//
//	list<string>::const_iterator i = sentence.begin();
//	if(!sentence.empty()){
//		cout << *i;
//		++i;
//	}
//
//	while(i != sentence.end()){
//		cout << " " << *i;
//		++i;
//	}
//	cout << endl;
//
//	return 0;
//}