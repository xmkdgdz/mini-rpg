#include <stdio.h>
#include <string.h>
#include<easyx.h>
#include "main.h"

//传入装备并实现player的数值改变

//参数：&player，现有武器，新武器（如果原来没有武器就都写新武器）
bool getwp(player *p,wp wp2) {
	if (p->wp.at > wp2.at) {//原武器更好
		p->gold += wp2.gold;
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "您已装备较强武器，无法替换");
		Sleep(1000);
		return false;
	}
	else if (p->wp.at == wp2.at) {//原来没有装备武器
		p->at += wp2.at;
		p->wp = wp2;
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "您已成功装备新武器");
		Sleep(1000);
		return true;
	}
	else {//新武器更好
		p->at = p->at - p->wp.at + wp2.at;
		p->wp = wp2;
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "您已成功装备新武器");
		Sleep(1000);
		return true;
	}
}

//参数：&player，现有防具，新防具
bool getar(player* p,ar ar2) {
	if (p->ar.df > ar2.df) {//原防具更好
		p->gold += ar2.gold;
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "您已装备较强防具，无法替换");
		Sleep(1000);
		return false;
	}
	else if (p->ar.df == ar2.df) {//原来没有装备防具
		p->df += ar2.df;
		p->ar = ar2;
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "您已成功装备新防具");
		Sleep(1000);
		return true;
	}
	else {//新防具更好
		p->df = p->df - p->ar.df + ar2.df;
		p->ar = ar2;
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "您已成功装备新防具");
		Sleep(1000);
		return true;
	}
}

//参数：&player，特殊道具
void getspe(player* p, spe sp) {
	if (strcmp(sp.name,"女巫的裹脚布")==0) {
		p->hp += 200;
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "您已成功使用女巫的裹脚布");
		Sleep(1000);
	}
	else if (strcmp(sp.name, "皇后的魔镜")==0) {
		p->df = (int)((double)p->df * 0.2) + p->df;//类型强转，提高精确度
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "您已成功使用皇后的魔镜");
		Sleep(1000);
	}
	else if (strcmp(sp.name, "鸽鸽的蛋")==0) {
		//这个免疫下一次伤害咋写噢
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "您已成功使用鸽鸽的蛋");
		Sleep(1000);
	}
	else if (strcmp(sp.name, "泡了3天的泡面")==0 ) {
		p->at = (int)((double)p->at * 0.2 ) + p->at;
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "您已成功使用泡了3天的泡面");
		Sleep(1000);
	}
	else if (strcmp(sp.name, "冬日的被窝")==0) {
		p->df = (int)((double)p->df * 0.15) + p->df;
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "您已成功使用冬日的被窝");
		Sleep(1000);
	}
	else if (strcmp(sp.name, "衡水日程表")==0) {
		p->at = (int)((double)p->at * 0.15) + p->at;
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "您已成功使用衡水日程表");
		Sleep(1000);
	}

}

