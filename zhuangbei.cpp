#include <stdio.h>
#include <string.h>
#include<easyx.h>
#include "main.h"

//����װ����ʵ��player����ֵ�ı�

//������&player�����������������������ԭ��û�������Ͷ�д��������
bool getwp(player *p,wp wp2) {
	if (p->wp.at > wp2.at) {//ԭ��������
		p->gold += wp2.gold;
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "����װ����ǿ�������޷��滻");
		Sleep(1000);
		return false;
	}
	else if (p->wp.at == wp2.at) {//ԭ��û��װ������
		p->at += wp2.at;
		p->wp = wp2;
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "���ѳɹ�װ��������");
		Sleep(1000);
		return true;
	}
	else {//����������
		p->at = p->at - p->wp.at + wp2.at;
		p->wp = wp2;
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "���ѳɹ�װ��������");
		Sleep(1000);
		return true;
	}
}

//������&player�����з��ߣ��·���
bool getar(player* p,ar ar2) {
	if (p->ar.df > ar2.df) {//ԭ���߸���
		p->gold += ar2.gold;
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "����װ����ǿ���ߣ��޷��滻");
		Sleep(1000);
		return false;
	}
	else if (p->ar.df == ar2.df) {//ԭ��û��װ������
		p->df += ar2.df;
		p->ar = ar2;
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "���ѳɹ�װ���·���");
		Sleep(1000);
		return true;
	}
	else {//�·��߸���
		p->df = p->df - p->ar.df + ar2.df;
		p->ar = ar2;
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "���ѳɹ�װ���·���");
		Sleep(1000);
		return true;
	}
}

//������&player���������
void getspe(player* p, spe sp) {
	if (strcmp(sp.name,"Ů�׵Ĺ��Ų�")==0) {
		p->hp += 200;
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "���ѳɹ�ʹ��Ů�׵Ĺ��Ų�");
		Sleep(1000);
	}
	else if (strcmp(sp.name, "�ʺ��ħ��")==0) {
		p->df = (int)((double)p->df * 0.2) + p->df;//����ǿת����߾�ȷ��
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "���ѳɹ�ʹ�ûʺ��ħ��");
		Sleep(1000);
	}
	else if (strcmp(sp.name, "���ĵ�")==0) {
		//���������һ���˺�զд��
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "���ѳɹ�ʹ�ø��ĵ�");
		Sleep(1000);
	}
	else if (strcmp(sp.name, "����3�������")==0 ) {
		p->at = (int)((double)p->at * 0.2 ) + p->at;
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "���ѳɹ�ʹ������3�������");
		Sleep(1000);
	}
	else if (strcmp(sp.name, "���յı���")==0) {
		p->df = (int)((double)p->df * 0.15) + p->df;
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "���ѳɹ�ʹ�ö��յı���");
		Sleep(1000);
	}
	else if (strcmp(sp.name, "��ˮ�ճ̱�")==0) {
		p->at = (int)((double)p->at * 0.15) + p->at;
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "���ѳɹ�ʹ�ú�ˮ�ճ̱�");
		Sleep(1000);
	}

}

