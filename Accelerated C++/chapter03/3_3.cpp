//#include<iostream>
//#include<string>
//#include<algorithm>
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
//	cout << "Please enter some words: "
//		    "followed by end-of-file: ";
//
//	//���뵥��
//	vector<string> words;
//	string word;
//	while(cin >> word){
//		words.push_back(word);
//	}
//
//	//
//	typedef vector<string>::size_type vc_size;
//	vc_size size = words.size();
//	if(size == 0){
//		cout << "You must enter words! Please try again!" << endl;
//		return 1;
//	}
//
//	//����
//	sort(words.begin(), words.end());
//
//	//ͳ�Ʋ����
//	int count = 1;
//	vc_size i = 1;
//	while(i != size){
//		if(words[i] != words[i-1]){
//			cout << words[i-1] << ": " << count << endl;
//			count = 1;//��������
//		} else {
//			++count;
//		}
//		++i;
//	}
//	cout << words[i-1] << ": " << count << endl;
//
//	return 0;
//}