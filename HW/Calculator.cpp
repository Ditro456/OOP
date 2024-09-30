#include <iostream>
#include <string>

using namespace std; //cin cout�� ���Ǽ� ������ �ۼ���

class Add {
private:
    int a, b;//������ ������ �Ű������� ����� ����ϱ� ���� �ۼ���
public://����ο� �������� �и��� ���ؼ� ������
    void setValue(int x, int y);
    int calculate();
};
//����ο� �����θ� �и��Ͽ� ������ �ذ���
void Add::setValue(int x, int y) {
    a = x;
    b = y;
}
int Add::calculate() {
    return a + b;
}

class Sub {
private:
    int a, b;//������ ������ �Ű������� ����� ����ϱ� ���� �ۼ���
public://����ο� �������� �и��� ���ؼ� ������
    void setValue(int x, int y);
    int calculate();
};
//����ο� �����θ� �и��Ͽ� ������ �ذ���
void Sub::setValue(int x, int y) {
    a = x;
    b = y;
}
int Sub::calculate() {
    return a - b;
}

class Mul {
private:
    int a, b;//������ ������ �Ű������� ����� ����ϱ� ���� �ۼ���
public://����ο� �������� �и��� ���ؼ� ������
    void setValue(int x, int y);
    int calculate();
};
//����ο� �����θ� �и��Ͽ� ������ �ذ���
void Mul::setValue(int x, int y) {
    a = x;
    b = y;
}
int Mul::calculate() {
    return a * b;
}

class Div {
private:
    int a, b;//������ ������ �Ű������� ����� ����ϱ� ���� �ۼ���
public://����ο� �������� �и��� ���ؼ� ������
    void setValue(int x, int y);
    int calculate();
};
//����ο� �����θ� �и��Ͽ� ������ �ذ���
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
    while (true) {//���ѷ����� ���ؼ� �ۼ���
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