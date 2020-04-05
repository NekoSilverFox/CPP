#include "snake.h"

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

	//如果原来头不为空 改为 身子
	if (nullptr != header_) wall_.setWall(header_->x_point, header_->y_point, '=');
	wall_.setWall(x, y, 'D');
	newPoint->next_ = header_;
	//更新头部
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
	// 如果只有两个节点就无需删除
	if (nullptr == header_ || nullptr == header_->next_) return;

	Point* pCurrent = header_;
	Point* pRear = header_->next_;

	//删除尾节点
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

	// 判断：下一步碰到的是尾巴，不应该死亡
	Point* pCurrent = header_;
	Point* pRear = header_->next_;
	while (pRear->next_ != nullptr)
	{
		pCurrent = pCurrent->next_;
		pRear = pRear->next_;
	}

	// 碰到的是尾巴
	if (pRear->x_point == x && pRear->y_point == y) isRool = true;
	else
	{
		// 判断用户到达的位置是否成功
		if (wall_.getWall(x, y) == '*' || wall_.getWall(x, y) == '=')
		{
			// 头卡墙里
			{
				addPoint(x, y);
				deleteRear();
				system("cls");
				wall_.drawWall();
			}

			cout << "GAME OVER" << endl;
			return false;
		}

	}

	// 移动成功分两种 1.吃到食物 2.没有
	if (wall_.getWall(x, y) == '#')
	{
		addPoint(x, y);
		wall_.setScore(100);
		// 重新设置食物
		food_.setFood();
	}
	else
	{
		addPoint(x, y);
		deleteRear();

		if (isRool == true)
		{
			wall_.setWall(x, y, 'D');
		}

	}
	return true;
}

int Snake::getSleepTime()
{
	int sleep_time = 0;
	int size = countList();
	if (size < 8)
	{
		sleep_time = 300;
	}
	else if (size >= 8 && size <= 14 )
	{
		sleep_time = 200;
	}
	else if (size > 14 && size <= 18)
	{
		sleep_time = 100;
	}
	else
	{
		sleep_time = 80;
	}
	return sleep_time;
}

// 获取蛇身段
int Snake::countList()
{
	int size = 0;
	Point* pCurrent = header_;
	while (pCurrent != nullptr)
	{
		size++;
		pCurrent = pCurrent->next_;
	}
	return size;
}

