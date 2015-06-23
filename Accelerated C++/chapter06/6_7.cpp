//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include"chapter4\Student_info.h"
//#include"analysis.h"
//using namespace std;
//
//vector<Student_info> extract_didnt(vector<Student_info>& students){
//	vector<Student_info>::iterator i = stable_partition(students.begin(), students.end(), did_all_hw);
//	vector<Student_info> didnt(i, students.end());
//	students.erase(i, students.end());
//	return didnt;
//}
//
//int main(){
//	vector<Student_info> did;
//	Student_info s;
//	while(read(cin, s)){
//		did.push_back(s);
//	}
//
//	vector<Student_info> didnt = extract_didnt(did);
//
//	if(did.empty()){
//		cout << "No student did all the homework!" << endl;
//		return 1;
//	}
//	if(didnt.empty()){
//		cout << "Every student did all the homework!" << endl;
//		return 1;
//	}
//
//	//·ÖÎö
//    write_analysis(cout, "median", median_analysis, did, didnt);
//	write_analysis(cout, "average", average_analysis, did, didnt);
//	write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);
//
//	return 0;
//}