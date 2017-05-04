#include "stdafx.h"
#include "vect_utils.h"

//вычисление суммы всех отрицательных чисел
double get_neg_sum(std::vector<double>::iterator first, std::vector<double>::iterator last)
{
	if (first == last) throw "Вектор пуст";

	double sum = 0;
	for (std::vector<double>::iterator it = first; it != last; ++it)
	{
		if (*it < 0) sum += *it;
	}
	return sum;
}

//модификация контейнера
void modify(std::vector<double>& v) 
{
    double half_neg_sum = get_neg_sum(v.begin(), v.end()) / 2;
    if (half_neg_sum == 0) 
	{ 
		throw std::exception("В контейнере нет отрицательных чисел."); 
	}
    for (std::vector<double>::iterator it = v.begin(); it != v.end(); ++it) 
	{
        *it = *it + half_neg_sum;
    }
}

//модификация части контейнера
void modify(std::vector<double>& v, std::vector<double>::iterator first, std::vector<double>::iterator last) 
{
    double half_neg_sum = get_neg_sum(first, last) / 2;
    if (half_neg_sum == 0) 
	{ 
		throw std::exception("В контейнере нет отрицательных чисел."); 
	}
    for (std::vector<double>::iterator it = first; it != last; ++it) 
	{
        *it = *it + half_neg_sum;
    }
}

//модификации через transform
void modify_transform(std::vector<double>& v) 
{
    double half_neg_sum = get_neg_sum(v.begin(), v.end()) / 2;
    if (half_neg_sum == 0) 
	{ 
		throw std::exception("В контейнере нет отрицательных чисел."); 
	}
    std::transform(v.begin(), v.end(), v.begin(), transform_functor(half_neg_sum));
}

//модификации через for_each
void modify_foreach(std::vector<double>& v) 
{
    double half_neg_sum = get_neg_sum(v.begin(), v.end()) / 2;
    if (half_neg_sum == 0) 
	{ 
		throw std::exception("В контейнере нет отрицательных чисел."); 
	}
    std::for_each(v.begin(), v.end(), foreach_functor(half_neg_sum));
}

//функция суммирования контейнера
double sum_container(std::vector<double> v) 
{
    double sum = 0;
    std::vector<double>::iterator it = v.begin();
    while (it != v.end()) 
	{
        sum += *it;
        ++it;
    }
    return sum;
}

//вычисление среднего арифмитического контейнера
double avg_container(std::vector<double> v) 
{
    double avg = 0;
    if (v.size() != 0) {
        avg = sum_container(v) / v.size();
    }
    return avg;
}

//функция для демонстрации контейнера
void show_container(std::vector<double> v) 
{
    std::vector<double>::iterator it = v.begin();
    while (it != v.end()) 
	{
        if (it != v.begin()) 
		{
            std::cout << ", ";
        }
        std::cout << *it;
        ++it;
    }
    std::cout << std::endl;
}