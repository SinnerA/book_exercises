//#include<iostream>
//
//#include"Student_info.h"
//#include"Core.h"
//
//using namespace std;
//
//istream& Student_info::read(istream& is){
//	delete cp;
//
//	char ch;
//	while(is >> ch){
//		if(ch == 'U')
//			cp = new Core(is);
//		else
//			cp = new Grad(is);
//	}
//	return is;
//}
//
////复制构造函数
//Student_info::Student_info(const Student_info& s):cp(0){
//	if(s.cp)
//		cp = s.cp->clone();
//}
//
////赋值操作符函数
//Student_info& Student_info::operator=(const Student_info& s){
//	if(&s != this){
//		delete cp;
//		if(s.cp)
//			cp = s.cp->clone();
//		else
//			cp = 0;
//	}
//	return *this;
//}
//
