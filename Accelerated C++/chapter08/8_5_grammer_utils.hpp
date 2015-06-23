//#pragma once
//
//#include<string>
//#include<vector>
//#include<map>
//#include<stdexcept>
//
////��������
//typedef std::vector<std::string> Rule;
////���򼯺�����
//typedef std::vector<Rule> Rule_collection;
////ӳ�������
//typedef std::map<std::string, Rule_collection> Grammer;
//
//int nrand(int);
//
//bool bracketed(const std::string&);
//
//Grammer read_grammar(std::istream&);
//
////�����ķ�������䣬��������
//template <class OutputIterator>
//void gen_aux(Grammer& g, const std::string& word, OutputIterator d){
//	if(!bracketed(word)){
//		*d = word;
//	} else {
//		//Ϊ��Ӧ��word�Ĺ���λ
//		Grammer::const_iterator iter = g.find(word);
//		if(iter == g.end()){
//			throw std::logic_error("empty rules!");
//		}
//		//��ÿ��ܹ��򼯺�
//		const Rule_collection& c = iter->second;
//		//�ӹ��򼯺������ѡ��һ������
//		const Rule& r = c[nrand(c.size())];
//		//�ݹ�չ����ѡ���Ĺ���
//		for(Rule::const_iterator i = r.begin(); i != r.end(); ++i){
//			gen_aux(g, *i, d++);
//		}
//	}
//}
//
////�����ķ��������
//template <class OutputIterator>
//OutputIterator gen_sentence(Grammer& g, OutputIterator d){
//	gen_aux(g, "<sentence>", d);
//	return d;
//}
