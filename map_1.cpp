#include<easyx.h>
#include<stdio.h>
#include "main.h"
#include<conio.h>

//分隔框及左下状态栏文字
void map_init(player player)
{
	
	line(0, 500, WIDTH, 500);
	line(WIDTH / 2, 500, WIDTH / 2, HEIGH);

	//整形转换为字符串，便于输出变量
	char s1[10], s2[10], s3[10], s4[10];
	sprintf_s(s1, 10, "生命:%d", player.hp);
	sprintf_s(s2, 10, "攻击:%d", player.at);
	sprintf_s(s3, 10, "防御:%d", player.df);
	sprintf_s(s4, 10, "金币:%d", player.gold);

	settextstyle(TEXT_1_H, TEXT_1_W, _T("楷体"));
	outtextxy(40, 500 + 25, s1);
	outtextxy(40, 500 + 50 + 25, s2);
	outtextxy(40, 500 + 50 * 2 + 25, s3);
	outtextxy(40, 500 + 50 * 3 + 25, "道具:");
	outtextxy(WIDTH / 5, 500 + 25, "武器:");
	outtextxy(WIDTH / 5 + TEXT_1_H * 3 + 5, 500 + 25, player.wp.name);
	outtextxy(WIDTH / 5, 500 + 50 + 25, "防具:");
	outtextxy(WIDTH / 5 + TEXT_1_H * 3 + 5, 500 + 50 + 25, player.ar.name);
	outtextxy(WIDTH / 5, 500 +100+ 25,s4);
	FlushBatchDraw();
	Sleep(50);
}

//人物移动
void walk(int *x, int *y)
{
	char key;
	if (_kbhit()){
		switch (key = _getch())
		{
		case 72://上键的虚拟值
		case 'W':
		case 'w':
			*y -= 10;
			break;
		case 80://下键的虚拟值
		case 'S':
		case 's':
			*y += 10;
			break;
		case 75://左键的虚拟值
		case 'A':
		case 'a':
			*x -= 10;
			break;
		case 77://右键的虚拟值
		case 'D':
		case 'd':
			*x += 10;
			break;
		}
	}
}

//地图1 新手村
void map_1(int pl_x,int pl_y)
{
	int i;
	IMAGE shop_img;

	settextstyle(TEXT_2_H, TEXT_2_W, _T("微软雅黑"));
	cleardevice();

	//人物位置
	outtextxy(pl_x,pl_y, "我"); 

	outtextxy(100, 230, "王");
	outtextxy(300, 370, "巫");
	for (i = 0; i < 63;++i)
		outtextxy(0 + i * (TEXT_2_W+10), 400, "路");
	for (i = 0; i < 63; ++i)
		outtextxy(0 + i * (TEXT_2_W+10), 200, "路");

	//商店位置
	loadimage(&shop_img, "./image\\shop.jpg",222 / 1.3, 186 / 1.3);
	putimage(500,60, &shop_img);

	FlushBatchDraw();
}




