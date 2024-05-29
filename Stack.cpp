#include "Stack.h" 
#include <iostream>

using namespace std;

Stack::Stack()
{
    top = -1;
}

bool Stack::Push(int x)
{ //Yığına yeni bir eleman eklemeyi sağlar
    if (top >= (BOYUT - 1))
    {
        cout << "Yigin Dolu";
        return false;
    }
    else
    {
        YIGIN[++top] = x;
        cout << x << " degeri Yigina eklendi\n";
        return true;
    }
}

int Stack::Pop()
{ //Yığına eklenen son elemanı çıkarmaya yarar.
    if (top < 0)
    {
        cout << "Yigin Bos";
        return 0;
    }
    else
    {
        int x = YIGIN[top--];
        return x;
    }
}

bool Stack::IsEmpty()
{ /*Yığının boş olup olmadığını kullanıcıya bildirir.
Yığın boş ise true aksi durumda false dönecektir.*/
    return (top < 0);
}

int Stack::StackTop()
{/*stackTop( ) fonksiyonu eklenen son elemanı göstermek için*/
    if (top == -1)
    {
        cout << "\n yigin bos";
        return -1;
    }
    else
        return (YIGIN[top]);
}

void Stack::WriteAll()
{
    if (top >= 0) {
        cout << "Yigindaki elemanlar:";
        for (int i = top; i >= 0; i--)
            cout << YIGIN[i] << " ";
        cout << endl;
    }
    else
        cout << "Yigin bos" << endl;
}

void Stack::DeleteAll()
{
    top = -1;
}

void Stack::DisplayStack() {
    cout << "top -->";
    for (int i = top; i >= 0; i--)
        cout << "\t| " << YIGIN[i] << " | " << endl;
    cout << "\t|----|" << endl;
}

void Stack::stackMenu() {

    int choice, value;
    do {
        cout << "Yigin icin islem seciniz\n";
        cout << "1 - Yigina eleman ekle\n";
        cout << "2 - Yigindan eleman cikar\n";
        cout << "3 - Yigini temizle\n";
        cout << "4 - Yigindaki elemanlari goster\n";
        cout << "5 - Yigindaki eleman sayisini goster\n";
        cout << "6 - Ana sayfaya don\n";
        cout << "Seciminiz: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Eklemek istediginiz degeri giriniz: ";
            cin >> value;
            Push(value);
            break;
        case 2:
            Pop();
            break;
        case 3:
            DeleteAll();
            cout << "Yigin temizlendi\n";
            break;
        case 4:
            WriteAll();
            break;
        case 5:
            cout << "Yigindaki eleman sayisi: " << (top + 1) << endl;
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
