//
//  main.cpp
//  BOARDCOVER2
//
//  Created by 다곰 on 2021/01/16.
//

#include <iostream>
using namespace std;

//보드크기 = H*W
int H, W;
int board[20][20];

//채울 도형 모양 고정
int shapes[4][3][2] { {{0,0},{1,0},{0,1}},{{0,0},{1,0},{1,1}},{{0,0},{0,1},{1,1}},{{0,0},{1,0},{1,-1}}};

bool position(int y, int x, int shape, int a) {   //도형 놓을 수 있는 위치인지 검사
    bool chk = true;    //도형 놓을 수 있는 위치
    
    //검사할 좌표
    for (int i = 0; i < 3; i++) {
        int cy = y + shapes[shape][i][0];
        int cx = x + shapes[shape][i][1];
        
        //도형 놓을 수 없는 위치일 경우 false 반환해 도형 삭제하도록 함
        //다른 도형이랑 겹침->여기서 해당 자리 1로 채우기??
        if((board[cy][cx] += a) > 1) chk = false;
        //보드 벗어남
        else if(cx < 0 || cy < 0 || cx >= W || cy >= H) chk = false;
    }
   
    return chk;
}

int cover() {
    int x = -1, y = -1; //x, y 초기화
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if(board[i][j] == 0) {  //비어 있으면 x,y에 업데이트해서 도형 올 수 있는 위치인지 검사
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1) {  //(i,j)가 0인 좌표 존재하는 경우 for문 나오기
            break;
        }
    }
    
    if (y == -1) {  //보드판 다 채워진 경우 return하면 count값에 추가되어 방법이 하나 느는 것
        return 1;
    }
    
    int count = 0;  //도형 놓는 방법 수
    for (int shape = 0; shape < 4; shape++) {
        if(position(y, x, shape,1)) { //도형 놓을 수 있는 위치일 경우
            //cover() 재귀하면 현위치에는 이미 채워졌으므로 다음 칸부터 검사함
            //보드판 다 채울 때까지 재귀호출해서 다 채우면 1 return해 count 증가
            count += cover();
        }
        
        //이 경우는 현 위치에 도형 놓을 수 없을 경우나 현재 도형으로 계속 재귀호출하면서 진행한 결과 보드 채우는 방법 몇 가지 알아낸 경우 다른 모양으로도 방법 count하려는 것
        //다른 모양 도형도 가능한지 확인하기 위해 현위치에서 앞선 모양으로 덮은 블록 지움
        position(y, x, shape,-1);
    }

    return count;
}

int main() {

    //입력
    //케이스
    int C;
    cin >> C;
    
    //게임판 입력
    char s[20];
    for (int k = 0; k < C; k++) {
        cin >> H >> W;
        for (int i = 0; i < H; i++) {
            cin >> s;
            for (int j = 0; j < W; j++) {
                
                //도형 채워진 곳은 1, 아닌 곳은 0으로 채우기
                board[i][j] = (s[j] == '#') ? 1 : 0;
            }
        }
        //출력
        cout << cover() << endl;
    }
    
    
    //솔루션
    //2. 도형 놓을 수 있는지 검사(겹치기x, 게임판 안에 있기)->놓을 수 없으면 보드판 다 채워진 것
    //도형 놓아보기
    //3. 도형 놓은 위치는 1로 변경
    //4. 도형 놓을 수 없으면 탐색점도 0으로 변경
    
    
    
}
