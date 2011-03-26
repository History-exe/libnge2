#ifndef NGE_FONT_H_
#define NGE_FONT_H_

#include "nge_common.h"
#include "nge_image.h"

#ifdef __cplusplus
extern "C"{
#endif

//encoding flags
#define ENCODING_ASCII   0
#define ENCODING_UNICODE 1
#define ENCODING_GBK     2
//type flags
#define FONT_TYPE_HZK      1
#define FONT_TYPE_GBK      2
#define FONT_TYPE_FREETYPE 4
//show flags
#define FONT_SHOW_NORMAL   0
#define FONT_SHOW_SHADOW   1
//freetype private flags
#define FONT_ANTIALIAS 32
#define FONT_KERNING   64
#define FLAGS_FREETYPE_BOLDER 1
#define FLAGS_FREETYPE_NORMAL 0

enum{
	SET_ATTR_FIXWIDTH = 0,
	SET_ATTR_BOLD,
	SET_ATTR_MARGIN,
	SET_ATTR_SIZE
};

typedef struct {
	/**
	* Maximum advance width of any character.
	*/
	int maxwidth;
	/**
	* Height of "most characters" in the font. This does not include any
	* leading (blank space between lines of text).
	* Always equal to (baseline+descent).
	*/
	int height;
	/**
	* The ascent (height above the baseline) of "most characters" in
	* the font.
	*
	* Note: This member variable should be called "ascent", to be
	* consistent with FreeType 2, and also to be internally consistent
	* with the "descent" member.  It has not been renamed because that
	* would break backwards compatibility.  FIXME
	*/
	int baseline;
	/**
	* The descent (height below the baseline) of "most characters" in
	* the font.
	*
	* Should be a POSITIVE number.
	*/
	int descent;
	/**
	* Maximum height of any character above the baseline.
	*/
	int maxascent;
	/**
	* Maximum height of any character below the baseline.
	* Should be a POSITIVE number.
	*/
	int maxdescent;
	/**
	* The distance between the baselines of two consecutive lines of text.
	* This is usually height plus some font-specific "leading" value.
	*/
	int linespacing;
	/**
	* First character in the font.
	*/
	int firstchar;
	/**
	* Last character in the font.
	*/
	int lastchar;
	/**
	* True (nonzero) if font is fixed width.  In that case, maxwidth
	* gives the width for every character in the font.
	*/
	BOOL fixed;
	/**
	* Table of character advance widths for characters 0-255.
	* Note that fonts can contain characters with codes >255 - in that
	* case this table contains the advance widths for some but not all
	* characters.  Also note that if the font contains kerning
	* information, the advance width of the string "AV" may differ from
	* the sum of the advance widths for the characters 'A' and 'V'.
	*/
	uint8 widths[256];
} FontInfo, *PFontInfo;

struct _fontproc;
typedef struct _pfont{		/* common hdr for all font structures*/
	struct _fontproc*		procs;	/* font-specific rendering routines*/
	int			size;	/* font height in pixels*/
	int			rotation;	/* font rotation*/
	uint32			disp;	/* font attributes: kerning/antialias*/
	/* font-specific rendering data here*/
}TFont,*PFont;

typedef struct _fontproc{
	int		encoding;	/* routines expect this encoding*/
	BOOL	(*GetFontInfo)(PFont pfont, PFontInfo pfontinfo);
	void 	(*GetTextSize)(PFont pfont, const void *text, int cc,int flags, int *pwidth, int *pheight,int *pbase);
	void	(*GetTextBits)(PFont pfont, int ch, const uint8 **retmap,int *pwidth, int *pheight,int *pbase);
	void	(*DestroyFont)(PFont pfont);
	void	(*DrawText)(PFont pfont, image_p pimage, int x, int y,const void *str, int count, int flags);
	void	(*DrawTextShadow)(PFont pfont, image_p pimage, int x, int y,const void *str, int count, int flags);
	uint32  (*SetFontColor)(PFont pfont, uint32 color);
	void    (*SetFontSize)(PFont pfont, int fontsize);
	void    (*SetFontRotation)(PFont pfont, int rot);
	void    (*SetFontAttr)(PFont pfont, int setflags, int clrflags);
	PFont   (*Duplicate) (PFont psrcfont, int fontsize);
	void    (*SetFlags)(PFont pfont,int flags);
	void    (*SetShadowColor)(PFont pfont, uint32 color_fg,uint32 color_bg,uint32 color_sh);
}FontProcs,*PFontProcs;

/**
 *����һ��GBK(hzk)font,Ĭ��ΪGBK�ĵ���
 *@param const char* cname,�����ֿ�ͨ����GBKxx
 *@param const char* aname,Ӣ���ֿ�ͨ����ASCxx
 *@param int height,�߶�,�����ֿ�ΪGBK16,�������16
 *@param int disp,��ʾģʽ,4����ʾģʽ֮һ,�Ƽ�ʹ��5551,4444
 *@return PFont pfont,����fontָ��
 */
PFont create_font_hzk(const char* cname,const char* aname, int height,int disp);

/**
 *��һ���ڴ�buf�ϴ���һ��GBK(hzk)font,Ĭ��ΪGBK�ĵ���
 *@param const char *cfbuf,�����ֿ�bufͨ����GBKxx
 *@param int csize,����buf�Ĵ�С
 *@param const char *afbuf,�����ֿ�cbufͨ����ASCxx
 *@param int asize,����abuf�Ĵ�С
 *@param int height,�߶�,�����ֿ�ΪGBK16,�������16
 *@param int disp,��ʾģʽ,4����ʾģʽ֮һ,�Ƽ�ʹ��5551,4444
 *@return PFont pfont,����fontָ��
 */
PFont create_font_hzk_buf(const char *cfbuf,int csize,const char* afbuf,int asize, int height,int disp);

/**
 *����һ��ttf(freetype)font
 *@param const char* cname,freetype�ļ���
 *@param int height,�߶�����
 *@param int disp,��ʾģʽ,4����ʾģʽ֮һ,�Ƽ�ʹ��8888,4444
 *@return PFont pfont,����fontָ��
 */
PFont create_font_freetype(const char* ttfname, int height,int disp);

/**
 *��һ���ڴ�buf�ϴ���һ��ttf(freetype)font
 *@param const char *cfbuf,freetype���ڴ�buf
 *@param int csize,freetype���ڴ�buf
 *@param int height,�߶�����
 *@param int disp,��ʾģʽ,4����ʾģʽ֮һ,�Ƽ�ʹ��8888,4444
 *@return PFont pfont,����fontָ��
 */
PFont create_font_freetype_buf(const char *cfbuf,int csize, int height,int disp);

/**
 * ��ʾһ���ֵ��ڴ�ͼtextarea,ע�������create_image�����ڴ�ͼtextarea
 *@param PFont pf,����ָ��,��create_font_xxx����
 *@param const char* text,��ʾ������
 *@param int len,��ʾ���ֵĳ���,��strlen����
 *@param image_p textarea,�ڴ�ͼtextarea
 *@param int dx,�������ڴ�ͼ��xλ������
 *@param int dy,�������ڴ�ͼ��yλ������
 *@param int flag,��ʾ��־,Ŀǰֻ��0(����),1(��Ӱ)
 *@return ��
 */
void font_drawtext(PFont pf,const char* text,int len,image_p textarea,int dx,int dy,int flags);
/**
 *�������������
 *@param PFont pf,����ָ��
 *@param int attr,����ֵ
 *@param int setflag,��Ҫ���õ����Ա�־
 *@return ��
 */
void font_setattr(PFont pf,int attr,int setflag);
/**
 *�ͷ�һ������
 *@param PFont pf,���ͷŵ�����ָ��
 *@return ��
 */
void font_destory(PFont pf);
/**
 *����������ɫ
 *@param PFont pf,����ָ��
 *@param uint32 color,������ɫ����ɫֵ�뽨�������dtype��Ӧ,���罨����16λ5551,�������MAKE_RGBA5551����
 *@return int,��һ����ɫ
 */
int font_setcolor(PFont pf,uint32 color);
/**
 *��ǿ������������ɫ,��֧�ֶ���
 *@param PFont pf,����ָ��
 *@param uint32 color_fg,ǰ��ɫ(������ɫ)����ɫֵ�뽨�������dtype��Ӧ,���罨����16λ5551,�������MAKE_RGBA5551����
 *@param uint32 color_bg,����ɫ����ɫֵ�뽨�������dtype��Ӧ
 *@param uint32 color_sh,������Ӱɫ����ɫֵ�뽨�������dtype��Ӧ
 *@return int,��
 */
void font_setcolor_ex(PFont pfont, uint32 color_fg,uint32 color_bg ,uint32 color_sh );
/**
 *�õ�һ�����ֵķ�Χ
 *@param PFont pf,����ָ��
 *@param const void *text,����ָ��
 *@param int cc,���ֳ���
 *@param int *pwidth  ��
 *@param int *pheight ��
 *@param int *pbase   ����
 *@return
 */
void font_textsize(PFont pfont, const void *text, int cc,int *pwidth, int *pheight,int *pbase);


PFont create_font_nfont_buf(const char *nfbuf,int nsize,int disp);
PFont create_font_nfont(const char* name,int disp);

#ifdef __cplusplus
}
#endif


#endif
