//#include<iostream>
//#include"6_8_classify.h"
//#include"analysis.h"
//
//using namespace std;
//
//int main(){
//	vector<Student_info> did;
//	Student_info s;
//	while(read(cin, s)){
//		did.push_back(s);
//	}
//
//	vector<Student_info> didnt = classify(did, did_all_hw);
//
//	if (did.empty()){
//		cout << "No student did all the homework!" << endl;
//		return 1;
//	}
//	
//	if(didnt.empty()){
//	  cout << "Every student did all the homework!" << endl;
//	  return 1;
//	}
//	
//	//·ÖÎö
//	write_analysis(cout, "median", median_analysis, did, didnt);
//	write_analysis(cout, "average", average_analysis, did, didnt);
//	write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);
//
//	return 0;
//}