#include <iostream>
#include <string>
#include "Train.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


// Функция для разбиения текста на предложения
int splitSentences(const std::string& text, std::string*& sentences) {
    std::istringstream iss(text);
    int count = 0;
    std::string sentence;

    while (std::getline(iss, sentence, '.')) { // Предполагаем, что предложения разделены точкой
        sentences[count++] = sentence;
    }

    return count;
}


int main() 
{
    setlocale(LC_ALL, "Russian");
    //////////  Задание 1

        int numTrains;
        std::cout << "Enter the number of trains: ";
        std::cin >> numTrains;

        Train* trains = new Train[numTrains]; // Создаем динамический массив для хранения поездов

        // Заполнение информации о поездах
        for (int i = 0; i < numTrains; ++i) {
            std::cout << "Enter Destination for Train " << i + 1 << ": ";
            std::string dest;
            std::cin >> dest;
            trains[i].setDestination(dest);

            std::cout << "Enter Train Number for Train " << i + 1 << ": ";
            int number;
            std::cin >> number;
            try {
                trains[i].setTrainNumber(number);
            }
            catch (const std::invalid_argument& e) {
                std::cerr << "Invalid argument: " << e.what() << std::endl;
            }

            std::cout << "Enter Departure Time for Train " << i + 1 << ": ";
            std::string time;
            std::cin >> time;
            trains[i].setDepartureTime(time);
        }

        // Сортировка по номерам поездов
        if (numTrains > 0) {
            trains[0].quickSort(trains, 0, numTrains - 1); // Вызываем функцию быстрой сортировки
        }

        // Вывод информации о поезде по введенному номеру
        int searchNumber;
        std::cout << "Enter train number to search: ";
        std::cin >> searchNumber;

        bool found = false;
        for (int i = 0; i < numTrains; ++i) {
            if (trains[i].getTrainNumber() == searchNumber) {
                std::cout << "Train found: " << trains[i] << std::endl;
                found = true;
                break;
            }
        }

        if (!found) 
        {
            std::cout << "Train with number " << searchNumber << " not found." << std::endl;
        }

        for (int i = 0; i < numTrains; ++i) 
        {
            std::cout << trains[i]<<std::endl;
        }

        delete[] trains; // Освобождаем выделенную память

        
        //////////  Задание 2

        const int INITIAL_SIZE = 100; // Начальный размер массива предложений
        std::string* sentences = new std::string[INITIAL_SIZE]; 
        // Динамический массив 
        // для хранения предложений

        int capacity = INITIAL_SIZE; // Изначальная вместимость массива
        int numSentences = 0; // Количество предложений

        std::ifstream inputFile("input.txt"); // Имя вашего файла с текстом

        if (!inputFile.is_open()) {
            std::cout << "Unable to open file!" << std::endl;
            delete[] sentences; // Освобождаем выделенную память перед выходом
            return 1;
        }

        std::string text;
        std::string line;
        while (std::getline(inputFile, line)) {
            text += line; // Собираем весь текст из файла в одну строку
        }

        inputFile.close(); // Закрываем файл

        // Запрос пользователя о количестве слов в предложении
        int wordCount;
        std::cout << "Enter the number of words in the sentence: ";
        std::cin >> wordCount;

        // Выделяем память под предложения
        sentences = new std::string[capacity];

        // Получаем предложения из текста
        numSentences = splitSentences(text, sentences);

        // Выводим предложения с заданным количеством слов
        for (int i = 0; i < numSentences; ++i) {
            std::istringstream wordStream(sentences[i]);
            int count = 0;
            std::string word;

            while (wordStream >> word) {
                count++;
            }

            if (count == wordCount) {
                std::cout << sentences[i] << std::endl;
            }
        }

        delete[] sentences; // Освобождаем выделенную память

        return 0;


}