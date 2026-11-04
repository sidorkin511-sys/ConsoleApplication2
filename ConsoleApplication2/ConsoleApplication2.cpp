#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <clocale>

#include "TrafficLight.h"

using namespace std::chrono_literals;


// Определение текущего состояния светофора
TrafficLightsState TrafficLight::GetCurrentState()
{
    // Получаем текущее время
    auto now = std::chrono::system_clock::now();

    // Переводим время в секунды
    auto now_sec = std::chrono::floor<std::chrono::seconds>(now).time_since_epoch();

    // Получаем секунды текущей минуты
    int seconds = (now_sec % 60).count();

    if (seconds >= 0 && seconds <= 5)
    {
        return TrafficLightsState::YELLOW;
    }
    else if (seconds >= 6 && seconds <= 29)
    {
        return TrafficLightsState::RED;
    }
    else if (seconds >= 30 && seconds <= 54)
    {
        return TrafficLightsState::GREEN;
    }
    else
    {
        return TrafficLightsState::YELLOW;
    }
}


// Вывод информации о светофоре
void TrafficLight::GetInfo()
{
    std::cout << "\n--- Информация о светофоре ---\n";

    std::cout << "Страна: " << address.country << std::endl;
    std::cout << "Город: " << address.city << std::endl;
    std::cout << "Улица: " << address.street << std::endl;

    std::cout << "Координаты: "
        << address.latitude << ", "
        << address.longitude << std::endl;

    // Получаем текущее состояние
    TrafficLightsState state = GetCurrentState();

    std::cout << "Текущий цвет: ";

    switch (state)
    {
    case TrafficLightsState::RED:
        std::cout << "КРАСНЫЙ";
        break;

    case TrafficLightsState::YELLOW:
        std::cout << "ЖЁЛТЫЙ";
        break;

    case TrafficLightsState::GREEN:
        std::cout << "ЗЕЛЁНЫЙ";
        break;
    }

    std::cout << std::endl;
}


// Главная функция программы
int main()
{
    setlocale(LC_ALL, "Russian");

    // Создаём объект светофора
    TrafficLight trafficLight;

    // Заполняем адрес
    trafficLight.address.country = "Россия";
    trafficLight.address.city = "Москва";
    trafficLight.address.street = "Тверская улица";
    trafficLight.address.latitude = 55.765;
    trafficLight.address.longitude = 37.605;

    // Бесконечный цикл
    while (true)
    {
        trafficLight.GetInfo();

        // Ожидаем 23 секунды
        std::this_thread::sleep_for(23000ms);
    }

    return 0;
}
