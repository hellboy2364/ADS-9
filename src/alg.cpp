// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
    std::ifstream fin(filename);
    if (!fin) {
        std::cout << "File error!" << std::endl;
        exit(1);
    }
    char c;
    std::string sl;
    BST<std::string> wood;
    while (fin.get(c)) {
        if (isalpha(c)) {
            sl += tolower(c);
        } else if (!sl.empty()) {
            wood.add(sl);
            sl.clear();
        }
    }
    fin.close();
    return wood;
}
