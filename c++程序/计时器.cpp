#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")
using namespace std;
void gotoxy(int x, int y)//��λ��꣬xΪ������,yΪ������
{
	COORD pos = {x,y};//������  λ�ã��� 
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  //�õ���׼������׼��������� 
	SetConsoleCursorPosition(hOut, pos);//���ÿ���̨���λ�ã� 
} 

void hidden()//���ع��
{
    	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut,&cci);
	cci.bVisible=0;//��1Ϊ��ʾ����0Ϊ����
	SetConsoleCursorInfo(hOut,&cci);
}

class Timer
{
	private:
		long start_time;
		long pause_time;
		//����boolֵ�������״̬ 
		bool is_pause; //��¼��ʱ����״̬ ���Ƿ�����ͣ״̬��
		bool is_stop;//�Ƿ���ֹͣ״̬ 
	public:
		Timer();
		bool isPause(); //���ؼ�ʱ��״̬ 
		bool isStop();
		//��ʱ�������ֶ��������ܣ� 
		void Start(); 
		void Pause();
		void play(); 
		void Stop();
		inline long getStartTime() {return start_time;}
		void show();
};
void Timer::play()
{
	long cnt=time(0)-start_time;
	if(cnt%60==0)
	PlaySound("D:\\Mr����.wav",NULL,SND_FILENAME|SND_ASYNC);
	else if(cnt%30==0)
	PlaySound("D:\\Mr����.wav",NULL,SND_FILENAME|SND_ASYNC);
}

Timer::Timer()
{
	is_pause = false; //��ʼ����ʱ��״̬ 
	is_stop = true;
}


bool Timer::isPause()
{	
	if(is_pause)
	return true;
	else
	return false;
}

bool Timer::isStop()
{
	if(is_stop)
		return true;
	return false;
} 

void Timer::Start() //��ʼ 
{
	if(is_stop)
	{
		start_time = time(0);
		is_stop = false;
	}
	else if(is_pause)
	{
		is_pause = false;
		start_time += time(0)-pause_time; //���¿�ʼʱ�䣺�ô�ʱ��ʱ�� - ��ͣʱ���õ�ʱ�� + ��һ�ο�ʼ��ʱ�� = ��ʱ�Ŀ�ʼʱ�� 
	}
}

void Timer::Pause() //��ͣ 
{
	if(is_stop||is_pause) //�������ֹͣ/��ͣ״̬,�˶��������κδ���ֱ�ӷ��� 
		return; 
	else    //�������Ϊ��ͣ״̬
	{
		is_pause = true;
		pause_time = time(0); //��ȡ��ͣʱ�� 
	}
}
void Timer::Stop()  //ֹͣ 
{
	if(is_stop) //���������ֹͣ״̬��������ͣ״̬���������κδ��� 
		return ; 
	else if(is_pause) //�ı��ʱ��״̬ 
	{
		is_pause = false;
		is_stop = true;
	}
	else if(!is_stop)
	{
		is_stop = true;
	} 
}

void Timer::show()
{
	long t = time(0) - start_time;
	gotoxy(35,12);
	cout<<setw(2)<<setfill('0')<<t/60/60<<":"
	    <<setw(2)<<setfill('0')<<t/60<<":"
		<<setw(2)<<setfill('0')<<t%60<<endl;
}

int main()
{
	Timer t; 
	char ch; 
	hidden();//���ع��
	system("color 02"); 
	gotoxy(35,12);
	cout<<"00:00:00";
	gotoxy(20,18);
	cout<<"��a��ʼ�����ո���ͣ����sֹͣ";
	while(1)
	{
		if(kbhit())
		{
			ch = getch();
			switch (ch)
			{
				case 'a':t.Start();break;
				case 's':t.Stop();break;
				case ' ':t.Pause();break;
				default :break;
			}
		}
		if(!t.isStop()&&!t.isPause()) 
		{
			t.show();
			t.play();
		}
	}
	
}
