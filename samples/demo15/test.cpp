#include "libnge2.h"
#include "hgedistort.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/**
 * nge_test:nge����:ͼƬŤ��
 */
//�˳���ʶ
int game_quit = 0;
//����ͼƬ
image_p p_bg = NULL;
//logoͼƬ
image_p p_logo  = NULL;
hgeDistortionMesh* mDistortionMesh;

nge_timer* timer;
//last tick;
int mlast = 0;

const int nRows=16;
const int nCols=16;

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

void Update()
{
	int i, j;
	mlast = timer->get_ticks(timer);
	for(i=1;i<nRows-1;i++)
		for(j=1;j<nCols-1;j++)
		{
			mDistortionMesh->SetDisplacement(j,i,cosf(mlast/100.0+(i+j)/2)*5,sinf(mlast/100.0+(i+j)/2)*5,HGEDISP_NODE);
		}
}

void DrawScene()
{
	BeginScene(1);
	ImageToScreen(p_bg, 0, 0);
	mDistortionMesh->Render(20,20);
	EndScene();
}

extern "C"
int main(int argc, char* argv[])
{
	//��ʼ��NGE��ΪVIDEO,AUDIO��������ֻ��ʼ��VIDEO�������ʼ��������INIT_VIDEO|INIT_AUDIO,����INIT_ALL
	NGE_Init(INIT_VIDEO);
	//��ʼ����������btn_down�ǰ�����Ӧ,�����ǵ���ʱ����Ӧ��0����nge����home��Ϣ(ֱ���˳�),��1������PSPϵͳ����
	//home��Ϣ,ͨ����1�����˳���1.50������Ƴ�����Ҫ��0��
	InitInput(btn_down,NULL,1);
	//���һ��������psp swizzle�Ż���ͨ����1
	p_bg = image_load("images/demo0.jpg",DISPLAY_PIXEL_FORMAT_8888,1);
	if(p_bg == NULL) {
		printf("can not open file\n");
	}
	p_logo = image_load("images/nge2logo.png",DISPLAY_PIXEL_FORMAT_8888,1);
	if(p_logo == NULL) {
		printf("can not open file\n");
	}
	//��ʼ��Ť������
	mDistortionMesh = new hgeDistortionMesh(nCols, nRows);
	mDistortionMesh->SetTexture(p_logo);
	mDistortionMesh->SetTextureRect(0,0,p_logo->w,p_logo->h);
	mDistortionMesh->Clear(0xFFFFFFFF);
	timer = timer_create();
	timer->start(timer);
	
	while ( !game_quit )
	{
		ShowFps();
		InputProc();
		Update();
		DrawScene();
		LimitFps(60);
	}
	image_free(p_logo);
	image_free(p_bg);
	SAFE_FREE(mDistortionMesh);
	delete mDistortionMesh;
	NGE_Quit();
	return 0;
}
