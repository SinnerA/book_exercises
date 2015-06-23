//#include<iostream>
//#include<string>
//#include<vector>
//#include<list>
//#include<ctime>
//#include"chapter4\Student_info.h"
//#include"chapter4\grade.h"
//
//using namespace std;
//
//list<Student_info> extract_fails(list<Student_info>& students){
//	list<Student_info> fails;
//	list<Student_info>::iterator iter = students.begin();
//
//	while(iter != students.end()){
//		if(fgrade(*iter)){
//			fails.push_back(*iter);
//		} else {
//			students.insert(students.begin(), *iter);
//		}
//		++iter;
//	}
//
//	students.resize(students.size() - fails.size());
//
//	return fails;
//}
//
//int main(){
//
//	list<Student_info> vs;
//	Student_info s;
//
//	while(read(cin, s)){
//		vs.push_back(s);
//	}
//
//	clock_t start = clock();
//	list<Student_info> fails = extract_fails(vs);
//	clock_t elapsed = clock() - start;
//
//	cout << "Elapsed: " << elapsed << endl;
//	return 0;
//}