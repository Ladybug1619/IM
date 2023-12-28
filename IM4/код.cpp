#include <iostream>
#include <stdio.h>


using namespace std;

//Объявление уровней и констант
double credit, crediting, creditPayment, loanRate, account, sizeOfCredit, minAccount, paymentSize;
int creditDecision, paymentDecision;


int main(){
    setlocale(LC_ALL, "Russian");

    //Инициализация уровней и констант


    creditDecision = 0; paymentDecision = 0;
    credit = 0;  loanRate = 0.01;
    account = 10000; sizeOfCredit = 10000;
    minAccount = 5000; paymentSize = 1000;

    creditPayment = 1000;



 
    //Пошаговый расчет
    for (int t = 0; t < 10; t++)
    {
        creditDecision = 0; paymentDecision = 0;
        //вывод данных
        printf("Шаг: %d  Счет: %10.2f   Текущий кредит: %.2f\n",t, account, credit);
        //ввод данных
        if (account < minAccount) {
            cout << "Желаете взять кредит?(1 - да, 0 - нет) ";
            cin >> creditDecision;
            if (creditDecision) {
                cout << "Размер кредита: ";
                cin >> sizeOfCredit;
            }
        }
        if (credit > 0) {
            cout << "Желаете выплатить часть кредита? (1 - да, 0 - нет) ";
            cin >> paymentDecision;
            if (paymentDecision) {
                cout << "Размер выплаты: ";
                cin >> paymentSize;
            }
        }

        //изменение уровней, переменных и темпов
        account = account + (rand() % 3000) - 2000;  //доход-убыль магазина
        crediting = sizeOfCredit * creditDecision;
        creditPayment = min(account, min(paymentSize * paymentDecision, credit));

        account = account + crediting - creditPayment; //кредитование
        credit = credit + (credit * loanRate) + crediting - creditPayment;
        
    
    }

    system("pause");

}