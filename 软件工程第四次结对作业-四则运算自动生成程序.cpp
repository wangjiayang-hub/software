#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 生成指定范围内的随机整数
int generateRandomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}
// 生成指定范围内的随机小数
double generateRandomDouble(double min, double max) {
    double scaled = (double)rand() / RAND_MAX;
    double result = min + scaled * (max - min);
    return result;
}
// 生成随机运算符
char generateRandomOperation(char* operations, int numOperations) {
    int index = rand() % numOperations;
    return operations[index];
}

// 生成带括号的四则运算题目
void generateArithmeticQuestion0(int maxNumber, char* operations, int numOperations, int hasDecimal, int hasParentheses, int numOperands) {
    int* operands = (int*)malloc(numOperands * sizeof(int));
    char* operators = (char*)malloc((numOperands - 1) * sizeof(char));
    char operatorChar;

    // 生成操作数
    for (int i = 0; i < numOperands; i++) {
        if (hasDecimal) {
            operands[i] = generateRandomInt(0, maxNumber);
        }
        else {
            operands[i] = generateRandomInt(1, maxNumber);
        }
    }

    // 生成运算符
    for (int i = 0; i < numOperands - 1; i++) {
        operators[i] = generateRandomOperation(operations, numOperations);
    }

    // 输出题目
    if (hasParentheses) {
        // 随机选择括号位置
        int position = rand() % (numOperands - 1);
        for (int i = 0; i < numOperands; i++) {
            if (i == position) {
                printf("(");
            }
            printf("%d", operands[i]);
            if (i == position + 1) {
                printf(")");
            }
            if (i < numOperands - 1) {
                printf(" %c ", operators[i]);
            }
        }
    }
    else {
        for (int i = 0; i < numOperands - 1; i++) {
            printf("%d %c ", operands[i], operators[i]);
        }
        printf("%d", operands[numOperands - 1]);
    }
    printf(" = ?\n");

    // 释放动态分配的内存
    free(operands);
    free(operators);
}
void generateArithmeticQuestion1(double maxNumber, char* operations, int numOperations, int hasParentheses, int numOperands) {
    double* operands = (double*)malloc(numOperands * sizeof(double));
    char* operators = (char*)malloc((numOperands - 1) * sizeof(char));
    char operatorChar;

    // 生成操作数
    for (int i = 0; i < numOperands; i++) {
        operands[i] = generateRandomDouble(0, maxNumber);
    }

    // 生成运算符
    for (int i = 0; i < numOperands - 1; i++) {
        operators[i] = generateRandomOperation(operations, numOperations);
    }

    // 输出题目
    if (hasParentheses) {
        // 随机选择括号位置
        int position = rand() % (numOperands - 1);
        for (int i = 0; i < numOperands; i++) {
            if (i == position) {
                printf("(");
            }
            printf("%.2f", operands[i]);
            if (i == position + 1) {
                printf(")");
            }
            if (i < numOperands - 1) {
                printf(" %c ", operators[i]);
            }
        }
    }
    else {
        for (int i = 0; i < numOperands - 1; i++) {
            printf("%.2f %c ", operands[i], operators[i]);
        }
        printf("%.2f", operands[numOperands - 1]);
    }
    printf(" = ?\n");

    // 释放动态分配的内存
    free(operands);
    free(operators);
}
int main() {
    int numQuestions;
    int maxNumber;
    int numOperations;
    char operations[4];
    int hasDecimal;
    int hasParentheses;
    int numOperands;

    // 用户输入题目数量、最大数、运算符、是否有小数、是否有括号、操作数个数
    printf("Enter the number of questions: ");
    scanf("%d", &numQuestions);
    printf("Enter the maximum number: ");
    scanf("%d", &maxNumber);
    printf("Enter the number of operations (up to 4): ");
    scanf("%d", &numOperations);
    printf("Enter the operations (+, -, *, /): ");
    for (int i = 0; i < numOperations; i++) {
        scanf(" %c", &operations[i]);
    }
    printf("Include decimals? (1 for yes, 0 for no): ");
    scanf("%d", &hasDecimal);
    printf("Include parentheses? (1 for yes, 0 for no): ");
    scanf("%d", &hasParentheses);
    do {
        printf("Enter the number of operands (2 or more): ");
        scanf("%d", &numOperands);
    } while (numOperands < 2);

    // 设置随机种子
    srand(time(NULL));
    if (hasDecimal == 0)
    {
        // 生成题目
        for (int i = 0; i < numQuestions; i++) {
            generateArithmeticQuestion0(maxNumber, operations, numOperations, hasDecimal, hasParentheses, numOperands);
        }
    }
    if (hasDecimal == 1)
    {
        for (int i = 0; i < numQuestions; i++) {
            generateArithmeticQuestion1(maxNumber, operations, numOperations, hasParentheses, numOperands);
        }
    }
    return 0;
}
