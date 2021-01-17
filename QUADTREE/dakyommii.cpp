//
//  main.cpp
//  quardTree3
//
//  Created by 다곰 on 2021/01/16.
//

#include <iostream>
using namespace std;

string quard(string &str, int idx) {
    //문자열 한 글자씩 추출
    char s = str[idx];
    
    //w, b일 경우 그대로 return해줌
    if(s == 'w') return "w";
    if(s == 'b') return "b";
    
    //x일 경우 -> 영역 나눠서 반전해서 return해주기
    //좌측 상단/우측상단/좌측하단/우측하단 순으로 나눠서 순서대로 1,2,3,4분면이라고 하면 1-3,2-4분면끼리 바꾸면 뒤집은 쿼드트리 구현 가능
    //재귀함수를 사용하므로 x를 계속 만나면 그 x노드에 대한 하위 노드 반전을 하고 그 상위 노드로 넘어가므로 2사분면에서 처리를 하다가 x를 만나서 하위 노드를 처리하면 하위 노드 처리를 모두 하고 다시 그 위치로 복구되어 이어서 3,4분면 처리할 수 있음
    
    //똑같은 문자열에 대해 검사 시작점만 달라지는 것이므로 문자열은 고정되고 idx만 달라짐
    //좌측 상단(1)
    idx += 1;   //x 다음부터 시작
    string lt = quard(str, idx);
    
    //우측 상단(2)
    idx += lt.length(); //lt 끝난 지점부터 시작
    string rt = quard(str, idx);
    
    //좌측 하단(3)
    idx += rt.length(); //rt 끝난 지점부터 시작
    string lb = quard(str, idx);
    
    //우측 하단(4)
    idx += lb.length(); //lb 끝난 지점부터 시작
    string rb = quard(str, idx);
    
    return "x" + lb + rb + lt + rt;
}


int main() {
    //입력
    //케이스
    int C;
    cin >> C;
    
    //문자열
    string * s = new string[C];
    for (int i = 0; i < C; i++) {
        cin >> s[i];
    }
    
    //계산
    string * reverse = new string[C];
    for (int i = 0; i < C; i++) {
        reverse[i] = quard(s[i], 0);
    }
    
    //출력
    for (int i = 0; i < C; i++) {
        cout << reverse[i] << endl;
    }
}
