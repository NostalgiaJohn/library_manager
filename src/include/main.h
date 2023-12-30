#include <ctime>
#include <iostream>
#include <string>
#include <vector>

#include "fmt.h"
#include "struct.h"
#include "macro.h"

/**
 * @brief Get the Time Current object
 *        ��ȡ��ǰʱ�䲢����Time�ṹ��
 * @return Time
 * @assignee CP
**/
Time TimeGetCurrent(void);

/**
 * @brief Get the Time Input object
 *        �ں����л�ȡ�û�������ꡢ�¡���ʱ�䲢����Time�ṹ��
 * @return Time
**/
Time TimeGetInput(void);

/*-----------------------------------------------------------------------------*/

Library LibraryInitialize(void);
/**
 * @brief ��ʼ��������Ⱥ
 *
 * @return Group
**/
Group GroupInitialize(void);

/*-----------------------------------------------------------------------------*/

/**
 * @brief ��ID�����Ƿ���ڸý�����
 *
 * @param gp
 * @param id
 * @return int �����򷵻�1�������ڷ���0
**/
int UserIDSearch(Group &gp, std::string id);

/*-----------------------------------------------------------------------------*/


/**
 * @brief ��BookID����ͼ�飨�Ȳ���ISBN���ٲ��Ҹ����ţ�
 *
 * @param lib
 * @param id
 * @return int �����鵥�е���Ȼλ�ã�1��2��3...��
 *             ʧ�ܷ��س���Ϊ0��vector
**/
std::vector<int> LibraryBookIDSearch(Library lib, BookID id);

/**
 * @brief �����Ʋ���ͼ�飬����vector�����鵥����������������ͼ�����Ȼλ��
 *
 * @param lib
 * @param bk_name
 * @return vector �����鵥�е���Ȼλ�ã�1��2��3...��
 *                ʧ�ܷ��س���Ϊ0��vector
**/
std::vector<int> LibraryBookNameSearch(Library lib, std::string bk_name);

/**
 * @brief ��ISBN����ͼ�飬����vector�����鵥����������������ͼ�����Ȼλ��
 *
 * @param lib
 * @param ISBN
 * @return vector �����鵥�е���Ȼλ�ã�1��2��3...��
 *                ʧ�ܷ��س���Ϊ0��vector
**/
std::vector<int> LibraryBookISBNSearch(Library lib, std::string ISBN);

/*-----------------------------------------------------------------------------*/

/**
 * @brief ¼����޸�ͼ��
 *        �� book_sample != {0} ʱ������¼�룻
 *           book_sample == {0} ʱ�������޸ģ�
 *        ����ǿ�޸Ĳ��ֵķ�����
 *        ע�⣺
 *        û�� book_sample ����ʱ��copy �� 1���������޸�
 *        ���޸Ĳ�������
 * @param book_ptr
 * @param book_sample
 * @return int
**/
int LibraryBook_Append_Update(BookPTR book_ptr, Book book_sample = {0});


/**
 * @brief ���ͼ�鸱��
 *        �� book_sample ���Ƶ� book_ptr ��ָ��λ��
 *        ע�⣺
 *        ���޸ĸ�����
 *        ���޸Ĳ�������
 * @param book_ptr
 * @param book_sample
 * @return int
**/
int LibraryBook_Copy(BookPTR book_ptr, Book book_sample);


/**
 * @brief ͼ��¼�����޸ġ�ɾ����                                  // δ���ǲ������ڣ���Ĭ�ϴ� TimeGetCurrent ����ֵ��ֵ
 *        Ҫ���û�����������ISBN
 *        1. ���鵥�в����ڸ���ʱ��ѯ���Ƿ�Ҫ¼����飬��������ͼ����鵥����ĩβ¼�룻
 *        2. ���鵥�д�  �ڸ���ʱ�����ظ�������ѯ��Ҫ
 *          a. �޸� һ ������       (�Ӻ�������ʱ���ø����ĸ�������1) // ��©�������޸�Ϊ������ͬͼ��ʱ����������Ϊ1
 *          aa.�޸����и�����       (���޸ĸ�����)
 *          b. ɾ�� һ ������       (���޸ĸ�����)
 *          bb.ɾ�����и�����       (���޸ĸ�����)
 *          c. ¼�루���ƣ�һ��������(�������� ԭ������+1)
 *          d. �˳�
 *          �������һ��������ʼ������غ���
 *        ע�⣺
 *        1. ʹ�� ...Search ��������ͼ�飻
 *        2. ʹ�� LibraryBook_Append_Update �����޸ĺ�¼��ͼ�飬
 *           �޸����и���ʱ��ʹ�� LibraryBook_Copy �������׸��޸ĺ��ͼ�鸴�Ƶ���������λ�ã�
 *        3. ʹ�� LibraryBook_Delete ����ɾ��ͼ�顣
 * @param lib
**/
void LibraryBook_Append_Update_Delete_Director(Library &lib);

/*-----------------------------------------------------------------------------*/


/**
 * @brief ͼ����
 *        Ҫ���û�����
 *          1. ID                       // �������������
 *          ʹ�ú��������Ƿ��и���
 *          ���У�
 *              ������Ƿ�߱������ʸ�0��������飩��1����������飩
 *          ��������������޴��ˡ�
 *          2. ����/ISBN
 *          ʹ�ú��������Ƿ��и���
 *          ������vector���Ȳ�Ϊ0���������
 *              ����Ƿ���ʣ��ͼ�飨0��ͼ���ڹݣ���-2��ͼ�����ڣ�-1��ͼ����1��ͼ����;��
 *          ������vector���� Ϊ 0������������޴��顱
 *        �����û��Ƿ��ѽ�����鸱��
 *        ��������һ����������ʱ��������ֵ���������ԭ���˳�������
 *        ���������������㣬�޸ĸ� BookID ��Ӧͼ������ʷ���û�������ʷ������ʱ��� TimeGetCurrent ����ֵ��ֵ������ȷ���죩 // ���ڿ��տ���
 *                        �޸ĸ� BookID ��Ӧͼ�����״̬
 *
 * @param gp
 * @param lib
**/
void UserBookBorrow(Group &gp, Library &lib);

/*-----------------------------------------------------------------------------*/
/**
 * @brief ͼ��黹
 *        Ҫ���û�����
 *          1. ID                       // �������������
 *          ʹ�ú��������Ƿ��и���
 *          ���У�
 *              ����䵱ǰ�������Ƿ�Ϊ0��Ϊ 0 ��������޽����¼�����������
 *          ��������������޴��ˡ�
 *          2. ����/ISBN
 *          ���Ҹ��˽����������Ƿ��и���
 *          ���У�
 *              ���������״̬��-2���������ڣ�-1��������������0���ѹ黹�� // �ݲ��������ڵĴ�������
 *          �����������δ������顱
 *        ����������һ������ʱ���������������ԭ���˳�����
 *        ���������������㣬�޸ĸ� BookID ��Ӧͼ�����״̬��0��ͼ���ڹݣ���
 *                            ���û��ĵ�ǰ��������������ʷ�и� BookID ��Ӧ�Ľ���״̬��0���ѹ黹�� // �ݲ��������ڷ�������
 *
 * @param gp
 * @param lib
**/
void UserBookReturn(Group &gp, Library &lib);



#include "..\func\functions.cpp"