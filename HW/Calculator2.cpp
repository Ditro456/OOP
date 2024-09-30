#include <iostream>
#include <string>
#include "calculator.h"//Ŭ���� ������� ��������� �ҷ���

using namespace std;//cin cout�� ���Ǽ� ������ �ۼ���
//Ŭ������ ������ �ڵ�
void Add::setValue(int x, int y) {
    a = x;
    b = y;
}

int Add::calculate() {
    return a + b;
}

void Sub::setValue(int x, int y) {
    a = x;
    b = y;
}

int Sub::calculate() {
    return a - b;
}

void Mul::setValue(int x, int y) {
    a = x;
    b = y;
}

int Mul::calculate() {
    return a * b;
}

void Div::setValue(int x, int y) {
    a = x;
    b = y;
}

int Div::calculate() {
    return a / b;
}

int main() {
    //������ �ۼ��� ǥ���
    Add a;
    Sub s;
    Mul m;
    Div d;
    while (true) {//���α׷��� ���ѷ����� ����
        //������ �ۼ��� ǥ���
        cout << "�� ������ �����ڸ� �Է��ϼ���>>";
        int x, y;
        char op;
        cin >> x >> y >> op;

        //�������� ������ ���ؼ� IF���� �ƴ� Switch���� ����Ͽ� ������ �����ϰ���
        switch (op) {
        case '+':
            a.setValue(x, y);
            cout << a.calculate() << endl;
            break;
        case '-':
            s.setValue(x, y);
            cout << s.calculate() << endl;
            break;
        case '*':
            m.setValue(x, y);
            cout << m.calculate() << endl;
            break;
        case '/':
            d.setValue(x, y);
            cout << d.calculate() << endl;
            break;
        default:
            break;
        }
    }

    return 0;
}