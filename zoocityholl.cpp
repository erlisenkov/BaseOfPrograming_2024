#include <iostream>
#include <string>
using namespace std;

class ZooPark
{
public:
    string type;
    string todo;
    string voice;
    string name;
    int age;
};

void wait(int seconds) // доступно для int. Если сделать double seconds(будет работать, но есть варнинг)
{
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait) {}
}

int main() {

    int choice;
    cout << "Добро пожаловать в наш Зоопарк, тут вы встретите незабываемых рептилий и не только" << endl;
    cout << "Пожалуйста, купите билет, чтобы войти в зоопарк (нажмите 1, чтобы купить билет) (нажмите 2, чтобы не покупать билет)" << endl;

    while (true) {
        cout << "Ваш выбор: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Пожалуйста, введите корректное число." << endl;
        }
        else {
            if (choice == 1 || choice == 2) {
                break;
            }
            else {
                cout << "Пожалуйста, выберите 1 или 2." << endl;
            }
        }
        
        

    }

    cout << "Юху, мы это сделали, я верил, что зоопарк будет интересен тебе. Так, а теперь бери вон ту ламу в руки и погнали экскурсовода искать. Нажимай 1 и стартуууееем" << endl;
    
    while (true) {
        cout << "Ваш выбор: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Пожалуйста, введите корректное число." << endl;
        }
        else {
            if (choice == 1) {
                break;
            }
            else {
                cout << "Пожалуйста, выберите 1" << endl;
            }
        }



    }
    wait(1);
    cout << "топ" << endl;
    wait(1);
    cout << "топ" << endl;
    wait(1);
    cout << "топ" << endl;
    wait(1);
    cout << "" << endl;
    cout << "Вот они мои хорошики" << endl;
    cout << "" << endl;

    ZooPark leo;

    leo.type = "Лев";
    leo.age = 1;
    leo.todo = "играет со своими друзьями";
    leo.name = "Лёва";
    leo.voice = "*страшный РРРРРРРРРРРРРРРРРР";
    cout << "А вот наш первый зверёк " << leo.type << " и он " << leo.todo << " и кстати ему " << leo.age << " год. Его зовут " << leo.name << " и он сам приходит, и говорит " << leo.voice << endl;
    
    cout << "---------------------------" << endl;
    wait(2);

    ZooPark wolf;

    wolf.type = "Волк";
    wolf.age = 4;
    wolf.todo = "пьёт водичку из миски";
    wolf.name = "Серый";
    wolf.voice = "*страшный АУУУУУУУУУУУУУУУУ";
    cout << "А вот наш второй зверёк " << wolf.type << " и он " << wolf.todo << " и кстати ему " << wolf.age << " года. Его зовут " << wolf.name << " и он сам приходит, и говорит " << wolf.voice << endl;

    cout << "---------------------------" << endl;
    wait(2);

    ZooPark monkey;

    monkey.type = "Обезьяна";
    monkey.age = 3;
    monkey.todo = "доедает банан";
    monkey.name = "Морковка";
    monkey.voice = "ауаауауащащаоааова";
    cout << "А вот наш третий зверёк " << monkey.type << " и она " << monkey.todo << " и кстати ей " << monkey.age << " годика. Её зовут " << monkey.name << " и она сама приходит, и говорит " << monkey.voice << endl;

    cout << "---------------------------" << endl;
    wait(2);

    ZooPark avakado;

    avakado.type = "Авакадо";
    avakado.age = 2;
    avakado.todo = "лежит";
    avakado.name = "из петёрочки 50 руб кг";
    avakado.voice = "*не разговаривает";
    cout << "А вот наш четвёртый зверёк " << avakado.type << " и это " << avakado.todo << " стоп, что, откуда, кстати ему " << avakado.age << " дня. Его зовут " << avakado.name << " и оно на столе, и говорит " << avakado.voice << endl;


    return 0;
}
