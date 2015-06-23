//#include"split.h"
//#include"pics.h"
//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<iomanip>
//
//using namespace std;
//
//struct Rotation{
//	vector<string>::size_type first;
//	vector<string> words;
//};
//
//vector<string> read_lines(){
//	vector<string> lines;
//	string s;
//	
//	while(getline(cin, s)){
//		lines.push_back(s);
//	}
//	return lines;
//}
//
////一行轮转的集合
//vector<Rotation> rotate_line(const string& line){
//	vector<Rotation> rots;
//
//	vector<string> words = split(line);
//	
//	for(string::size_type i = 0; i != words.size(); ++i){
//		Rotation rot = {words.size() - i, words};
//		rots.push_back(rot);
//
//		//行首单词交换到行尾
//		rotate(words.begin(), words.begin() + 1, words.end());
//	}
//	return rots;
//}
//
////多行轮转集合
//vector<Rotation> rotate_lines(const vector<string>& lines){
//	vector<Rotation> rots;
//
//	for(vector<string>::size_type i = 0; i != lines.size(); ++i){
//		vector<Rotation> new_rots = rotate_line(lines[i]);
//		rots.insert(rots.end(), new_rots.begin(), new_rots.end());
//	}
//	return rots;
//}
//
////比较
//bool compare(const Rotation& a, const Rotation& b){
//	return a.words < b.words;
//}
//
//void print_rotations(vector<Rotation>& rots){
//
//	vector<string> lefts, rights;
//	string::size_type maxlen_lefts = 0;
//
//	for(vector<Rotation>::size_type i = 0; i != rots.size(); ++i){
//		vector<string> words = rots[i].words;
//		vector<string>::size_type first = rots[i].first;
//
//		string::size_type j = 0;
//		string left, right;
//
//		for(j = first; j < words.size(); ++j){
//			left +=  words[j] + " ";
//		}
//
//		lefts.push_back(left);
//
//		if(maxlen_lefts < left.size())
//			maxlen_lefts = left.size();
//
//		for(j = 0; j < first; ++j){
//			right += words[j] + " ";
//		}
//
//		rights.push_back(right);
//	}
//
//	//输出
//	for(vector<string>::size_type i = 0; i != lefts.size(); ++i){
//		cout << setw(maxlen_lefts) 
//			 << lefts[i]
//		     << "\t"
//			 << rights[i]
//		     << endl;
//	}
//}
//
//int main(){
//	vector<string> lines = read_lines();
//	vector<Rotation> rots = rotate_lines(lines);
//	sort(rots.begin(), rots.end(), compare);
//	print_rotations(rots);
//	return 0;
//}
//
//
//
