#include "Canvas.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	Canvas obj;
	POINT pp[6];
	pp[0].x = 50; pp[0].y = 150;
	pp[1].x = 100; pp[1].y = 100;
	pp[2].x = 150; pp[2].y = 150;
	pp[3].x = 150; pp[3].y = 250;
	pp[4].x = 100;  pp[4].y = 300;
	pp[5].x = 50;  pp[5].y = 250;

	//{ Добавление объектов в список.
	obj.AddObject((Primitive*)new Point(200, 50, RGB(255, 0, 255)));
	obj.AddObject((Primitive*)new Line(40, 300, 70, 200, RGB(138, 43, 226)));
	obj.AddObject((Primitive*)new rectangle(150, 100, 200, 250, RGB(0, 0, 255), true));
	obj.AddObject((Primitive*)new ellipse(300, 300, 400, 400, RGB(255, 255, 0), true));
	obj.AddObject((Primitive*)new polygon(pp, RGB(255, 0, 0), true));

	obj.ObjectOutput(); // Получение информации об объектах в списке.

	system("pause");
	system("cls");

	cout << "Нажмите 'y' чтобы перерисовать фигуру" << endl;
	cout << "Нажмите 'n' чтобы завершить программу" << endl;
	system("pause");
	system("cls");

	char button = 0; // Вывод фигур, хранящихся в списке.
	while (button != 'n') { 
		cin >> button;
		system("cls");
		switch (button) {
		case 121:
			obj.Show();
			break;
		}

	}

	obj.DeleteObject(2);
	cout << "Объект №2 удалён(линия)" << endl;

	system("pause");
	system("cls");

	cout << "Нажмите 'y' чтобы перерисовать фигуру" << endl;
	cout << "Нажмите 'n' чтобы завершить программу" << endl;
	system("pause");
	system("cls");

	button = 0; // Вывод фигур, хранящихся в списке.
	while (button != 'n') {
		cin >> button;
		system("cls");
		switch (button) {
		case 121:
			obj.Show();
			break;
		}

	}
	return 0;
}