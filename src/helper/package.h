
/*
 *	2009-04-09
 *	����: �׷�
 *	˵��: ���С����,���ִ���ο���"sijiu"����Ʒ"MpkPackage",���벻ͨ��������NGE2����δ������ȷ,
 *	ֻ��Ҫ��#define __HIDE_PSP_FUNC_��ע��ȥ�������ô���ͨ������,������������򲿷ֹ���ȱʧ
 */
#ifndef _PACKAGE_H_
#define _PACKAGE_H_

#ifdef WIN32
	#include <io.h>
#endif

#include <stdio.h>
#include <string.h>

//#define __HIDE_PSP_FUNC_	// ȥ��ע������������PSP�ú���

typedef struct packDate	{	/* �ļ����������� */
	unsigned char name[64-8];		/* �ļ��� */
	long offset;			/* �ļ�λ�� */
	long size;				/* �ļ���С */
} packDate;

typedef struct packInfo	{	/* �ļ�ͷ */
	int VER;				/* ��汾 */
	int nums;				/* �ļ���Ŀ */
	char info[128-8];		/* �����Ϣ */
} packInfo;

typedef struct packItem	{	/* ���������� */
	packDate date;			/* ���� */
	struct packItem* next;	/* ���� */
}  packItem;

#ifdef __cplusplus
extern "C" {
#endif

	static packInfo* fileInfo = NULL;
	static packItem* fileItem = NULL;
	static packItem* fileItem_temp = NULL;

void packageInit();		// ��ʼ����������ļ�ͷ��ϢΪ0
void packageFini();
void add_fileItem();	// ���һ������,�������ͷΪ������һ��
void del_fileItem();	// ����������β��ɾ��һ������
void add_fileInfo();	// ����һ���ļ�ͷ����,���ܵ��ü���ֻ�ܴ���һ��
void del_fileInfo();	// ɾ���ļ�ͷ����
void save_fileName(const char* filename);
void save_fileSize(const long size);
void save_fileOffset(const int fileID);	// ����Ϣ���浽��ǰ������
void save_fileItem(FILE* fp);	// �������������ݵ��ļ�β��
void save_fileInfo(FILE* fp);	// �����ļ�ͷ���ݵ��ļ�β��
void set_fileInfo(const char* text);
void save_fileAddfile(const char* filename1,const char* filename2);	// �ļ�2��ӵ��ļ�1β��
void save_itemTofile(char* filename,char* filetype);	// ��ѹ�����н�ѹ�ļ�
int get_fileID();		// �õ����������
long get_fileSize(const char* filename);	// �õ�������һ���ļ��Ĵ�С
void printf_allDate();			// ������Ϣ
void* safe_malloc(const long size);
void safe_free(void* p);

#ifndef __HIDE_PSP_FUNC_
/*
 *	����PSP�ú��� -- ���벻ͨ��ʱ��PSP�ú���ȫ��ע�͵�����
 *-------------------------------------------------------------------
 */

/*
 *	����:��ʼ��ϵͳ��������Դ������,�������
 *	const char* filename ��Ҫ���صĴ���ļ�
 *	return �ļ�����ʧ�ܷ���-1,�ɹ������ļ�ָ��fd
 */
int		packInit		(const char* filename);
/*
 *	����:�򿪴���ļ�����Ϊfilename���ļ�,���ɽ����ļ��رղ���
 *			�ļ��رղ�����ϵͳ���,ֻ�ǵ�����õ�ĳ���ļ������ô˺���
 *	{
 *		packInit("DATA.BIN");
 *		int fd = packOpen("image001.jpg");
 *		int size = packSize("image001.jpg");
 *		.....;
 *		packFini();
 *	}
 *	const char* filename ��Ҫ�򿪵��ļ���
 *	return ��ʧ�ܷ���-1,�򿪳ɹ������ļ�ָ��fd
 */
int		packOpen		(const char* filename);
/*
 *	����:�첽�򿪴���ļ�����Ϊfilename���ļ�,����ȡ�����ô˺���,
 *			ʹ�������Ҫ���н����ļ��رղ���,����:
 *	{
 *		packInit("DATA.BIN");
 *		int fd = packOpenAsync("bgmusic.mp3");
 *		int size = packSize("bgmusic.mp3");
 *		.....;
 *		io_fclose(fd);
 *		packFini();
 *	}
 *	const char* filenmae ��Ҫ�򿪵��ļ���
 *	return ��ʧ�ܷ���-1,�򿪳ɹ������ļ�ָ��fd
 */
int		packOpenAsync	(const char* filename);
/*
 *	����:�õ�����ļ�����Ϊfilename���ļ���С
 *	const char* filename ��Ҫ�򿪵��ļ���
 *	return ��ʧ�ܷ���-1,�򿪳ɹ������ļ���С
 */
long	packSize		(const char* filename);
/*
 *	����:�õ�����ļ�����Ϊfilename���ļ�ƫ����
 *	const char* filename ��Ҫ�򿪵��ļ���
 *	return ��ʧ�ܷ���-1,�򿪳ɹ������ļ�ƫ����offset
 */
long	packOffset		(const char* filename);
/*
 *	����:�ر�ϵͳ�������Դ
 *	return ��
 */
void	packFini		(void);

#endif

#ifdef __cplusplus
}
#endif

#endif