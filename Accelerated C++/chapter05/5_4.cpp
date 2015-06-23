//#include<iostream>
//#include<string>
//#include<vector>
//#include<list>
//#include<algorithm>
//
//#include"Student_info.h"
//#include"grade.h"
//
//using namespace std;
//
//typedef list<Student_info> Student_infos;
//
//Student_infos extract_fails(Student_infos& students){
//	Student_infos fails;
//	Student_infos::iterator iter = students.begin(); 
//	while(iter != students.end()){
//		if(fgrade(*iter)){
//			fails.push_back(*iter);
//			iter = students.erase(iter);
//		} else {
//			++iter;
//		}
//	}
//	return fails;
//}
//
//int main(){
//	
//	Student_infos vs;
//	Student_info s;
//	string::size_type maxlen = 0;
//
//	while(read(cin, s)){
//		vs.push_back(s);
//		maxlen = max(maxlen, s.name.size());
//	}
//
//	Student_infos fails = extract_fails(vs);
//
//	for(Student_infos::const_iterator iter = fails.begin(); iter != fails.end(); ++iter){
//		cout << iter->name << " " << grade(*iter) << endl;
//	}
//
//	return 0;
//}