//#include<iostream>
//#include<vector>
//#include<string>
//#include<iterator>
//
//#include"6_1_pics.h"
//
//using namespace std;
//
//int main(){
//	vector<string> p;
//	p.push_back("this is an");
//	p.push_back("example");
//	p.push_back("to");
//	p.push_back("illustrate");
//	p.push_back("framing");
//
//	ostream_iterator<string> ofile(cout, "\n");
//	copy(p.begin(), p.end(), ofile);
//	cout << endl;
//
//	vector<string> f = frame(p);
//	copy(f.begin(), f.end(), ofile);
//	cout << endl;
//
//	vector<string> h = hcat(p, f);
//	copy(h.begin(), h.end(), ofile);
//	cout << endl;
//
//	return 0;
//}