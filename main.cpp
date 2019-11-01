#include <iostream>
#include "dictionary.hpp"
int main() {
dictionary d("../dictionary.txt");
d.makeDictionary();
d.printMenu();

int decision;
while(cin >> decision && decision != 4){
    switch(decision){
        case 1:
            d.printDictionary(d.getDictionary());
            d.printMenu();
            break;
        case 2:
            d.findWord(d.getDictionary());
            d.printMenu();
            break;
        case 3:
            d.enterNewWord(d.getDictionary());
            d.printMenu();
            break;
        case 4:
            exit(0);
        default:
            cout << "Please enter again"<< endl;
            d.printMenu();
            break;
    }
}
return 0;
}