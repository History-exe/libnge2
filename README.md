NGE2
====

NGE2(Not a Game Engine�ĵݹ���д)��NGE��һ��ԭΪ�����й�����PSP��д���ڶ���õ��˸�ȫ���ǿ����
��PSP/Windows/iPhone/Linux/android������һ������⣬��Ƶĳ��Բ���һ����Ϸ���棬���˼���Ǽ����ã�
������������ʾ���������Ϸ���棬NGE2׷��������ܣ�����ȫ���õ�c����д������ʾ����Ҳ��Ϊ��������Ҫ��
�ṩ��ͬ����ʾ������ 
NGE2���������ƾ����ÿ�����Ա����Ҫ��PSP���Ծ��ܿ�����PSP��Ӧ�ó��򡣺�����������IOS��Android��
����˵��Windows/linux�µ��ԣ���PSP/iphone/android�����У���󽵵���PSP/iphone/android���Գ����˷ѵ�ʱ�䡣
NGE2 v2.1����BSD���֤��

�ص�:
---------
* ֧��16λ��RGBA5650 RGBA5551 RGBA4444��/32λ(RGBA_8888)��ʾ��
* ֧��JPG,BMP(24,32λ),PNG,TGA��24,32λ��ͼƬ��ȡ����ת����������ʾģʽ��
* ֧��HZK��GBK�������壬FreeType������ʾ��
* ֧�ָ�Ч��ͼƬ������ת��alpha��ɫЧ����
* ������ʾ�������ṩ��ͬ�����ܡ�
* ֱ�ߣ����Σ������Σ�Բ�εȼ���ͼ�εĻ��ơ�
* ��Ƶ֧�֣����ڲ���������mp3��wav������չ��
* ����֧�֣����ڲ��Ŷ�����֧��gif��
* ֧��HGE�����ӿ⡣
* J2ME�Ŀ������ܺ��������֣�֧��ͼ��ü�SetClip����ͼ����DrawRegion��
* �ṩӲ������ͼƬ��ͼƬ����image_to_image��

��ҳ:
----------
http://www.iacger.com/

��װ
---------

NGE2ʹ�� CMake ���й�����
��windows���Ƽ�ʹ��cmake-gui������VS200x�Ĺ����ļ�����롣
Ŀǰ��ͨ�� Windows��linux ��android �� PSP ƽ̨�Ĺ����ļ������ɺͱ��롣iOsƽ̨Ŀǰ��Ҫ�����ֶ�����xCoder���̡�
����UNIXƽ̨�£�psp��android��linux���Ƽ�ʹ����Ŀ��Ŀ¼���ṩ��
�ű�������

PSP:
./script/make-psp.sh

linux:
./script/make-linux.sh

android:
./script/make-android.sh

����ϸ���÷���ͨ��--helpѡ��鿴������

./script/make-android.sh --help

�����ȱʧ���κ�������CMake �Ὣ��ָ����������ڰ�װ�������������������Ȼ������Ҫ��ɾ�� `CMakeCache.txt` �ļ���

cache���޸ģ�
�� Unix/Mac ƽ̨�ϣ������ʹ�� `ccmake` ͼ��ʽ�趨����Ҫ��ѡ�
�� windows �ϣ������ʹ�� `cmake-gui` (�������ʹ��cmake-gui��������G֮)��

