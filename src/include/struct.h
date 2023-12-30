/**
 * @file struct.h
 * @author ChengPu (chengpu@stu.scu.edu.cn)
 * @brief 1. ��ͼ������� char(*)[4] classify_letter
 *                    ��Ϊ std::string classifier
 * @version 0.2
 * @date 2023-12-29
 *
 * @copyright Copyright (c) 2023
 *
**/

#ifndef MY_STRUCT

// ʱ��ṹ��
typedef struct{
    std::string YY, MM, DD;
}Time;

/*-----------------------------------------------------------------------------*/


// ������Ϣ
typedef struct{
    std::string name;
    char nation[3] = {0};     // ʹ��ISO3166-1 alpha-2���ַ������ע����
    unsigned int gender:1;
    unsigned int isTranslator:1;
}AuthorInfo, *AuthorList;

// ������Ϣ
typedef struct{
    std::string press;              // ������
    Time date;                      // ��������
    float price = 0;                // �۸�
}PublishInfo;

// ͼ����
typedef struct{
    std::string ISBN;               // ISBN�ţ�eg��9787020024759��
    int copy;                       // ������
    Time store_date;                // ��������
}BookID;


// ����������ڵ�
typedef struct BorrowerNode{
    std::string borrower_ID;                 // ������ID
    Time lend_date;                       // ����ʱ��

    BorrowerNode* next_ptr = nullptr;
}BorrowerNode, *BorrowerNodePTR;

// �����ʷ
typedef struct{
    int lend_times;                   // �������
    BorrowerNodePTR borrower_list_hPTR;   // ����������ͷָ��
}LendHistory;


// ͼ��ṹ��
typedef struct{
    std::string name;               // ����
    std::string classifier;         // ��ͼ�����
    AuthorList authors_info_list;   // �������߱�����
    PublishInfo publish_info;       // ������Ϣ
    BookID identification;          // ���
                                        /* �����
                                            ��������
                                        */
    int lend_state_flag:3;          // ����״̬��-2��ͼ�����ڣ�-1��ͼ������0: ͼ���ڹݣ�1��ͼ����;��
    LendHistory lend_history;       // �����ʷ
}Book, *BookList, *BookPTR;


// ͼ��ݽṹ��
typedef struct{
    int book_amount;               // ͼ��ݲ�����
    BookList book_list;            // ͼ����鵥
                                        /* Ӧʹ�����齨������0λʹ����Ȼ����1��2��3...��
                                        */
}Library;

/*-----------------------------------------------------------------------------*/
// ��������ڵ�
typedef struct BookNode{
    BookID book_ID;                 // ͼ����
    Time borrow_date;               // ����ʱ��
    int borrow_state_flag:3;        // ����״̬��-2���������ڣ�-1������������0���ѹ黹��1���黹δ�����ڷ��

    BookNode* next_ptr = nullptr;
}BookNode, *BookNodePTR;

// ������ʷ
typedef struct{
    int borrowed_books_acc;                 // �ۼƽ�����
    int borrowed_books_cur;                 // ��ǰ������
    BookNodePTR book_list_hPTR;             // ��������ͷָ��
}BorrowHistory;

// �����߽ṹ��
typedef struct{
    std::string ID;                      // ������ID
    unsigned int gender:1;               // �Ա�
    unsigned int permission_flag:1;      // ����Ȩ�ޣ�0��������飻1����������飩

    BorrowHistory borrow_history;        // ������ʷ
}Borrower, *BorrowerList; // ʹ��������������Ⱥ

typedef struct{
    int borrower_amount;                 // ����������
    BorrowerList borrower_list;          // ����������
                                             /* Ӧʹ��������
                                             */
}Group;

#endif