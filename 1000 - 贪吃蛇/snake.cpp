#include "snake.h"

Snake::Snake(Wall& wall, Food& food) : wall_(wall), food_(food)
{
	header_ = nullptr;
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
	if (nullptr != header_) wall_.setWall(header_->x_point, header_->y_point, '=');
	wall_.setWall(x, y, 'D');
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

	// �ж��û������λ���Ƿ�ɹ�
	if (wall_.getWall(x, y) == '*' || wall_.getWall(x, y) == '=')
	{
		cout << "GAME OVER" << endl;
		return false;
	}

	// �ƶ��ɹ������� 1.�Ե�ʳ�� 2.û��
	if (wall_.getWall(x, y) == '#')
	{
		addPoint(x, y);
		
		// ��������ʳ��
		food_.setFood();
	}
	else
	{
		addPoint(x, y);
		deleteRear();
	}
	return true;
}