/**
 * @file struct.h
 * @author ChengPu (chengpu@stu.scu.edu.cn)
 * @brief 1. ɾ����BookID, ISBN��Ϣ����Publish_Info�ṹ��
 *        2. ���ӵ��鱾Ψһʶ���� ��std::string identification��
 *        3. �� Book �ṹ����������������ڿ���ֱ��ͨ�� std::cout ���Book���ͱ���
 * @version 0.4
 * @date 2023-1-2
 *
 * @copyright Copyright (c) 2023
 *
**/
#ifndef MY_STRUCT
#define MY_STRUCT
// ʱ��ṹ��
typedef struct{
    std::string YY, MM, DD; // ȡ 10000 Ϊ��Чֵ
}Time;

/*-----------------------------------------------------------------------------*/


// ������Ϣ
typedef struct{
    std::string name;
    std::string nationality;     // ʹ��ISO3166-1 alpha-2���ַ������ע����
    unsigned int gender;       // 0 Ϊ���ԣ�1 ΪŮ��
    unsigned int isTranslator; // 0 ��ʾΪ�����ߣ�1 ��ʾΪ����
}AuthorInfo;

// ������Ϣ
typedef struct{
    std::string ISBN;               // ISBN�ţ�eg��9787020024759��
    std::string press;              // ������
    Time date;                      // ��������
    float price = 0;                // �۸�
}PublishInfo;


// ����������ڵ�
typedef struct BorrowerNode{
    std::string borrower_ID;                 // ������ID
    Time lend_date;                       // ����ʱ��

    BorrowerNode* next_ptr = nullptr;
}BorrowerNode, *BorrowerNodePTR;

// �����ʷ
typedef struct{
    int lend_times;                   // �������
    BorrowerNodePTR borrower_list_hPTR = nullptr;   // ����������ͷָ��
}LendHistory;


// ͼ��ṹ��
typedef struct Book{
    std::string name;               // ����
    std::string classifier;    // ��ͼ�����
    std::vector<AuthorInfo> authors_info_list;   // �������߱�����
    PublishInfo publish_info;       // ������Ϣ
    std::string identification;     // Ψһʶ����
                                        /* �����
                                            ��������
                                        */
    int lend_state_flag;          // ����״̬��-2��ͼ�����ڣ�-1��ͼ������0: ͼ���ڹݣ�1��ͼ����;��
    LendHistory lend_history;       // �����ʷ

    friend std::ostream &operator << (std::ostream &o_s, Book &bk)
    {
        o_s << fmt::format("����          ��{:<30}\n"
                           "��ͼ�����    ��{:<10}\n"
                           "��/���ߣ�{:^1}�ˣ���\n", bk.name, bk.classifier, bk.authors_info_list.size());

        int author_total_calc     = 1;
        int translator_total_calc = 1;
        for (int i = 0; i <= bk.authors_info_list.size()-1; i++) {
            o_s << fmt::format("\t{:->6}{:-<3}:\n"
                               "\t\t������{}\n"
                               "\t\t�Ա�{}\n"
                               "\t\t������{}\n", bk.authors_info_list[i].isTranslator
                                                ? "����" : "����"
                                              , bk.authors_info_list[i].isTranslator
                                                ? translator_total_calc : author_total_calc
                                              , bk.authors_info_list[i].name
                                              , bk.authors_info_list[i].gender ? "Ů" : "��"
                                              , bk.authors_info_list[i].nationality);
            bk.authors_info_list[i].isTranslator ? translator_total_calc++ : author_total_calc++;
        }

        o_s << fmt::format("������  ��{}\n"
                           "�������ڣ�{}/{}/{}\n"
                           "�۸�    ��{:<.2f}\n", bk.publish_info.press
                                          , bk.publish_info.date.YY
                                          , bk.publish_info.date.MM == (std::string)"0" ? "N.A." : bk.publish_info.date.MM
                                          , bk.publish_info.date.DD == (std::string)"0" ? "N.A." : bk.publish_info.date.DD
                                          , bk.publish_info.price);

        o_s << fmt::format("ͼ��Ψһʶ���룺{}\n", bk.identification);
        o_s << fmt::format("ͼ�����״̬  ��{}\n", bk.lend_state_flag);
        o_s << fmt::format("���Ĵ���      ��{}\n", bk.lend_history.lend_times);
        return o_s;
    }
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
    std::string book_ID;            // ͼ��Ψһʶ����
    Time borrow_date;               // ����ʱ��
    int borrow_state_flag;        // ����״̬��-2���������ڣ�-1������������0���ѹ黹��1���黹δ�����ڷ��

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
    unsigned int gender;               // �Ա�
    unsigned int permission_flag;      // ����Ȩ�ޣ�0��������飻1����������飩

    BorrowHistory borrow_history;        // ������ʷ
}Borrower, *BorrowerList; // ʹ��������������Ⱥ

typedef struct{
    int borrower_amount;                 // ����������
    BorrowerList borrower_list;          // ����������
                                             /* Ӧʹ��������
                                             */
}Group;

#endif