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
	void virtual play();


	/**
	 * \brief Виртуальная функция настройки инструмента.
	 * 
	 */
	virtual void tune() {
		cout << "Настройка инструмента:" << name << endl;
	};

	/**
	 * \brief Виртуальная функция получения типа инструмента.
	 * 
	 * \return Строка с типом инструмента
	 */
	virtual string getType();

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
protected:
	int numberOfStrings;
	double tension;
	string* stringMaterials;
public:
	/**
	 * \brief Конструктор с параметрами
	 * \param name Название инструмента
	 * \param year Год изготовления
	 * \param strings Количество струн
	 * \param tension Натяжение струн
	 */
	StringInstrument(const string& name, int year, int strings, double tension) : MusicalInstrument(name, year), numberOfStrings(strings), tension(tension) {
		stringMaterials = new string[numberOfStrings];
		for (int i = 0; i < numberOfStrings; i++) {
			stringMaterials[i] = "Steel";
		}
	}


	/**
	 * \brief Конструктор копирования с глубоким копированием
	 * \param other Копируемый объект
	 *
	 * Выполняет глубокое копирование динамического массива stringMaterials
	 */
	StringInstrument(const StringInstrument& other) : MusicalInstrument(other), numberOfStrings(other.numberOfStrings), tension(other.tension) {
		stringMaterials = new string[numberOfStrings];
		for (int i = 0; i < numberOfStrings; i++) {
			stringMaterials[i] = other.stringMaterials[i];
		};
	}

	/**
	 * @brief Виртуальный деструктор
	 *
	 * Освобождает динамически выделенную память
	 */
	virtual ~StringInstrument() {
		delete[] stringMaterials;
	}

	/**
	 * \brief Переопределённая функция настройки струнного инструмента.
	 * 
	 */
	void tune() override {
		MusicalInstrument::tune();
		cout << "Натяжение струн: " << tension << endl;
	}


	/**
	 * \brief Получить количество струн
	 * \return Количество струн
	 */
	int getNumberOfStrings() const { return numberOfStrings; }

	/**
	 * \brief Получить натяжение струн
	 * \return Натяжение струн
	 */
	double getTension() const { return tension; }

	/**
	 * \brief Установить натяжение струн
	 * \param t Новое значение натяжения
	 */
	void setTension(double t) { tension = t; }
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