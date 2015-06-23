//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<vector>
//#include<map>
//#include<stdexcept>
//#include<cstdlib>
//
//using namespace std;
//
////规则类型
//typedef vector<string> Rule;
////规则集合类型
//typedef vector<Rule> Rule_collection;
////映射表类型
//typedef map<string, Rule_collection> Grammer;
//
////单词分割
//vector<string> split(const string& s){
//	vector<string> ret;
//	typedef string::size_type str_size;
//	str_size i = 0;
//
//	while(i != s.size()){
//		//找到单词开始位置
//		while(i != s.size() && isspace(s[i]))
//			++i;
//
//		str_size j = i;
//		//找到单词结束位置
//		while(j != s.size() && !isspace(s[j]))
//			++j;
//
//		//找到一个单词，并存储
//		if(i != j){
//			ret.push_back(s.substr(i, j-i));
//		    i = j;
//		}
//	}
//
//	return ret;
//}
//
////从一个特定的输入流中读入文法
//Grammer read_grammer(istream& in){
//	Grammer ret;
//	string line;
//
//	while(getline(in, line)){
//		vector<string> entry = split(line);
//
//		if(!entry.empty()){
//			ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
//		}
//	}
//	return ret;
//}
//
////检查单词是否被括号括起
//bool bracketed(const string& s){
//	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
//}
//
////返回[0,n)的一个随机整数
//int nrand(int n){
//	if(n <= 0 || n > RAND_MAX)
//		throw domain_error("Argument to nrand is out of range!");
//	
//	//存储桶大小
//	const int bucket_size = RAND_MAX / n;
//	
//	int r;//存储桶的编号
//	do
//	  r = rand() / bucket_size;
//	while(r >= n);
//
//	return r;
//}
//
////根据文法生成语句，辅助函数
//void gen_aux(Grammer& g, const string& word, vector<string>& stack, vector<string>& ret){
//	if(!bracketed(word)){
//		ret.push_back(word);
//	} else {
//		//为对应于word的规则定位
//		Grammer::const_iterator iter = g.find(word);
//		if(iter == g.end()){
//			throw logic_error("empty rules!");
//		}
//		//获得可能规则集合
//		const Rule_collection& c = iter->second;
//		//从规则集合中随机选择一条规则
//		const Rule& r = c[nrand(c.size())];
//		//展开所选定的规则，压入堆栈
//		//反序，因为进栈出栈都是从后面开始
//		for(Rule::const_reverse_iterator i = r.rbegin(); i != r.rend(); ++i){
//			stack.push_back(*i);
//		}
//	}
//}
//
////根据文法生成语句
//vector<string> gen_sentence(Grammer& g){
//	vector<string> ret;
//	vector<string> stack;//堆栈，保存规则
//	stack.push_back("<sentence>");
//
//	//出栈
//	while(!stack.empty()){
//		string token = stack.back();
//		stack.pop_back();
//		gen_aux(g, token, stack, ret);
//	}
//	return ret;
//}
//
//int main(){
//	vector<string> sentence = gen_sentence(read_grammer(cin));
//
//	vector<string>::const_iterator iter = sentence.begin();
//	if(!sentence.empty()){
//		cout << *iter;
//		++iter;
//	}
//
//	while(iter != sentence.end()){
//		cout << " " << *iter;
//		++iter;
//	}
//	cout << endl;
//	
//	return 0;
//}