// lab1.cpp: ������� ���� �������.
//��������� �.�. 2 ���� 9 ������
//14. �������� � ������� ����� ��������� ���� ������������� �����. 
//A. ������ (std::vector)

//1. ������� ���������� ���������� ����� N ������ ���������� ������� � ��������� �� -M �� M. 
//   ��� �����, N � M ��������� �� ���� �������, ���� ������������ �������� ��� ��������� (������������ ������ �����-������). 
//   ����������� ��� �������� ��������� ����� � � ����� � � �������������� ��������� std::generate. 
//2. �������, ���������� ���� �� ����, � ������������ ���������������� ���������, ����������� ������� �� �����. 
//3. ������� modify, ����������� �������������� ����������� ����������. 
//   �� ���� ������� ������ ��������� ���������, � �������� ���������� ������� ������ ���������� ���������������� ���������. 
//4. ������������� ������� modify, ����������� �� ���� ��������� ������ � ����� �������������� ����� ����������. 
//5. �������, ����������� ��������� �������������� � �������������� ��������� std::transform ������ ������� modify. 
//6. �������, ����������� ��������� �������������� � �������������� ��������� std::for_each ������ ������� modify. 
//7. �������, ����������� ����� � ������� �������������� �����, ������������ � ����������. 
//8. ������� ������ ���������� � ���� � �� ����� (�����������). 


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "help_utils.h"
#include "file_utils.h"
#include "vect_utils.h"


std::string file_name = "";
std::fstream* file;

//������� ��� ����������� �������� ����
void print_menu(std::vector<double> v)
{
    system("cls");
	std::cout << "1. ���������� ���������� ����� �������..." << std::endl;
	std::cout << "2. ���������� ���������� �� �����" << std::endl;
	std::cout << "3. �������������� ����������..." << std::endl;
	std::cout << "4. �����" << std::endl;
	std::cout << "5. ������� ��������������" << std::endl;
	std::cout << "6. ����� ���������� �� �����" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "0. �����" << std::endl;
    if (v.size() == 0) { std::cout << "��������, ������ ����! ��������� �������� ����������!" << std::endl; }
}

//������� �������� ���� � ��������� ������
int main_menu(std::vector<double> v) 
{
	int option = -1;
	while ((option < 0) || (option > 7))
	{
		print_menu(v);
		get_num(0, 7, option);
	}
	return option;
}

//�������� �� ������������ ����������
void sum_container_action(std::vector<double> v) 
{
    system("cls");
    if (v.size() == 0) 
	{
        std::cout << "��������� ����." << std::endl;
    } else 
	{
        show_container(v);
        std::cout << "����� ����� � ���������� = " << sum_container(v) << std::endl;
    }
    system("pause");
}

//�������� �� ���������� �������� ���������������
void avg_container_action(std::vector<double> v) 
{
    system("cls");
    if (v.size() == 0) 
	{
        std::cout << "��������� ����." << std::endl;
    } else 
	{
        show_container(v);
        std::cout << "������� �������������� ����� � ���������� = " << avg_container(v) << std::endl;
    }
    system("pause");
}

//�������� ��� ������������ ����������
void show_container_action(std::vector<double> v) 
{
    system("cls");
    if (v.size() == 0) 
	{
        std::cout << "��������� ����!" << std::endl;
    } else 
	{
        show_container(v);
    }
    system("pause");
}

//�������� �� ���������� �����
void fill_file_action() 
{
    system("cls");
    std::cout << "�������� ���� �� ������� ����:" << std::endl;
    std::cout << "1. ��������� ����� ����� ����" << std::endl;
    std::cout << "2. ��������� ����� ����� generate" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
    std::cout << "0. �����" << std::endl;
    int option = -1;
    while ((option < 0) || (option > 2)) 
	{
        get_num(0, 2, option);
    }
    switch (option) 
	{
    case 1: 
		{
        system("cls");
        int size = -1, max = -1;
        if (get_filling_params(file_name, size, max)) 
		{
            if (file != NULL) 
			{
                file->close();
            }
            file = &fill_file_with_numbers(size, max, file_name);
        }
        break;
    }
    case 2: 
		{
        system("cls");
        int size = -1, max = -1;
        if (get_filling_params(file_name, size, max)) 
		{
            if (file != NULL) 
			{
                file->close();
            }
            file = &fill_file_with_numbers_generate(size, max, file_name);
        }
        break;
    }
    default: break;
    }
	if (file != NULL) 
	{
		file->close();
	}
	file_name = "";
}

