#include <iostream>
#include <string>

using namespace std;

class Printer {
    string model, manuf;
    int  avlcount;
protected:
    Printer(string model, string manuf, int avlcount){
        this->model = model; 
        this->manuf = manuf;
        this->avlcount = avlcount;
    }
    bool print(int pCount) {
        if (pCount < 0) {
            cout << "�߸��� �Է��Դϴ�.\n";
            return false;
        }
        if (avlcount < pCount) {
            cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�.\n";
            return false;
        }
        avlcount -= pCount;
        return true;
    }
    string get_model() const { return model; }
    string get_manuf() const { return manuf; }
    int get_avlcount() const { return avlcount; }
};

class InkJetPrinter : public Printer {
    int avlink;
public:
    InkJetPrinter(string model, string manuf, int avlcount, int avlink) : Printer(model, manuf, avlcount) {
        this->avlink = avlink;
    }
    bool InkJetprint(int pCount){
        if (avlink < pCount) {
            cout << "��ũ�� �����Ͽ� ����Ʈ �� �� �����ϴ�.\n";
            return false;
        }
        if (!print(pCount))
            return false;
        avlink -= pCount;
        return true;
    }
    void show() {
        cout << get_model() << ", " << get_manuf() << ", ���� ����: " << get_avlcount() << "��, ���� ��ũ: " << avlink << endl;
    }
};

class LaserPrinter : public Printer {
    int avltoner;
public:
    LaserPrinter(string model, string manuf, int avlcount, int avltoner) : Printer(model, manuf, avlcount) {
        this->avltoner = avltoner;
    }
    bool Laserprint(int pCount){
        if (avltoner < pCount) {
            cout << "��ʰ� �����Ͽ� ����Ʈ �� �� �����ϴ�.\n";
            return false;
        }
        if (!print(pCount))
            return false;
        avltoner -= pCount;
        return true;
    }
    void show(){
        cout << get_model() << ", " << get_manuf() << ", ���� ����: " << get_avlcount() << "��, ���� ���: " << avltoner << endl;
    }
};

int main() {
    int pNum, pCount;
    char yon;
    InkJetPrinter* inkjet = new InkJetPrinter("Officejet V40", "Hp", 7, 5);
    LaserPrinter* laser = new LaserPrinter("SCX-6x45", "�Ｚ����", 3, 5);

    cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����\n";
    cout << "��ũ�� : ";
    inkjet->show();
    cout << "������ : ";
    laser->show();
    cout << endl;

    while (true) {
        cout << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
        cin >> pNum >> pCount;

        bool success = false;
        if (pNum == 1) 
            success = inkjet->InkJetprint(pCount);
        else if (pNum == 2) 
            success = laser->Laserprint(pCount);
        else 
            cout << "�����͸� �߸� �����ϼ̽��ϴ�.\n";

        if (success) 
            cout << "����Ʈ�� �Ϸ�Ǿ����ϴ�.\n";
        inkjet->show();
        laser->show();

        while (true) {
            cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
            cin >> yon;
            if (yon == 'y')
                break;
            else if (yon == 'n') 
                return 0;
            else 
                cout << "�߸� �Է��ϼ̽��ϴ�.\n";
        }
    }
    delete inkjet;
    delete laser;
    return 0;
}