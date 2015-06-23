//#include<fstream>
//#include<string>
//#include<iostream>
//
//using namespace std;
//
//int main(int argc, char** argv){
//	int fail_count = 0;
//
//	for(int i = 1; i != argc; ++i){
//		ifstream infile(argv[i]);
//
//		string s;
//		if(infile){
//			while(getline(infile, s)){
//				cout << s << endl;
//			}
//		} else {
//			cerr << "cannot open file!" << argv[i] << endl;
//			++fail_count;
//		}
//	}
//
//	return fail_count;
//}