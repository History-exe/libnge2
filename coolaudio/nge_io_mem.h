#ifndef NGE_IO_MEM_H_
#define NGE_IO_MEM_H_

#define IO_RDONLY 0
#define IO_WRONLY 1
#define IO_APPEND 2


#define IO_SEEK_CUR SEEK_CUR
#define IO_SEEK_END SEEK_END
#define IO_SEEK_SET SEEK_SET

#ifdef __cplusplus
extern "C"{
#endif
	/**
	*��MEM,ע��ȷ��MEM��Ч
	*@param const char*,memָ��
	*@param int,size
	*@param int,�򿪱�־(IO_RDONLY,IO_WRONLY,IO_APPEND��һ��)
	*@return int,�ļ����,��д���ô��ļ�������в���
	*/
	int io_mopen(const char* mem,int size,int flag);
	/**
	*��MEM�ļ�,��fread����
	*@param void*,�����ȡ���ݵĻ���
	*@param int,��ȡ����
	*@param int,��ȡ��С
	*@param int,�ļ����
	*@return,ʵ�ʶ�ȡ����
	*/
	int io_mread(void* buffer,int count,int size,int handle);
	/**
	*дMEM�ļ�,��fwrite����
	*@param void*,��д���ݵĻ���
	*@param int,��д�����
	*@param int,��д���С
	*@param int,�ļ����
	*@return,ʵ��д������
	*/
	int io_mwrite(void* buffer,int count,int size,int handle);
	/**
	*�ļ�ָ��ƫ������,��fseek����
	*@param int,�ļ����
	*@param int offset,ƫ����
	*@param int flag,seek��־,IO_SEEK_CUR,IO_SEEK_END,IO_SEEK_SET
	*@return int,����0�ɹ�,-1ʧ��
	*/
	int io_mseek(int handle,int offset,int flag);
	/**
	*��õ�ǰ�ļ�ƫ��ֵ
	*@param int handle,�ļ����
	*@return int,�ļ�ƫ��ֵ
	*/
	int io_mtell(int handle);
	/**
	*�ر�MEM�ļ�
	*@param int handle,�ļ����
	*@return int,-1ʧ��
	*/
	int io_mclose(int handle);
	/**
	*MEM size��С
	*@param int handle,�ļ����
	*@return int,MEM size��С
	*/
	int io_msize(int handle);
	
#ifdef __cplusplus
}
#endif

#endif

