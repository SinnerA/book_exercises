//#include"PF_Student_info.hpp"
//
//using namespace std;
//
////构造函数
//Student_info::Student_info():midterm(0),final(0){};
//
//Student_info::Student_info(istream& in){
//	read(in);
//}
//
////读取数据
//istream& Student_info::read(istream& in){
//	in >> n >> midterm >> final;
//	return in;
//}
//
////是否通过
//bool Student_info::passing() const{
//	return ((midterm + final) / 2) >= 60.0;
//}
//
////比较姓名
//bool compare(const Student_info& x, const Student_info& y){
//	return x.name() < y.name();
//}
