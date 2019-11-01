//
// Created by kimem on 2019-11-01.
//

#ifndef LAB6_DICTIONARY_HPP
#define LAB6_DICTIONARY_HPP
#include <map>
#include <iterator>
#include <iostream>

using namespace std;
class dictionary{
private:
    map<string, string> my_dictionary;
    string file;
    map<string, string>::iterator iter;



public:
    dictionary(string file);
    void makeDictionary();
    void printDictionary(map<string, string> &dictionary);
    map<string, string> &getDictionary(){return my_dictionary;}
    void printMenu();
    bool findWord(map<string, string> &dictionary);
void enterNewWord(map<string, string> &dictionary);
void updateDictionary(map<string, string> &dictionary, string newWord, string newWordDefinition);

};
#endif //LAB6_DICTIONARY_HPP
