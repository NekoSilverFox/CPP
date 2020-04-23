#include<iostream>
#include<stdlib.h>
#include<windows.h> 
#define M 10
#define N 10
using namespace std;
struct Node{
	int x,y;
	int m[M][N];
	Node *next;
};
class List_LK{ //分叉路口 
	public:
		List_LK();
		void In(int a,int b,int c[M][N]);//插入分叉路口坐标 
		void Delete();//删除
		int Get_x();//得到坐标x 
		int Get_y();//y 
		int LK[M][N];
		void get_m();
	private:
		Node *first;
};
	List_LK::List_LK(){
	first=new Node;
	first->next=NULL;
}
void List_LK::In(int a,int b,int c[M][N]){
	Node *p = first,*s = NULL;
	s = new Node;
	s->x = a; s->y = b;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++)
		s->m[i][j] = c[i][j];
	}
	s->next = p->next;
	p->next = s;
}
void List_LK::Delete(){
	Node *p = first,*q = NULL;
	q = p->next;
	p->next = q->next;
	delete q;
}
int List_LK::Get_x(){
	return first->next->x;
}
int List_LK::Get_y(){
	return first->next->y;
}
	int maze[M][N] = {{2,2,2,2,2,2,2,2,2,2},
                      {0,0,2,0,2,0,0,0,0,2},
                      {2,0,0,0,0,0,2,0,2,2},
                      {2,2,2,0,2,0,2,0,2,2},
                      {2,0,0,0,2,0,0,0,0,2},
                      {2,0,2,0,2,0,2,2,0,2},
                      {2,0,2,0,2,0,0,2,0,2},
                      {2,2,2,0,2,2,2,2,0,2},
                      {2,0,0,0,0,0,0,2,0,0},
                      {2,2,2,2,2,2,2,2,2,2}};
    int rat_x = 1,rat_y = 0; //老鼠初始位置 
    int maze_1[M][N]= {{2,2,2,2,2,2,2,2,2,2},
                      {0,0,2,0,2,0,0,0,0,2},
                      {2,0,0,0,0,0,2,0,2,2},
                      {2,2,2,0,2,0,2,0,2,2},
                      {2,0,0,0,2,0,0,0,0,2},
                      {2,0,2,0,2,0,2,2,0,2},
                      {2,0,2,0,2,0,0,2,0,2},
                      {2,2,2,0,2,2,2,2,0,2},
                      {2,0,0,0,0,0,0,2,0,0},
                      {2,2,2,2,2,2,2,2,2,2}};//创建迷宫副本，用来记录已经走过的路线  
 void List_LK::get_m(){
			for(int i=0;i<M;i++){
				for(int j=0;j<N;j++)
				maze[i][j]=first->next->m[i][j] ;
		}
		}	   
int main(){
	void printf_m();//申明函数 打印地图 
	void move();// 申明函数 老鼠移动 
	int JudgeLK(int a,int b);//判断是否走到分叉路口的函数 
	maze[1][0] = 1;//老鼠初始的位置 
	printf_m();
	List_LK MAZE;//创建用来记录分叉路口的链表 
	while(1){
		move();
		if(JudgeLK(rat_x,rat_y) == 1){//用链表记录分叉路口和地图状态 
			MAZE.In(rat_x,rat_y,maze);	
		}
		if(JudgeLK(rat_x,rat_y) == 2){//判断死路，返回上一个路口
			if(maze_1[M-2][N-1] == 1)//判断是否走到终点，跳出循环 
				break;
			rat_x=MAZE.Get_x();
			rat_y=MAZE.Get_y();
			MAZE.get_m();
			if(JudgeLK(rat_x,rat_y) == 2){//返回上个路口再判断，如果都已经走过了，删除节点，返回上上个路口 
				MAZE.Delete();
				rat_x=MAZE.Get_x();
				rat_y=MAZE.Get_y();
				MAZE.get_m();
			}	
		int x1=rat_x,y1=rat_y;
		
		} 
		system("cls");
		printf_m();
		Sleep(100);
	} 
		system("cls");
		printf_m();
		Sleep(100);
} 
void printf_m(){//输出地图 
	int i,j; 
	for( i = 0; i < 10; i++)
      {
          for(j = 0; j < 10; j++)
          	  if(maze[i][j] == 2)
                  printf("█");
              else if(maze[i][j] == 0)
                  printf("  ");
              else if(maze[i][j] == 1)
            	  printf("* ");
          printf("\n");
      }
}
void  move(){//老鼠移动函数 
	if(maze[rat_x+1][rat_y] == 0 && maze_1[rat_x+1][rat_y] == 0){
			rat_x++;
			maze[rat_x][rat_y] = 1;
			maze_1[rat_x][rat_y] = 1;
		}
		else if(maze[rat_x][rat_y+1] == 0 && maze_1[rat_x][rat_y+1] == 0){
			rat_y++;
			maze[rat_x][rat_y] = 1;
			maze_1[rat_x][rat_y] = 1;
		}
		else if(maze[rat_x-1][rat_y] == 0 && maze[rat_x-1][rat_y] == 0){
			rat_x--;
			maze[rat_x][rat_y] = 1;
			maze_1[rat_x][rat_y] = 1;
		}
		else if(maze[rat_x][rat_y-1] == 0 && maze[rat_x][rat_y-1] == 0){
			rat_y--;
			maze[rat_x][rat_y] = 1;
			maze_1[rat_x][rat_y] = 1;
		}
} 
int JudgeLK(int a,int b){//判断是否是分叉路口 or无路 
	int T = 0;
	if(maze_1[a+1][b] == 0)
		T++;
	if(maze_1[a][b+1] == 0)
		T++;
	if(maze_1[a-1][b] == 0)
		T++;
	if(maze_1[a][b-1] == 0)
		T++;
	if(T >= 2)
		return 1;
	else if(T < 1)
		return 2;
	else
		return 0;
} 
