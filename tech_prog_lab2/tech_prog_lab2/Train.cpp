#include "Train.h"

void Train:: setDestination(const std::string& dest) 
{
    destination = dest;
}

void Train::setTrainNumber(int number) {

    if (number <= 0) {
        throw std::invalid_argument("Train number should be a positive integer.");
    }

    train_number = number;
}

void Train::setDepartureTime(const std::string& time) {
    departure_time = time;
}

std::string Train::getDestination() const {
    return destination;
}

int Train::getTrainNumber() const {
    return train_number;
}

std::string Train::getDepartureTime() const {
    return departure_time;
}

int Train::partition(Train* trains, int low, int high) {
    int pivot = trains[high].getTrainNumber();
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (trains[j].getTrainNumber() < pivot) {
            i++;
            std::swap(trains[i], trains[j]);
        }
    }
    std::swap(trains[i + 1], trains[high]);
    return (i + 1);
}

// Рекурсивная функция быстрой сортировки по номеру поезда
void Train::quickSort(Train* trains, int low, int high) {
    if (low < high) {
        int pi = partition(trains, low, high);

        quickSort(trains, low, pi - 1);
        quickSort(trains, pi + 1, high);
    }
}