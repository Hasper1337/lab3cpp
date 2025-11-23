/*****************************************************************//**
 * \file   tests.cpp
 * \brief  Тестирование иерархии музыкальных инструментов
 * 
 * \author Viner Sakhibgareev
 * \date   November 2025
 *********************************************************************/

#include "lab3.cpp"


/**
 * \brief Тест 1: Создание объектов всех типов
 * 
 * Проверяет создание инструментов всех классов и работу
 * статического счётчика totalInstruments
 */
void test1() {
    cout << "ТЕСТ 1: Создание инструментов" << endl;
    
    Guitar guitar("Fender", 2020);
    Violin violin("Stradivarius", 1721);
    Flute flute("Yamaha", 2018);
    SynthGuitar synth("Roland", 2023);
    
    cout << "Создано инструментов: " << MusicalInstrument::getTotalInstruments() << endl;
    cout << string(50, '=') << endl;
}


/**
 * \brief Тест 3: Работа статических членов и функций
 *
 * Проверяет работу статического счётчика инструментов и
 * статистики использования getMostPlayedType()
 */
void test3() {
    cout << "\nТЕСТ 3: Статические члены и функции" << endl;

    cout << "Всего инструментов: " << MusicalInstrument::getTotalInstruments() << endl;
    cout << "Самый популярный: " << MusicalInstrument::getMostPlayedType() << endl;
    cout << string(50, '=') << endl;
}

/**
 * \brief Тест 4: Копирование и присваивание (проверка независимости копий)
 *
 * Демонстрирует работу конструктора копирования и независимость
 * оригинала и копии (глубокое копирование динамической памяти)
 */
void test4() {
    cout << "\nТЕСТ 4: Конструктор копирования" << endl;

    Guitar original("Original", 2020);
    original.setTension(10.0);
    cout << "Original have tension: " << original.getTension() << endl;

    Guitar copy(original);
    copy.setTension(8.0);
    cout << "Copy have tension: " << copy.getTension() << endl;
    cout << "Original after edit copy: " << original.getTension() << endl;
}


/**
 * \brief Тест 5: Множественное наследование
 *
 * Демонстрирует работу SynthGuitar, который наследуется от
 * Guitar и IElectronicDevice. Проверяет доступ к функциям
 * обоих базовых классов.
 */
void test5() {
    cout << "\nТЕСТ 5: Множественное наследование" << endl;

    SynthGuitar synth("Roland", 2023);

    cout << "\n1. Без питания:" << endl;
    synth.play();

    cout << "\n2. Включаем устройство:" << endl;
    synth.powerOnDevice();
    synth.setPatch(42);
    synth.play();

    cout << "\n3. Доступ через Guitar*:" << endl;
    Guitar* guitarPtr = &synth;
    guitarPtr->play();

    cout << "\n4. Доступ через IElectronicDevice*:" << endl;
    IElectronicDevice* devicePtr = &synth;
    devicePtr->setPatch(99);
    cout << "   Текущий патч: " << (devicePtr->isPoweredOn() ? "активен" : "неактивен") << endl;
}

int main() {
    test1();
    test3();
    test4();
    test5();
    return 0;
}