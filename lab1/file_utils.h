#pragma once
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> 

//��������� ��� ��������� ��������� ����� � ��������� [-m, m]
struct Random 
{
public:
    Random(int m) { max = m; }
	double operator()() { return double((std::rand()) % (2 * max) - max); };
private:
    int max;
};

//���������� ���������� ����� N ������ ���������� ������� � ��������� �� -M �� M (� �����)
std::fstream& fill_file_with_numbers(int n, int m, std::string filename);

//���������� ���������� ����� N ������ ���������� ������� � ��������� �� -M �� M (� �������������� ��������� std::generate)
std::fstream& fill_file_with_numbers_generate(int n, int m, std::string filename);

//���������� ���������� �� �����
std::vector<double>& get_vect_from_file(std::fstream& file);

//��������� ����� �����
std::string& get_file_name(std::string message);

//��������� ���������� ��� ���������� �����
bool get_filling_params(std::string& file_name, int& size, int& max);

//������� ������ ������� � ���� (����������)
std::fstream& save_vect_to_file(std::vector<double> v, std::string filename);

//������� ������ ������� � ���� (����������)
void add_vect_to_file(std::vector<double> v, std::fstream& file);