#include <stdio.h>
#include <easyx.h>
# include <time.h>
#include "main.h"

/*�����λ�ã����⣩��
���Ͻǣ�WIDTH / 2��500��        ���Ͻǣ�WIDTH��500��
���½ǣ�WIDTH / 2��HEIGH��      ���½ǣ�WIDTH��HEIGH��
һ�����19���֣�һ��7��*/
//TEXT_1_H 24 //״̬�����ָ߶�//
//TEXT_1_W 16//״̬�����ֿ�� //һ������Ҫռ2�����
//�ı���ʼλ�ã�x=WIDTH/2+20  y=520 

void clear() {
	solidrectangle(WIDTH, 525, WIDTH / 2 + 1, 525 + 170);
}
void juqing(int a) {

	//�������������ʽ
	settextstyle(TEXT_1_H, TEXT_1_W, _T("����"));
	//���ò�������ɫΪ��ɫ
	setfillcolor(BLACK);


	if(a==1){
		outtextxy((WIDTH/2+20), (525), "�����ۣ�");
	}
	else if(a==2){
		Sleep(1400);//Ϊ�����������ı�����ȥ�ģ�������ɾ��
		outtextxy((WIDTH/2+20), (525+24), "��ǰ�ĺڰ�Ⱦ�Ź��������죬���ܵ�");
		Sleep(1400);
		outtextxy((WIDTH/2+20), (525+48), "�����ƺ�ֹͣ�����������ճ�������");
		Sleep(1400);
		outtextxy((WIDTH/2+20), (525+72), "�����߳����ϸ�ܵ�߽�");
		Sleep(1400);
		outtextxy((WIDTH/2+20), (525+96), "�ҵ�ͷһ�����ʹ�������������ۡ�");
		Sleep(1400);
	}
	else if (a == 3) {
		clear();//������ı����������
		outtextxy((WIDTH / 2 + 20), (525), "������û�뵽��Ȼ�ɹ��ˣ�����ٻ���");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 24), "     ����������������ˡ�");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 48), "     �����ĳ�������������������");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 72), "     ����Ҳ������ץ���ˣ�");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 96), "     ����ʵ���������޲ߡ�");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 120), "     �����ٻ������߳�����");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 144), "     ��Ȼ����ѡ֮�ˡ�");
		Sleep(1400);
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "�������¸ҵ����ߣ�������ҵ������");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525+24), "�ң�...�Һ���ֻ�ܽ��ܡ�");
		Sleep(1400);
		clear();//������ı����������
		outtextxy((WIDTH / 2 + 20), (525), "��������л���������ĸ���");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 24), "     ��������Щ��");
		Sleep(1400);
	}
	else if(a==4){
		clear();//������ı����������
		outtextxy((WIDTH / 2 + 20), (525), "Ů�ף���������������ߣ�������");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 24), "      ����ǰ��������Ϊ��������ռ����");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 48), "      !@#$^@*$$%#$");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 72), "      ������ô��......");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 96), "��Ů�׵���ɫ��òҰף�");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 120), "Ů�ף�����̫��Ǹ�ˣ����ߡ�");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 144), "      �������ҵ�Ǹ��ɡ�");
		Sleep(1400);
	}

}