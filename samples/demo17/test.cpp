#include "libnge2.h"
#include "hgedistort.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * nge_test:nge����:ͼƬŤ��
 */

#define RES_PATH(path) (path)

//�˳���ʶ
int game_quit = 0;
//����ͼƬ
image_p p_bg = NULL;
//logoͼƬ
image_p p_logo  = NULL;
hgeDistortionMesh* mDistortionMesh;

nge_timer* timer;
//last tick;����Ϊ��λ
float mlast = 0;

const int nRows=16;
const int nCols=16;

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
		break;
	case PSP_BUTTON_START:
		//���¿�ʼ���˳�
		game_quit = 1;
		break;
    }
}
#endif

void Update()
{
	int i, j;
	mlast = timer->get_ticks(timer)/1000.0;
	for(i=1;i<nRows-1;i++)
		for(j=1;j<nCols-1;j++)
		{
			mDistortionMesh->SetDisplacement(j,i,cosf(10.0*mlast+(i+j)/2)*5,sinf(10.0*mlast+(i+j)/2)*5,HGEDISP_NODE);
		}
}

void DrawScene()
{
	BeginScene(1);
	ImageToScreen(p_bg, 0, 0);
	mDistortionMesh->Render(20,20);
	EndScene();
}

int init() {
	//��ʼ��NGE��ΪVIDEO,AUDIO��������ֻ��ʼ��VIDEO�������ʼ��������INIT_VIDEO|INIT_AUDIO,����INIT_ALL
	NGE_Init(INIT_VIDEO);
	//��ʼ����������btn_down�ǰ�����Ӧ,�����ǵ���ʱ����Ӧ��0����nge����home��Ϣ(ֱ���˳�),��1������PSPϵͳ����
	//home��Ϣ,ͨ����1�����˳���1.50������Ƴ�����Ҫ��0��
#ifdef NGE_INPUT_BUTTON_SUPPORT
	InitInput(btn_down,NULL,1);
#endif
	p_bg = image_load(RES_PATH("images/demo0.jpg"),DISPLAY_PIXEL_FORMAT_8888,1);
	if(p_bg == NULL) {
		printf("can not open file\n");
	}
	p_logo = image_load(RES_PATH("images/nge2logo.png"),DISPLAY_PIXEL_FORMAT_8888,1);
	if(p_logo == NULL) {
		printf("can not open file\n");
	}
	//��ʼ��Ť������
	mDistortionMesh = new hgeDistortionMesh(nCols, nRows);
	mDistortionMesh->SetTexture(p_logo);
	mDistortionMesh->SetTextureRect(0,0,p_logo->w,p_logo->h);
	mDistortionMesh->Clear(0xFFFFFFFF);
	timer = nge_timer_create();
	timer->start(timer);

	return 0;
}

int mainloop() {
	if (game_quit)
		return NGE_APP_QUIT;

	ShowFps();
#ifdef NGE_INPUT_HAS_PROC
	InputProc();
#endif
	Update();
	DrawScene();
	LimitFps(60);

	return NGE_APP_NORMAL;
}

int fini() {
	image_free(p_logo);
	p_logo = NULL;
	image_free(p_bg);
	p_bg = NULL;
	delete mDistortionMesh;
	mDistortionMesh = NULL;
	nge_timer_free(timer);
	NGE_Quit();
	return 0;
}

static nge_app_t app;

extern "C"
int main(int argc, char* argv[])
{
	nge_init_app(&app);
	app.init = init;
	app.mainloop = mainloop;
	app.fini = fini;
	nge_register_app(&app);
	return 0;
}
