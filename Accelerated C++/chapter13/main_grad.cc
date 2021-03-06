//#include <algorithm>
//#include <iomanip>
//#include <iostream>
//#include <stdexcept>
//#include <string>
//#include <vector>
//
//#include "Student_info.h"
//#include"Core.h"
//
//using namespace std;
//
//int main() {
//  vector<Grad> students;
//  Grad record;
//  string::size_type maxlen = 0;
//
//  while (record.read(cin)) {
//    maxlen = max(maxlen, record.name().size());
//    students.push_back(record);
//  }
//
//  sort(students.begin(), students.end(), Student_info::compare);
//
//  for(vector<Grad>::size_type i = 0; i != students.size(); ++i){
//    cout << students[i].name()
//	 << string(maxlen + 1 - students[i].name().size(), ' ');
//
//    try {
//      double final_grade = students[i].grade();
//      streamsize prec = cout.precision();
//      cout << setprecision(3) << final_grade
//	       << setprecision(prec) << endl;
//    } catch (domain_error e) {
//      cout << e.what() << endl;
//    }
//  }
//
//  return 0;
//}