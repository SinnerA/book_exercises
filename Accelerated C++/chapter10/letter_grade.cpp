//#include"letter_grade.hpp"
//
//using namespace std;
//
//string letter_grade(double grade){
//	static const double numbers[] = {
//		97, 94, 90, 87, 84, 80, 77, 74, 70, 60 ,0
//	};
//	static const char* const letters[] = {
//		"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
//	};
//
//	//计算成绩的个数
//	static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);
//
//	//根据分数得到相应的字母
//	for(size_t i = 0; i != ngrades; ++i){
//		if(grade >= numbers[i])
//			return letters[i];
//	}
//	return "\?\?\?";
//}