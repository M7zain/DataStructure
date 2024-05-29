#include<iostream> 
using namespace std;

#define BOYUT 10 

class Stack
{
    int top; //indis bilgisi
    int YIGIN[BOYUT]; /*Veri tiplerimiz private çünkü
    kullanıcı örneğin «top» değişkenini kafasına göre değiştirmesin
    yani yığının yapısını bozmasın*/
public:

    Stack(); /*Kurucu fonksiyon; sınıftan bir nesne oluşturduğumuzda
    başlangıç değerlerini belirliyor*/

    bool Push(int x);  /*İşlemin gerçekleşip gerçekleşmediğinin
    anlaşılması için bool kullanıyoruz.*/
    int Pop(); //silinen sayıyı göterecek
    bool IsEmpty(); /*top elemanı -1 değerine sahipse yığın boş demek olacak.*/
    int StackTop(); /*stackTop( ) fonksiyonu eklenen son elemanı göstermek için*/
    void WriteAll();
    void DisplayStack();
    void DeleteAll();   
    void stackMenu();

};
/*- Kurucu fonksiyon; yığını başlangıç durumuna getirir.
Yığın başlangıçta elemana sahip olmadığından top=-1 olmalıdır.
Yani bu durum yığının boş olduğunu gösterir.
Top = BOYUT-1 olursa yığın dolu demektir.
*/