Windowsƽ̨�ı������̣�
1 ��װVS2003�������ϰ汾��
2 ʹ��git����libnge2��Դ���롣
3 ����Win32Depends.7z(https://github.com/downloads/ifreedom/libnge2/Win32Depends.7z)���ѹ��libnge2�ĸ�Ŀ¼��
4 �������ӵ���Դ�ļ�res.7z(https://github.com/downloads/ifreedom/libnge2/res.7z)���ѹ�ŵ�sampleĿ¼�¡�
5 ʹ��CMake-guiѡ��libnge2��Ŀ¼����һ��vs2003���̡�
6 ��CMake-gui���ɵĹ��̱��뼴�ɡ�

Androidƽ̨�ı������̣�
NGE2���õ���NDK��ʽ��������Ҫ�NDK�Ŀ���������������ubuntu��Ϊʵ����
1 ����NDK,д���ĵ�ʱ���µ�Ϊandroid-ndk-r8b������������汾Ϊ������ѹ��Ŀ¼�������õ�ǰ�û���homeĿ¼(��~/Ŀ¼)��
2 ���������նˣ�����NDK�Ļ�������export ANDROID_NDK=~/android-ndk-r8b��
3 ʹ��git����libnge2��ѹ��
4 ����[AndroidDepends.7z](https://github.com/downloads/ifreedom/libnge2/AndroidDepends.7z)��ѹ��libnge2�ĸ�Ŀ¼��
5 �������ӵ���Դ�ļ�res.7z(https://github.com/downloads/ifreedom/libnge2/res.7z)���ѹ�ŵ�sampleĿ¼�¡�
6 �������ն˽���libnge2��Ŀ¼�£�������ִ��./script/make-android.sh

������κ����ʣ����Ե����۰棺
http://www.iacger.com/forum.php?mod=forumdisplay&fid=180

����
---------
�����ֱ�����������Ǵ���õ�ѹ������ѹ����Ŀ��Ŀ¼���ɡ�
* [Win32Depends.7z](https://github.com/downloads/ifreedom/libnge2/Win32Depends.7z)
* [AndroidDepends.7z](https://github.com/downloads/ifreedom/libnge2/AndroidDepends.7z)

NGE2ʹ�õĿ�����
----------
* zlib
Simple data compression library
http://www.zlib.net

* libjpeg
Library for JPEG image compression
http://sourceforge.net/projects/libjpeg

* libpng
Official PNG reference library
http://www.libpng.org/pub/png/libpng.html

* giflib
A library for processing GIF
http://sourceforge.net/projects/giflib

* freetype
Portable font engine
http://www.freetype.org

* OpenGL (need on win32 and linux)
OpenGL render system
http://www.opengl.org/

* Gstreamer (need on linux)
Open source multimedia framework
http://gstreamer.freedesktop.org/

* sqlite3 (need for demo5)
a self-contained, serverless, zero-configuration, transactional SQL database engine
http://www.sqlite.org/

* unzip (need for demo9)
a library to uncompress .zip files
on linux, you can download it from download page.

���� PSP SDK - ����PSP��
---------------
�Ƽ���
minpspw(pspsdk)(http://sourceforge.net/projects/minpspw/)

�����ư汾���ص�ַ��δ���£���

* [linux (ubuntu 32bit)](http://sourceforge.net/projects/minpspw/files/SDK%20%2B%20devpak/pspsdk%200.11.1/minpspw_0.11.1-1ubuntu0_i386.deb/download)

* [linux (ubuntu 64bit)](http://sourceforge.net/projects/minpspw/files/SDK%20%2B%20devpak/pspsdk%200.11.1/minpspw_0.11.1-1ubuntu0_amd64.deb/download)

* [linux (rpm 32bit)](http://sourceforge.net/projects/minpspw/files/SDK%20%2B%20devpak/pspsdk%200.11.1/minpspw-pspsdk-0.11.1-1.i386.rpm/download)

* [linux (rpm 64bit)](http://sourceforge.net/projects/minpspw/files/SDK%20%2B%20devpak/pspsdk%200.11.1/minpspw-pspsdk-0.11.1-1.x86_64.rpm/download)

* [windows (32bit)](http://sourceforge.net/projects/minpspw/files/SDK%20%2B%20devpak/pspsdk%200.11.1/pspsdk-setup-0.11.1.exe/download)

* [Mac](http://sourceforge.net/projects/minpspw/files/SDK%20%2B%20devpak/pspsdk%200.11.1/MinPSP%200.11%20Mac.mpkg/download)
