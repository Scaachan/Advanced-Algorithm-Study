//
//  main.cpp
//  QUADTREE
//
//  Created by yujeong on 2021/01/17.
//
#include<iostream>
#include<string>

using namespace std;

void quadTree(const string& word) {
    
    if (word[0] != 'x') {
        cout << word;
        return;
    }

    int index[4] = {0};
    int count = 1,  cnt = 0, num = 0;
    
    for (int i = 1; i < word.size(); i++) {
        cnt++;
        if (count == cnt) {
            index[num] = i;
            num++;
            count = 1;
            cnt = 0;
        }

        if (word[i] == 'x') count += 4;

    }

    cout << "x";
    
    quadTree(word.substr(index[2], index[3] - index[2]));
    quadTree(word.substr(index[3]));
    quadTree(word.substr(index[0], index[1] - index[0]));
    quadTree(word.substr(index[1], index[2] - index[1]));
}


int main() {

    int c;
    cin >> c;

    for (int i=0; i < c; i++) {
        string tree;
        cin >> tree;

        quadTree(tree);
        cout << endl;
    }

    return 0;
}
