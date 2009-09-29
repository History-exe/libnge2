#ifndef NGE_SYS_COMPATIBLE_H_
#define NGE_SYS_COMPATIBLE_H_
#include "nge_define.h"
#if defined WIN32 || defined IPHONEOS
typedef struct st_tm{
	uint16  year;
	uint16  month; 
	uint16  day; 
	uint16  hour; 
	uint16  minutes; 
	uint16  seconds; 
	uint32  microseconds; 
}sys_time_t,*sys_time_p;
#else
//psp
#include <psprtc.h>
typedef pspTime  sys_time_t;
typedef pspTime*  sys_time_p;
#endif



#ifdef __cplusplus
extern "C"{
#endif
/**
 *��ȡϵͳ�ı���ʱ��
 *@param sys_time_p tm,ϵͳʱ��ṹ
 *@return int,�ɹ�����1,ʧ�ܷ���0
 */
int sys_localtime(sys_time_p tm);

#ifdef __cplusplus
}
#endif


#endif