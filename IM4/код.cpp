#include <iostream>
#include <stdio.h>


using namespace std;

//���������� ������� � ��������
double credit, crediting, creditPayment, loanRate, account, sizeOfCredit, minAccount, paymentSize;
int creditDecision, paymentDecision;


int main(){
    setlocale(LC_ALL, "Russian");

    //������������� ������� � ��������


    creditDecision = 0; paymentDecision = 0;
    credit = 0;  loanRate = 0.01;
    account = 10000; sizeOfCredit = 10000;
    minAccount = 5000; paymentSize = 1000;

    creditPayment = 1000;



 
    //��������� ������
    for (int t = 0; t < 10; t++)
    {
        creditDecision = 0; paymentDecision = 0;
        //����� ������
        printf("���: %d  ����: %10.2f   ������� ������: %.2f\n",t, account, credit);
        //���� ������
        if (account < minAccount) {
            cout << "������� ����� ������?(1 - ��, 0 - ���) ";
            cin >> creditDecision;
            if (creditDecision) {
                cout << "������ �������: ";
                cin >> sizeOfCredit;
            }
        }
        if (credit > 0) {
            cout << "������� ��������� ����� �������? (1 - ��, 0 - ���) ";
            cin >> paymentDecision;
            if (paymentDecision) {
                cout << "������ �������: ";
                cin >> paymentSize;
            }
        }

        //��������� �������, ���������� � ������
        account = account + (rand() % 3000) - 2000;  //�����-����� ��������
        crediting = sizeOfCredit * creditDecision;
        creditPayment = min(account, min(paymentSize * paymentDecision, credit));

        account = account + crediting - creditPayment; //������������
        credit = credit + (credit * loanRate) + crediting - creditPayment;
        
    
    }

    system("pause");

}