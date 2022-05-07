#include <iostream>

using namespace std;

class  PersegiPanjang{
    public:
        int x_min;
        int x_max;
        int y_min;
        int y_max;

    //operasi pertambahan antar dua persegi
    PersegiPanjang operator+ (PersegiPanjang kedua){
        PersegiPanjang new_persegi;
        if(PersegiPanjang::x_min <= kedua.x_min){
            new_persegi.x_min = PersegiPanjang::x_min;
        } else {
            new_persegi.x_min = kedua.x_min;
        }

        if(PersegiPanjang::x_max >= kedua.x_max){
            new_persegi.x_max = PersegiPanjang::x_max;
        } else {
            new_persegi.x_max = kedua.x_max;
        }

        if(PersegiPanjang::y_min <= kedua.y_min){
            new_persegi.y_min = PersegiPanjang::y_min;
        } else {
            new_persegi.y_min = kedua.y_min;
        }

        if(PersegiPanjang::y_max >= kedua.y_max){
            new_persegi.y_max = PersegiPanjang::y_max;
        } else {
            new_persegi.y_max = kedua.y_max;
        }

        return new_persegi;
    }

    //operasi pengurangan antar dua persegi
    PersegiPanjang operator- (PersegiPanjang kedua){
        PersegiPanjang new_persegi;
        if(PersegiPanjang::x_min >= kedua.x_min){
            new_persegi.x_min = PersegiPanjang::x_min;
        } else {
            new_persegi.x_min = kedua.x_min;
        }

        if(PersegiPanjang::x_max <= kedua.x_max){
            new_persegi.x_max = PersegiPanjang::x_max;
        } else {
            new_persegi.x_max = kedua.x_max;
        }

        if(PersegiPanjang::y_min >= kedua.y_min){
            new_persegi.y_min = PersegiPanjang::y_min;
        } else {
            new_persegi.y_min = kedua.y_min;
        }

        if(PersegiPanjang::y_max <= kedua.y_max){
            new_persegi.y_max = PersegiPanjang::y_max;
        } else {
            new_persegi.y_max = kedua.y_max;
        }

        return new_persegi;
    }

    //operasi untuk menambah dua kali luasan 
    PersegiPanjang operator ++(){
        PersegiPanjang new_persegi;

        new_persegi.x_min = PersegiPanjang::x_min;
        new_persegi.x_max = PersegiPanjang::x_max * 2;
        new_persegi.y_min = PersegiPanjang::y_min;
        new_persegi.y_max = PersegiPanjang::y_max * 2;

        return new_persegi;
    }

    //operasi untuk mengurangi 1/2 kali luasan
    PersegiPanjang operator --(){
        PersegiPanjang new_persegi;

        new_persegi.x_min = PersegiPanjang::x_min;
        new_persegi.x_max = PersegiPanjang::x_max / 2;
        new_persegi.y_min = PersegiPanjang::y_min;
        new_persegi.y_max = PersegiPanjang::y_max / 2;

        return new_persegi;
    }

    //operator index
    int operator[](int index){
        switch (index)
        {
        case 0:
            return PersegiPanjang::x_min;
            break;
        case 1:
            return PersegiPanjang::x_max;
            break;
        case 2:
            return PersegiPanjang::y_min;
            break;
        case 3:
            return PersegiPanjang::y_max;
            break;
        default:
            break;
        }
    }

    //operator untuk menentukan irisan atau tidak
    bool operator == (PersegiPanjang kedua){
        bool is_xirisan = (PersegiPanjang::x_min < kedua.x_max) && (kedua.x_min < PersegiPanjang::x_max);
        bool is_yirisan = (PersegiPanjang::y_min < kedua.y_max) && (kedua.y_min < PersegiPanjang::y_max);

        bool is_irisan = is_xirisan && is_yirisan;

        return is_irisan;
    }

    //method untuk menampilkan data
    void getTampilkan(){
        cout << "Posisi persegipanjang saat ini : " << endl;
        cout << x_min << " " << x_max << endl;
        cout << y_min << " " << y_max << endl;
        cout << endl;
    }

};

