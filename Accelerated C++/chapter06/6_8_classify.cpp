//#include<algorithm>
//#include"6_8_classify.h"
//
//using namespace std;
//
//vector<Student_info> classify(vector<Student_info>& input, bool criteria(const Student_info& s)){
//	vector<Student_info>::iterator i = stable_partition(input.begin(), input.end(), criteria);
//	vector<Student_info> output(i, input.end());
//	input.erase(i, input.end());
//	return output;
//}