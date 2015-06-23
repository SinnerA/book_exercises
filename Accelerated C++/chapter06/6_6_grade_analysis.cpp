//#include<iostream>
//#include"6_6_analysis.h"
//#include"chapter4/Student_info.h"
//
//using namespace std;
//
//int main(){
//
//	vector<Student_info> did, didnt;
//	Student_info s;
//
//	while(read(cin, s)){
//		if(did_all_hw(s))
//			did.push_back(s);
//		else
//			didnt.push_back(s);
//	}
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
//	write_analysis(cout, "median", grade_aux, did, didnt);
//	write_analysis(cout, "average", average_grade, did, didnt);
//	write_analysis(cout, "median of homework turned in", optimistic_median, did, didnt);
//
//	return 0;
//}