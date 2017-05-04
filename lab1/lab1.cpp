// lab1.cpp: главный файл проекта.
//Дуленкова М.А. 2 курс 9 группа
//14. Добавить к каждому числу полусумму всех отрицательных чисел. 
//A. вектор (std::vector)

//1. Функция заполнения текстового файла N целыми случайными числами в диапазоне от -M до M. 
//   Имя файла, N и M поступают на вход функции, файл возвращается функцией как результат (использовать потоки ввода-вывода). 
//   Реализовать два варианта генерации чисел — в цикле и с использованием алгоритма std::generate. 
//2. Функция, получающая файл на вход, и возвращающая последовательный контейнер, заполненный числами из файла. 
//3. Функция modify, выполняющая преобразование полученного контейнера. 
//   На вход функции должен поступать контейнер, в качестве результата функция должна возвращать модифицированный контейнер. 
//4. Перегруженная функция modify, принимающая на вход итераторы начала и конца обрабатываемой части контейнера. 
//5. Функция, реализующая требуемое преобразование с использованием алгоритма std::transform вместо функции modify. 
//6. Функция, реализующая требуемое преобразование с использованием алгоритма std::for_each вместо функции modify. 
//7. Функции, вычисляющие сумму и среднее арифметическое чисел, содержащихся в контейнере. 
//8. Функция вывода результата в файл и на экран (опционально). 


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

//функция для отображения главного меню
void print_menu(std::vector<double> v)
{
    system("cls");
	std::cout << "1. Заполнение текстового файла числами..." << std::endl;
	std::cout << "2. Заполнение контейнера из файла" << std::endl;
	std::cout << "3. Преобразование контейнера..." << std::endl;
	std::cout << "4. Сумма" << std::endl;
	std::cout << "5. Среднее арифметическое" << std::endl;
	std::cout << "6. Вывод контейнера на экран" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "0. Выход" << std::endl;
    if (v.size() == 0) { std::cout << "Внимание, вектор пуст! Некоторые действия недоступны!" << std::endl; }
}

//функция главного меню с возвратом выбора
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

//действие по суммированию контейнера
void sum_container_action(std::vector<double> v) 
{
    system("cls");
    if (v.size() == 0) 
	{
        std::cout << "Контейнер пуст." << std::endl;
    } else 
	{
        show_container(v);
        std::cout << "Сумма чисел в контейнере = " << sum_container(v) << std::endl;
    }
    system("pause");
}

//действие по вычислению среднего арифметического
void avg_container_action(std::vector<double> v) 
{
    system("cls");
    if (v.size() == 0) 
	{
        std::cout << "Контейнер пуст." << std::endl;
    } else 
	{
        show_container(v);
        std::cout << "Среднее арифметическое чисел в контейнере = " << avg_container(v) << std::endl;
    }
    system("pause");
}

//действие для демонстрации контейнера
void show_container_action(std::vector<double> v) 
{
    system("cls");
    if (v.size() == 0) 
	{
        std::cout << "Контейнер пуст!" << std::endl;
    } else 
	{
        show_container(v);
    }
    system("pause");
}

//действие по заполнению файла
void fill_file_action() 
{
    system("cls");
    std::cout << "Выберите один из пунктов меню:" << std::endl;
    std::cout << "1. Генерация файла через цикл" << std::endl;
    std::cout << "2. Генерация файла через generate" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
    std::cout << "0. Назад" << std::endl;
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

//действие по заполнению контейнера
void fill_container_action(std::vector<double>& v) 
{
    if (file_name == "") 
	{
		file_name = get_file_name("Введите имя файла (Пустая строка - отмена.):");
        if (file_name == "") {return;}
        file = new std::fstream(file_name, std::fstream::in | std::fstream::out);
		if (!file->is_open())
		{
			std::cout << "Файл не может быть открыт." << std::endl;
			system("pause");
			return;
		}
    }
    if (v.size() != 0) { v.clear(); }
    v = get_vect_from_file(*file);
	file->close();
	file_name = "";
}

//вывод результата с выбором
void show_result(std::vector<double> v, std::vector<double> modified_v)
{
	std::cout<< "Вывести результат:" << std::endl;
	std::cout<< "1. На экран" << std::endl;
	std::cout<< "2. В файл" << std::endl;
	int option = -1;
    while ((option < 1) || (option > 2)) 
	{
        get_num(1, 2, option);
    }
	switch (option)
	{
	case 1:
		{
			std::cout << "Контейнер до модификации:" << std::endl;
			show_container(v);
			std::cout << "Контейнер после модификации:" << std::endl;
			show_container(modified_v);
			break;
		}
	case 2:
		{
			if (file_name == "")
			{
				file_name = get_file_name("Введите имя файла (Если файл существует, он будет перезаписан. Пустая строка - отмена.):");
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

//действие по модификации контейнера
void modify_container_action(std::vector<double> v) 
{
    system("cls");
    std::cout << "Выберите один из пунктов меню:" << std::endl;
    std::cout << "1. Модификация полная" << std::endl;
    std::cout << "2. Модификация частичная" << std::endl;
    std::cout << "3. Модификация с пом. transform (полная)" << std::endl;
    std::cout << "4. Модификация с пом. for_each (полная)" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
    std::cout << "0. Назад" << std::endl;
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
					std::cout << "Введите позицию начала изменения от 1 до " + int_to_str(size) << std::endl;
					get_num(1, size, begin);
				}
            
				int end = -1;
				while ((end < begin) || (end > size)) 
				{
					std::cout << "Введите позицию конца изменения от " + int_to_str(begin) + " до " + int_to_str(size) << std::endl;
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

//выполнение пунктов меню
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
