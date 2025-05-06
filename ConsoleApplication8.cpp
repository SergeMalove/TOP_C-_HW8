#include <iostream>
#include <ctime>

//Написать программу, которая создает массив размером 10 и заполняет его случайными числами от 1 до 100 включительно.
//Только помните о том, что для реальных проектов этот генератор использовать не стоит, потому что уж больно плохо 
//он генерирует "случайные" числа(запустив несколько раз вашу программу, можно заметить, что числа всегда получается 
//примерно одни и те же - в общем, кринж, но для общего знакомства пусть будет).

int inputArrSize()
{
    int arrSize = 0;
    
    std::cout << "Введите размер массива: ";

    std::cin >> arrSize;

    return arrSize;
}

int* createRandNumArr(int& arrSize) 
{
    int* randNums = new int[arrSize];

    for (int i = 0; i < arrSize; ++i)
    {
        randNums[i] = rand() % (100 - 1);
    }

    return randNums;
}

// Я не понял как корректно сюда передать массив по ссылке
// по этому печать полученного массива в Мэйне.

void printRandNumArr(const int(&randNums)[], int arrSize)
{
    std::cout << "\nПолученный массив:\n";
    
    for (int i = 0; i < arrSize; ++i)
    {
        std::cout << randNums[i] << std::endl;
    }
}

int main() {
    srand(time(NULL));
    setlocale(LC_CTYPE, "rus");

    int arrSize = inputArrSize();

    int* randNums = createRandNumArr(arrSize);

    std::cout << "\nПолученный массив:\n";

    for (int i = 0; i < arrSize; ++i)
    {
        std::cout << randNums[i] << std::endl;
    }

    delete randNums;
    return 0;
}