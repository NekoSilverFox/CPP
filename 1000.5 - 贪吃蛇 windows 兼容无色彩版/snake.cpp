#include "snake.h"

void gotoxy_snack(HANDLE hOut_snack, int x, int y)
{
	COORD pos;
	pos.X = x;             // ������
	pos.Y = y;            // ������
	SetConsoleCursorPosition(hOut_snack, pos);
}
HANDLE hOut_snack = GetStdHandle(STD_OUTPUT_HANDLE); // ������ʾ���������

Snake::Snake(Wall& wall, Food& food) : wall_(wall), food_(food), isRool(false)
{
	header_ = nullptr;
	//isRool = false;
}

void Snake::initSnake()
{
	destotySnake();
	addPoint(5, 6);
	addPoint(5, 7);
	addPoint(5, 8);
}
void Snake::addPoint(int x, int y)
{
	Point* newPoint = new Point;
	newPoint->x_point = x;
	newPoint->y_point = y;
	newPoint->next_ = nullptr;

	//���ԭ��ͷ��Ϊ�� ��Ϊ ����
	if (nullptr != header_)
	{
		wall_.setWall(header_->x_point, header_->y_point, '=');
		gotoxy_snack(hOut_snack, header_->y_point * 2, header_->x_point);
		cout << "=";
	}
	wall_.setWall(x, y, 'D');
	gotoxy_snack(hOut_snack, y * 2, x);
	cout << "D";
	newPoint->next_ = header_;
	//����ͷ��
	header_ = newPoint; 
}

void Snake::destotySnake()
{
	if (nullptr == header_) return;

	Point* pCurrent = nullptr;

	while (header_ != nullptr)
	{
		pCurrent = header_->next_;
		delete header_;
		header_ = nullptr;
		header_ = pCurrent;
	}
}

void Snake::deleteRear()
{
	// ���ֻ�������ڵ������ɾ��
	if (nullptr == header_ || nullptr == header_->next_) return;

	Point* pCurrent = header_;
	Point* pRear = header_->next_;

	//ɾ��β�ڵ�
	while (pRear->next_ != nullptr)
	{
		pCurrent = pRear;
		pRear = pRear->next_;
	}

	wall_.setWall(pRear->x_point, pRear->y_point, ' ');
	gotoxy_snack(hOut_snack, pRear->y_point * 2, pRear->x_point);
	cout << ' ';

	delete pRear;
	pRear = nullptr;
	pCurrent->next_ = nullptr;
}

bool Snake::moveSnake(char key)
{
	int x = header_->x_point;
	int y = header_->y_point;

	
	switch (key)
	{
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;
	default:
		break;
	}

	// �жϣ���һ����������β�ͣ���Ӧ������
	Point* pCurrent = header_;
	Point* pRear = header_->next_;
	while (pRear->next_ != nullptr)
	{
		pCurrent = pCurrent->next_;
		pRear = pRear->next_;
	}

	// ��������β��
	if (pRear->x_point == x && pRear->y_point == y) isRool = true;
	else
	{
		// �ж��û������λ���Ƿ�ɹ�
		if (wall_.getWall(x, y) == '*' || wall_.getWall(x, y) == '=')
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			// ͷ��ǽ��
			{
				addPoint(x, y);
				deleteRear();
				system("cls");
				wall_.drawWall();
			}
			cout << R"(
 �X�T�T�T�j�T�T�T�j�T�[�X�T�j�T�T�T�[�X�T�T�T�j�[�����X�j�T�T�T�j�T�T�T�[
 �U�X�T�[�U�X�T�[�U�U�^�a�U�U�X�T�T�a�U�X�T�[�U�^�[�X�a�U�X�T�T�g�X�T�[�U
 �U�U���^�g�U���U�U�X�[�X�[�U�^�T�T�[�U�U���U�d�[�U�U�X�g�^�T�T�g�^�T�a�U
 �U�U�X�T�g�^�T�a�U�U�U�U�U�U�X�T�T�a�U�U���U�U�U�^�a�U�U�X�T�T�g�X�[�X�a
 �U�^�m�T�U�X�T�[�U�U�U�U�U�U�^�T�T�[�U�^�T�a�U�^�[�X�a�U�^�T�T�g�U�U�^�[
 �^�T�T�T�m�a���^�m�a�^�a�^�m�T�T�T�a�^�T�T�T�a���^�a���^�T�T�T�m�a�^�T�a
)";
			return false;
		}

	}

	// �ƶ��ɹ������� 1.�Ե�ʳ�� 2.û��
	if (wall_.getWall(x, y) == '#')
	{
		addPoint(x, y);
		wall_.setScore(100);
		// ��������ʳ��
		food_.setFood();
	}
	else
	{
		addPoint(x, y);
		deleteRear();

		if (isRool == true)
		{
			wall_.setWall(x, y, 'D');
			gotoxy_snack(hOut_snack, y * 2, x);
			cout << "D";
		}

	}
	return true;
}

int Snake::getSleepTime()
{
	int sleep_time = 0;
	int size = countList();

	if (size < 8) sleep_time = 300;
	else if (size >= 8 && size <= 14 ) sleep_time = 200;
	else if (size > 14 && size <= 18) sleep_time = 100;
	else sleep_time = 80;

	return sleep_time;
}

// ��ȡ�����
int Snake::countList()
{
	int size_snake = 0;
	Point* pCurrent = header_;
	while (pCurrent != nullptr)
	{
		size_snake++;
		pCurrent = pCurrent->next_;
	}
	return size_snake;
}

