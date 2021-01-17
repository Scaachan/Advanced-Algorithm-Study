#include <iostream>
#include <string>

using namespace std;

string makeQuadtree();
string str;
int i;

int main(void) {
	int c;
	cin >> c;
	
	while (c--) {
		i = -1;
		cin >> str;
		cout << makeQuadtree() << "\n";
	}
}

// str을 0부터 돌며 x일경우 재귀호출을 통해 각각 분할 해서 넣어주고 마지막 return으로 상하 변경해서 return

string makeQuadtree(void) {

	i++;

	if (str[i] == 'b' || str[i] == 'w')     // b나 w면 그 값을 return
		return ((str[i] == 'b')? "b":"w");

	string leftUp = makeQuadtree();
	string rightUp = makeQuadtree();
	string leftDn = makeQuadtree();
	string rightDn = makeQuadtree();

	return "x" + leftDn + rightDn + leftUp + rightUp;  // 상하 변경해서 return

}