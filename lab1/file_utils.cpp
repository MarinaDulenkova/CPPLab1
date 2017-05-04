#include "stdafx.h"
#include "file_utils.h"
#include "help_utils.h"

//���������� ���������� ����� N ������ ���������� ������� � ��������� �� -M �� M (� �����)
std::fstream& fill_file_with_numbers(int n, int m, std::string filename)
{
    srand(time(NULL));
    std::fstream* fout = new std::fstream(filename, std::fstream::in | std::fstream::out | std::fstream::trunc);
    if (fout->is_open()) 
	{
        double random_number;
        for (int i = 1; i <= n; ++i) 
		{
            random_number = double(std::rand() % (2 * m) - m);
            *fout << random_number << std::endl;
        }
    }
    return *fout;
}

/*
//���������� � ������������ ����:
//��������� ��� ��������� ��������� ����� � ��������� [-m, m]
struct Random 
{
public:
    Random(int m) { max = m; }
    double operator()();
private:
    int max;
};

double Random::operator()() 
{
    return double((std::rand()) % (2 * max) - max);
}
*/

//���������� ���������� ����� N ������ ���������� ������� � ��������� �� -M �� M (� �������������� ��������� std::generate)
std::fstream& fill_file_with_numbers_generate(int n, int m, std::string filename)
{
    srand(time(NULL));
    std::fstream* fout = new std::fstream(filename, std::fstream::in | std::fstream::out | std::fstream::trunc);
    if (fout->is_open()) 
	{
        std::vector<double> buf_v(n);
        std::generate(buf_v.begin(), buf_v.end(), Random(m));
        for (std::vector<double>::iterator it = buf_v.begin(); it != buf_v.end(); ++it)
            *fout << *it << std::endl;
    }
    return *fout;
}

//���������� ���������� �� �����
std::vector<double>& get_vect_from_file(std::fstream& file) 
{
    std::vector<double>* v = new std::vector<double>();
    file.clear();
    file.seekg(0);
    if (file.is_open())
    {
        std::string line;
        int num;
        while (!file.eof())
        {
            std::getline(file, line);
            try 
			{
                num = std::stoi(line);
                v->push_back(double(num));
            }
            catch (std::exception e) {}
        }
    }
    return *v;
}

//��������� ����� �����
std::string& get_file_name(std::string message)
{
	std::cout << message << std::endl;
	std::string* file_name = new std::string("");
    std::getline(std::cin, *file_name);
	return *file_name;
}

//��������� ���������� ��� ���������� �����
bool get_filling_params(std::string& file_name, int& size, int& max) 
{
	file_name = get_file_name("������� ��� ����� (���� ���� ����������, �� ����� �����������. ������ ������ - ������.):");
    if (file_name == "") 
	{
        return false;
    }
    size = -1;
    while ((size < 1) || (size >= INT_MAX)) 
	{
        std::cout << "������� ���������� �����:" << std::endl;
        get_num(1, INT_MAX, size);
    }
    max = -1;
    while ((max < 1) || (max >= INT_MAX)) 
	{
        std::cout << "������� ������ ������� ��� ��������� �����:" << std::endl;
        get_num(1, INT_MAX, max);
    }
    return true;
}

//������� ������ ������� � ���� (����������)
std::fstream& save_vect_to_file(std::vector<double> v, std::string filename)
{
	std::fstream *fout = new std::fstream(filename, std::fstream::in | std::fstream::out | std::fstream::trunc);
	if (fout->is_open())
	{
		for (std::vector<double>::iterator it = v.begin(); it != v.end(); ++it)
			*fout << *it << std::endl;
	}
	return *fout;
}

//������� ������ ������� � ���� (����������)
void add_vect_to_file(std::vector<double> v, std::fstream& file)
{
	if (file.is_open())
	{
		for (std::vector<double>::iterator it = v.begin(); it != v.end(); ++it)
			file << *it << std::endl;
	}
}


