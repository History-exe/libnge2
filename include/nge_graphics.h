#ifndef NGE_GRAPHICS_H_
#define NGE_GRAPHICS_H_

#include "nge_common.h"
#include "nge_image.h"

#define SCREEN_WIDTH_PSP  480
#define SCREEN_HEIGHT_PSP 272

#define SCREEN_WIDTH_IPHONE  320
#define SCREEN_HEIGHT_IPHONE 480

#define SCREEN_WIDTH_ANDROID  240
#define SCREEN_HEIGHT_ANDROID 320

#ifdef NGE_IPHONEOS
#define	SCREEN_WIDTH  SCREEN_WIDTH_IPHONE
#define	SCREEN_HEIGHT SCREEN_HEIGHT_IPHONE
#elif defined NGE_ANDROID
#define	SCREEN_WIDTH  SCREEN_WIDTH_ANDROID
#define	SCREEN_HEIGHT SCREEN_HEIGHT_ANDROID
#else
#define	SCREEN_WIDTH  SCREEN_WIDTH_PSP
#define	SCREEN_HEIGHT SCREEN_HEIGHT_PSP
#endif

#define SCREEN_BPP    32
#define DEFAULT_FPS 60

//NGE_TRANS_x
enum{
	NGE_TRANS_NONE = 0,
	NGE_TRANS_V,
	NGE_TRANS_H,
	NGE_TRANS_HV
};

typedef struct {
	char *name;
	int width;
	int height;
	int bpp;
	int fullscreen;

	int ori_width;
	int ori_height;
	float rate_w;
	float rate_h;
}screen_context_t, *screen_context_p;

typedef struct{
	float x;
	float y;
} pointf;

typedef struct{
	float top;
	float left;
	float right;
	float bottom;
} rectf;

