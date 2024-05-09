#include <graphics.h>              // 引用图形库头文件
#include <conio.h>
#include <stdio.h>
#include <windows.h>				//用到了定时函数sleep()
#include <math.h>
#include <string.h>
#include<mmsystem.h>//包含多媒体设备接口头文件,一定放在graphics.h下面
#pragma comment(lib,"winmm.lib")//加载静态库


int r[4][4] = { { 500,240,780,380 },{ 500,400,780,540 },{ 500,560,780,700 },{ 430,20,850,180 } };//三个按钮的二维数组
/*int r1[] = {500,240,780,380};//输入按钮的矩形参数
int r2[] = { 500,400,780,540 };//运行按钮的矩形参数
int r3[] = { 500,560,780,700 };//退出按钮的矩形参数
int r4[] = { 430,20,850,180 };//标题*/


int button_judge(int x, int y)
{
	if (x > r[0][0] && x<r[0][2] && y>r[0][1] && y < r[0][3])return 1;
	if (x > r[1][0] && x<r[1][2] && y>r[1][1] && y < r[1][3])return 2;
	if (x > r[2][0] && x<r[2][2] && y>r[2][1] && y < r[2][3])return 3;
	return 0;
}


void menu()
{
	mciSendString("play ./music\\菜单.mp3 repeat", 0, 0, 0);
	bool x = 1;
	int i, event = 0;
	short win_width, win_height;//定义窗口的宽度和高度
	win_width = 1280;win_height = 720;
	initgraph(win_width, win_height);//初始化窗口（黑屏）
	for (i = 0;i < 256;i += 5)
	{
		setbkcolor(RGB(i, i, i));//设置背景色，原来默认黑色
		cleardevice();//清屏（取决于背景色）
		Sleep(15);//延时15ms
	}
	RECT R1 = { r[0][0],r[0][1],r[0][2],r[0][3] };//矩形指针R1
	RECT R2 = { r[1][0],r[1][1],r[1][2],r[1][3] };//矩形指针R2
	RECT R3 = { r[2][0],r[2][1],r[2][2],r[2][3] };//矩形指针R3
	RECT R4 = { r[3][0],r[3][1],r[3][2],r[3][3] };//矩形指针R4
	LOGFONT f;//字体样式指针
	gettextstyle(&f);					//获取字体样式
	_tcscpy_s(f.lfFaceName, _T("宋体"));	//设置字体为宋体
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	settextstyle(&f);                     // 设置字体样式
	settextcolor(BLACK);				//BLACK在graphic.h头文件里面被定义为黑色的颜色常量
	drawtext(_T("新的冒险"), &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域R1内输入文字，水平居中，垂直居中，单行显示
	drawtext(_T("再起征程"), &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域R2内输入文字，水平居中，垂直居中，单行显示
	drawtext(_T("遗憾离场"), &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域R3内输入文字，水平居中，垂直居中，单行显示
	drawtext(_T("Moutalin"), &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域R4内输入文字，水平居中，垂直居中，单行显示
	setlinecolor(BLACK);
	rectangle(r[0][0], r[0][1], r[0][2], r[0][3]);
	rectangle(r[1][0], r[1][1], r[1][2], r[1][3]);
	rectangle(r[2][0], r[2][1], r[2][2], r[2][3]);
	rectangle(r[3][0], r[3][1], r[3][2], r[3][3]);
	MOUSEMSG m;//鼠标指针

	while (x)
	{
		
		m = GetMouseMsg();//获取一条鼠标消息

		switch (m.uMsg)
		{
		case WM_MOUSEMOVE:
			setrop2(R2_XORPEN);
			setlinecolor(LIGHTCYAN);//线条颜色为亮青色
			setlinestyle(PS_SOLID, 3);//设置画线样式为实现，10磅
			setfillcolor(WHITE);//填充颜色为白色
			if (button_judge(m.x, m.y) != 0)
			{
				if (event != button_judge(m.x, m.y))
				{
					event = button_judge(m.x, m.y);//记录这一次触发的按钮
					fillrectangle(r[event - 1][0], r[event - 1][1], r[event - 1][2], r[event - 1][3]);//有框填充矩形（X1,Y1,X2,Y2）
				}
			}
			else
			{
				if (event != 0)//上次触发的按钮未被修正为原来的颜色
				{
					fillrectangle(r[event - 1][0], r[event - 1][1], r[event - 1][2], r[event - 1][3]);//两次同或为原来颜色
					event = 0;
				}
			}
			break;
		case WM_LBUTTONDOWN:
			setrop2(R2_NOTXORPEN);//二元光栅——NOT(屏幕颜色 XOR 当前颜色)
			for (i = 0;i <= 10;i++)
			{
				setlinecolor(RGB(25 * i, 25 * i, 25 * i));//设置圆颜色
				circle(m.x, m.y, 2 * i);
				Sleep(20);//停顿30ms
				circle(m.x, m.y, 2 * i);//抹去刚刚画的圆
			}
			//按照按钮判断左键单击后的操作
			switch (button_judge(m.x, m.y))
			{
				//复原按钮原型
			case 1:
				//大地图游戏界面
				x = 0;
				FlushMouseMsgBuffer();//单击事件后清空鼠标消息
				break;
			case 2:
				//大概率做不出来的存档函数
				FlushMouseMsgBuffer();//单击事件后清空鼠标消息
				break;
			case 3:
				closegraph();//关闭绘图环境
				exit(0);//正常退出
			default:
				FlushMouseMsgBuffer();//单击事件后清空鼠标消息
				//printf("\r\n(%d,%d)",m.x,m.y);//打印鼠标坐标，方便调试时确定区域
				break;
			}
			break;
		}
	}
}