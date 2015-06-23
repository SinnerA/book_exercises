//#include<iostream>
//#include<string>
//#include<vector>
//
//using std::cout;
//using std::cin;
//using std::endl;
//using std::string;
//using std::vector;
//
//int main(){
//
//	cout << "Please enter some words: ";
//	string word;
//	vector<string> words;
//	while(cin >> word){
//		words.push_back(word);
//	}
//
//	//判断字符串是否存在
//	typedef vector<string>::size_type vc_size;
//	vc_size size = words.size();
//	if(size == 0){
//		cout << "You must enter some words! Please try again!" << endl;
//		return 1;
//	}
//	
//	typedef string::size_type str_size;
//	vc_size i = 0;
//	str_size min = words[0].size();//最小
//	str_size max = words[0].size();//最大
//	str_size curLen = 0;//当前字符串长度
//	while(i != size){
//		curLen = words[i].size();
//		if(curLen < min)
//			min = curLen;
//		if(curLen > max)
//			max = curLen;
//		++i;
//	}
//
//	//得到结果
//	cout << "The max is: " << max << ", and the min is: " << min << endl;
//
//	return 0;
//}