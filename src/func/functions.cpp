Time TimeGetCurrent(void)
{
    static time_t raw_curtime;
    static struct tm *curtime;
    Time r_time;

    time(&raw_curtime);
    curtime = gmtime(&raw_curtime);

    r_time.YY = std::to_string(curtime->tm_year + 1900);
    r_time.MM = std::to_string(curtime->tm_mon + 1);
    r_time.DD = std::to_string(curtime->tm_mday);

    return r_time;
}

Time TimeGetInput(void)
{
    float tmp_YY, tmp_MM, tmp_DD;

    while (1) {
        std::cout << "��������ݣ�";
        std::cin >> tmp_YY;

        if (!std::cin) {
			std::cout << "���������֣�\n\n";			     // �����ʾ
			std::cin.clear();								// ���std::cin�쳣ָʾ
			std::cin.ignore(500, '\n');						// ������뻺����
			continue;										// ���¿�ʼ����ѭ��

        } else if (tmp_YY - (int)tmp_YY != 0) {           // �����벻������ʱ
			std::cout << "������������\n\n";			     // �����ʾ
			std::cin.ignore(500, '\n');						// ������뻺����
			continue;										// ���¿�ʼ����ѭ��

		} else{											    // ��������ܽ�����Ϸ�ʱ
            break;
		}
    }
    while (1) {
        std::cout << "�������·ݣ������� 0 ��ʾ�޸�����Ϣ��";
        std::cin >> tmp_MM;

        if (!std::cin) {
			std::cout << "���������֣�\n\n";			     // �����ʾ
			std::cin.clear();								// ���std::cin�쳣ָʾ
			std::cin.ignore(500, '\n');						// ������뻺����
			continue;										// ���¿�ʼ����ѭ��

        } else if ((tmp_MM < 0) || (tmp_MM - (int)tmp_MM != 0)) { // �����벻��������ʱ
			std::cout << "������Ǹ�������\n\n";			     // �����ʾ
			std::cin.ignore(500, '\n');						// ������뻺����
			continue;										// ���¿�ʼ����ѭ��

		} else{											    // ��������ܽ�����Ϸ�ʱ
            break;
		}
    }
    while (1) {
        std::cout << "���������ڣ������� 0 ��ʾ�޸�����Ϣ��";
        std::cin >> tmp_DD;

        if (!std::cin) {
			std::cout << "���������֣�\n\n";			     // �����ʾ
			std::cin.clear();								// ���std::cin�쳣ָʾ
			std::cin.ignore(500, '\n');						// ������뻺����
			continue;										// ���¿�ʼ����ѭ��

        } else if ((tmp_DD < 0) || (tmp_DD - (int)tmp_DD != 0)) { // �����벻��������ʱ
			std::cout << "������Ǹ�������\n\n";			     // �����ʾ
			std::cin.ignore(500, '\n');						// ������뻺����
			continue;										// ���¿�ʼ����ѭ��

		} else{											    // ��������ܽ�����Ϸ�ʱ
            break;
		}
    }

    Time r_time = {.YY = std::to_string((int)tmp_YY),
                   .MM = std::to_string((int)tmp_MM),
                   .DD = std::to_string((int)tmp_DD)};

    return r_time;
}

std::vector<int> LibraryBookNameSearch(Library lib, std::string bk_name)
{
    std::vector<int> a;
    return a;
}

std::vector<int> LibraryBookISBNSearch(Library lib, std::string ISBN)
{
    std::vector<int> a;
    return a;
}

void LibraryBook_Append_Update_Delete_Director(Library &lib)
{
    std::string bkISBN_input, bkname_input;
    std::vector<int> result_search;

    int mode_flag;
    std::cout << "��ѡ������ģʽ\n"
                  "\t1. ISBN\n"
                  "\t2. ����\n"
                  "$?-";
    std::cin >> mode_flag;

    switch (mode_flag)
    {
    case 1:
        std::cout << "������ISBN:";
        std::cin >> bkISBN_input;
        result_search = LibraryBookISBNSearch(lib, bkISBN_input);
        break;

    case 2:
        std::cout << "����������";
        std::cin >> bkname_input;
        result_search = LibraryBookNameSearch(lib, bkname_input);
        break;

    default:
        break;
    }

    if (result_search.size() == 0) {
        int append_flag;
        std::cout << "ͼ���������ͬ��\n";
        std::cout << "�Ƿ�Ҫ��Ӹ��飿\n"
                      "\t0. ��\n"
                      "\t1. ��\n"
                      "$?-";
        std::cin >> append_flag;

        if (append_flag == 0){
            std::cout << "�˳�\n";
        } else if (lib.book_amount >= BOOK_MAX_NUM) {
            std::cout << "ͼ��ݲ���������\n";
        } else{
            LibraryBook_Append(lib.book_list[lib.book_amount + 1], bkname_input, bkISBN_input);
        }
    } else{
        std::cout << "ͼ���������ͬ��\n";
        LibraryBook_Update_Copy_Delete_Director(lib, result_search);
    }
}