#ifdef __cplusplus
extern "C"{
#endif

/**
 *得到屏幕信息
 *@return 屏幕信息
 */
screen_context_p GetScreenContext();
/**
 * 初始化函数,由nge2系统调用,用户无须显式调用
 */
void InitGrahics();
/**
 * 结束函数,由nge2系统调用,用户无须显式调用
 */
void FiniGrahics();
/**
 * 屏幕绘制开始函数,所有绘制到屏幕均在BeginScene,EndScene之间调用
 *@param uint8 clear,清屏标志，默认为1清屏
 *@return 无
 */
void BeginScene(uint8 clear);
/**
 * 屏幕绘制结束函数,所有绘制到屏幕均在BeginScene,EndScene之间调用
 *@return 无
 */
void EndScene();
/**
 * 设置是否显示FPS和调试信息
 *@return 无
 */
void ShowFps();
/**
 * 限制帧数
 *@param int fps,目标帧数
 *@return 无
 */
void LimitFps(uint32 fps);
/**
 * 设置裁剪区域，在目标区域内的才显示，同J2ME的SetClip
 *@param int x,目标区域x坐标
 *@param int y,目标区域y坐标
 *@param int w,目标区域裁剪的width
 *@param int h,目标区域裁剪的height
 *@return 无
 */
void SetClip(int x,int y,int w,int h);
/**
 * 重置置裁剪区域，等同于调用SetClip(0,0,SCREEN_WIDTH,SCREEN_HEIGHT)
 *@return 无
 */
void ResetClip();
/**
 * 画线函数1，输入坐标点
 *@param float x1,第一个点x坐标
 *@param float y1,第一个点y坐标
 *@param float x2,第二个点x坐标
 *@param float y2,第二个点y坐标
 *@param int color,颜色与下面对应，例如下面用的5551，这里就用MAKE_RGBA5551
 *@param int dtype,显示模式，与上面的对应
 *@return 无
 */
void DrawLine(float x1, float y1, float x2, float y2, int color,int dtype);
/**
 * 画线函数2，输入坐标的pointf
 *@param pointf p1,第一个点xy坐标
 *@param pointf p2,第二个点xy坐标
 *@param int color,颜色与下面对应，例如下面用的5551，这里就用MAKE_RGBA5551
 *@param int dtype,显示模式，与上面的对应
 *@return 无
 */
void DrawLineEx(pointf p1,pointf p2, int color,int dtype);
/**
 * 画矩形线框的函数1，输入为位置和宽高
 *@param float dx,矩形左上角的x坐标
 *@param float dy,矩形左上角的y坐标
 *@param float width,矩形的宽
 *@param float height,矩形的高
 *@param int color,颜色与下面对应，例如下面用的5551，这里就用MAKE_RGBA5551
 *@param int dtype,显示模式，与上面的对应
 *@return 无
 */
void DrawRect(float dx, float dy, float width, float height,int color,int dtype);
/**
 * 画矩形线框的函数2，输入为矩形位置坐标
 *@param rectf rect,矩形位置坐标
 *@param int color,颜色与下面对应，例如下面用的5551，这里就用MAKE_RGBA5551
 *@param int dtype,显示模式，与上面的对应
 *@return 无
 */
void DrawRectEx(rectf rect,int color,int dtype);
/**
 * 画填充矩形的函数1，输入为位置和宽高
 *@param float dx,矩形左上角的x坐标
 *@param float dy,矩形左上角的y坐标
 *@param float width,矩形的宽
 *@param float height,矩形的高
 *@param int color,颜色与下面对应，例如下面用的5551，这里就用MAKE_RGBA5551
 *@param int dtype,显示模式，与上面的对应
 *@return 无
 */
void FillRect(float dx, float dy, float width, float height,int color,int dtype);
/**
 * 画填充矩形的函数2，输入为矩形位置坐标
 *@param rectf rect,矩形位置坐标
 *@param int color,颜色与下面对应，例如下面用的5551，这里就用MAKE_RGBA5551
 *@param int dtype,显示模式，与上面的对应
 *@return 无
 */
void FillRectEx(rectf rect,int color,int dtype);
/**
 * 画填充渐变矩形的函数1，输入为位置和宽高
 *@param float dx,矩形左上角的x坐标
 *@param float dy,矩形左上角的y坐标
 *@param float width,矩形的宽
 *@param float height,矩形的高
 *@param int* colors,4个顶点的color,颜色与下面对应，例如下面用的5551，这里就用MAKE_RGBA5551
 *@param int dtype,显示模式，与上面的对应
 *@return 无
 */
void FillRectGrad(float dx, float dy, float width, float height,int* colors,int dtype);
/**
 * 画填充矩形的函数2，输入为矩形位置坐标
 *@param rectf rect,矩形位置坐标
 *@param int* colors,4个顶点的color,颜色与下面对应，例如下面用的5551，这里就用MAKE_RGBA5551
 *@param int dtype,显示模式，与上面的对应
 *@return 无
 */
void FillRectGradEx(rectf rect,int* colors,int dtype);
/**
 * 画图函数1，效率依次是ImageToScreen>DrawImage>DrawImageMask>RenderQuad;
 * sx,sy,sw,sh,构成待显示的图片范围，例如要显示一张图片200*200的图片的
 * 20，20到50宽50高的子图块，这里就填依次20,20,50,50。如果要显示原图,都填上0
 * 即可.都填0是显示0,0,tex->w,tex->h。xscale,yscale是放大缩小因子1是原始比例，
 * 如果放大一倍，都填2，缩小1倍填0.5。mask是颜色遮罩，用于对图片进行混色，
 * 例如半透明效果等，默认是显示原色，这里用texture->mask即可
 * 例子1:将200*200的图片tex显示在屏幕100，0处，并放大一倍显示
 * RenderQuad(tex,0,0,0,0,100,0,2,2,0,tex->mask);
 * 例子2:将图片tex的32，32开始的64宽,64高的部分显示在40，80处并旋转90度
 * RenderQuad(tex,32,32,64,64,40,80,1,1,90,tex->mask);
 * 例子3:将图片tex(tex显示模式是8888)的80，80开始的64宽,64高的部分显示在100，100处并半透明显示
 * RenderQuad(tex,80,80,64,64,100,100,1,1,0,MAKE_RGBA_8888(255,255,255,128));
 *@param image_p texture,图片指针
 *@param float sx,图片x坐标
 *@param float sy,图片y坐标
 *@param float sw,图片宽
 *@param float sh,图片高,
 *@param float dx,屏幕x坐标
 *@param float dy,屏幕y坐标
 *@param float xscale,图片x方向放大缩小因子
 *@param float yscale,图片y方向放大缩小因子
 *@param float angle,旋转角度
 *@param int mask,颜色遮罩
 *@return 无
 */
void RenderQuad(image_p texture,float sx ,float sy ,float sw ,float sh ,float dx ,float dy ,float xscale  ,float yscale ,float angle ,int mask);
/**
 * 画图函数2,sw,sh为0是画原图，dw，dh为0是显示sw和dh大小
 * 例子1:将200*200的图片tex显示在屏幕100，0处
 * DrawImage(tex,0,0,0,0,100,0,0,0);
 * 或者用严格方式：DrawImage(tex,0,0,200,200,100,0,200,200);
 *@param image_p texture,图片指针
 *@param float sx,图片x坐标
 *@param float sy,图片y坐标
 *@param float sw,图片宽
 *@param float sh,图片高
 *@param float dx,屏幕x坐标
 *@param float dy,屏幕y坐标
 *@param float dw,屏幕宽
 *@param float dh,屏幕高
 *@return 无
 */
void DrawImage(image_p texture,float sx,float sy,float sw,float sh,float dx,float dy,float dw,float dh);
/**
 * 画图函数3
 * 同上，只是多了个MASK
 *@param image_p texture,图片指针
 *@param float sx,图片x坐标
 *@param float sy,图片y坐标
 *@param float sw,图片宽
 *@param float sh,图片高
 *@param float dx,屏幕x坐标
 *@param float dy,屏幕y坐标
 *@param float dw,屏幕宽
 *@param float dh,屏幕高
 *@param int mask,颜色遮罩
 *@return 无
 */
void DrawImageMask(image_p tex,float sx , float sy, float sw, float sh, float dx, float dy, float dw, float dh,int mask);
/**
 * 画图函数4，最简单的画图函数,将图片画到dx,dy
 *@param image_p texture,图片指针
 *@param float dx,屏幕x坐标
 *@param float dy,屏幕y坐标
 *@return 无
 */
void ImageToScreen(image_p texture,float dx,float dy);

/**
 *同RenderQuad,增加一个trans参数
 *@param image_p texture,图片指针
 *@param float sx,图片x坐标
 *@param float sy,图片y坐标
 *@param float sw,图片宽
 *@param float sh,图片高,
 *@param float dx,屏幕x坐标
 *@param float dy,屏幕y坐标
 *@param float xscale,图片x方向放大缩小因子
 *@param float yscale,图片y方向放大缩小因子
 *@param float angle,旋转角度
 *@param int mask,颜色遮罩
 *@param int trans,目前支持的NGE_TRANS_NONE,NGE_TRANS_V,NGE_TRANS_H,NGE_TRANS_VH
 *@return 无
 */
void RenderQuadTrans(image_p texture,float sx ,float sy ,float sw ,float sh ,float dx ,float dy ,float xscale  ,float yscale ,float angle ,int mask,int trans);
/**
 *同DrawImage,增加一个trans参数
 *@param image_p texture,图片指针
 *@param float sx,图片x坐标
 *@param float sy,图片y坐标
 *@param float sw,图片宽
 *@param float sh,图片高
 *@param float dx,屏幕x坐标
 *@param float dy,屏幕y坐标
 *@param float dw,屏幕宽
 *@param float dh,屏幕高
 *@param int trans,目前支持的NGE_TRANS_NONE,NGE_TRANS_V,NGE_TRANS_H,NGE_TRANS_VH
 *@return 无
 */
void DrawImageTrans(image_p texture,float sx,float sy,float sw,float sh,float dx,float dy,float dw,float dh,int trans);
/**
 *同DrawImageMask,增加一个trans参数
 *@param image_p texture,图片指针
 *@param float sx,图片x坐标
 *@param float sy,图片y坐标
 *@param float sw,图片宽
 *@param float sh,图片高
 *@param float dx,屏幕x坐标
 *@param float dy,屏幕y坐标
 *@param float dw,屏幕宽
 *@param float dh,屏幕高
 *@param int mask,颜色遮罩
 *@param int trans,目前支持的NGE_TRANS_NONE,NGE_TRANS_V,NGE_TRANS_H,NGE_TRANS_VH
 *@return 无
 */
void DrawImageMaskTrans(image_p tex,float sx , float sy, float sw, float sh, float dx, float dy, float dw, float dh,int mask,int trans);
/**
 *同ImageToScreen,增加一个trans参数
 *@param image_p texture,图片指针
 *@param float dx,屏幕x坐标
 *@param float dy,屏幕y坐标
 *@param int trans,目前支持的NGE_TRANS_NONE,NGE_TRANS_V,NGE_TRANS_H,NGE_TRANS_VH
 *@return 无
 */
void ImageToScreenTrans(image_p texture,float dx,float dy,int trans);

/**
 *将屏幕内容保存在image_p中
 *@return image_p,返回image_p指针,出错返回NULL
 */
image_p ScreenToImage();
/**
 * 保存一个snapshot图片打文件,这个图片是png格式的
 *@param const char* filename,保存图片文件名
 *@return 无
 */
void ScreenShot(const char* filename);
/**
 *设置屏幕颜色，r,g,b,a
 *@param uint8 r,设置r分量(0-255)
 *@param uint8 g,设置g分量(0-255)
 *@param uint8 b,设置b分量(0-255)
 *@param uint8 a,设置a分量(0-255)
 *@return uint32,上一个屏幕颜色值,可用宏GET_RGBA_8888分离出各个颜色分量
 */
uint32 SetScreenColor(uint8 r,uint8 g,uint8 b,uint8 a);
/**
 * 设置当前的混合方式
 *@param int src_blend,
 *@param int des_blend,
 *@return
 */
void SetTexBlend(int src_blend, int des_blend);
/**
 *将混合方式恢复为默认方式
 *@return
 */
void ResetTexBlend();

/**
 * 在屏幕上画一个点的函数
 *@param float x,横坐标
 *@param float y,纵坐标
 *@param int color,颜色
 *@param int dtype,颜色类型
 *@return
 */
void PutPix(float x,float y ,int color,int dtype);

/**
 * 画圆形线框函数
 *@param float x,圆心横坐标
 *@param float y,圆心纵坐标
 *@param float radius,圆半径
 *@param int color,颜色
 *@param int dtype,颜色类型
 *@return
 */
void DrawCircle(float x, float y, float radius, int color,int dtype);

/**
 * 画实心圆函数
 *@param float x,圆心横坐标
 *@param float y,圆心纵坐标
 *@param float radius,圆半径
 *@param int color,颜色
 *@param int dtype,颜色类型
 *@return
 */
void FillCircle(float x, float y, float radius, int color,int dtype);

/**
 * 画椭圆线框函数
 *@param float x,圆心横坐标
 *@param float y,圆心纵坐标
 *@param float xradius,椭圆x半径
 *@param float yradius,椭圆y半径
 *@param int color,颜色
 *@param int dtype,颜色类型
 *@return
 */
void DrawEllipse(float x,float y ,float xradius,float yradius,int color,int dtype);

/**
 * 画实心椭圆函数
 *@param float x,圆心横坐标
 *@param float y,圆心纵坐标
 *@param float xradius,椭圆x半径
 *@param float yradius,椭圆y半径
 *@param int color,颜色
 *@param int dtype,颜色类型
 *@return
 */
void FillEllipse(float x,float y ,float xradius,float yradius,int color,int dtype);

/**
 * 画任意多边形线框函数
 * 注意顶点顺序是顺时针方向
 *@param float* x,顶点横坐标数组
 *@param float* y,顶点纵坐标数组
 *@param int count ,顶点个数
 *@param int color,颜色
 *@param int dtype,颜色类型
 *@return
 */
void DrawPolygon(float* x, float* y, int count, int color,int dtype);

/**
 * 画任意实心多边形函数
 * 注意顶点顺序是顺时针方向
 *@param float* x,顶点横坐标数组
 *@param float* y,顶点纵坐标数组
 *@param int count ,顶点个数
 *@param int color,颜色
 *@param int dtype,颜色类型
 *@return
 */
void FillPolygon(float* x, float* y, int count, int color,int dtype);

/**
 * 画渐进颜色任意实心多边形函数
 * 注意顶点顺序是顺时针方向
 *@param float* x,顶点横坐标数组
 *@param float* y,顶点纵坐标数组
 *@param int count ,顶点个数
 *@param int* colors,颜色数组注意与顶点个数相同
 *@param int dtype,颜色类型
 *@return
 */
void FillPolygonGrad(float* x, float* y, int count, int* colors,int dtype);

/**
 *设置屏幕类型0通常1全屏,2翻转横屏(ip)
 */
void SetScreenType(int type);

#ifdef __cplusplus
}
#endif
#endif
