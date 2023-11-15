#include <iostream>
#include <string>
#include "Train.h"

int main() 
{
   
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
                std::cout << "Enter Departure Time for Train " << i + 1 << ": ";
                std::string time;
                std::cin >> time;
                trains[i].setDepartureTime(time);
            }
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

        if (!found) {
            std::cout << "Train with number " << searchNumber << " not found." << std::endl;
        }

        delete[] trains; // Освобождаем выделенную память

        return 0;
}