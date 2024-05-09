#include<easyx.h>
#include<stdio.h>
#include "main.h"
#include<conio.h>

//�ָ�������״̬������
void map_init(player player)
{
	
	line(0, 500, WIDTH, 500);
	line(WIDTH / 2, 500, WIDTH / 2, HEIGH);

	//����ת��Ϊ�ַ����������������
	char s1[10], s2[10], s3[10], s4[10];
	sprintf_s(s1, 10, "����:%d", player.hp);
	sprintf_s(s2, 10, "����:%d", player.at);
	sprintf_s(s3, 10, "����:%d", player.df);
	sprintf_s(s4, 10, "���:%d", player.gold);

	settextstyle(TEXT_1_H, TEXT_1_W, _T("����"));
	outtextxy(40, 500 + 25, s1);
	outtextxy(40, 500 + 50 + 25, s2);
	outtextxy(40, 500 + 50 * 2 + 25, s3);
	outtextxy(40, 500 + 50 * 3 + 25, "����:");
	outtextxy(WIDTH / 5, 500 + 25, "����:");
	outtextxy(WIDTH / 5 + TEXT_1_H * 3 + 5, 500 + 25, player.wp.name);
	outtextxy(WIDTH / 5, 500 + 50 + 25, "����:");
	outtextxy(WIDTH / 5 + TEXT_1_H * 3 + 5, 500 + 50 + 25, player.ar.name);
	outtextxy(WIDTH / 5, 500 +100+ 25,s4);
	FlushBatchDraw();
	Sleep(50);
}

//�����ƶ�
void walk(int *x, int *y)
{
	char key;
	if (_kbhit()){
		switch (key = _getch())
		{
		case 72://�ϼ�������ֵ
		case 'W':
		case 'w':
			*y -= 10;
			break;
		case 80://�¼�������ֵ
		case 'S':
		case 's':
			*y += 10;
			break;
		case 75://���������ֵ
		case 'A':
		case 'a':
			*x -= 10;
			break;
		case 77://�Ҽ�������ֵ
		case 'D':
		case 'd':
			*x += 10;
			break;
		}
	}
}

//��ͼ1 ���ִ�
void map_1(int pl_x,int pl_y)
{
	int i;
	IMAGE shop_img;

	settextstyle(TEXT_2_H, TEXT_2_W, _T("΢���ź�"));
	cleardevice();

	//����λ��
	outtextxy(pl_x,pl_y, "��"); 

	outtextxy(100, 230, "��");
	outtextxy(300, 370, "��");
	for (i = 0; i < 63;++i)
		outtextxy(0 + i * (TEXT_2_W+10), 400, "·");
	for (i = 0; i < 63; ++i)
		outtextxy(0 + i * (TEXT_2_W+10), 200, "·");

	//�̵�λ��
	loadimage(&shop_img, "./image\\shop.jpg",222 / 1.3, 186 / 1.3);
	putimage(500,60, &shop_img);

	FlushBatchDraw();
}




