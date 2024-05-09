#include <stdio.h>
#include <easyx.h>
# include <time.h>
#include "main.h"

/*输出框位置（最外）：
左上角（WIDTH / 2，500）        右上角（WIDTH，500）
左下角（WIDTH / 2，HEIGH）      右下角（WIDTH，HEIGH）
一行最多19个字，一共7行*/
//TEXT_1_H 24 //状态栏文字高度//
//TEXT_1_W 16//状态栏文字宽度 //一个汉字要占2个宽度
//文本起始位置：x=WIDTH/2+20  y=520 

void clear() {
	solidrectangle(WIDTH, 525, WIDTH / 2 + 1, 525 + 170);
}
void juqing(int a) {

	//设置输出字体样式
	settextstyle(TEXT_1_H, TEXT_1_W, _T("楷体"));
	//设置擦除线颜色为黑色
	setfillcolor(BLACK);


	if(a==1){
		outtextxy((WIDTH/2+20), (525), "（睁眼）");
	}
	else if(a==2){
		Sleep(1400);//为了连续测试文本加上去的，最后可以删掉
		outtextxy((WIDTH/2+20), (525+24), "眼前的黑暗染着光刺来的深红，四周的");
		Sleep(1400);
		outtextxy((WIDTH/2+20), (525+48), "空气似乎停止了流动，变得粘稠而诡异");
		Sleep(1400);
		outtextxy((WIDTH/2+20), (525+72), "，耳边充斥着细密的呓语。");
		Sleep(1400);
		outtextxy((WIDTH/2+20), (525+96), "我的头一阵阵刺痛，我勉力睁开眼。");
		Sleep(1400);
	}
	else if (a == 3) {
		clear();//先清除文本框里的内容
		outtextxy((WIDTH / 2 + 20), (525), "国王：没想到竟然成功了，真的召唤出");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 24), "     了来自异世界的旅人。");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 48), "     恶龙的出现让王国民不聊生，连");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 72), "     公主也被恶龙抓走了，");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 96), "     我们实在是束手无策。");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 120), "     您从召唤阵中走出来，");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 144), "     必然是天选之人。");
		Sleep(1400);
		clear();
		outtextxy((WIDTH / 2 + 20), (525), "国王：勇敢的旅者，请接受我的请求吧");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525+24), "我：...我好像只能接受。");
		Sleep(1400);
		clear();//先清除文本框里的内容
		outtextxy((WIDTH / 2 + 20), (525), "国王：感谢您对王国的付出");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 24), "     请收下这些吧");
		Sleep(1400);
	}
	else if(a==4){
		clear();//先清除文本框里的内容
		outtextxy((WIDTH / 2 + 20), (525), "女巫：来自异世界的旅者，请留步");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 24), "      临行前，请让我为您来进行占卜吧");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 48), "      !@#$^@*$$%#$");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 72), "      啊！怎么会......");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 96), "（女巫的脸色变得惨白）");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 120), "女巫：真是太抱歉了，旅者。");
		Sleep(1400);
		outtextxy((WIDTH / 2 + 20), (525 + 144), "      请收下我的歉礼吧。");
		Sleep(1400);
	}

}