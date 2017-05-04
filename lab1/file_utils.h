#pragma once
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> 

//структура для генерации рандомных чисел в диапазоне [-m, m]
struct Random 
{
public:
    Random(int m) { max = m; }
	double operator()() { return double((std::rand()) % (2 * max) - max); };
private:
    int max;
};

//заполнение текстового файла N целыми случайными числами в диапазоне от -M до M (в цикле)
std::fstream& fill_file_with_numbers(int n, int m, std::string filename);

//заполнение текстового файла N целыми случайными числами в диапазоне от -M до M (с использованием алгоритма std::generate)
std::fstream& fill_file_with_numbers_generate(int n, int m, std::string filename);

//заполнение контейнера из файла
std::vector<double>& get_vect_from_file(std::fstream& file);

//получение имени файла
std::string& get_file_name(std::string message);

//получение параметров для заполнения файла
bool get_filling_params(std::string& file_name, int& size, int& max);

//функция вывода вектора в файл (перезапись)
std::fstream& save_vect_to_file(std::vector<double> v, std::string filename);

//функция вывода вектора в файл (добавление)
void add_vect_to_file(std::vector<double> v, std::fstream& file);