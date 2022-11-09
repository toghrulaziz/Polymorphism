#include <iostream>
#include <vector>

using namespace std;


//class : Car ++
// 
//class : Manual ++
//class : Automatic ++ 
//
//Manaul ve Automatic - den de mashinlar yaransin. ++
//Misal class Bmw : Automatic ++ 
//
//funksiya yazirisiz, Parametr olaraq Base qebul edir. ++
//Funksiya icersinde mashinlarin melumatlarni chap edirsiz. ++
//
//Her mashina aid field - ler ve mehodlar olsun. ++ 
//
//Base class adi altinda butun mashinlari vector - da saxlamaq ++
//Dersde kecdiylermizden istifade etmek... ++



class Car {
	string vendor;
	string model;
public:


	Car(string vendor, string model)
	{
		SetVendor(vendor);
		SetModel(model);
	}

	void SetVendor(string vendor) {
		this->vendor = vendor;
	}

	void SetModel(string model) {
		this->model = model;
	}

	string GetVendor()const { return vendor; }
	string GetModel()const { return model; }



	virtual void Show() {
		cout << "Vendor: " << vendor << "\nModel: " << model;
	}
};



class Manual : public Car {
	string engineNo;
	string company;
	double volume;
public:


	Manual(string vendor, string model, string engineNo, string company, double volume) : Car(vendor, model)
	{
		SetEngineNo(engineNo);
		SetCompany(company);
		SetVolume(volume);
	}

	void SetEngineNo(string engineNo) {
		this->engineNo = engineNo;
	}

	void SetCompany(string company) {
		this->company = company;
	}

	void SetVolume(double volume) {
		this->volume = volume;
	}

	string GetEngineNo()const { return engineNo; }
	string GetCompany()const { return company; }
	double GetVolume()const { return volume; }



	void Show() override {
		Car::Show();
		cout << "\nEngine Number: " << engineNo << "\nCompany: " << company << "\nVolume: " << volume;
	}

};



class Automatic : public Car {
	string engineNo;
	string company;
	double volume;
public:

	Automatic(string vendor, string model, string engineNo, string company, double volume) : Car(vendor, model)
	{
		SetEngineNo(engineNo);
		SetCompany(company);
		SetVolume(volume);
	}

	void SetEngineNo(string engineNo) {
		this->engineNo = engineNo;
	}

	void SetCompany(string company) {
		this->company = company;
	}

	void SetVolume(double volume) {
		this->volume = volume;
	}

	string GetEngineNo()const { return engineNo; }
	string GetCompany()const { return company; }
	double GetVolume()const { return volume; }


	
	void Show() override {
		Car::Show();
		cout << "\nEngine Number: " << engineNo << "\nCompany: " << company << "\nVolume: " << volume;
	}
};



class Bmw : public Automatic {
	int year;
	int km;
public:

	Bmw(string vendor, string model, string engineNo, string company, double volume, int year,int km) : Automatic(vendor, model, engineNo, company, volume)
	{
		SetYear(year);
		SetKm(km);
	}

	void SetYear(int year) {
		this->year = year;
	}

	void SetKm(int km) {
		this->km = km;
	}

	int GetYear()const { return year; }

	int GetKm()const { return km; }

	
	void Show() override {
		Automatic::Show();
		cout << "\nYear: " << year << "\nKm: " << km << endl << endl;
	}
};


class Mercedes : public Manual {
	int year;
	int km;
public:
	Mercedes(string vendor, string model, string engineNo, string company, double volume, int year,int km) : Manual(vendor, model, engineNo, company, volume) {
		SetYear(year);
		SetKm(km);
	}

	void SetYear(int year) {
		this->year = year;
	}

	void SetKm(int km) {
		this->km = km;
	}

	int GetYear()const { return year; }

	int GetKm()const { return km; }
	

	void Show() override {
		Manual::Show();
		cout << "\nYear: " << year << "\nKm: " << km << endl << endl;
	}

};


void show(Car* car) {
	car->Show();
}


class Garrage {
public:
	vector<Car*> cars;

};


void main() {

	Car* car1 = new Bmw("BMW", "X5", "F15", "BMW", 4.4, 2015,120000);
	Car* car2 = new Bmw("BMW", "F30", "S55", "BMW", 4.8, 2020,15000);
	Car* car3 = new Mercedes("Mercedes", "GLC200", "X253", "Mercedes", 5.6, 2019,100000);

	Garrage* garrage = new Garrage();

	garrage->cars.push_back(car1);
	garrage->cars.push_back(car2);
	garrage->cars.push_back(car3);


	for (auto car : garrage->cars) {
		show(car);
	}

	delete car1;
	delete car2;
	delete car3;

	delete garrage;

}