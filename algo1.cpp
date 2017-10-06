/*
��ǥ:
7*7 �ٵ��Ǹ�������� ���۰��� �ο��ϰ� ��Ģ������ ��ȭ������ ����Ѵ�

��Ģ:
1. on�Ǵ� off�� �� �̿��� ���(8����)�� �� ������ on(����ִ� ����)�̸� on
2. on ������ ��� �̿��� ���(8����)�� �ΰ��� on�̸� on
3. �������� ��� off���°� �ȴ�

����:

1.	7*7����� �ٵ����� ����� off���·� �ʱ�ȭ�Ѵ�.
2.	Ư����ǥ�� ���¸� ��ȯ�ϴ� �Լ�,
�ֺ��̿��� �˻��ϰ� ����ִ� ���¸�ŭ�� ���� ��ȯ�ϴ� �Լ�,
���� ������ �ٵ����� ����ϴ� �Լ��� �����.
3.	�Է°����� �Է� �ް� �� �� ��ŭ Ư����ǥ�� �Է� �޴´�.
4.	�Է� ���� ��ǥ�� on���·� ����� �� ȭ���� ����Ѵ�.
5.	��Ģ�� ���� on, off���¸� �����ϰ� ��� ȭ���� ����Ѵ�.
6.	������ Ƚ����ŭ ����� �ݺ��Ѵ�.
*/
#include <iostream>
//#include<Windows.h>

using namespace std;

#define DEAD 0
#define ALIVE 1
//ǥ���� ���� ����

//��Ȯ�� �ٵ��Ǹ���� ������ ���� ����Լ�
ostream &oth(ostream &stream)
{
	stream.width(2);
	stream.fill(' ');
	return stream;
}
//Ŭ��������
class DEADorALIVE {
	
public:
	
	int board[7][7];
	//7*7
	DEADorALIVE() {
		//0���� �ʱ�ȭ
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
//������ �Է��� ���� �Լ�
void DEADorALIVE::start(int y,int x) {
	board[y][x] = ALIVE;
}
//����� ���� �Լ� ��Ȯ�� �ٵ��Ǹ���� ���� ostream &oth ���
void DEADorALIVE::viewBoard() {
	cout << oth << "";
	for (int x = 0; x<7; x++) {
		cout << oth << x;
	}
	cout << endl;
	for (int y = 0; y<7; y++) {
		cout << oth << y;
		for (int x = 0; x<7; x++) {
				//�׾��ִ°��� ���� ���
			if (board[y][x] == DEAD)
				cout << oth << "";
			else//����ִ°��� �����
				cout << oth << "*";
		}
		cout << endl;
	}
}
//�ش�Ÿ���� �������� Ȯ�� �ΰ��� ���¹ۿ� ���⶧���� bool���
bool DEADorALIVE::checkALIVE(int y, int x)
{
	
	// ������ �Ѿ�ºκ� ó��
	if (x < 0 || y < 0 || x > 7 || y > 7) return false;
	// ������ 0
	if (board[x][y] == DEAD) return false;
	// ��� 1
	if (board[x][y] == ALIVE) return true;

	return false;
}
//�ֺ��� ����ִ� �� �˻� �� ��ȯ �̿��� 8������ ���ʷ� �˻��ϰ� cnt�� ����
//cnt�� ������ ������ ����ִ°�
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
	cout << " �Է��� ���� :";
	cin >> ninput;

	DEADorALIVE.viewBoard();
	//�Է°�����ŭ ������ǥ �Է¹���
	for (int i = ninput; i > 0; i--)
	{
		cout << "�Է��Ͻ� x��ǥ�� �Է��ϼ���: ";
		cin >> x;
		cout << "�Է��Ͻ� y��ǥ�� �Է��ϼ���: ";
		cin >> y;
		cout << endl;
		DEADorALIVE.start(y, x);
	}
	//7������ ����Ʈ
	for (int i = 0; i < 7; i++)
	{

		DEADorALIVE.viewBoard();
		//cout << DEADorALIVE.checkALIVE(1, 1) << endl;
		//�Է¹��� �ֺ��˻�
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