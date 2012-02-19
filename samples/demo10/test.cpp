﻿#include "libnge2.h"
#include "nge_app.h"
#include <stdio.h>
// #define DEBUG_HERE() nge_print("%s %s %d\n",__FUNCTION__,  __FILE__, __LINE__)
/**
 * nge_test:最简单的nge程序:显示一张图片
 */

//退出标识
int game_quit = 0;
//背景图片
image_p p_bg = NULL;
//logo图片
image_p p_logo  = NULL;
//logo图片的图片遮罩
int logomask1,logomask2;

#ifdef NGE_INPUT_BUTTON_SUPPORT
void btn_down(int keycode)
{
	switch(keycode)
    {
	case PSP_BUTTON_UP:
		break;
	case PSP_BUTTON_DOWN:
		break;
	case PSP_BUTTON_LEFT:
		break;
	case PSP_BUTTON_RIGHT:
		break;
	case PSP_BUTTON_TRIANGLE:
		break;
	case PSP_BUTTON_CIRCLE:
		break;
	case PSP_BUTTON_CROSS:
		break;
    case PSP_BUTTON_SQUARE:
		break;
	case PSP_BUTTON_SELECT:
		//按下选择键退出
		game_quit = 1;
		break;
	case PSP_BUTTON_START:
		//按下开始键退出
		game_quit = 1;
		break;
    }
}
#endif

void DrawScene()
{
	BeginScene(1);
	ImageToScreen(p_bg,0,0);
	DrawImage(p_logo,0,0,0,0,128,0,256,256);
	DrawImageMask(p_logo,0,0,0,0,0/*dx*/,0/*dy*/,128/*dw*/,128/*dh*/,logomask1);
	DrawImageMask(p_logo,0,0,0,0,480-128/*dx*/,272-128/*dy*/,128/*dw*/,128/*dh*/,0x7fffffff);
	DrawImageMask(p_logo,0,0,0,0,0/*dx*/,272-128/*dy*/,128/*dw*/,128/*dh*/,logomask2);
	DrawImageMask(p_logo,0,0,0,0,480-128/*dx*/,0/*dy*/,128/*dw*/,128/*dh*/,logomask2);
	EndScene();
}

#ifdef ANDROID
#define RES_PATH(path) ("/sdcard/libnge2/demo10/" path)
#else
#define RES_PATH(path) (path)
#endif

int init() {
	//初始化NGE分为VIDEO,AUDIO，这里是只初始化VIDEO，如果初始化所有用INIT_VIDEO|INIT_AUDIO,或者INIT_ALL
	NGE_Init(INIT_VIDEO);
	//初始化按键处理btn_down是按下响应,后面是弹起时的响应，0是让nge处理home消息(直接退出),填1就是让PSP系统处理
	//home消息,通常填1正常退出（1.50版的自制程序需要填0）
#ifdef NGE_INPUT_BUTTON_SUPPORT
	InitInput(btn_down,NULL,1);
#endif
	//最后一个参数是psp swizzle优化，通常填1
	p_bg = image_load(RES_PATH("images/demo0.jpg"),DISPLAY_PIXEL_FORMAT_8888,1);
	if(p_bg == NULL)
		nge_print("can not open file\n");
	p_logo = image_load(RES_PATH("images/nge2logo.png"),DISPLAY_PIXEL_FORMAT_4444,1);
	if(p_logo == NULL)
		nge_print("can not open file\n");
	//创建一个半透明的图片遮罩color
	logomask1 = CreateColor(255,255,255,128,p_logo->dtype);
	//随便创建一个图片遮罩color
	logomask2 = CreateColor(100,100,100,255,p_logo->dtype);
	return 0;
}

int mainloop() {
	if (game_quit)
		return NGE_APP_QUIT;

	ShowFps();
#ifdef NGE_INPUT_HAS_PROC
	InputProc();
#endif
	DrawScene();

	return NGE_APP_NORMAL;
}

int fini() {
	image_free(p_bg);
	p_bg = NULL;
	image_free(p_logo);
	p_logo = NULL;
	NGE_Quit();
	return 0;
}

static nge_app_t app;

extern "C"
int main(int argc, char* argv[])
{
	app.init = init;
	app.mainloop = mainloop;
	app.fini = fini;
	nge_register_app(&app);
	return 0;
}
