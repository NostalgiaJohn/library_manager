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

    while (true) {
        std::cout << "��������ݣ�";
        std::cin >> tmp_YY;

        if (!std::cin) {
			std::cout << "���������֣�\n\n";			     // �����ʾ
			std::cin.clear();								// ���std::cin�쳣ָʾ
			std::cin.ignore(500, '\n');						// ������뻺����
			continue;										// ���¿�ʼ����ѭ��

        } else if ((tmp_YY <= 0) || (tmp_YY - (int)tmp_YY != 0)) { // �����벻��������ʱ
			std::cout << "��������������\n\n";			     // �����ʾ
			std::cin.ignore(500, '\n');						// ������뻺����
			continue;										// ���¿�ʼ����ѭ��

		} else{											    // ��������ܽ�����Ϸ�ʱ
            break;
		}
    }
    while (true) {
        std::cout << "�������·ݣ�";
        std::cin >> tmp_MM;

        if (!std::cin) {
			std::cout << "���������֣�\n\n";			     // �����ʾ
			std::cin.clear();								// ���std::cin�쳣ָʾ
			std::cin.ignore(500, '\n');						// ������뻺����
			continue;										// ���¿�ʼ����ѭ��

        } else if ((tmp_MM <= 0) || (tmp_MM - (int)tmp_MM != 0)) { // �����벻��������ʱ
			std::cout << "��������������\n\n";			     // �����ʾ
			std::cin.ignore(500, '\n');						// ������뻺����
			continue;										// ���¿�ʼ����ѭ��

		} else{											    // ��������ܽ�����Ϸ�ʱ
            break;
		}
    }
    while (true) {
        std::cout << "���������ڣ�";
        std::cin >> tmp_DD;

        if (!std::cin) {
			std::cout << "���������֣�\n\n";			     // �����ʾ
			std::cin.clear();								// ���std::cin�쳣ָʾ
			std::cin.ignore(500, '\n');						// ������뻺����
			continue;										// ���¿�ʼ����ѭ��

        } else if ((tmp_DD <= 0) || (tmp_DD - (int)tmp_DD != 0)) { // �����벻��������ʱ
			std::cout << "��������������\n\n";			     // �����ʾ
			std::cin.ignore(500, '\n');						// ������뻺����
			continue;										// ���¿�ʼ����ѭ��

		} else{											    // ��������ܽ�����Ϸ�ʱ
            break;
		}
    }

    Time r_time = {.YY = std::to_string(tmp_YY),
                   .MM = std::to_string(tmp_MM),
                   .DD = std::to_string(tmp_DD)};

    return r_time;
}
