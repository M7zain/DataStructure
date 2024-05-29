#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue() // Kurucu (Yapıcı) fonksiyon
{
    KS = -1;
    KB = -1;
    ES = 0;
}

bool Queue::Ekle(int yeniEleman) {
    if (ES >= BOYUT) // Dizi dolu ve ekleme yapamazsın
        return false; // Kuyruğa ekleme işlemi gerçekleşmedi

    if (KB == -1) {
        KB++;
    }

    if (KS == BOYUT - 1)
        KS = 0; // Kuyruk sonunu 0 yapalım, çünkü zaten KB=0 değil
    else
        KS++;

    Kuyruk[KS] = yeniEleman;
    ES++;
    cout << yeniEleman << " degeri Kuyruga eklendi\n";
    return true; // Kuyruğa ekleme işlemi gerçekleşti
}

bool Queue::Cikar(int& hucre) {
    if (ES == 0)
        return false; // Kuyruk boş, çıkarma işlemi yapılamaz

    hucre = Kuyruk[KB]; // Kuyruğun başındaki elemanı parametreye ata

    if (KB == BOYUT - 1)
        KB = 0;
    else
        KB++;

    ES--;

    if (ES <= 0) // Kuyrukta eleman kalmadıysa başlangıç durumuna getir
        KS = KB = -1;

    cout << hucre << " degeri Kuyruktan cikartildi\n";
    return true; // Çıkarma işlemi yapıldı
}

bool Queue::Bosmu() {
    return (ES == 0);
}

void Queue::Yazdir() {
    if (ES > 0) { // Kuyrukta eleman var
        cout << "Kuyruktaki elemanlar: ";

        if (KS >= KB) {
            for (int i = KB; i <= KS; i++)
                cout << Kuyruk[i] << " ";
        }
        else {
            for (int i = KB; i < BOYUT; i++)
                cout << Kuyruk[i] << " ";
            for (int i = 0; i <= KS; i++)
                cout << Kuyruk[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "Kuyruk bos\n";
    }
}

void Queue::Temizle() {
    KS = KB = -1;
    ES = 0;
    cout << "Kuyruk temizlendi\n";
}

void Queue::queueMenu() {
    int choice, value, removedValue;
    do {
        cout << "Kuyruk icin islem seciniz\n";
        cout << "1 - Kuyruga eleman ekle\n";
        cout << "2 - Kuyruktan eleman cikar\n";
        cout << "3 - Kuyrugu temizle\n";
        cout << "4 - Kuyruktaki elemanlari goster\n";
        cout << "5 - Kuyruktaki eleman sayisini goster\n";
        cout << "6 - Ana sayfaya don\n";
        cout << "Seciminiz: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Eklemek istediginiz degeri giriniz: ";
            cin >> value;
            if (!Ekle(value)) {
                cout << "Kuyruk dolu, ekleme yapilamadi\n";
            }
            break;
        case 2:
            if (Cikar(removedValue)) {
                cout << removedValue << " degeri Kuyruktan cikartildi\n";
            }
            else {
                cout << "Kuyruk bos, cikarma yapilamadi\n";
            }
            break;
        case 3:
            Temizle();
            break;
        case 4:
            Yazdir();
            break;
        case 5:
            cout << "Kuyruktaki eleman sayisi: " << ES << endl;
            break;
        case 6:
            cout << "Ana sayfaya donuluyor...\n";
            break;
        default:
            cout << "Gecersiz secim. Lutfen tekrar deneyin.\n";
            break;
        }
    } while (choice != 6);
}
