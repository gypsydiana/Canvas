#ifndef CANVA_H
#define CANVA_H
#include <vector>
#include <istream>
#include <iostream>
#include <Windows.h>
#include <conio.h>
struct Primitive {
	int type;
	Primitive(int type);
	virtual void show(HDC hdc); // виртуальный метод, позволяющий использовать метод show конкретного класса
};
class Point : Primitive {
public:
	COLORREF color_circuit;
	int x, y;
	Point();
	Point(int x1, int y1, COLORREF c);
	void show(HDC hdc);
};
class Line : Primitive {
public:
	COLORREF color_circuit;
	Point p1, p2;
	Line(int x1, int y1, int x2, int y2, COLORREF c);
	void show(HDC hdc);
};
class rectangle : Primitive {
public:
	bool colored;
	COLORREF background_color;
	COLORREF color_circuit;
	Point r1, r2;
	rectangle(int x1, int y1, int x2, int y2, COLORREF c, bool colored);
	void show(HDC hdc);
};
class ellipse : Primitive {
public:
	bool colored;
	COLORREF background_color;
	COLORREF color_circuit;
	Point e1, e2;
	ellipse(int x1, int y1, int x2, int y2, COLORREF c, bool colored);
	void show(HDC hdc);
};
class polygon : Primitive {
public:
	bool colored;
	COLORREF color_circuit;
	COLORREF background_color;
	const POINT* Ippt;
	const POINT* Ippt1;
	polygon(const POINT Points[6], COLORREF c , bool colored);
	void show(HDC hdc);
	~polygon();
};
class Canvas {
private:
	std::vector<Primitive*> primitives;
	HWND hWnd;
	HDC hdc;
public:
	Canvas();
	void AddObject(Primitive *obj);
	void DeleteObject(int int_delete);
	void ClearingTheList();
	void ObjectOutput();
	void Show();
	~Canvas();
};
#endif //CANVA_H
