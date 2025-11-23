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
#include <string>
#include <map>

using namespace std;


/**
 * \brief Абстрактный базовый класс, c методам play, tune и getType
 */
class MusicalInstrument {
protected:
	string name;
	int yearMade;
	static int totalInstruments;
	static map<string, int> playCountByType;

	/**
	 * \brief Увеличить счётчик воспроизведений для типа инструмента
	 * \param type Тип инструмента
	 */
	void incrementPlayCount(const string& type) const { playCountByType[type]++; }

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
	virtual string getType() const;

	/**
	 * \brief Получить общее количество созданных инструментов.
	 * 
	 * \return Количество инструментов
	 */
	static int getTotalInstruments() { return totalInstruments; }


	/**
	 * \brief Получить самый популярный тип инструмента
	 * 
	 * \return Строка с типом инструмента и количеством воспроизведений
	 */
	static string getMostPlayedType() {
		if (playCountByType.empty()) return "Нет данных";

		string maxType;
		int maxCount = 0;
		for (const auto& pair : playCountByType) {
			if (pair.second > maxCount) {
				maxCount = pair.second;
				maxType = pair.first;
			}
		}
		return maxType + " (" + to_string(maxCount) + " раз)";
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
map<string, int> MusicalInstrument::playCountByType;

/**
 * \brief Промежуточный класс для струнных инструментов, класс наследник от MusicalInstrument, c методам strings, tension
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
 * \brief Промежуточный класс для духовых инструментов, класс наследник от MusicalInstrument
 */
class WindInstrument : public MusicalInstrument {
protected:
	string material;
	double airPressure;
public:

	/**
	 * \brief Конструктор с параметрами
	 * \param name Название инструмента
	 * \param year Год изготовления
	 * \param material Материал изготовления
	 */
	WindInstrument(const string& name, int year, const string& material)
		: MusicalInstrument(name, year), material(material), airPressure(1.0) {
	}

	/**
	 * \brief Переопределённая функция tune() для настройки духового инструмента
	 */
	void tune() override {
		MusicalInstrument::tune();
		cout << "Давление воздуха: " << airPressure << endl;
	}

	/**
	 * \brief Установить давление воздуха
	 * \param pressure Новое значение давления
	 */
	void setAirPressure(double pressure) { airPressure = pressure; }
};

/**
 * \brief Класс наследник от StringInstrument
 */
class Guitar : public StringInstrument {
	public:
	
    /**
     * \brief Конструктор гитары
     * \param name Название гитары
     * \param year Год изготовления
	 * \param strings Количество струн
	 * \param tension Натяжение струн
     */
    Guitar(const string& name, int year, int strings, double tension) : StringInstrument(name, year, strings, tension) {}
    
	/**
     * \brief Воспроизведение звука гитары
     */
	void play() override {
		incrementPlayCount(getType());
		cout << "Guitar " << name << "sound like: Strum Strum... ♪" << endl;
	};


	/**
	 * \brief Получить тип инструмента
	 * \return Строка "Guitar"
	 */
	string getType() const override { return "Guitar"; }

	/**
	 * \brief Настройка гитары
	 */
	void tune() override {
		StringInstrument::tune();
		cout << "The guitar is tuned in E-A-D-G-B-E" << endl;
	}
};

/**
 * \brief Класс наследник от StringInstrument
 */
class Violin : public StringInstrument {
public:

	 /**
     * \brief Конструктор скрипки
	 * \param name Название скрипки
     * \param year Год изготовления
	 * \param strings Количество струн
	 * \param tension Натяжение струн
     */
	Violin(const string& name, int year, int strings, double tension) : StringInstrument(name, year, strings, tension) {}
	

	/**
	 * \brief Воспроизведение звука скрипки
	 */
	void play() override {
		incrementPlayCount(getType());
		cout << "Violin " << name << "sound like: Strum Strum... ♪" << endl;
	};


	/**
	 * \brief Получить тип инструмента
	 * \return Строка "Violin"
	 */
	string getType() const override { return "Violin"; }
};

/**
 * \brief Класс наследник от WindInstrument
 */
class Flute : public WindInstrument {
public:

    /**
     * \brief Конструктор флейты
     * \param name Название флейты
     * \param year Год изготовления
     */
    Flute(const string& name, int year, const string& material) : WindInstrument(name, year, material) {}

	/**
	 * \brief Воспроизведение звука скрипки
	 */
	void play() override {
		incrementPlayCount(getType());
		cout << "Flute" << name <<  "sound like Toot Toot" << endl;
	};


	/**
	 * \brief Получить тип инструмента
	 * \return Строка "Flute"
	 */
	string getType() const override { return "Flute"; }
};

/**
 * \brief Класс интерфейс для электронных устройств
 */
class IElectronicDevice {
protected:
	bool powerOn;
	int currentPatch;

public:

	/**
	 * \brief Конструктор по умолчанию
	 */
	IElectronicDevice() : powerOn(false), currentPatch(0) {}


	/**
	 * \brief Включить устройство
	 */
	void powerOnDevice() {
		powerOn = true;
		cout << "Device is turned on" << endl;
	}

	/**
	 * \brief Установить патч (пресет)
	 * \param patch Номер патча
	 */
	void setPatch(int patch) {
		currentPatch = patch;
		cout << "Patch #" << patch << " set" << endl;
	}

	/**
	 * \brief Проверить, включено ли устройство
	 * \return true если включено, false если выключено
	 */
	bool isPoweredOn() const { return powerOn; }
};

/**
 * \brief Класс наследник от Guitar и IElectronicDevice
 */
class SynthGuitar : public Guitar, public IElectronicDevice {
public:

	/**
	 * \brief Конструктор синтезаторной гитары
	 * \param name Название инструмента
	 * \param year Год изготовления
	 */
	SynthGuitar(const string& name, int year) : Guitar(name, year, 0, 0) {}


	/**
	 * \brief Воспроизведение звука синтезаторной гитары
	 *
	 * Работает только при включенном питании
	 */
	void play() override {
		incrementPlayCount(getType());
		if (powerOn) {
			cout << "SynthGuitar " << name << " (patch #" << currentPatch
				<< "): Electronic sound ... ♪♫" << endl;
		}
		else {
			cout << "The synth guitar is turned off!" << endl;
		}
	}

	/**
	 * \brief Получить тип инструмента
	 * \return Строка "SynthGuitar"
	 */
	string getType() const override { return "SynthGuitar"; }

	/**
	 * \brief Настройка синтезаторной гитары
	 *
	 * Требует включенного питания для электронной калибровки
	 */
	void tune() override {
		if (powerOn) {
			Guitar::tune();
			cout << "Synth guitar calibration is complete." << endl;
		}
		else {
			cout << "Turn on the power to configure" << endl;
		}
	}
};