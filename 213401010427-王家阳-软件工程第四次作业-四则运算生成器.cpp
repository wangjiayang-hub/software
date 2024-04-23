#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<iostream>
using namespace std;
// 生成20以内的加法或减法运算式
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

// 生成50以内的加减法混合运算式
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

// 生成1000以内的加减乘混合运算式
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

// 生成带括号的混合运算式
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
        if (operator1 == 3) { // 除数不能为0
            operator1 = 2;
        }
        if (operator2 == 3) {
            operator2 = 2;
        }
        if (operator3 == 3) {
            operator3 = 2;
        }
        int t1, t2;
        if (operator1 == 2 && operator2 == 1) { // 避免除数和减数为负数
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
        if (operator1 == 0) { // 第一个运算符为加号
            result = a + b;
        }
        else if (operator1 == 1) { // 第一个运算符为减号
            result = a - b;
        }
        else if (operator1 == 2) { // 第一个运算符为乘号
            result = a * b;
        }
        else { // 第一个运算符为除号
            result = a / b;
        }
        if (operator2 == 0) { // 第二个运算符为加号
            result += c;
        }
        else if (operator2 == 1) { // 第二个运算符为减号
            result -= c;
        }
        else if (operator2 == 2) { // 第二个运算符为乘号
            result *= c;
        }
        else { // 第二个运算符为除号
            result /= c;
        }
        if (operator3 == 0) { // 第三个运算符为加号
            result += d;
        }
        else if (operator3 == 1) { // 第三个运算符为减号
            result -= d;
        }
        else if (operator3 == 2) { // 第三个运算符为乘号
            result *= d;
        }
        else { // 第三个运算符为除号
            result /= d;
        }
        printf("(%d %c %d) %c %d %c %d = \n", a, operator1 == 3 ? '/' : (operator1 == 2 ? '*' : operator1 == 1 ? '-' : '+'), b, operator2 == 3 ? '/' : (operator2 == 2 ? '*' : operator2 == 1 ? '-' : '+'), c, operator3 == 3 ? '/' : (operator3 == 2 ? '*' : operator3 == 1 ? '-' : '+'), d);
    }
}

int main() {
    int grade, count;
    srand((unsigned)time(NULL));
    printf("请输入年级和题目数量（用空格隔开）：");
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
        printf("输入年级无效！\n");
    }
    return 0;
}
