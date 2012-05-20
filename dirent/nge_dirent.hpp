/***************************************************************************
 *            nge_dirent.hpp
 *
 *  2011/03/25 08:30:03
 *  Copyright  2011  Kun Wang <ifreedom.cn@gmail.com>
 ****************************************************************************/
/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef _NGE_DIRENT_HPP
#define _NGE_DIRENT_HPP

#if defined __linux__ || defined IPHONEOS
#error "Don't support linux and iphone now"
#endif
#include <vector>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

typedef enum
{
	IS_DIR = 0, /*Ŀ¼*/
	IS_FILE 	/*�ļ�==Unknow*/
} file_type;

/*
����ʱ��
�޸�ʱ��
*/
typedef struct
{
	int year;
	int month;
	int day;

	int hour;
	int min;
	int sec;
}file_time;



class DIR
{
private:
	string name;	/*�ļ���: ������ʾ*/
	string path;	/*�ļ�����·�� ������ȫ�ļ��� PSP�Ƕ��ļ���:���ڷ���*/
	int size;		/*�ļ���С:byte*/
	file_type type;	/*�ļ����� [Ŀ¼|�ļ�]*/

	file_time ctime; /*����ʱ��*/
	file_time mtime; /*�޸�ʱ��*/

public:

	DIR()
	{


	}

	DIR(string n,string p,int s,file_type t,file_time ct,file_time mt)
	{
		name=n;
		path=p;
		size=s;
		type=t;

		ctime=ct;
		mtime=mt;
	}

	string getPath()
	{
		return path;
	}

	string getName() const
	{
		return name;
	}

	int getSize() const
	{
		return size;
	}

	file_type getType() const
	{
		return type;
	}

	file_time getCreatTime() const
	{
		return ctime;
	}

	file_time getModityTime() const
	{
		return mtime;
	}
};

class DIRComparatorByName
{
public:
	bool operator()(const DIR& d1,const DIR& d2) const
	{
		return d1.getName() < d2.getName();
	}
};

class DIRComparatorByType
{
public:
	bool operator()(const DIR& d1,const DIR& d2) const
	{
		return d1.getType()<d2.getType();
	}
};

class DIRComparatorBySize
{
public:
	bool operator()(const DIR& d1,const DIR& d2) const
	{
		return d1.getSize()<d2.getSize();
	}
};

class DIRComparatorByCreatTime
{
public:
	bool operator()(const DIR& d1,const DIR& d2) const
	{
		int year =d1.getCreatTime().year-d2.getCreatTime().year;
		int month=d1.getCreatTime().month-d2.getCreatTime().month;
		int day  =d1.getCreatTime().day-d2.getCreatTime().day;

		if(year<0)
		{
			return true;
		}
		else if(year>0)
		{
			return false;
		}
		else
		{
			if(month<0)
			{
				return true;
			}
			else if(month>0)
			{
				return false;
			}
			else
			{
				if(day<0)
				{
					return true;
				}
				else if(day>0)
				{
					return false;
				}
			}
		}

		return false;
	}
};


class DIRComparatorByModityTime
{
public:
	bool operator()(const DIR& d1,const DIR& d2) const
	{
		int year =d1.getModityTime().year-d2.getModityTime().year;
		int month=d1.getModityTime().month-d2.getModityTime().month;
		int day  =d1.getModityTime().day-d2.getModityTime().day;

		if(year<0)
		{
			return true;
		}
		else if(year>0)
		{
			return false;
		}
		else
		{
			if(month<0)
			{
				return true;
			}
			else if(month>0)
			{
				return false;
			}
			else
			{
				if(day<0)
				{
					return true;
				}
				else if(day>0)
				{
					return false;
				}
			}
		}
		return false;
	}
};

class DIR_Sta
{
private:
	string path;
public:
	string getPath()
	{
		return path;
	}
};

class NGEDirent
{
public:
	NGEDirent();
	~NGEDirent();

	//ͨ���෵��
	/**[���ĵ������]--��������Ŀ¼����,��Դ������
	 * Ŀ¼�������ʺ���,֧���С�Ӣ����·�����С�Ӣ�����ļ���.
	 *  ���� 8.3 ���ļ��� (UTF-8) ���ۿ���֧���κα����ļ���
	 * ע����PSP�� �ļ��� ��Сд����仯,���ʲ��ִ�Сд.
	 *@param string directory, ������Ŀ¼��
	 *@param vector<DIR> &dirVec, ���ʻص�Ŀ¼vector
	 ** <vector> dirVec ��̬����ռ䣬
	 ** �������������±꣬ͬʱҲ֧�ֵ���������
	 ** dirVec.begin() == dirVec[0]
	 ** Ŀ¼�ļ����� = dirVec.size()
	 *@return int ,����ֵ-1(����ʧ��), �ļ���
	 */
	int openDirent(string directory);

	//ֱ�ӷ���Ŀ¼�ṹ
	int openDirent(string directory,vector<DIR> &dirVec);

	//[����������]--�������Ŀ¼����,�õ�Ŀ¼�ļ��ܴ�С
	int openDeepDirent(string directory);
	int openDeepDirent(string directory,vector<DIR> &dirVec);

	//�ر�Ŀ¼
	void closeDirent();

	//��ȡĿ¼
	vector<DIR> getDirent()
	{
		return vec;
	}

	//��ȡ��ǰ����Ŀ¼
	string getCurrentPath()
	{
		return currentPath;
	}

	/*�ۺ�����
	* ���� ���������--�ļ�������
	* �Ȱ� �ļ���������[�ļ���>�ļ�]
	* �� �ļ�������
	*
	* [DIR0]
	* [DIR1]
	* [FILE0]
	* [FILE1]
	*/
	void sortDirent();

	//���ļ�������--�������ļ�����
	void sortDirentByName();

	//���ļ���������
	void sortDirentByType();

	//���ļ���С����
	void sortDirentBySize();

	//������ʱ������
	void sortDirentByCreatTime();

	//���޸�ʱ������
	void sortDirentByModityTime();


private:

	vector<DIR> vec;

	string currentPath;
};

#endif /* _NGE_DIRENT_HPP */
