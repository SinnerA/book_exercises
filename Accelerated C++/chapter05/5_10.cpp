//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<iterator>
//
//using namespace std;
//
////是否回文
//bool is_palindrome(const string& word){
//	string reversed;
//	reverse_copy(word.begin(), word.end(), back_inserter(reversed));
//	return word == reversed;
//}
//
//int main(){
//	vector<string> palindromes;
//	string longest_palindrome = 0;
//	string s;
//
//	while(cin >> s){
//		if(is_palindrome(s)){
//			palindromes.push_back(s);
//			if(longest_palindrome.size() < s.size())
//				longest_palindrome = s;
//		}
//	}
//
//	cout << "The longest palindrome is: " << longest_palindrome << endl;
//	for(vector<string>::const_iterator iter = palindromes.begin; iter != palindromes.end(); ++iter){
//		cout << *iter << endl;
//	}
//	return 0;
//}