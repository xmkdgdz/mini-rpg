#include <graphics.h>              // ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <stdio.h>
#include <windows.h>				//�õ��˶�ʱ����sleep()
#include <math.h>
#include <string.h>
#include<mmsystem.h>//������ý���豸�ӿ�ͷ�ļ�,һ������graphics.h����
#pragma comment(lib,"winmm.lib")//���ؾ�̬��


int r[4][4] = { { 500,240,780,380 },{ 500,400,780,540 },{ 500,560,780,700 },{ 430,20,850,180 } };//������ť�Ķ�ά����
/*int r1[] = {500,240,780,380};//���밴ť�ľ��β���
int r2[] = { 500,400,780,540 };//���а�ť�ľ��β���
int r3[] = { 500,560,780,700 };//�˳���ť�ľ��β���
int r4[] = { 430,20,850,180 };//����*/


int button_judge(int x, int y)
{
	if (x > r[0][0] && x<r[0][2] && y>r[0][1] && y < r[0][3])return 1;
	if (x > r[1][0] && x<r[1][2] && y>r[1][1] && y < r[1][3])return 2;
	if (x > r[2][0] && x<r[2][2] && y>r[2][1] && y < r[2][3])return 3;
	return 0;
}


void menu()
{
	mciSendString("play ./music\\�˵�.mp3 repeat", 0, 0, 0);
	bool x = 1;
	int i, event = 0;
	short win_width, win_height;//���崰�ڵĿ��Ⱥ͸߶�
	win_width = 1280;win_height = 720;
	initgraph(win_width, win_height);//��ʼ�����ڣ�������
	for (i = 0;i < 256;i += 5)
	{
		setbkcolor(RGB(i, i, i));//���ñ���ɫ��ԭ��Ĭ�Ϻ�ɫ
		cleardevice();//������ȡ���ڱ���ɫ��
		Sleep(15);//��ʱ15ms
	}
	RECT R1 = { r[0][0],r[0][1],r[0][2],r[0][3] };//����ָ��R1
	RECT R2 = { r[1][0],r[1][1],r[1][2],r[1][3] };//����ָ��R2
	RECT R3 = { r[2][0],r[2][1],r[2][2],r[2][3] };//����ָ��R3
	RECT R4 = { r[3][0],r[3][1],r[3][2],r[3][3] };//����ָ��R4
	LOGFONT f;//������ʽָ��
	gettextstyle(&f);					//��ȡ������ʽ
	_tcscpy_s(f.lfFaceName, _T("����"));	//��������Ϊ����
	f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
	settextstyle(&f);                     // ����������ʽ
	settextcolor(BLACK);				//BLACK��graphic.hͷ�ļ����汻����Ϊ��ɫ����ɫ����
	drawtext(_T("�µ�ð��"), &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R1���������֣�ˮƽ���У���ֱ���У�������ʾ
	drawtext(_T("��������"), &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R2���������֣�ˮƽ���У���ֱ���У�������ʾ
	drawtext(_T("�ź��볡"), &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R3���������֣�ˮƽ���У���ֱ���У�������ʾ
	drawtext(_T("Moutalin"), &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R4���������֣�ˮƽ���У���ֱ���У�������ʾ
	setlinecolor(BLACK);
	rectangle(r[0][0], r[0][1], r[0][2], r[0][3]);
	rectangle(r[1][0], r[1][1], r[1][2], r[1][3]);
	rectangle(r[2][0], r[2][1], r[2][2], r[2][3]);
	rectangle(r[3][0], r[3][1], r[3][2], r[3][3]);
	MOUSEMSG m;//���ָ��

	while (x)
	{
		
		m = GetMouseMsg();//��ȡһ�������Ϣ

		switch (m.uMsg)
		{
		case WM_MOUSEMOVE:
			setrop2(R2_XORPEN);
			setlinecolor(LIGHTCYAN);//������ɫΪ����ɫ
			setlinestyle(PS_SOLID, 3);//���û�����ʽΪʵ�֣�10��
			setfillcolor(WHITE);//�����ɫΪ��ɫ
			if (button_judge(m.x, m.y) != 0)
			{
				if (event != button_judge(m.x, m.y))
				{
					event = button_judge(m.x, m.y);//��¼��һ�δ����İ�ť
					fillrectangle(r[event - 1][0], r[event - 1][1], r[event - 1][2], r[event - 1][3]);//�п������Σ�X1,Y1,X2,Y2��
				}
			}
			else
			{
				if (event != 0)//�ϴδ����İ�ťδ������Ϊԭ������ɫ
				{
					fillrectangle(r[event - 1][0], r[event - 1][1], r[event - 1][2], r[event - 1][3]);//����ͬ��Ϊԭ����ɫ
					event = 0;
				}
			}
			break;
		case WM_LBUTTONDOWN:
			setrop2(R2_NOTXORPEN);//��Ԫ��դ����NOT(��Ļ��ɫ XOR ��ǰ��ɫ)
			for (i = 0;i <= 10;i++)
			{
				setlinecolor(RGB(25 * i, 25 * i, 25 * i));//����Բ��ɫ
				circle(m.x, m.y, 2 * i);
				Sleep(20);//ͣ��30ms
				circle(m.x, m.y, 2 * i);//Ĩȥ�ոջ���Բ
			}
			//���հ�ť�ж����������Ĳ���
			switch (button_judge(m.x, m.y))
			{
				//��ԭ��ťԭ��
			case 1:
				//���ͼ��Ϸ����
				x = 0;
				FlushMouseMsgBuffer();//�����¼�����������Ϣ
				break;
			case 2:
				//��������������Ĵ浵����
				FlushMouseMsgBuffer();//�����¼�����������Ϣ
				break;
			case 3:
				closegraph();//�رջ�ͼ����
				exit(0);//�����˳�
			default:
				FlushMouseMsgBuffer();//�����¼�����������Ϣ
				//printf("\r\n(%d,%d)",m.x,m.y);//��ӡ������꣬�������ʱȷ������
				break;
			}
			break;
		}
	}
}