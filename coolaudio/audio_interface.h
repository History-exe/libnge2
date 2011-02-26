#ifndef AUDIO_INTERFACE_H_
#define AUDIO_INTERFACE_H_


// lib = libLSAudio.a

#define AUDIO_SEEK_SET	0
#define AUDIO_SEEK_CUR	1
#define	AUDIO_SEEK_END	2

/*
 * ���ļ�������audio�Ĺ����ӿ�
 */
struct audio_play;
/**
 *���ļ�����һ��audio�ļ����ڴ�
 */
typedef int (*fd_load) (struct audio_play* This,const char* filename);
/**
 *���ڴ����һ��audio�ļ����ڴ�
 */
typedef int (*fd_load_buf) (struct audio_play* This,const char* buf,int size);
/**
 *���ļ�ָ�����һ��audio�ļ����ڴ�
 */
typedef int (*fd_load_fp) (struct audio_play* This,int handle,char closed_by_me);

/**
 *����һ������
 *times=0Ϊѭ�����ţ�time=n�Ͳ��ż��Σ�������ɺ�
 *����ĩβ(eof()==true)���ȴ������ͷ��ڴ棬�����ٴε���rewind����ͷ����seek��ĳ����ʼ��Ȼ��play���ţ����ߵ���stop�ͷ��ڴ棩��
 *free_when_stop�ǲ�����Ϻ��Ƿ��ͷ��ڴ棨�����Ҫ�����ڲ�����Чʹ�ã���
 */
typedef int (*fd_play) (struct audio_play* This,int times,int free_when_stop);
/**
 * ���ŵļ򻯰棬�ȼ���fd_play(This,1,1),���ڲ�����Ч;
 */
typedef int (*fd_playstop) (struct audio_play* This);

//��ͣ����һ������,��resume���Իָ���
typedef void (*fd_pause) (struct audio_play* This);

//ֹͣ�������ͷ��ڴ����Դ��ֻ���ٴ�load�������¼���������
typedef int (*fd_stop) (struct audio_play* This);

//�ָ�����һ��pause��������
typedef void (*fd_resume)(struct audio_play* This);


//��������
typedef int (*fd_volume) (struct audio_play* This,int volume);



//�ص�������ͷ��ͬ��seek(this,0,SEEK_BEGIN);
typedef void (*fd_rewind)(struct audio_play* This);

//ms�������flag��ʱ�䵥λΪms��flag��Begin��end�����磺
//seek(this,0,Begin);���ǻص���ͷ���ȼ���rewind��
typedef void (*fd_seek) (struct audio_play* This,int ms,int flag);

//�ж��������Ƿ񵽴�����β��
typedef int (*fd_iseof) (struct audio_play* This);
//�ж��������Ƿ���ͣ��
typedef int (*fd_ispaused)(struct audio_play* This);

//�ͷź������ͷ�����������Ĺ�����Դ
//����player����.�Ժ��player������ʹ����,
//player��Ϊһ����Чָ�룬Ҫ��ʹ�ñ�������create
typedef int (*fd_destroy)(struct audio_play* This);
/*
 * �ⲿ�ӿ�.
 */
typedef struct audio_play{
	fd_load       load;
	fd_load_fp    load_fp;
	fd_load_buf   load_buf;
	fd_play       play;
	fd_playstop   playstop;
	fd_pause      pause;
	fd_stop       stop;
	fd_resume     resume;
	fd_volume     volume;
	fd_rewind     rewind;
	fd_seek       seek;
	fd_iseof      iseof;
	fd_ispaused   ispaused;
	fd_destroy    destroy;
}audio_play_t,*audio_play_p;

//the interface
#ifdef __cplusplus
extern "C"{
#endif
//init and finish
void CoolAudioDefaultInit();
void CoolAudioDefaultFini();

//MP3
audio_play_p CreateMp3Player();
//wav
audio_play_p CreateWavPlayer();
//ogg
audio_play_p CreateOggPlayer();

#ifdef __cplusplus
}
#endif



#endif

