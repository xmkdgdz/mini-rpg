#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include <string.h>
#include<easyx.h>
#include"main.h"

#define a 125//商店坐标（矩形左上角顶点x值）
#define b 80//商店坐标（矩形左上角顶点y值）
#define c 845//商店主界面右边界
#define d 680//商店主界面下边界

//以下是各个内容描述，再开一个源文件太麻烦了

spe spe1 = {"女巫的裹脚布","增加生命值200",200,20,"试一试味道如何？" };
spe spe2 = {"皇后的魔镜","防御力+20%",20,40,"揽镜后你深切自卑" };
spe spe3 = {"鸽鸽的蛋","免疫下一次伤害",1,60,"赋予不坏之身" };
spe spe4 = {"泡了3天的泡面","增加攻击力20%",20,40,"这个天气可以砸人" };
spe spe5 = {"冬日的被窝","增加防御力15%",15,30,"又是起不来的早七" };
spe spe6 = {"衡水日程表","增加攻击力15%",15,30,"越看越生气" };
spe spe7 = {"女巫的裹脚布","增加生命值200",200,20,"试一试味道如何？" };
spe spe8 = {"女巫的裹脚布","增加生命值200",200,20,"试一试味道如何？" };
spe spe9 = {"女巫的裹脚布","增加生命值200",200,20,"试一试味道如何？" };
struct spe spei[9] = { spe1,spe2,spe3,spe4,spe5,spe6,spe7,spe8,spe9 };


wp wp2 = { "屠龙宝刀",16,32,"曾使恶龙自宫" };
wp wp1 = { "菜刀",15,30,"残留着刚吃的肉的血丝" };
wp wp3 = { "迪迦变身器",17,34,"迪迦奥特曼，变身" };
wp wp4 = { "坤坤的篮球",18,36,"篮球撞击之神" };
wp wp5 = { "高数课教鞭",19,38,"看你禁不禁得起洛" };
wp wp6 = { "传奇*宝刀",20,40,"一刀999" };
wp wp7 = { "核酸的棉签",21,42,"一捅定阴阳" };
wp wp8 = { "下品银剑",22,44,"上剑下剑，金剑银剑" };
wp wp9 = { "v我50",25,50,"懂的都懂" };
struct wp wpi[9] = { wp1,wp2,wp3,wp4,wp5,wp6,wp7,wp8,wp9 };
char s5[20], s6[20], s10[40];
ar ar1 = {"纸做的盾",16,32,"或许——一戳就破？" };
ar ar2 = {"龙鳞衣",17,34,"或许——是屠龙刀屠的龙？" };
ar ar3 = {"迪迦的外套",18,36,"或许——观赏性大于实用性" };
ar ar4 = {"坤坤的背带裤",19,38,"有着一甩就掉的能力" };
ar ar5 = {"大白外套",20,40,"专业抵抗病毒" };
ar ar6 = {"超人服装",21,42,"内裤超人的外穿内裤" };
ar ar7 = { "**%%##",22,44,"不可名状之物" };
ar ar8 = { "锡纸烫发型",23,46,"对方难以直视，转移对象" };
ar ar9 = { "&*o50^",24,48,"解析失败，但懂得都懂" };
struct ar ari[9] = { ar1,ar2,ar3,ar4,ar5,ar6,ar7,ar8,ar9 };//内容添加结束

