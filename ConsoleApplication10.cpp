#include <iostream>
#include <string>
#include <fstream>

// Напишите свое меню с использованием switch - case

// Написать две программы : пользователь выбирает хочет он добавить текст в файл или вывести 
// содержание файла.И соответственно, пользователь вводит или выводит текст в / из файла.


// По идее этот метод надо бы перегрузить, но я не знаю как. Поэтому с флагом.
void writeToFile(std::string fileName, int flag)
{
    std::ofstream fout;

    // Чисто по приколу тернарник поюзать
    flag == 0 ? fout.open(fileName) : fout.open(fileName, std::ios::app);
    
    if (!fout.is_open())
    {
        std::cout << "Ошибка открытия файла!" << std::endl;
    }
    else
    {
        std::string information;
        std::cin.ignore(); // Без этого нифига не работает =((((
        std::getline(std::cin, information);
        fout << information << "\n";
    }

    fout.close();
}

void readFromFile(std::string fileName)
{
    std::ifstream fin;
    fin.open(fileName);

    if (!fin.is_open())
    {
        std::cout << "Ошибка открытия файла!" << std::endl;
    }
    else
    {
        std::cout << "Содержание открытого файла:\n" << std::endl;
        std::string str;

        while (!fin.eof())
        {
            str = "";
            std::getline(fin, str);
            std::cout << str << std::endl;
        }
    }

    fin.close();
}

void printMenu()
{
    std::cout << "\nМеню записи и чтения файла\n\n" <<
        "1. Создать/записать информацию в файл с заменой данных\n" <<
        "2. Создать/дописать информацию в файл\n" <<
        "3. Вывести содержание файла на экран\n" <<
        "0. Закрыть программу" << std::endl;
}

std::string inputFileName()
{
    std::string fileName;
    std::cout << "\nВведите название файла: ";
    std::cin >> fileName;
    std::cout << "\n";
    return fileName;
}

int main()
{
    setlocale(LC_CTYPE, "rus");

    int pointMenu = -1;

    while (pointMenu != 0)
    {
        printMenu();

        std::cout << "\nВведите пункт меню: ";
        std::cin >> pointMenu;

        switch (pointMenu)
        {
        case 1:
            writeToFile(inputFileName(), 0);
            break;

        case 2:
            writeToFile(inputFileName(), 1);
            break;
        case 3:
            readFromFile(inputFileName());
            break;
        case 0:
            std::cout << "\nЗавершение работы программы" << std::endl;
            break;
        default:
            std::cout << "\nВы ввели неправильный номер пункта меню! Повторите ввод.\n" << std::endl;
            break;
        }
    };

    return 0;
}
