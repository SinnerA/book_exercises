//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<iomanip>
//
//using namespace std;
//
////学生信息
//struct Student_info{
//	string name;
//	double grade;
//};
//
////求家庭作业中值
//double median(vector<double> homeworks){
//	if(homeworks.size() == 0){
//		throw domain_error("median of an empty vector");
//	}
//
//	//排序
//	sort(homeworks.begin(), homeworks.end());
//
//	typedef vector<double>::size_type vc_size;
//	vc_size size = homeworks.size();
//	vc_size mid = size/2;
//
//	return size%2 == 0 ? (homeworks[mid] + homeworks[mid-1])/2 : homeworks[mid];
//}
//
////计算分数
//double grade(double midterm, double final, double median){
//	return 0.2 * midterm + 0.4 * final + 0.4 * median;
//}
//
//double grade(double midterm, double final, const vector<double>& homeworks){
//	if(homeworks.size() == 0){
//		throw domain_error("student has done no homewor");
//	}
//	return grade(midterm, final, median(homeworks));
//}
//
//double grade(const Student_info& s){
//	return s.grade;
//}
//
////读取家庭作业分数
//istream& read_hw(istream& in, vector<double>& hw){
//	if(in){
//		hw.clear();
//
//		double x;
//		while(in >> x){
//			hw.push_back(x);
//		}
//		//清除流以便对下一个学生输入有效
//		in.clear();
//	}
//	return in;
//}
//
////读入学生信息
//istream& read(istream& in, Student_info& s){
//
//	double midterm, final;
//	vector<double> hw;
//
//	in >> s.name >> midterm >> final;
//	read_hw(in, hw);
//
//	if(in)
//		s.grade = grade(midterm, final, hw);
//
//	return in;
//}
//
////名字排序
//bool compare(Student_info& a, Student_info& b){
//	return a.name < b.name;
//}
//
//int main(){
//
//	Student_info record;
//	vector<Student_info> students;
//	string::size_type maxlength = 0;
//
//	//计算最长name的长度
//	try{
//		while(read(cin, record)){
//			students.push_back(record);
//			maxlength = max(record.name.size(), maxlength);
//		}
//	} catch(domain_error e){
//		cout << e.what() << endl;
//	}
//
//	//排序
//	sort(students.begin(), students.end(), compare);
//
//	//输出学生信息
//	for(vector<Student_info>::size_type i = 0; i != students.size(); i++){
//		//姓名
//		cout << students[i].name << string(maxlength-students[i].name.size()+1, ' ');
//
//		//分数
//		streamsize prec = cout.precision();
//		cout << setprecision(3)
//			 << grade(students[i])
//			 << setprecision(prec)
//			 << endl;
//	}
//
//	return 0;
//}