void nine(int e, int f, int g, int h, int p) {//九宫格函数，用于绘画商店主界面的九宫格
	int l = e, k = 0;
	clearrectangle(e, f, c - 1, d - 1);
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			rectangle(e, f, e + g, f + g);
			settextstyle(30, 15, _T("黑体"));
			if (p == 1) {
				outtextxy(e + 10, f + 1, wpi[k].name);
				sprintf_s(s5, 10, "攻击：%d", wpi[k].at);
				outtextxy(e + 10, f + 29, s5);
				sprintf_s(s6, 20, "售价：%d", wpi[k].gold);
				outtextxy(e + 10, f + 57, s6);
				settextstyle(15, 8, _T("黑体"));
				outtextxy(e + 10, f + 90, wpi[k].say);
			}//第一页，武器九宫格
			if (p == 2) {
				outtextxy(e + 10, f + 1, ari[k].name);
				sprintf_s(s5, 10, "攻击：%d", ari[k].df);
				outtextxy(e + 10, f + 29, s5);
				sprintf_s(s6, 20, "售价：%d", ari[k].gold);
				outtextxy(e + 10, f + 57, s6);
				settextstyle(15, 8, _T("黑体"));
				outtextxy(e + 10, f + 90, ari[k].say);
			}//第二页，防具九宫格
			if (p == 3) {
				settextstyle(17, 13, _T("黑体"));
				outtextxy(e + 5, f + 5, spei[k].name);
				outtextxy(e + 5, f + 34, spei[k].function);
				sprintf_s(s6, 20, "售价：%d", spei[k].gold);
				settextstyle(20, 15, _T("黑体"));
				outtextxy(e + 10, f + 62, s6);
				settextstyle(15, 8, _T("黑体"));
				outtextxy(e + 10, f + 95, spei[k].say);
			}//第三页，特殊道具九宫格
			e = e + g + h;
			k++;
		}
		e = l;
		f = f + g + h - 2;
	}
	settextstyle(30, 15, _T("黑体"));
}
void supermarket(player *p) {
	int k2, k3, flag = 0;//判断商店是否展开
	int afford = 0;//判断金币数量与商品售价，是否能够购买
	int page = 1;//判断商店界面为几号
	int q1 = b + (c - a) / 4 + 29, q2 = b + 65, q3 = (3 * (c - b) / 4 - 58) / 3;//九宫格大小的控制参数
	//该参数含义为可读取鼠标左键操作，如果要并入main函数需要把这个加进去
	cleardevice();
	EndBatchDraw();
	settextstyle(60, 20, _T("黑体"));
	outtextxy(a + 10, b, _T("商店"));
	rectangle(a, b, 220, 155);
	while (1) {
		if (MouseHit() && flag == 0)//判断是否有鼠标信息
		{
			MOUSEMSG msg1 = GetMouseMsg();
			if (msg1.uMsg == WM_LBUTTONDOWN) {//uMsg判断鼠标信息是什么信息(此处为左键信息)
				if ((msg1.x > a && msg1.x < c) && (msg1.y > b && msg1.y < d))
				{
					flag = 1;
					setlinecolor(WHITE);
					clearrectangle(a, b, c, d);
					rectangle(a, b, c, d);
					outtextxy(a + c * 2 / 5, b + 1, _T("商店"));
					line(a, b + 60, c, b + 60);
					line(a, (2 * b + d) / 3 + 40, b + 10 + (c - a) / 4, (2 * b + d) / 3 + 40);
					line(a, (b + 2 * d) / 3 + 40, b + 10 + (c - a) / 4, (b + 2 * d) / 3 + 40);
					line(b + 10 + (c - a) / 4, b + 60, b + 10 + (c - a) / 4, d);
					nine(q1, q2, q3, 10, 1);
					outtextxy(a + 20, b + 120, "武器");
					outtextxy(a + 20, b + 120 + (d - b - 60) / 3, "防具");
					outtextxy(a + 20, b + 120 + 2 * (d - b - 60) / 3, "道具");
					rectangle(c - 150, b + 10, c - 60, b + 50);
					outtextxy(c - 148, b + 15, "关闭");
					sprintf_s(s10, 40, "金币数量：%d", p->gold);
					outtextxy(a + 100, b + 10, s10);
				}//展开商店主界面
			}
		}
		if (MouseHit() && flag == 1)//判断是否有鼠标信息
		{
			MOUSEMSG msg2 = GetMouseMsg();//获取鼠标信息并根据选择展开下属页面
			if (msg2.uMsg == WM_LBUTTONDOWN) {
				if ((msg2.x > a && msg2.x < b + 10 + (c - a) / 4) && (msg2.y > b + 60 && msg2.y < (2 * b + d) / 3 + 40)) {
					page = 1;
					nine(q1, q2, q3, 10, page);
				}
				if ((msg2.x > a && msg2.x < b + 10 + (c - a) / 4) && (msg2.y > (2 * b + d) / 3 + 40 && msg2.y < (b + 2 * d) / 3 + 40)) {
					page = 2;
					nine(q1, q2, q3, 10, page);

				}
				if ((msg2.x > a && msg2.x < b + 10 + (c - a) / 4) && (msg2.y > (b + 2 * d) / 3 + 40 && msg2.y < d)) {
					page = 3;
					nine(q1, q2, q3, 10, page);
				}
				//以下是点击某件装备后出来的选择框
				int x1 = q1, x2 = q3 + q1, y1 = q2, y2 = q2 + q3;
				k2 = 0;
				for (int j = 0; j < 3; j++) {
					for (int i = 0; i < 3; i++) {
						if ((msg2.x > x1 && msg2.x< x2 && msg2.y>y1 && msg2.y < y2)) {
							flag = 2;
							setlinecolor(WHITE);
							clearrectangle(360, 240, 720, 480);
							rectangle(360, 240, 720, 480);
							settextstyle(30, 15, _T("黑体"));
							outtextxy(400, 300, "请确认是否购买此装备");
							outtextxy(410, 400,"是 ");
							outtextxy(620, 400, "否 ");
							settextstyle(60, 20, _T("黑体"));
							rectangle(380, 390, 500, 450);
							rectangle(580, 390, 700, 450);
							k3 = k2;
						}
						k2++;
						x1 = x1 + q3 + 10;
						x2 = x2 + q3 + 10;
					}
					x1 = q1;
					x2 = q1 + q3;
					y1 = y1 + q3 + 10;
					y2 = y2 + q3 + 10;
				}
				if ((msg2.x > c - 150 && msg2.x < c - 60) && (msg2.y > b + 10 && msg2.y < b + 50)) {//此位置为关闭商店按钮
					//到时候这里放大地图的函数
					break;
				}
			}
		}
		if (MouseHit() && flag == 2) {//判断是否有鼠标信息以确定是否购买
			MOUSEMSG msg3 = GetMouseMsg();
			if (msg3.uMsg == WM_LBUTTONDOWN) {
				if ((msg3.x > 380 && msg3.x < 500 && msg3.y>390 && msg3.y < 450) || (msg3.x > 580 && msg3.x < 700 && msg3.y > 390 && msg3.y < 450)) {
					if (msg3.x > 380 && msg3.x < 500 && msg3.y>390 && msg3.y < 450) {
						if (page == 1 && p->gold >= wpi[k3].gold) {
							afford = 1;
							p->gold = p->gold - wpi[k3].gold;
							clearrectangle(a + 90, b + 9, 450, b + 50);
							settextstyle(30, 15, _T("黑体"));
							sprintf_s(s10, 40, "金币数量：%d", p->gold);
							outtextxy(a + 100, b + 10, s10);
							settextstyle(60, 20, _T("黑体"));
						}
						if (page == 2 && p->gold >= ari[k3].gold) {
							afford = 1;
							p->gold = p->gold - ari[k3].gold;
							clearrectangle(a + 90, b + 9, 450, b + 50);
							settextstyle(30, 15, _T("黑体"));
							sprintf_s(s10, 40, "金币数量：%d", p->gold);
							outtextxy(a + 100, b + 10, s10);
							settextstyle(60, 20, _T("黑体"));
						}
						if (page == 3 && p->gold >= spei[k3].gold) {
							afford = 1;
							p->gold = p->gold - spei[k3].gold;
							clearrectangle(a + 90, b + 9, 450, b + 50);
							settextstyle(30, 15, _T("黑体"));
							sprintf_s(s10, 40, "金币数量：%d", p->gold);
							outtextxy(a + 100, b + 10, s10);
							settextstyle(60, 20, _T("黑体"));
						}
						//以上用于判定金币数量与售价
						settextstyle(30, 15, _T("黑体"));
						if (afford == 1) {
							afford = 0;
							switch (page) {
							case 1:
								if (getwp(p, wpi[k3]))
								{
									clearrectangle(200, 20, 800, 60);
									outtextxy(200, 25, "恭喜玩家获得道具:");
									clearrectangle(500, 20, 800, 60);
									outtextxy(500, 20, wpi[k3].name);
								}
								break;
							case 2:
								if (getar(p, ari[k3]))
								{
									clearrectangle(200, 20, 800, 60);
									outtextxy(200, 25, "恭喜玩家获得道具:");
									clearrectangle(500, 20, 800, 60);
									outtextxy(500, 20, ari[k3].name);
								}
								break;
							case 3:
								clearrectangle(200, 20, 800, 60);
								outtextxy(200, 25, "恭喜玩家获得道具:");
								clearrectangle(500, 20, 800, 60);
								outtextxy(500, 20, spei[k3].name);
								getspe(p, spei[k3]);

								break;
							}
						}
						else {
							clearrectangle(200, 20, 900, 60);
							outtextxy(200, 25, "穷鬼！饭都吃不起了，别买了！");
						}//金币不足以购买的提示
					}
					flag = 1;
					clearrectangle(b + 12 + (c - a) / 4, q2 + 1, c - 1, d - 1);
					nine(q1, q2, q3, 10, page);
				}
			}
		}
	}

}