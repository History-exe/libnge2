#ifndef NGE_DIR_IO_H
#define NGE_DIR_IO_H

#if defined _PSP || defined WIN32 || defined __linux__
enum FileFlags{
	FIO_F_DIR,//dir
	FIO_F_FILE//file
};

#define MAX_NAME 256
typedef struct  {
	int    flag;// FileFlags
	char   name[MAX_NAME];// name
}dir_desc_t,*dir_desc_p;

typedef void (*file_travel_cb)(dir_desc_p dir_desc,void* data);

#ifdef __cplusplus
extern "C"{
#endif

/**
 * Ŀ¼�������ʺ���,ֻ֧��Ӣ��·�����ļ���.
 * ע����PSP��ȫСд���ļ�������ȫ����д��ʾ.
 *@param const char* directory, ������Ŀ¼��
 *@param file_travel_cb callback, ���ʻص�����
 *@param void* user_data,�û�����
 *@return int ,����ֵ0,1
 */
int io_dir_travel(const char* directory, file_travel_cb callback,void* user_data);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // PSP || WIN32 || linux
#endif
