//#include<iostream>
//#include<string>
//#include<vector>
//#include<list>
//#include<algorithm>
//#include<ctime>
//
//#include"Student_info.h"
//#include"grade.h"
//
//using namespace std;
//
////typedef vector<Student_info> Student_infos;
//typedef list<Student_info> Student_infos;
//
//Student_infos extract_fails(Student_infos& students){
//	Student_infos fails;
//	Student_infos::iterator iter = students.begin(); 
//
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
//
//int main(){
//	Student_infos fails, students;
//	Student_info s;
//
//	while(read(cin, s)){
//		students.push_back(s);
//	}
//
//	students.sort(compare);
//	//sort(students.begin(), students.end(), compare);
//
//	//消耗的时间
//	clock_t start = clock();
//	fails = extract_fails(students);
//	clock_t elapsed = clock() - start;
//
//	cout << "Elapsed:　" << elapsed << endl;
//}
