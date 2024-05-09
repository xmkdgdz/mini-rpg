#pragma once

#include "main.h"

#define WEAPON 15
#define ARMOR 15
#define WIDTH 1280 //窗口宽度  
#define HEIGH 720 //窗口高度
#define TEXT_1_H 24 //状态栏文字高度（对话字体和大小也是这个） 字体楷体
#define TEXT_1_W 16//状态栏文字宽度
#define TEXT_2_H 25 //地图文字高度 字体微软雅黑
#define TEXT_2_W 10//地图文字宽度

typedef struct wp {
	char name[WEAPON];
	int at;
	int gold;
	const char* say;
}wp;//武器结构
typedef struct ar {
	char name[ARMOR];
	int df;
	int gold;
	const char* say;
}ar;//防具结构
typedef struct spe {
	const char* name;
	const char* function;
	int fun;
	int gold;
	const char* say;
}spe;//特殊道具结构

typedef struct nspe {
	spe data;
	nspe* next;
}nspe;




typedef struct player{
	int x,y;//角色坐标
	int hp; //生命
	int at;//攻击
	int df;//防御
	int gold;//金币
	wp wp;//武器
	ar ar;//防具
}player;

typedef struct enemy{
	int hp;
	int at;//
	int gold;//
	const char* name;
}enemy;//怪物结构



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