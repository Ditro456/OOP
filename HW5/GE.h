#ifndef GE_H
#define GE_H
#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Line.h"
#include "Rect.h"
#include "UI.h"

class GraphicEditor {
    Shape* pStart;
    Shape* pLast;

    void insert();
    void remove();
    void paint();

    bool addShape(Shape* a, int idx = -1);
    bool rmvShape(int idx = -1);

public:
    GraphicEditor() { pStart = pLast = nullptr; }
    ~GraphicEditor();
    void start();
};
#endif // !GE_H