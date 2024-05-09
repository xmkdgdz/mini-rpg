 #include<easyx.h>
#include<stdio.h>
#include "main.h"
#include<conio.h>
#include <graphics.h>
#include<mmsystem.h>//包含多媒体设备接口头文件,一定放在graphics.h下面
#pragma comment(lib,"winmm.lib")//加载静态库


int main()
{	
	//初始化窗口
	menu();
	mciSendString("stop ./music\\菜单.mp3", 0, 0, 0);
	closegraph();
	initgraph(WIDTH, HEIGH, EW_DBLCLKS);
	flushmessage(-1);
	setrop2(R2_COPYPEN);
	setbkcolor(BLACK);
	settextcolor(WHITE);
	setlinecolor(WHITE);
	setfillcolor(BLACK);

	int map = 1;
	wp wp0 = {"无",0,0,""}; ar ar0= { "无",0,0,"" };
	player player = {0,325,100,10,10,100,wp0,ar0};
	int* px;px = &player.x;
	int* py;py = &player.y;
	int x0, y0;
	struct player* pplayer;pplayer = &player;

	mciSendString("play ./music\\装备.mp3 repeat", 0, 0, 0);
	BeginBatchDraw();
	while (1)
	{
		map_init(player);
		switch (map)
		{
		case 1:
			x0 = player.x; y0 = player.y;
			walk(px, py);

			if(player.y>380|| player.y < 220||(player.x<100+20&& player.x > 100 - 20 &&
				player.y < 230+20&& player.y > 230 - 20)||(player.x < 300 + 20 && 
					player.x > 300 - 20 &&player.y < 370 + 20 && player.y > 370 - 20))
			{player.x = x0; player.y = y0;}
			map_1(player.x, player.y);

			if (player.x < 100 + 30 && player.x > 100 - 30 && player.y < 230 + 30 && player.y > 230 - 30)
			{
				if (_kbhit())
					if (_getch() == 'F' || _getch() == 'f')
					{
						map_init(player);
						EndBatchDraw();
						juqing(3);
						BeginBatchDraw();
					}
			}
			if (player.x < 300 + 30 && player.x > 300 - 30 && player.y < 370 + 30 && player.y > 370 - 30)
			{
				if (_kbhit())
					if (_getch() == 'F' || _getch() == 'f')
					{
						map_init(player);
						EndBatchDraw();
						juqing(4);
						BeginBatchDraw();
					}
			}
			if (player.x > 26*(TEXT_2_W + 10 )&&player.x< 32*(TEXT_2_W + 10) &&player.y<240)
			{
				if (_kbhit())
					if (_getch() == 'F' || _getch() == 'f')
					{
						supermarket(pplayer);
						BeginBatchDraw();
					}
			}

			if (player.x > 1260)
				map = 2;
		break;
		case 2:
			map_2(pplayer);
			map = 1;
			player.x = 1240; player.y = 300;
			break;
		}
	}

	EndBatchDraw();
	return 0;
}