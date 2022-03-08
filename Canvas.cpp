#include "Canvas.h"

void Point::show(HDC hdc) {
	SetPixel(hdc, x, y, color_circuit);
}
Point::Point() :Primitive(1) {
	x = 0;
	y = 0;
}
Point::Point(int x1, int y1, COLORREF c ) : Primitive(1) {
	color_circuit = c;
	x = x1;
	y = y1;
}
Line::Line(int x1, int y1, int x2, int y2, COLORREF c ): Primitive(2) {
	color_circuit = c;
	p1.x = x1;
	p1.y = y1;
	p2.x = x2;
	p2.y = y2;
}
void Line::show(HDC hdc) {
	SelectObject(hdc, GetStockObject(DC_PEN)); // выбор стандартного пера
	SetDCPenColor(hdc, color_circuit); // установка цвета контура фигуры
	MoveToEx(hdc, p1.x, p1.y, NULL);//устанавливает координаты текущей точки на устройстве
	LineTo(hdc, p2.x, p2.y);//рисуем линию из первой точки в новые 
}
rectangle::rectangle(int x1, int y1, int x2, int y2, COLORREF c, bool colored):Primitive(3) {
	colored = 0;
	background_color = c;
	color_circuit = c;
	r1.x = x1;
	r1.y = y1;
	r2.x = x2;
	r2.x = y2;
}
void rectangle::show(HDC hdc) {
	SelectObject(hdc, GetStockObject(DC_PEN)); // выбор стандартного пера
	SetDCPenColor(hdc, color_circuit); // установка цвета контура фигуры
	SetDCBrushColor(hdc, background_color); // установка цвета закраски
	if (colored)
	{
		SelectObject(hdc, GetStockObject(DC_BRUSH)); // выбор стандартной кисти
	}
	else
	{
		SelectObject(hdc, GetStockObject(NULL_BRUSH)); // отключение закраски
	}
	Rectangle(hdc, r1.x, r1.y, r2.x, r2.y);
}
ellipse::ellipse(int x1, int y1, int x2, int y2, COLORREF c, bool colored):Primitive(4) {
	color_circuit = 0;
	colored = 0;
	e1.x = x1;
	e1.y = y1;
	e2.x = x2;
	e2.y = y2;
}
void ellipse::show(HDC hdc) {
	SelectObject(hdc, GetStockObject(DC_PEN)); // выбор стандартного пера
	SetDCPenColor(hdc, color_circuit); // установка цвета контура фигуры
	SetDCBrushColor(hdc, background_color); // установка цвета закраски
	if (colored)
	{
		SelectObject(hdc, GetStockObject(DC_BRUSH)); // выбор стандартной кисти
	}
	else
	{
		SelectObject(hdc, GetStockObject(NULL_BRUSH)); // отключение закраски
	}
	Ellipse(hdc, e1.x, e1.y, e2.x, e2.y);
}
polygon::polygon(const POINT Points[6], COLORREF c, bool colored) :Primitive(5) {
	colored = 0;
	color_circuit = c;
	background_color = c;
	Ippt = Points;
	Ippt1 = Points;
}

void polygon::show(HDC hdc) {
	SelectObject(hdc, GetStockObject(DC_PEN));
	SetDCPenColor(hdc, color_circuit);
	SetDCBrushColor(hdc, background_color);
	if (colored) {
		SelectObject(hdc, GetStockObject(DC_BRUSH));
	}
	else {
		SelectObject(hdc, GetStockObject(NULL_BRUSH));
	}
	Polygon(hdc, Ippt, 6);
}

polygon :: ~polygon() {}

Canvas :: ~Canvas() {
	ReleaseDC(hWnd, hdc);
	primitives.clear();
}
Canvas::Canvas() {
	HWND hWnd = GetConsoleWindow(); // ссылка на окно
	hdc = GetDC(hWnd);
}
void Canvas::AddObject(Primitive *obj) {
	this->primitives.push_back(obj);
}
void Canvas::DeleteObject(int int_delete) {
	primitives.erase(primitives.begin() + (int_delete - 1));
}
void Canvas::ClearingTheList() {
	primitives.clear();
}
void Canvas::ObjectOutput() {
	for (int i = 0; i < primitives.size(); i++) {
		switch (primitives.at(i)->type){
		case 1: {
			Point* pptr1 = (Point*)primitives.at(i);
			std::cout << "Point (" << pptr1->x << "," << pptr1->y << ")" << std::endl;
		}
				break;
		case 2: {
			Line* pptr2 = (Line*)primitives.at(i);
			std::cout << "Line (" << pptr2->p1.x << "," << pptr2->p1.y << "," << pptr2->p2.x << "," << pptr2->p2.y << ")" << std::endl;
		}
				break;
		case 3: {
			rectangle* pptr3 = (rectangle*)primitives.at(i);
			std::cout << "Rectangle (" << pptr3->r1.x << "," << pptr3->r1.y << "," << pptr3->r2.x << "," << pptr3->r2.y << ")" << std::endl;
		}
				break;
		case 4: {
			ellipse* pptr4 = (ellipse*)primitives.at(i);
			std::cout << "Ellipse (" << pptr4->e1.x << "," << pptr4->e1.y << "," << pptr4->e2.x << "," << pptr4->e2.y << ")" << std::endl;
		}
				break;
		case 5: {
			polygon* pptr5 = (polygon*)primitives.at(i);
			std::cout << "Polygon (";
			for (int j = 0; j < 6; j++) {
				if (j != 5) {
					std::cout << pptr5->Ippt1->x << ", ";
					std::cout << pptr5->Ippt1->y << "; ";
					pptr5->Ippt1++;
				}
				else {
					std::cout << pptr5->Ippt1->x << ", ";
					std::cout << pptr5->Ippt1->y;
					pptr5->Ippt1++;
				}
			}
			std::cout << ")" << std::endl;
			pptr5->Ippt1 = pptr5->Ippt;
			break;
		}
		}
	}
}
void Primitive::show(HDC hdc) {}
void Canvas::Show() {
	for (int i = 0; i < primitives.size(); i++) {
		primitives[i]->show(hdc);
	}
}// метод рисования 
Primitive::Primitive(int type) {
	this->type = type;
}
