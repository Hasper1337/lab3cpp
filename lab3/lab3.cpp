/*****************************************************************//**
 * \file   lab3.cpp
 * \brief  Лабораторная работа №3 по ООП
 * 
 * \author Viner Sakhibgareev
 * \date   November 2025
 * 
 * Работа содержит реализацию иерархии наследования, полиморфизм, виртуальные функции,
 * множественное наследование
 *********************************************************************/

#include <iostream>

using namespace std;


/**
 * \brief Абстрактный базовый класс, c методам play (виртуальный), tune и getType
 */
class MusicalInstrument {
protected:
	string name;
	int yearMade;
	static int totalInstruments;
public:

	/**
	 * \brief Конструктор c параметрами.
	 * 
	 * \param name Название инструмента
	 * \param year Год создания инструмента
	 */
	MusicalInstrument(const string& name, int year) : name(name), yearMade(year) {
		totalInstruments++;
	}

	/**
	 * \brief Конструктор копирования.
	 * 
	 * \param other Копируемый объект
	 */
	MusicalInstrument(const MusicalInstrument& other) : name(other.name), yearMade(other.yearMade) {
		totalInstruments++;
	}

	/**
	 * \brief Деструктор.
	 */
	virtual ~MusicalInstrument() {
		totalInstruments--;
	}

	/**
	 * \brief Перегрузка оператора присваивания.
	 * 
	 * \param other Объект для присваивания
	 * \return Ссылка на текущий объект
	 */
	MusicalInstrument& operator=(const MusicalInstrument& other) {
		if (this != &other) {
			name = other.name;
			yearMade = other.yearMade;
		}
		return *this;
	}
	/**
	 * \brief Виртуальная функция воспроизведение звука.
	 * 
	 */
	void virtual play() const = 0;


	/**
	 * \brief Виртуальная функция настройки инструмента.
	 * 
	 */
	void tune() {
		cout << "Настройка инструмента:" << name << endl;
	};

	/**
	 * \brief Виртуальная функция получения типа инструмента.
	 * 
	 * \return Строка с типом инструмента
	 */
	virtual string getType() const = 0;

	/**
	 * \brief Получить общее количество созданных инструментов.
	 * 
	 * \return Количество инструментов
	 */
	static int getTotalInstruments() {
		return totalInstruments;
	}

	/**
	 * \brief Получить название инструмента.
	 * 
	 * \return Название инструмента
	 */
	string getName() const { return name; }

	/**
	 * \brief Получить год изготовления
	 * \return Год изготовления
	 */
	int getYearMade() const { return yearMade; }

};

int MusicalInstrument::totalInstruments = 0;

/**
 * \brief Класс наследник от MusicalInstrument, c методам strings, tension
 */
class StringInstrument : public MusicalInstrument {
	void strings() { // струны

	};

	void tension() { // натяжение

	};
};

/**
 * \brief Класс наследник от MusicalInstrument, c методам diaphragm, material
 */
class WindInstrument : public MusicalInstrument {
	void diaphragm() { // диафрагма

	};
	
	void material() { // материал

	};
};

/**
 * \brief Класс наследник от StringInstrument
 */
class Guitar : public StringInstrument {
	public:
	void play() override {
		cout << "Guitar sound like Strum Strum" << endl;
	};

};

/**
 * \brief Класс наследник от StringInstrument
 */
class Violin : public StringInstrument {
	public:
	void play() override {
		cout << "Violin sound like Screech Screech" << endl;
	};

};

/**
 * \brief Класс наследник от WindInstrument
 */
class Flute : public WindInstrument {
	public:
	void play() override {
		cout << "Flute sound like Toot Toot" << endl;
	};

};

class IElectronicDevice {
	public:
	void powerOn() {
	};
	void powerOff() {
	};
};

/**
 * \brief Класс наследник от Guitar и IElectronicDevice
 */
class SynthGuitar : public Guitar, public IElectronicDevice {

};

int main() {

}