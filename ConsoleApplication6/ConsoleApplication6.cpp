#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;

class student;

class teacher;

class dekan;

class metodist;

class student {
	friend class teacher;
public:
	int lab;
	int ocenLab;
	bool exam;
	int ocenExam;
	bool vedomost;
	bool accVedomost;
	bool prikaz;
	bool accPrikaz;

	student() {
		lab = 0;
		ocenLab = 0;
		exam = false;
		ocenExam = 0;
		vedomost = false;
		accVedomost = false;
		prikaz = false;
		accPrikaz = false;
	}

	void passLab();
	void passExam();
	void perevod();
};

class teacher {
	friend student;
public:
	void markLab(student& stud);
	void markExam(student& stud);
};

class dekan {
	friend student;
public:
	void acceptVedomost(student& stud);
	void acceptPrikaz(student& stud);
};

class metodist {
	friend student;
public:
	void createVedomost(student& st);
	void createPrikaz(student& st);
};

void student::passLab() {
	cout << "Лабораторная отправлена на проверку" << endl;
	lab++;
	_getch();
}

void teacher::markLab(student& stud) {
	if (stud.lab > stud.ocenLab) {
		cout << "Лабораторные студента оценены" << endl;
		stud.ocenLab = stud.lab;
	}
	else {
		cout << "Новых лабораторных работ на оценку нет" << endl;
	}
	_getch();
}

void student::passExam() {
	if (ocenLab > 5) {
		cout << "Сдача экзамена" << endl << endl;
		cout << "Экзамен отправлен на проверку" << endl;
		exam = true;
	}
	_getch();
}

void teacher::markExam(student& stud) {
	if (stud.exam) {
		cout << "Оцените экзамен студента в диапазоне от 1 до 5" << endl;
		cin >> stud.ocenExam;
		while ((stud.ocenExam < 1) || (stud.ocenExam > 5)){
			cout << "Неправильно введены данные << endl" << endl;
			cout << "Оцените экзамен студента в диапазоне от 1 до 5" << endl;
			cin >> stud.ocenExam;
		}
	}
	if (stud.ocenExam < 3) {
		stud.exam = false;
		cout << "Необходима пересдача";
		stud.ocenExam = 0;
	}
	_getch();
}

void metodist::createVedomost(student& stud) {
	if (stud.ocenExam > 2) {
		cout << "Экзамены сданы успешно. Ведомость создана." << endl;
		stud.vedomost = true;
	}
	else {
		cout << "Экзамен не сдан, или сдан неудовлетворительно." << endl;
	}
	_getch();
}

void dekan::acceptVedomost(student& stud) {
	if (stud.vedomost) {
		cout << "Ведомость утверждена." << endl;
		stud.accVedomost = true;
	}
	else {
		cout << "Ведомость не была создана для её утверждения." << endl;
	}
	_getch();
}

void metodist::createPrikaz(student& stud) {
	if (stud.accVedomost) {
		cout << "Приказ о переводе на студента следующий семестр создан" << endl;
		stud.prikaz = true;
	}
	else {
		cout << "Приказ не может быть создан без утверждённой ведомости." << endl;
	}
	_getch();
}

void dekan::acceptPrikaz(student& stud) {
	if (stud.prikaz) {
		cout << "Приказ утверждён." << endl;
		stud.accPrikaz = true;
	}
	else {
		cout << "Приказ не был создан для его утверждения." << endl;
	}
	_getch();
}

void student::perevod(){
	if (accPrikaz) {
		cout << "Вы переведены на следующий семестр!" << endl;
	}
	else
		cout << "Приказ не утверждён Деканом. Пока вы не переведены на следующий семестр." << endl;
	_getch();
}

int main() {
	setlocale(LC_ALL, "rus");
	student s;
	teacher t;
	dekan d;
	metodist m;
	while (1) {
		system("cls");
		cout << "Выберете пользователя:" << endl;
		cout << "1. Студент" << endl;
		cout << "2. Преподаватель" << endl;
		cout << "3. Методист" << endl;
		cout << "4. Декан" << endl;
		cout << "5. Выход" << endl;
		int switcher = 0;
		cin >> switcher;
		switch (switcher)
		{
		case 1:
			while (1) {
				system("cls");
				cout << "Выберите необходимый пункт:" << endl;
				cout << "1. Сдать лабораторную работу" << endl;
				cout << "2. Сдать экзамен" << endl;
				cout << "3. Проверить, переведён ли ты на следующий семестр." << endl;
				cout << "4. Выход" << endl;
				cin >> switcher;
				if (switcher == 4) {
					break;
				}
				switch (switcher)
				{
				case 1:
					s.passLab();
					break;
				case 2:
					s.passExam();
					break;
				case 3:
					s.perevod();
					break;
				case 4:
					break;
					break;
				default:
					break;
				}
			}
			break;
		case 2:
			while (1) {
				system("cls");
				cout << "Выберите необходимый пункт:" << endl;
				cout << "1. Проверить все новые лабораторные работы" << endl;
				cout << "2. Выставить оценку по экзамену" << endl;
				cout << "3. Выход" << endl;
				cin >> switcher;
				if (switcher == 3) {
					break;
				}
				switch (switcher)
				{
				case 1:
					t.markLab(s);
					break;
				case 2:
					t.markExam(s);
					break;
				case 3:
					break;
					break;
				default:
					break;
				}
			}
			break;
		case 3:
			while (1) {
				system("cls");
				cout << "Выберите необходимый пункт:";
				cout << "1. Создать ведомость";
				cout << "2. Создать приказ о переводе на следующий семестр";
				cout << "3. Выход";
				cin >> switcher;
				if (switcher == 3) {
					break;
				}
				switch (switcher)
				{
				case 1:
					m.createVedomost(s);
					break;
				case 2:
					m.createPrikaz(s);
					break;
				case 3:
					break;
					break;
				default:
					break;
				}
			}
			break;
		case 4:
			while (1) {
				system("cls");
				cout << "Выберите необходимый пункт:";
				cout << "1. Утвердить ведомость";
				cout << "2. Утвердить приказ";
				cout << "3. Выход";
				cin >> switcher;
				if (switcher == 3) {
					break;
				}
				switch (switcher)
				{
				case 1:
					d.acceptVedomost(s);
					break;
				case 2:
					d.acceptPrikaz(s);
					break;
				case 3:
					break;
					break;
				default:
					break;
				}
			}
			break;
		case 5:
			return 0;
		default:
			break;
		}
	}
	return 0;
}
