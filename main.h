#pragma once

#include "main.h"

#define WEAPON 15
#define ARMOR 15
#define WIDTH 1280 //���ڿ��  
#define HEIGH 720 //���ڸ߶�
#define TEXT_1_H 24 //״̬�����ָ߶ȣ��Ի�����ʹ�СҲ������� ���忬��
#define TEXT_1_W 16//״̬�����ֿ��
#define TEXT_2_H 25 //��ͼ���ָ߶� ����΢���ź�
#define TEXT_2_W 10//��ͼ���ֿ��

typedef struct wp {
	char name[WEAPON];
	int at;
	int gold;
	const char* say;
}wp;//�����ṹ
typedef struct ar {
	char name[ARMOR];
	int df;
	int gold;
	const char* say;
}ar;//���߽ṹ
typedef struct spe {
	const char* name;
	const char* function;
	int fun;
	int gold;
	const char* say;
}spe;//������߽ṹ

typedef struct nspe {
	spe data;
	nspe* next;
}nspe;




typedef struct player{
	int x,y;//��ɫ����
	int hp; //����
	int at;//����
	int df;//����
	int gold;//���
	wp wp;//����
	ar ar;//����
}player;

typedef struct enemy{
	int hp;
	int at;//
	int gold;//
	const char* name;
}enemy;//����ṹ



void map_init(player pl);
void map_1(int pl_x, int pl_y);
void map_2(player*p);
void walk(int *x, int *y);
void clear();
void juqing(int i);
void supermarket(player* p);
bool getwp(player* p,wp wp2);
bool getar(player* p, ar ar2);
void getspe(player* p, spe sp);
void fight(player* p, enemy enemy);
void menu();