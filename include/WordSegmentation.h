//结巴测试


#ifndef _WORDSEGMENTATION_H_
#define _WORDSEGMENTATION_H_
#include "simhash/cppjieba/Jieba.hpp"
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

//这里这个路径是相对于使用文件到jieba.dict.utf8的路径
const char * const DICT_PATH = "../dict/jieba.dict.utf8";//最大概率法
//(MPSegment: Max Probability)分词所使用的词典路径
const char * const HMM_PATH = "../dict/hmm_model.utf8";//隐式马尔科夫
//模型(HMMSegment: Hidden Markov Model)分词所使用的词典路径
const char * const USER_DICT_PATH = "../dict/user.dict.utf8";//用户自
//定义词典路径
const char* const IDF_PATH = "../dict/idf.utf8";//IDF路径
const char* const STOP_WORD_PATH = "../dict/stop_words.utf8";//停用词
//路径
class WordSegmentation//使用结巴分词库进行分词
{
public:
WordSegmentation()
: _jieba(DICT_PATH, HMM_PATH, USER_DICT_PATH,IDF_PATH,STOP_WORD_PATH)
//初始化Jieba类对象
{
cout << "cppjieba init!" << endl;
}
vector<string> operator()(const string str)//返回str的分词结果
{
vector<string> words;
_jieba.CutAll(str, words);//FullSegment
return words;
}
private:
cppjieba::Jieba _jieba;
};
#endif
