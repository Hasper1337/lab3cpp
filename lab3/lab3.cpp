#include <iostream>

using namespace std;

class MusicalInstrument {
public:

	void virtual play() {
		cout << "Musical instrument sound like ";
	};

	void tune() {

	};

	void getType() {

	};

};

class StringInstrument : MusicalInstrument {
	void strings() { // струны

	};

	void tension() { // натяжение

	};
};

class WindInstrument : MusicalInstrument {
	void diaphragm() { // диафрагма

	};
	
	void material() { // материал

	};
};

class Guitar {

};

class Violin {

};

class Flute {

};

class SynthGuitar : Guitar { //ещё IElectronicDevice??

};

int main() {

}