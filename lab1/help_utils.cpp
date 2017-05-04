#include "stdafx.h"
#include "help_utils.h"


//������� ��� ������ ���������
void print_message(std::string msg)
{
    std::cout << msg << std::endl;
    system("pause");
}

//������� Int � String
std::string int_to_str(int num)
{
    std::stringstream ss;
    ss << num;
    return ss.str();
}

//������� ��������� number � ��������� [min, max]
void get_num(int min, int max, int& number) {
    std::string choice = "";
    try {
        std::getline(std::cin, choice);
        number = std::stoi(choice);
        if ((number < min) || (number > max))
        {
            print_message("�� ������ ������ ����� �� " + int_to_str(min) + " �� " + int_to_str(max) + "!");
        }
    }
    catch (std::invalid_argument e)
    {
        print_message("�� ������ ������ �����!");
    }
    catch (std::out_of_range e)
    {
        print_message("����� �� ������� ����!");
    }
}