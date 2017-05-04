#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm> 

//структура для модификации элементов через transform
struct transform_functor 
{
    transform_functor(double half_neg_sum) : half_neg_sum(half_neg_sum) {}
    double operator()(double x) { return half_neg_sum + x; }

private:
    double half_neg_sum;
};

//структура для модификации через for_each
struct foreach_functor 
{
    foreach_functor(double half_neg_sum) : half_neg_sum(half_neg_sum) {}
    void operator()(double &x) { x = half_neg_sum + x; }

private:
    double half_neg_sum;
};

//поиск суммы всех отрицательных чисел
double get_neg_sum(std::vector<double>::iterator first, std::vector<double>::iterator last);

//модификация контейнера
void modify(std::vector<double>& v);

//модификация части контейнера
void modify(std::vector<double>& v, std::vector<double>::iterator first, std::vector<double>::iterator last);

//функция для модификации через transform
void modify_transform(std::vector<double>& v);

//функция для модификации через for_each
void modify_foreach(std::vector<double>& v);

//функция суммирования контейнера
double sum_container(std::vector<double> v);

//вычисление среднего арифмитического контейнера
double avg_container(std::vector<double> v);

//функция для демонстрации контейнера
void show_container(std::vector<double> v);