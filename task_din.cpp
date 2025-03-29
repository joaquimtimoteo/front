#include "task_din.h"
#include <vector>

// Função auxiliar para verificar se um número é de dois dígitos
bool isTwoDigit(int num) {
    return (num >= 10 && num <= 99);
}

// Função para calcular a média dos números de dois dígitos
double calculateAverage(int* array, int size, int& count) {
    double sum = 0.0;
    count = 0;

    for (int i = 0; i < size; i++) {
        if (isTwoDigit(array[i])) {
            sum += array[i];
            count++;
        }
    }

    return (count > 0) ? sum / count : 0.0;
}

// Função principal (task) para resolver a Tarefa 24
int* task(int* array, int size, int& newSize) {
    newSize = 0;

    // Passo 1: Calcular a média dos números de dois dígitos
    int twoDigitCount = 0;
    double average = calculateAverage(array, size, twoDigitCount);

    if (twoDigitCount == 0) {
        return nullptr; // Nenhum número de dois dígitos encontrado
    }

    // Passo 2: Filtrar elementos maiores que a média
    std::vector<int> tempResult;
    for (int i = 0; i < size; i++) {
        if (array[i] > average) {
            tempResult.push_back(array[i]);
        }
    }

    // Passo 3: Converter o vetor para um array dinâmico
    newSize = tempResult.size();
    if (newSize == 0) {
        return nullptr;
    }

    int* result = new int[newSize];
    for (int i = 0; i < newSize; i++) {
        result[i] = tempResult[i];
    }

    return result;
}
