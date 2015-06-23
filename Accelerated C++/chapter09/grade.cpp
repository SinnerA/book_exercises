//#include<vector>
//#include<stdexcept>
//
//#include"grade.h"
//#include"median.h"
//
//using namespace std;
//
//double grade(double midterm, double final, double homework){
//	return 0.2*midterm + 0.4*final + 0.4*homework;
//}
//
//double grade(double midterm, double final, const vector<double>& homework){
//	if(homework.size() == 0){
//		throw domain_error("There on one done the homework!");
//	}
//	return grade(midterm, final, median(homework));
//}