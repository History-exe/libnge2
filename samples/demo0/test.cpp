
#ifndef NGE_LIBTYPE_STATIC
#define NGE_LIBTYPE_STATIC
#endif

#include "libnge2.h"
#include <stdio.h>
/**
 * nge_test:��򵥵�nge����:��ʾһ��ͼƬ
 */
//�˳���ʶ
int game_quit = 0;
//����ͼƬ
image_p p_bg = NULL;
//logoͼƬ
image_p p_logo  = NULL;
//����ͼƬ
image_p p_p070  = NULL;
image_p p_p044  = NULL;
//logoͼƬ��ͼƬ����
int logomask1,logomask2;
image_p img;
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
		//����ѡ����˳�
		game_quit = 1;
		break;
	case PSP_BUTTON_START:
		//���¿�ʼ���˳�
		game_quit = 1;
		break;
    }
}


void btn_up(int keycode, const char* szBuf, int nLen)
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
		break;
	case PSP_BUTTON_START:
		break;
    }
}

void DrawScene()
{

	BeginScene(1);
		//RenderQuad(img,0,0,0,0,0,0,1,1,0,0x7fffffff);
		//RenderQuad(img,0,0,0,0,0,0,1,1,120,0x7fffffff);
	EndScene();
}

extern "C"
int main(int argc, char* argv[])
{
	//��ʼ��NGE��ΪVIDEO,AUDIO��������ֻ��ʼ��VIDEO�������ʼ��������INIT_VIDEO|INIT_AUDIO,����INIT_ALL
	NGE_Init(INIT_VIDEO);
	//��ʼ����������btn_down�ǰ�����Ӧ,�����ǵ���ʱ����Ӧ��0����nge����home��Ϣ(ֱ���˳�),��1������PSPϵͳ����
	//home��Ϣ,ͨ����1�����˳���1.50������Ƴ�����Ҫ��0��
	//InitInput(btn_down,NULL,1);
	//InitInput(btn_down, btn_up, 1);
	//���һ��������psp swizzle�Ż���ͨ����1
	p_bg = image_load("images/demo0.jpg",DISPLAY_PIXEL_FORMAT_8888,1);
	if(p_bg == NULL) {
		printf("can not open file\n");
	}
	p_logo = image_load("images/nge2logo.png",DISPLAY_PIXEL_FORMAT_4444,1);
	if(p_logo == NULL) {
		printf("can not open file\n");
	}
// 		image_to_image_ex(p_p044, img, 0,0,16,16,80,0,0);
		//ImageToScreen(p_logo,150,0);
//		DrawImage(p_logo,0,0,0,0,128,0,320,256);
// 		DrawImageMask(p_logo,0,0,0,0,0/*dx*/,0/*dy*/,128/*dw*/,128/*dh*/,logomask1);
// 		DrawImageMask(p_logo,0,0,0,0,480-128/*dx*/,272-128/*dy*/,128/*dw*/,128/*dh*/,0x7fffffff);
// 		DrawImageMask(p_logo,0,0,0,0,0/*dx*/,272-128/*dy*/,128/*dw*/,128/*dh*/,logomask2);
// 		DrawImageMask(p_logo,0,0,0,0,480-128/*dx*/,0/*dy*/,128/*dw*/,128/*dh*/,logomask2);
	//EndTarget();
p_p070 = image_create(480, 272, DISPLAY_PIXEL_FORMAT_8888);
p_p070->dontswizzle = 1;
	while ( !game_quit )
	{
		ShowFps();
		InputProc();
		DrawScene();
	}
	image_free(p_bg);
	image_free(p_logo);
	NGE_Quit();
	return 0;
}