int LibraryBook_Append(Book &bk, std::string bk_name, std::string bk_ISBN)
{
    time_t id;
    time(&id); // ʹ��ʱ�����Ϊ�鱾Ψһʶ����

    if (bk_name.size() != 0) {
        bk.name = bk_name;
        std::cout << "����������\n";

        std::cout << "��������ͼ�����\n$?-";
        std::cin >> bk.classifier;

        std::cout << "\n����������/����Ϣ\n";
        int authors_num;
        std::cout << "���������ߡ���������\n$?-";
        std::cin >> authors_num;

        bk.authors_info_list.resize(authors_num);
        for(int i = 0; i <= authors_num - 1; i++) {
            std::cout << fmt::format("�������{:^3}������/���ߵ�����\n$?-", i+1);
            std::cin >> bk.authors_info_list[i].name;

            std::cout << fmt::format("�������{:^3}������/���ߵ��Ա�0 Ϊ���ԣ�1 ΪŮ�ԣ�\n$?-", i+1);
            std::cin >> bk.authors_info_list[i].gender;

            std::cout << fmt::format("�������{:^3}������/���ߵĹ���\n$?-", i+1);
            std::cin >> bk.authors_info_list[i].nationality;

            std::cout << fmt::format("�������{:^3}������/���������߻������ߣ�0 Ϊ���ߣ�1Ϊ���ߣ�\n$?-", i+1);
            std::cin >> bk.authors_info_list[i].isTranslator;
        }

        std::cout << "\n�������������Ϣ\n";
        std::cout << "������ISBN��\n$?-";
        std::cin >> bk.publish_info.ISBN;

        std::cout << "���������������\n$?-";
        std::cin >> bk.publish_info.press;

        std::cout << "�������������\n";
        bk.publish_info.date = TimeGetInput();

        std::cout << "������۸�\n$?-";
        std::cin >> bk.publish_info.price;

        bk.lend_state_flag = 0;
        bk.lend_history.lend_times = 0;
        bk.identification = std::to_string(id);

    } else{
        std::cout << "����������\n$?-";
        std::cin >> bk.name;

        std::cout << "��������ͼ�����\n$?-";
        std::cin >> bk.classifier;

        std::cout << "\n����������/����Ϣ...\n";
        system("timeout 2");
        int authors_num;
        std::cout << "���������ߡ���������\n$?-";
        std::cin >> authors_num;

        bk.authors_info_list.resize(authors_num);
        for(int i = 0; i <= authors_num - 1; i++) {
            std::cout << fmt::format("\n�������{:^3}������/���ߵ�����\n$?-", i+1);
            std::cin >> bk.authors_info_list[i].name;

            std::cout << fmt::format("�������{:^3}������/���ߵ��Ա�0 Ϊ���ԣ�1 ΪŮ�ԣ�\n$?-", i+1);
            std::cin >> bk.authors_info_list[i].gender;

            std::cout << fmt::format("�������{:^3}������/���ߵĹ���\n$?-", i+1);
            std::cin >> bk.authors_info_list[i].nationality;

            std::cout << fmt::format("�������{:^3}������/���������߻������ߣ�0 Ϊ���ߣ�1Ϊ���ߣ�\n$?-", i+1);
            std::cin >> bk.authors_info_list[i].isTranslator;
        }

        std::cout << "\n�������������Ϣ\n";
        system("timeout 2");

        bk.publish_info.ISBN = bk_ISBN;
        std::cout << "ISBN��������\n";

        std::cout << "���������������\n$?-";
        std::cin >> bk.publish_info.press;

        std::cout << "�������������\n";
        bk.publish_info.date = TimeGetInput();

        std::cout << "������۸�\n$?-";
        std::cin >> bk.publish_info.price;

        bk.lend_state_flag = 0;
        bk.lend_history.lend_times = 0;
        bk.identification = std::to_string(id);
    }

    return 0;
}

void LibraryBook_Update_Copy_Delete_Director(Library &lib, std::vector<int> bk_position)
{

}