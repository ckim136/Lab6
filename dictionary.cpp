//
// Created by kimem on 2019-11-01.
//

#include "dictionary.hpp"
#include <fstream>
#include <limits>

dictionary::dictionary(string file) {
    this->file = file;
}

void dictionary::makeDictionary() {
    ifstream f(file);
    string line;
    string key;
    string value;
    int count = 0;
    bool set = false;
    while(getline(f, line)){
        if(count == 0){
            key = line;
            count ++;
        }
        else if(count == 1){
            value = line;
            count = 0;
            set = true;
        }
        if(set){
            my_dictionary.insert(make_pair(key, value));
            set = false;
        }

    }

}

void dictionary::printDictionary(map<string, string> &dictionary) {
for(iter = dictionary.begin(); iter != dictionary.end(); ++iter){
    cout << iter->first <<" - "<< iter->second<< endl;
}
cout << endl;
}

void dictionary::printMenu() {
    int decision;
    cout << "1 - Print dictionary" << endl;
    cout << "2 - Find word definition" << endl;
    cout << "3 - Enter new word and definition"<< endl;
    cout << "4 - Exit" << endl;
    cout << endl;
    cout<< "What would you like to do?" << endl;
}

bool dictionary::findWord(map<string, string> &dictionary) {
    string word;
    cout << "Enter a word that you would like to find"<< endl;
    cin >> word;
   if(dictionary.find(word) == dictionary.end()){
       cout << "Dictionary can't find the word you entered" << endl;
       cout << endl;
       return false;
   }else{
       cout << dictionary.find(word)->first << " - " << dictionary.find(word)->second << endl;
       cout << endl;
       return true;
   }


}

void dictionary::enterNewWord(map<string, string> &dictionary) {
    cout << "Enter a word you would like to add to the dictionary" << endl;
    string newWord;
    string newWordDefinition;
    cin >> newWord;
    if(dictionary.find(newWord) == dictionary.end()){
        cout << "Enter a definition for your new word " << newWord<< endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin ,newWordDefinition);

        cout << newWord << " - " << newWordDefinition<< " added"<< endl;
        cout << endl;

        dictionary.insert(make_pair(newWord, newWordDefinition));
        updateDictionary(dictionary, newWord, newWordDefinition);


    }else{
        cout << "The word " << newWord << " already exist in the dictionary" << endl;
        cout << endl;
    }

}

void dictionary::updateDictionary(map<string, string> &dictionary, string newWord, string newWordDefinition) {

    dictionary.insert(make_pair(newWord, newWordDefinition));
    ofstream f(file, ios::app);
    f << newWord << endl;
    f << newWordDefinition<< endl;
}