//�������� �� ���������� ����������
void fill_container_action(std::vector<double>& v) 
{
    if (file_name == "") 
	{
		file_name = get_file_name("������� ��� ����� (������ ������ - ������.):");
        if (file_name == "") {return;}
        file = new std::fstream(file_name, std::fstream::in | std::fstream::out);
		if (!file->is_open())
		{
			std::cout << "���� �� ����� ���� ������." << std::endl;
			system("pause");
			return;
		}
    }
    if (v.size() != 0) { v.clear(); }
    v = get_vect_from_file(*file);
	file->close();
	file_name = "";
}

//����� ���������� � �������
void show_result(std::vector<double> v, std::vector<double> modified_v)
{
	std::cout<< "������� ���������:" << std::endl;
	std::cout<< "1. �� �����" << std::endl;
	std::cout<< "2. � ����" << std::endl;
	int option = -1;
    while ((option < 1) || (option > 2)) 
	{
        get_num(1, 2, option);
    }
	switch (option)
	{
	case 1:
		{
			std::cout << "��������� �� �����������:" << std::endl;
			show_container(v);
			std::cout << "��������� ����� �����������:" << std::endl;
			show_container(modified_v);
			break;
		}
	case 2:
		{
			if (file_name == "")
			{
				file_name = get_file_name("������� ��� ����� (���� ���� ����������, �� ����� �����������. ������ ������ - ������.):");
				if (file_name == "") {return;}
				file = &save_vect_to_file(modified_v, file_name);
				file->close();
				file_name = "";
			}
			break;
		}
	default: break;
	}
}

//�������� �� ����������� ����������
void modify_container_action(std::vector<double> v) 
{
    system("cls");
    std::cout << "�������� ���� �� ������� ����:" << std::endl;
    std::cout << "1. ����������� ������" << std::endl;
    std::cout << "2. ����������� ���������" << std::endl;
    std::cout << "3. ����������� � ���. transform (������)" << std::endl;
    std::cout << "4. ����������� � ���. for_each (������)" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
    std::cout << "0. �����" << std::endl;
    int option = -1;
    while ((option < 0) || (option > 4)) 
	{
        get_num(0, 4, option);
    }
    std::vector<double> modified_v(v);
    try {
        switch (option) 
		{
        case 1: 
			{
				modify(modified_v);
				break;
			}
        case 2: 
			{
				int size = modified_v.size();
				int begin = -1;
				while ((begin < 1) || (begin > size)) 
				{
					std::cout << "������� ������� ������ ��������� �� 1 �� " + int_to_str(size) << std::endl;
					get_num(1, size, begin);
				}
            
				int end = -1;
				while ((end < begin) || (end > size)) 
				{
					std::cout << "������� ������� ����� ��������� �� " + int_to_str(begin) + " �� " + int_to_str(size) << std::endl;
					get_num(begin, size, end);
				}
				std::vector<double>::iterator first, last, it = modified_v.begin();
				int i = 1;
				while (i <= end) 
				{
					if (i == begin) { first = it; }
					if (i == end) { last = ++it; }
					++i;
					if (it != modified_v.end()) { ++it; }
				}
				modify(modified_v, first, last);
				break;
			}
        case 3: 
			{
				modify_transform(modified_v);
				break;
			}
        case 4: 
			{
				modify_foreach(modified_v);
				break;
			}
        default: break; 
        }
    }
    catch (std::exception e) 
	{
        std::cout << e.what() << std::endl;
    }
	show_result(v, modified_v);
    system("pause");
}

//���������� ������� ����
void create_menu_actions(int option, std::vector<double>& v) 
{
	switch (option) 
	{
	    case 1: 
			{
				fill_file_action();
				break;
			}
        case 2: 
			{
				fill_container_action(v);
				break;
			}
        case 3: 
			{
				if (v.size() != 0) modify_container_action(v);
				break;
			}
        case 4: 
			{
				if (v.size() != 0) sum_container_action(v);
				break;
			}
        case 5: 
			{
				if (v.size() != 0) avg_container_action(v);
				break;
			}
        case 6: 
			{
				if (v.size() != 0) show_container_action(v);
				break;
			}
        default: break; 
	}
}


int main(array<System::String ^> ^args)
{
    setlocale(LC_ALL, "Russian");
	std::vector<double> v;
    int option = -1;
    while (option != 0) 
	{
        option = main_menu(v);
        create_menu_actions(option, v);
    }
    if (file != NULL) 
	{
        file->close();
    }
    return 0;
}
