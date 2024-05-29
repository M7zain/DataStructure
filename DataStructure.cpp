#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "Node.h"
#include "BinaryTree.h"
#include "HashTable.h"

using namespace std;



 void mainMenu() {

     cout << "Yapmak istediginiz uygulamayi seciniz:" << endl;
     cout << "1-yigin uygulamasi                    " << endl;
     cout << "2-kuyruk uygulamasi:                  " << endl;
     cout << "3-Tek yonlu bagli liste uygulamasi    " << endl;
     cout << "4-ikili agac uygulamasi               " << endl;
     cout << "5-Cirpilama uygulamasi                " << endl;
     cout << "6-programdan cikis                    " << endl;

 }


int main()
{
    int secim; 
    Stack yigin;
    Queue kuyruk; 
    Node bagliListe;
    BinaryTree ikiliAgac;
    HashTable hashTablo; 

    do {
        mainMenu();
        cin >> secim;

        switch (secim) {
        case 1:
            yigin.stackMenu();
            break;
        case 2:
             kuyruk.queueMenu();
            break;
        case 3:
            bagliListe.linkedListMenu();
            break;
        case 4:
             ikiliAgac.binaryTreeMenu();
            break;
        case 5:
               hashTablo.hashTableMenu();
            break;
        case 6:
            cout << "Programdan cikiliyor...\n";
            break;
        default:
            cout << "Gecersiz secim. Lutfen tekrar deneyin.\n";
            break;
        }
    } while (secim != 6);


}

