#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include <string.h>
#include<time.h>
#include <windows.h>
#include"main.h"
#include<mmsystem.h>//包含多媒体设备接口头文件,一定放在graphics.h下面
#pragma comment(lib,"winmm.lib")//加载静态库



void quickclear() {
	setfillcolor(BLACK);
	solidrectangle(WIDTH, 525, WIDTH / 2 + 1, 525 + 170);
	//快速画线擦掉文字文字，用于清屏
}
char s7[100],s8[100],s9[100];
void check();
//check用于检查文字输出是否超界
int hi = 0;

//每次文本向下移动的高度，取的hight前2个字母
void fight(player *p ,enemy enemy) {//引用函数时输入怪物结构
	quickclear();
	int hurt;
	while (p->hp > 0 && enemy.hp > 0) {
		if (enemy.at > p->df) {
			hurt = enemy.at - p->df;
		}
		else {
			hurt = 0;
		}
		//该if函数用于判定是否造成伤害
		sprintf_s(s7, 100, "我使用%s对%s造成了%d伤害", p->wp.name, enemy.name, p->at);
		check();
		outtextxy(700, 503 + hi, s7);
		p->hp = p->hp - hurt;
		enemy.hp = enemy.hp - p->at;
		hi = hi + 20;
		check();
		Sleep(1000);
		sprintf_s(s8, 100, "%s发出鸡叫，对我造成了%d伤害", enemy.name, hurt);
		outtextxy(700, 503 + hi, s8);
		if (hurt == 0) {
			hi = hi + 20;
			check();
			outtextxy(700, 503+ hi, "它的攻击甚至打不破你的脸皮");
		}
		hi =hi+ 30;
		check();
		Sleep(1000);
	}
	//以上为战斗过程
	if (enemy.hp <= 0) {
		sprintf_s(s9, 100, "%s已阵亡", enemy.name);
		outtextxy(700, 503+ hi, s9);
		hi = hi + 20;
		check();
		outtextxy(700, 503 + hi, "恭喜您获得胜利！");
		hi = hi + 20;
		check();
		sprintf_s(s9, 100, "恭喜您获得金币：%d",enemy.gold);
		outtextxy(700, 503 + hi, s9);
		p->gold = p->gold + enemy.gold;
	}
	else {
		check();
		outtextxy(700, 503 + hi, "我已阵亡");
	}
	//以上为战斗结果判定
	hi = 0;
	Sleep(500);
	quickclear();
}
void check() {
	if (503 + hi > 700) {
		quickclear();
	}
}
