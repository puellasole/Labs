#include <iostream>
#include <vector>
#include <cassert>

enum Device_ID { Electricity_ID = 0, DiscreteSignals_ID, Heater_ID };

// Иерархия классов приборов
class Device
{
public:
    virtual void info() = 0;
    virtual ~Device() {}
    // Параметризированный статический фабричный метод
    static Device* createDevice(Device_ID id);
};

class Electricity : public Device
{
public:
    void info() {
        std::cout << "Electricity" << std::endl;
    }
};

class DiscreteSignals : public Device
{
public:
    void info() {
        std::cout << "DiscreteSignals" << std::endl;
    }
};

class Heater : public Device
{
public:
    void info() {
        std::cout << "Heater" << std::endl;
    }
};


// Реализация параметризированного фабричного метода
Device* Device::createDevice(Device_ID id)
{
    Device* p = nullptr;
    switch (id)
    {
    case Electricity_ID:
        p = new Electricity();
        break;
    case DiscreteSignals_ID:
        p = new DiscreteSignals();
        break;
    case Heater_ID:
        p = new Heater();
        break;
    default:
        assert(false);
    }
    return p;
};


// Создание объектов при помощи параметризированного фабричного метода
int main()
{
    std::vector<Device*> v;
    v.push_back(Device::createDevice(Electricity_ID));
    v.push_back(Device::createDevice(DiscreteSignals_ID));
    v.push_back(Device::createDevice(Heater_ID));

    for (int i = 0; i < v.size(); i++)
        v[i]->info();
    // ...
}
