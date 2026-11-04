#pragma once

#include <string>

// Структура адреса
struct Address
{
    std::string country;
    std::string city;
    std::string street;
    double latitude;
    double longitude;
};

// Перечисление цветов
enum TrafficLightsState
{
    RED,
    YELLOW,
    GREEN
};

// Класс светофора
class TrafficLight
{
public:
    Address address;

    TrafficLightsState GetCurrentState();
    void GetInfo();
};

