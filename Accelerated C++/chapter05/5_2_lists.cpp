//#include<iostream>
//#include<string>
//#include<list>
//#include<algorithm>
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
//	list<Student_info> fails, students;
//	Student_info s;
//
//	while(read(cin, s)){
//		students.push_back(s);
//	}
//
//	//list��������֧��������ʣ���˲���ֱ����sort
//	students.sort(compare);
//
//	//���ĵ�ʱ��
//	clock_t start = clock();
//	fails = extract_fails(students);
//	clock_t elapsed = clock() - start;
//
//	cout << "Elapsed:��" << elapsed << endl;
//}
