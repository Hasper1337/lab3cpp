/*****************************************************************//**
 * \file   tests.cpp
 * \brief  Тестирование иерархии музыкальных инструментов
 * 
 * \author Viner Sakhibgareev
 * \date   November 2025
 *********************************************************************/

#include "lab3.h"

int MusicalInstrument::totalInstruments = 0;
map<string, int> MusicalInstrument::playCountByType;

/**
 * \brief Тест 1: Создание объектов всех типов Проверяет создание инструментов всех классов и работу статического счётчика totalInstruments
 */
static void test1() {
    cout << "TEST 1: Making Musical Instruments" << endl;
    
    Guitar guitar("Fender", 2020);
    Violin violin("Stradivarius", 1721);
    Flute flute("Yamaha", 2018);
    SynthGuitar synth("Roland", 2023);
    
    cout << "Created musical instruments: " << MusicalInstrument::getTotalInstruments() << endl;
    
    // Воспроизведем звук каждого инструмента
    cout << "\nPlaying sounds:" << endl;
    guitar.play();
    violin.play();
    flute.play();
    
    synth.powerOnDevice();
    synth.play();
    
    cout << string(50, '=') << endl;
}


/**
 * \brief Тест 2: Полиморфизм через указатели на базовый класс
 *
 * Демонстрирует полиморфный вызов метода play() через
 * указатели на базовый класс MusicalInstrument
 */
void test2() {
    cout << "\nTEST 2: Polymorphism" << endl;

    Guitar guitar("Fender", 2020);
    Violin violin("Stradivarius", 1721);
    Flute flute("Yamaha", 2018);
    SynthGuitar synth("Roland", 2023);

    vector<MusicalInstrument*> orchestra;
    orchestra.push_back(&guitar);
    orchestra.push_back(&violin);
    orchestra.push_back(&flute);
    orchestra.push_back(&synth);

    cout << "\nOrchestra play:" << endl;
    for (auto* inst : orchestra) {
        inst->play();
    }
    cout << string(50, '=') << endl;
}

/**
 * \brief Тест 3: Работа статических членов и функций
 *
 * Проверяет работу статического счётчика инструментов и
 * статистики использования getMostPlayedType()
 */
void test3() {
    cout << "\nTEST 3: Static Members and Functions" << endl;
    
    // Создаём новые инструменты для этого теста
    Guitar guitar1("Gibson", 2021);
    Guitar guitar2("Ibanez", 2022);
    Violin violin("Yamaha", 2019);
    
    // Играем несколько раз
    guitar1.play();
    guitar1.play();
    guitar2.play();
    violin.play();

    cout << "\nTotal instruments: " << MusicalInstrument::getTotalInstruments() << endl;
    cout << "Most popular: " << MusicalInstrument::getMostPlayedType() << endl;
    cout << string(50, '=') << endl;
}

/**
 * \brief Тест 4: Копирование и присваивание (проверка независимости копий)
 *
 * Демонстрирует работу конструктора копирования и независимость
 * оригинала и копии (глубокое копирование динамической памяти)
 */
void test4() {
    cout << "\nTEST 4: Copy Constructor" << endl;

    Guitar original("Original", 2020);
    original.setTension(10.0);
    cout << "Original have tension: " << original.getTension() << endl;

    Guitar copy(original);
    copy.setTension(8.0);
    cout << "Copy have tension: " << copy.getTension() << endl;
    cout << "Original after edit copy: " << original.getTension() << endl;
    cout << string(50, '=') << endl;
}


/**
 * \brief Тест 5: Множественное наследование
 *
 * Демонстрирует работу SynthGuitar, который наследуется от
 * Guitar и IElectronicDevice. Проверяет доступ к функциям
 * обоих базовых классов.
 */
void test5() {
    cout << "\nTEST 5: Multiple Inheritance" << endl;

    SynthGuitar synth("Roland", 2023);

    cout << "\n1. No power:" << endl;
    synth.play();

    cout << "\n2. Turn on the device:" << endl;
    synth.powerOnDevice();
    synth.setPatch(42);
    synth.play();

    cout << "\n3. Access via Guitar*:" << endl;
    Guitar* guitarPtr = &synth;
    guitarPtr->play();

    cout << "\n4. Access via IElectronicDevice*:" << endl;
    IElectronicDevice* devicePtr = &synth;
    devicePtr->setPatch(99);
    cout << "   Current patch: " << (devicePtr->isPoweredOn() ? "active" : "inactive") << endl;
    
    cout << "\n5. Checking after patch change:" << endl;
    synth.play();
    
    cout << string(50, '=') << endl;
}

int main() {

    test1();
	test2();
    test3();
    test4();
    test5();

    return 0;
}