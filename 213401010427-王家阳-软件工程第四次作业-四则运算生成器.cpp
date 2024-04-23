#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<iostream>
using namespace std;
// ����20���ڵļӷ����������ʽ
void generateGrade1Exercise(int count) {
    int a, b, result;
    char operator1;
    for (int i = 0; i < count; i++) {
        a = rand() % 20;
        b = rand() % 20;
        operator1 = rand() % 2 == 0 ? '+' : '-';
        if (operator1 == '+'){
            result = a + b;
        }
        else {
            result = a - b;
        }
        printf("%d %c %d = \n", a, operator1, b);
    }
}

// ����50���ڵļӼ����������ʽ
void generateGrade2Exercise(int count) {
    int a, b, result;
    char operator1;
    for (int i = 0; i < count; i++) {
        a = rand() % 50;
        b = rand() % 50;
        operator1 = rand() % 2 == 0 ? '+' : '-';
        if (operator1 == '+') {
            result = a + b;
        }
        else {
            result = a - b;
        }
        printf("%d %c %d = \n", a, operator1, b);
    }
}

// ����1000���ڵļӼ��˻������ʽ
void generateGrade3Exercise(int count) {
    int a, b, c, result;
    char operator1, operator2;
    for (int i = 0; i < count; i++) {
        a = rand() % 1000;
        b = rand() % 1000;
        c = rand() % 1000;
        operator1 = rand() % 3 == 0 ? '+' : (rand() % 2 == 0 ? '-' : '*');
        operator2 = rand() % 2 == 0 ? '+' : '-';
        if (operator1 == '+') {
            result = a + b;
        }
        else if (operator1 == '-') {
            result = a - b;
        }
        else {
            result = a * b;
        }
        if (operator2 == '+') {
            result += c;
        }
        else {
            result -= c;
        }
        printf("%d %c %d %c %d = \n", a, operator1, b, operator2, c);
    }
}

// ���ɴ����ŵĻ������ʽ
void generateGrade456Exercise(int count) {
    int a, b, c, d, result;
    char operator1, operator2, operator3;
    for (int i = 0; i < count; i++) {
        a = rand() % 100;
        b = rand() % 100;
        c = rand() % 100;
        d = rand() % 100;
        operator1 = rand() % 4;
        operator2 = rand() % 4;
        operator3 = rand() % 4;
        if (operator1 == 3) { // ��������Ϊ0
            operator1 = 2;
        }
        if (operator2 == 3) {
            operator2 = 2;
        }
        if (operator3 == 3) {
            operator3 = 2;
        }
        int t1, t2;
        if (operator1 == 2 && operator2 == 1) { // ��������ͼ���Ϊ����
            t1 = a;
            a = b;
            b = t1;
            t2 = c;
            c = d;
            d = t2;
        }
        else if (operator2 == 2 && operator3 == 1) {
            t1 = b;
            b = c;
            c = t1;
            t2 = d;
            d = rand() % (b - c + 1);
            c += t2 - d;
        }
        if (operator1 == 0) { // ��һ�������Ϊ�Ӻ�
            result = a + b;
        }
        else if (operator1 == 1) { // ��һ�������Ϊ����
            result = a - b;
        }
        else if (operator1 == 2) { // ��һ�������Ϊ�˺�
            result = a * b;
        }
        else { // ��һ�������Ϊ����
            result = a / b;
        }
        if (operator2 == 0) { // �ڶ��������Ϊ�Ӻ�
            result += c;
        }
        else if (operator2 == 1) { // �ڶ��������Ϊ����
            result -= c;
        }
        else if (operator2 == 2) { // �ڶ��������Ϊ�˺�
            result *= c;
        }
        else { // �ڶ��������Ϊ����
            result /= c;
        }
        if (operator3 == 0) { // �����������Ϊ�Ӻ�
            result += d;
        }
        else if (operator3 == 1) { // �����������Ϊ����
            result -= d;
        }
        else if (operator3 == 2) { // �����������Ϊ�˺�
            result *= d;
        }
        else { // �����������Ϊ����
            result /= d;
        }
        printf("(%d %c %d) %c %d %c %d = \n", a, operator1 == 3 ? '/' : (operator1 == 2 ? '*' : operator1 == 1 ? '-' : '+'), b, operator2 == 3 ? '/' : (operator2 == 2 ? '*' : operator2 == 1 ? '-' : '+'), c, operator3 == 3 ? '/' : (operator3 == 2 ? '*' : operator3 == 1 ? '-' : '+'), d);
    }
}

int main() {
    int grade, count;
    srand((unsigned)time(NULL));
    printf("�������꼶����Ŀ�������ÿո��������");
    scanf("%d %d", &grade, &count);
    if (grade == 1) {
        generateGrade1Exercise(count);
    }
    else if (grade == 2) {
        generateGrade2Exercise(count);
    }
    else if (grade == 3) {
        generateGrade3Exercise(count);
    }
    else if (grade >= 4 && grade <= 6) {
        generateGrade456Exercise(count);
    }
    else {
        printf("�����꼶��Ч��\n");
    }
    return 0;
}
