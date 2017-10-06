/*
목표:
7*7 바둑판모양위에서 시작값을 부여하고 규칙에따른 변화과정을 출력한다

규칙:
1. on또는 off일 때 이웃한 블록(8방향)이 딱 세개가 on(살아있는 상태)이면 on
2. on 상태일 경우 이웃한 블록(8방향)이 두개가 on이면 on
3. 나머지의 경우 off상태가 된다

구현:

1.	7*7모양의 바둑판을 만들고 off상태로 초기화한다.
2.	특정좌표의 상태를 반환하는 함수,
주변이웃을 검사하고 살아있는 상태만큼의 수를 반환하는 함수,
현재 상태의 바둑판을 출력하는 함수를 만든다.
3.	입력개수를 입력 받고 그 수 만큼 특정좌표를 입력 받는다.
4.	입력 받은 좌표를 on상태로 만들고 그 화면을 출력한다.
5.	규칙에 따라 on, off상태를 결정하고 계속 화면을 출력한다.
6.	임의의 횟수만큼 출력을 반복한다.
*/
#include <iostream>
//#include<Windows.h>

using namespace std;

#define DEAD 0
#define ALIVE 1
//표현을 위한 정의

//정확한 바둑판모양의 구현을 위한 출력함수
ostream &oth(ostream &stream)
{
	stream.width(2);
	stream.fill(' ');
	return stream;
}
//클래스선언
class DEADorALIVE {
	
public:
	
	int board[7][7];
	//7*7
	DEADorALIVE() {
		//0으로 초기화
		for (int y = 0; y<7; y++) {
			for (int x = 0; x<7; x++) {
				board[y][x] = 0;
			}
		}
	}
		bool checkALIVE(int y, int x);
		void viewBoard();
		void start(int y, int x);
		int checkneiALIVE(int y, int x);

};
//시작점 입력을 위한 함수
void DEADorALIVE::start(int y,int x) {
	board[y][x] = ALIVE;
}
//출력을 위한 함수 정확한 바둑판모양을 위해 ostream &oth 사용
void DEADorALIVE::viewBoard() {
	cout << oth << "";
	for (int x = 0; x<7; x++) {
		cout << oth << x;
	}
	cout << endl;
	for (int y = 0; y<7; y++) {
		cout << oth << y;
		for (int x = 0; x<7; x++) {
				//죽어있는곳은 공백 출력
			if (board[y][x] == DEAD)
				cout << oth << "";
			else//살아있는곳은 별모양
				cout << oth << "*";
		}
		cout << endl;
	}
}
//해당타일의 생존여부 확인 두개의 상태밖에 없기때문에 bool사용
bool DEADorALIVE::checkALIVE(int y, int x)
{
	
	// 범위를 넘어가는부분 처리
	if (x < 0 || y < 0 || x > 7 || y > 7) return false;
	// 죽으면 0
	if (board[x][y] == DEAD) return false;
	// 살면 1
	if (board[x][y] == ALIVE) return true;

	return false;
}
//주변에 살아있는 수 검사 후 반환 이웃한 8군데를 차례로 검사하고 cnt값 리턴
//cnt는 본인을 포함한 살아있는값
int DEADorALIVE::checkneiALIVE(int y, int x)
{
	int cnt = 0;

	for (int dx = -1; dx <= 1; dx++)
	{
		for (int dy = -1; dy <= 1; dy++)
		{
			if (DEADorALIVE::checkALIVE(x + dx, y + dy)==ALIVE)
				cnt++;
				
		}
	}
	return cnt;
}
int main()
{
	DEADorALIVE DEADorALIVE;
	
	int ninput;
	int x, y;
	int temp[7][7] = { 0 };
	cout << " 입력할 개수 :";
	cin >> ninput;

	DEADorALIVE.viewBoard();
	//입력개수만큼 시작좌표 입력받음
	for (int i = ninput; i > 0; i--)
	{
		cout << "입력하실 x좌표를 입력하세요: ";
		cin >> x;
		cout << "입력하실 y좌표를 입력하세요: ";
		cin >> y;
		cout << endl;
		DEADorALIVE.start(y, x);
	}
	//7번정도 프린트
	for (int i = 0; i < 7; i++)
	{

		DEADorALIVE.viewBoard();
		//cout << DEADorALIVE.checkALIVE(1, 1) << endl;
		//입력받은 주변검사
		for (int j = 0; j < 7; j++) {
			for (int i = 0; i < 7; i++) {
				temp[j][i] = DEADorALIVE.checkneiALIVE(j, i);
			}
		}
/*
		for (int j = 0; j < 7; j++) {
			for (int i = 0; i < 7; i++) {
				cout << temp[j][i];
			}
			cout << endl;
		}
*/
		for (int j = 0; j < 7; j++) {
			for (int i = 0; i < 7; i++) {

				if (temp[j][i] == 3)
				{
					DEADorALIVE.board[j][i] = ALIVE;
				}
				else if (temp[j][i] == 4 && DEADorALIVE.board[j][i] == ALIVE)
				{
					DEADorALIVE.board[j][i] = ALIVE;
				}
				else DEADorALIVE.board[j][i] = DEAD;
			}
		}
		//Sleep(10000);
	}
		system("pause(100000);");

	return 0;
}