int main(int argc, char const *argv[])
{
    PersegiPanjang pos1;
    PersegiPanjang pos2;
    //variabel untuk input data
    int x1,y1,p1,l1;
    int x2,y2,p2,l2;


    cout << "PERSEGI PANJANG AJAIB" << endl;
    cout << "_____________________" << endl;

    cout << "Sebelum Masuk ke lasngkah berikutnya, buat persegi terlebih dahulu"<< endl;
    cout << "Masukkan Titik pusat X : ";
    cin >> x1;
    cout << "Masukkan titik pusat Y : ";
    cin >> y1;
    cout << "Masukkan panjang persegi : ";
    cin >> p1;
    cout << "Masukkan lebar persegi : ";
    cin >> l1;

    //memasukkan data input ke object pos1
    pos1.x_min = x1 - (p1/2);
    pos1.x_max = x1 + (p1/2);
    pos1.y_min = y1 - (l1/2);
    pos1.y_max = y1 + (l1/2);

    while (true)
    {
        cout << "PERSEGI PANJANG AJAIB" << endl;
        cout << "_____________________" << endl;
        cout << "Menu: " << endl;
        cout << "1 : Menambahkan luas persegi panjang (operator +)" << endl;
        cout << "2 : Mengurangi luar persegi panjang (operator -)" << endl;
        cout << "3 : Menambah luasan menjadi 2 kali luasan (operator ++)" << endl;
        cout << "4 : Mengurangi luasan menjadi 1/2 kali luasan (operator --)" << endl;
        cout << "5 : Mengambil salah satu atribut PersegiPanjang (operator [])" << endl;
        cout << "6 : Cek irisan dengan suatu persegi (operator ==)" << endl;
        cout << "7 : Ubah Persegi saat ini" << endl;
        cout << "8 : Tampilkan persegi saat ini" << endl;
        cout << "9 : break/selesai" << endl;
        cout << endl;

        int pilihan;
        cin >> pilihan;
        if(pilihan == 9){
            break;
        }

        switch (pilihan)
        {
        case 1:
            cout << "Input Persegi kedua : " << endl;
            cout << "Masukkan Titik pusat X : ";
            cin >> x2;
            cout << "Masukkan titik pusat Y : ";
            cin >> y2;
            cout << "Masukkan panjang persegi : ";
            cin >> p2;
            cout << "Masukkan lebar persegi : ";
            cin >> l2;
            cout << endl;
            pos2.x_min = x2 - (p1/2);
            pos2.x_max = x2 + (p1/2);
            pos2.y_min = y2 - (l1/2);
            pos2.y_max = y2 + (l1/2);

            if(pos1 == pos2){
                pos1 = pos1 + pos2;
                pos1.getTampilkan();
            } else {
                cout << "maaf, persegi tidak beririsan, operasi tidak dapat dilakukan" << endl << endl;
            }

            /* code */
            break;
        case 2:
            cout << "Input Persegi kedua : " << endl;
            cout << "Masukkan Titik pusat X : ";
            cin >> x2;
            cout << "Masukkan titik pusat Y : ";
            cin >> y2;
            cout << "Masukkan panjang persegi : ";
            cin >> p2;
            cout << "Masukkan lebar persegi : ";
            cin >> l2;
            cout << endl;
            pos2.x_min = x2 - (p1/2);
            pos2.x_max = x2 + (p1/2);
            pos2.y_min = y2 - (l1/2);
            pos2.y_max = y2 + (l1/2);

            if(pos1 == pos2){
                pos1 = pos1 - pos2;
                pos1.getTampilkan();
            } else {
                cout << "maaf, persegi tidak beririsan, operasi tidak dapat dilakukan" << endl << endl;
            }
            break;
            
        case 3:
            pos1 = ++pos1;
            pos1.getTampilkan();
            break;
             
        case 4:
            pos1 = --pos1;
            pos1.getTampilkan();
            break;

        case 5:
            cout << "Mengambil atribut" << endl;
            cout << "pilih index ke berapa yang mau diambil" << endl;
            cout << "(0: xmin, 1:xmax, 2:ymin, 3:ymax)" << endl;
            int choice;
            cin >> choice;
            cout << pos1[choice] << endl << endl;
            break;

        case 6:
            cout << "Cek irisan" << endl<<endl;
            cout << "Input Persegi kedua : " << endl;
            cout << "Masukkan Titik pusat X : ";
            cin >> x2;
            cout << "Masukkan titik pusat Y : ";
            cin >> y2;
            cout << "Masukkan panjang persegi : ";
            cin >> p2;
            cout << "Masukkan lebar persegi : ";
            cin >> l2;
            cout << endl;
            pos2.x_min = x2 - (p1/2);
            pos2.x_max = x2 + (p1/2);
            pos2.y_min = y2 - (l1/2);
            pos2.y_max = y2 + (l1/2);

            if(pos1 == pos2){
                cout << "Beririsan" << endl << endl;
            } else {
                cout << "Tidak Beririsan" << endl << endl;
            }            
            break;

        case 7:
            cout << "Masukkan Titik pusat X : ";
            cin >> x1;
            cout << "Masukkan titik pusat Y : ";
            cin >> y1;
            cout << "Masukkan panjang persegi : ";
            cin >> p1;
            cout << "Masukkan lebar persegi : ";
            cin >> l1;
            //untuk input ke class
            pos1.x_min = x1 - (p1/2);
            pos1.x_max = x1 + (p1/2);
            pos1.y_min = y1 - (l1/2);
            pos1.y_max = y1 + (l1/2);

            pos1.getTampilkan();
            break;
        case 8:
            pos1.getTampilkan();
        default:
            break;
        } 
    }
    return 0;
}
