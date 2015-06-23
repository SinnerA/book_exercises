//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//istream& read(istream& in, vector<string>& words){
//	if(in){
//		words.clear();
//		string word;
//
//		while(in >> word){
//			words.push_back(word);
//		}
//
//		in.clear();
//	}
//	return in;
//}
//
//int main(){
//	
//	vector<string> words;
//	read(cin, words);
//	
//	//单词排序
//	sort(words.begin(), words.end());
//
//	cout << "Num of words: " << words.size() << endl;
//
//	string prev_word = "";
//	int count = 0;
//	for(string::size_type i = 0; i != words.size(); i++){
//		if(words[i] != prev_word){
//			if(prev_word != ""){
//				cout << prev_word << " appeared " << count <<  endl;
//			}
//			prev_word = words[i];
//			count = 1;
//		} else {
//			++count;
//		}
//	}
//
//	//最后一个单词
//	cout << prev_word << " appeared " << count << endl;
//
//	return 0;
//}