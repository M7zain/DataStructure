
#define BOYUT 10
class Queue
{
    private:
    	int		Kuyruk[BOYUT]; //Kuyruk elemanlarının tutulacağı dizi
    	int		KB; //Kuyruğun ilk elemanının indis değerini tutan değişken
    	int		KS; //Kuyruğun son elemanının indis değerini tutan değişken
    	int		ES; //eleman sayısı
    public:
    	Queue();
    	bool	Ekle(int yeniEleman); //Kuyruğa eleman ekleme (Enqueue) Geçen Push() demiştik
    	bool	Cikar(int& hucre); //Kuyruktan eleman çıkarma (Dequeue) Geçen Pop() demiştik
    	bool	Bosmu(); //IsEmty() demiştik geçen hafta
    	void  	Yazdir(); //writeAll() Display() demiştik geçen hafta
        void    Temizle(); //kuyruktaki butun elemanlari siler 
        void    queueMenu(); //kuyruk icin olan menu
};

