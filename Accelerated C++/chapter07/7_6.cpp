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
////��������
//typedef vector<string> Rule;
////���򼯺�����
//typedef vector<Rule> Rule_collection;
////ӳ�������
//typedef map<string, Rule_collection> Grammer;
//
////���ʷָ�
//vector<string> split(const string& s){
//	vector<string> ret;
//	typedef string::size_type str_size;
//	str_size i = 0;
//
//	while(i != s.size()){
//		//�ҵ����ʿ�ʼλ��
//		while(i != s.size() && isspace(s[i]))
//			++i;
//
//		str_size j = i;
//		//�ҵ����ʽ���λ��
//		while(j != s.size() && !isspace(s[j]))
//			++j;
//
//		//�ҵ�һ�����ʣ����洢
//		if(i != j){
//			ret.push_back(s.substr(i, j-i));
//		    i = j;
//		}
//	}
//
//	return ret;
//}
//
////��һ���ض����������ж����ķ�
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
////��鵥���Ƿ���������
//bool bracketed(const string& s){
//	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
//}
//
////����[0,n)��һ���������
//int nrand(int n){
//	if(n <= 0 || n > RAND_MAX)
//		throw domain_error("Argument to nrand is out of range!");
//	
//	//�洢Ͱ��С
//	const int bucket_size = RAND_MAX / n;
//	
//	int r;//�洢Ͱ�ı��
//	do
//	  r = rand() / bucket_size;
//	while(r >= n);
//
//	return r;
//}
//
////�����ķ�������䣬��������
//void gen_aux(Grammer& g, const string& word, vector<string>& stack, vector<string>& ret){
//	if(!bracketed(word)){
//		ret.push_back(word);
//	} else {
//		//Ϊ��Ӧ��word�Ĺ���λ
//		Grammer::const_iterator iter = g.find(word);
//		if(iter == g.end()){
//			throw logic_error("empty rules!");
//		}
//		//��ÿ��ܹ��򼯺�
//		const Rule_collection& c = iter->second;
//		//�ӹ��򼯺������ѡ��һ������
//		const Rule& r = c[nrand(c.size())];
//		//չ����ѡ���Ĺ���ѹ���ջ
//		//������Ϊ��ջ��ջ���ǴӺ��濪ʼ
//		for(Rule::const_reverse_iterator i = r.rbegin(); i != r.rend(); ++i){
//			stack.push_back(*i);
//		}
//	}
//}
//
////�����ķ��������
//vector<string> gen_sentence(Grammer& g){
//	vector<string> ret;
//	vector<string> stack;//��ջ���������
//	stack.push_back("<sentence>");
//
//	//��ջ
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