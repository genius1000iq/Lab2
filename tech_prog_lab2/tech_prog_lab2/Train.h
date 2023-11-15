#pragma once
#include <string>
#include <iostream>
#include <stdexcept>

class Train
{
private:
    std::string destination;  // �������� ������ ����������
    int train_number;         // ����� ������
    std::string departure_time; // ����� �����������

public:
    // ����������� �� ���������
    Train()
    {
        destination = "";
        train_number = 0;
        departure_time = "";
    }

    Train(const std::string& dest, int number, const std::string& time)
        : destination{ dest }, train_number{ number }, departure_time{ time }
    {}

    Train(const Train& other)
        : destination(other.destination), train_number(other.train_number), departure_time(other.departure_time) 
    {}
    ~Train() {}

    void setDestination(const std::string& dest);
    void setTrainNumber(int number);
    void setDepartureTime(const std::string& time);


    std::string getDestination() const;
    int getTrainNumber() const;
    std::string getDepartureTime() const;



    friend std::istream& operator>>(std::istream& is, Train& train) {
        std::cout << "Enter Destination: ";
        is >> train.destination;
        std::cout << "Enter Train Number: ";
        is >> train.train_number;
        std::cout << "Enter Departure Time: ";
        is >> train.departure_time;
        return is;
    }


    friend std::ostream& operator<<(std::ostream& os, const Train& train) {
        os << "Destination: " << train.destination << ", Train Number: " << train.train_number
            << ", Departure Time: " << train.departure_time;
        return os;
    }


    // ������� ��� ���������� ������� ������� ��� quicksort
    int partition(Train* trains, int low, int high);

    // ����������� ������� ������� ���������� �� ������ ������
    void quickSort(Train* trains, int low, int high);

};