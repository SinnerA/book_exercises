//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<ctime>
//
//#include"Student_info.h"
//#include"grade.h"
//
//using namespace std;
//
//vector<Student_info> extract_fails(vector<Student_info>& students){
//	vector<Student_info> fails;
//	vector<Student_info>::iterator iter = students.begin(); 
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
//	vector<Student_info> fails, students;
//	Student_info s;
//
//	while(read(cin, s)){
//		students.push_back(s);
//	}
//
//	sort(students.begin(), students.end(), compare);
//
//	//消耗的时间
//	clock_t start = clock();
//	fails = extract_fails(students);
//	clock_t elapsed = clock() - start;
//
//	cout << "Elapsed:　" << elapsed << endl;
//}
