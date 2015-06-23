//#pragma once
//
//#include<string>
//#include<vector>
//#include<map>
//#include<stdexcept>
//
////规则类型
//typedef std::vector<std::string> Rule;
////规则集合类型
//typedef std::vector<Rule> Rule_collection;
////映射表类型
//typedef std::map<std::string, Rule_collection> Grammer;
//
//int nrand(int);
//
//bool bracketed(const std::string&);
//
//Grammer read_grammar(std::istream&);
//
////根据文法生成语句，辅助函数
//template <class OutputIterator>
//void gen_aux(Grammer& g, const std::string& word, OutputIterator d){
//	if(!bracketed(word)){
//		*d = word;
//	} else {
//		//为对应于word的规则定位
//		Grammer::const_iterator iter = g.find(word);
//		if(iter == g.end()){
//			throw std::logic_error("empty rules!");
//		}
//		//获得可能规则集合
//		const Rule_collection& c = iter->second;
//		//从规则集合中随机选择一条规则
//		const Rule& r = c[nrand(c.size())];
//		//递归展开所选定的规则
//		for(Rule::const_iterator i = r.begin(); i != r.end(); ++i){
//			gen_aux(g, *i, d++);
//		}
//	}
//}
//
////根据文法生成语句
//template <class OutputIterator>
//OutputIterator gen_sentence(Grammer& g, OutputIterator d){
//	gen_aux(g, "<sentence>", d);
//	return d;
//}
