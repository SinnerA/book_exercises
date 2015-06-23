//#include<iostream>
//#include<string>
//#include<vector>
//
//using namespace std;
//
//vector<string> center(const vector<string>& picture){
//	vector<string> new_pic;
//	string::size_type maxlen = 0;
//
//	for(vector<string>::const_iterator i = picture.begin(); i != picture.end(); ++i){
//		if(i->size() > maxlen)
//			maxlen = i->size();
//	}
//
//	for(vector<string>::const_iterator i = picture.begin(); i != picture.end(); ++i){
//		string::size_type padding = (maxlen - i->size()) / 2;
//		string new_line(padding, '-');
//		new_line +=*i;
//		new_pic.push_back(new_line);
//	}
//	return new_pic;
//}
//
//int main(){
//	vector<string> pic, new_pic;
//
//	pic.push_back("*");
//	pic.push_back("***");
//	pic.push_back("*****");
//
//	new_pic = center(pic);
//
//	for(vector<string>::const_iterator i = new_pic.begin(); i != new_pic.end(); ++i){
//		cout << *i << endl;
//	}
//
//	return 0;
//}
