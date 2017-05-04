#pragma once
#include <string>
#include <iostream>
#include <sstream>

//функция для вывода сообщений
void print_message(std::string msg);

//перевод Int To Str
std::string int_to_str(int num);

//функция получения одного из вариантов между min и max
void get_num(int min, int max, int& number);