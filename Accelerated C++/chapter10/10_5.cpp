//#include<string>
//#include<vector>
//#include<iostream>
//
//#include"List.hpp"
//
//using namespace std;
//
//int main(){
//	string arr1[] = {"hello", "to", "the", "world!"};
//	list<string> a = list<string>(arr1, arr1+4);
//	list<string>::const_iterator i = a.begin();
//
//	//Test "equality"
//	if(a.begin() == a.begin()){
//		cout << "The beginning" << endl;
//	}
//
//	//Test "inequality"
//	if(a.begin() != a.end()){
//		cout << "Is not the end" << endl;
//	}
//
//	//Test dereference
//	cout << *i << endl;
//	cout << i->size() << endl;
//	
//	//Test increment
//	++i;
//	cout << *i << endl;
//	i++;
//	cout << *i << endl;
//	cout << *i++ << endl;
//	cout << *i << endl;
//
//	//Test decrement
//	--i;
//	cout << *i << endl;
//	i--;
//	cout << *i << endl;
//	cout << *i-- << endl;
//	cout << *i << endl;
//
//	return 0;
//}