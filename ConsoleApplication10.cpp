#include <iostream>
#include <string>
#include <fstream>

//Написать две программы : пользователь выбирает хочет он добавить текст в файл или вывести 
//содержание файла.И соответственно, пользователь вводит или выводит текст в / из файла.



int main()
{
    setlocale(LC_CTYPE, "rus");

    std::string fileName;

    std::cin >> fileName;

    //std::ofstream fout;
    //fout.open(fileName);

    //if (!fout.is_open())
    //{
    //    std::cout << "Ошибка открытия файла!" << std::endl;
    //}
    //else
    //{
    //    std::string information;
    //    std::cin.ignore();
    //    std::getline(std::cin, information);
    //    fout << "\n" << information;
    //}

    //fout.close();

    std::ifstream fin;
    fin.open(fileName);

    if (!fin.is_open())
    {
        std::cout << "Ошибка открытия файла!" << std::endl;
    }
    else
    {
        std::cout << "Файл открыт." << std::endl;
        std::string str;
        
        while (fin.eof())
        {
            str = "";
            std::getline(fin, str);
            std::cout << str << std::endl;
        }
    }

    fin.close();

    return 0;
}