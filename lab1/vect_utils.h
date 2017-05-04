#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm> 

//��������� ��� ����������� ��������� ����� transform
struct transform_functor 
{
    transform_functor(double half_neg_sum) : half_neg_sum(half_neg_sum) {}
    double operator()(double x) { return half_neg_sum + x; }

private:
    double half_neg_sum;
};

//��������� ��� ����������� ����� for_each
struct foreach_functor 
{
    foreach_functor(double half_neg_sum) : half_neg_sum(half_neg_sum) {}
    void operator()(double &x) { x = half_neg_sum + x; }

private:
    double half_neg_sum;
};

//����� ����� ���� ������������� �����
double get_neg_sum(std::vector<double>::iterator first, std::vector<double>::iterator last);

//����������� ����������
void modify(std::vector<double>& v);

//����������� ����� ����������
void modify(std::vector<double>& v, std::vector<double>::iterator first, std::vector<double>::iterator last);

//������� ��� ����������� ����� transform
void modify_transform(std::vector<double>& v);

//������� ��� ����������� ����� for_each
void modify_foreach(std::vector<double>& v);

//������� ������������ ����������
double sum_container(std::vector<double> v);

//���������� �������� ��������������� ����������
double avg_container(std::vector<double> v);

//������� ��� ������������ ����������
void show_container(std::vector<double> v);