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
class List_LK{ //�ֲ�·�� 
	public:
		List_LK();
		void In(int a,int b,int c[M][N]);//����ֲ�·������ 
		void Delete();//ɾ��
		int Get_x();//�õ�����x 
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
    int rat_x = 1,rat_y = 0; //�����ʼλ�� 
    int maze_1[M][N]= {{2,2,2,2,2,2,2,2,2,2},
                      {0,0,2,0,2,0,0,0,0,2},
                      {2,0,0,0,0,0,2,0,2,2},
                      {2,2,2,0,2,0,2,0,2,2},
                      {2,0,0,0,2,0,0,0,0,2},
                      {2,0,2,0,2,0,2,2,0,2},
                      {2,0,2,0,2,0,0,2,0,2},
                      {2,2,2,0,2,2,2,2,0,2},
                      {2,0,0,0,0,0,0,2,0,0},
                      {2,2,2,2,2,2,2,2,2,2}};//�����Թ�������������¼�Ѿ��߹���·��  
 void List_LK::get_m(){
			for(int i=0;i<M;i++){
				for(int j=0;j<N;j++)
				maze[i][j]=first->next->m[i][j] ;
		}
		}	   
int main(){
	void printf_m();//�������� ��ӡ��ͼ 
	void move();// �������� �����ƶ� 
	int JudgeLK(int a,int b);//�ж��Ƿ��ߵ��ֲ�·�ڵĺ��� 
	maze[1][0] = 1;//�����ʼ��λ�� 
	printf_m();
	List_LK MAZE;//����������¼�ֲ�·�ڵ����� 
	while(1){
		move();
		if(JudgeLK(rat_x,rat_y) == 1){//�������¼�ֲ�·�ں͵�ͼ״̬ 
			MAZE.In(rat_x,rat_y,maze);	
		}
		if(JudgeLK(rat_x,rat_y) == 2){//�ж���·��������һ��·��
			if(maze_1[M-2][N-1] == 1)//�ж��Ƿ��ߵ��յ㣬����ѭ�� 
				break;
			rat_x=MAZE.Get_x();
			rat_y=MAZE.Get_y();
			MAZE.get_m();
			if(JudgeLK(rat_x,rat_y) == 2){//�����ϸ�·�����жϣ�������Ѿ��߹��ˣ�ɾ���ڵ㣬�������ϸ�·�� 
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
void printf_m(){//�����ͼ 
	int i,j; 
	for( i = 0; i < 10; i++)
      {
          for(j = 0; j < 10; j++)
          	  if(maze[i][j] == 2)
                  printf("��");
              else if(maze[i][j] == 0)
                  printf("  ");
              else if(maze[i][j] == 1)
            	  printf("* ");
          printf("\n");
      }
}
void  move(){//�����ƶ����� 
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
int JudgeLK(int a,int b){//�ж��Ƿ��Ƿֲ�·�� or��· 
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
