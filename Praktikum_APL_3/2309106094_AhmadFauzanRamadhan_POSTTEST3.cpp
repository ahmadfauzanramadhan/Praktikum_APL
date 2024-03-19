#include <iostream>
using namespace std;

#define max 10
string mobil[max], ulang;
int posdex = 0; //NOTE! : posdex = Posisi Index

int login (){
    string userName;
    string userPassword;
    int loginAttempt = 0;

    while (loginAttempt < 3)
    {
        cout << "Silahkan masukkan nama Anda : ";
        cin >> userName;
        cout << "Silahkan masukkan NIM Anda : ";
        cin >> userPassword;

        if (userName == "Ojan" && userPassword == "2309106094")
        {
            cout << "Selamat Datang Di Program Konversi Suhu\n";
            break;
        }
        else
        {
            cout << "NIM/NAMA ANDA SALAH. Silahkan COBA LAGI\n" << '\n';
            loginAttempt++;
        }
    }
    if (loginAttempt == 3)
    {
            cout << "Terlalu banyak percobaan. Program berhenti";
            return 0;
    }
    return 0;
}

void tampilkn(){
    system("cls");
    if(posdex > 0){
        cout << "==============" << endl;
        cout << "Data Tersimpan" << endl;
        cout << "==============" << endl;
        for(int a = 0; a < posdex; a++){
            cout << a+1 << ". " << mobil[a] << endl;
        }
    } else {
        cout << "===========\n";
        cout << "Data Kosong\n";
        cout << "===========\n";
    }
}

void tambah(){
    tampilkn();
    if (posdex < max){
        cin.ignore();
        cout << "Masukkan Merk : ";
        getline(cin, mobil[posdex]);
        posdex++;

        cout << "Tambah data lagi? (y/n): ";
        cin >> ulang;
        if (ulang == "y") {
            tambah(); // <-- Letak rekursi
        }
    } else {
        cout << "Data Penuh!" << endl;
        cout << "Ketik E Untuk Kembali : ";
        cin >> ulang;
    }
}

void ubah(){
    int dex;
    do{
        tampilkn();
        cout << "Ubah Data Ke : ";
        cin >> dex;
        cin.ignore();
        cout << "Ubah Menjadi : ";
        getline(cin, mobil[dex-1]);
        tampilkn();
        cout << "Apakah Ingin Mengubah Ubah Lagi? <y/n> : ";
        cin >> ulang;
    } while(ulang == "y");
}

void hpus(){
    int dex;
    do{
        tampilkn();
        if(posdex > 0){
            cout << "Hapus Data Ke : ";
            cin >> dex;
            for(int inpt = dex; inpt < posdex; inpt++){
                mobil[inpt-1] = mobil[inpt];
            }
            posdex--;
            tampilkn();
            cout << "Ingin Menghapus Lagi? <y/n> : ";
            cin >> ulang;
        } else {
            cout << "Isikan t : ";
            cin >> ulang;
        }

    } while(ulang == "y");
}

int main() {
    int pilih;
    login();
    do{
        system("cls");
            cout << "======================================\n";
            cout << "Selamat Datang Di List Merk-merk Mobil\n";
            cout << "============" << endl;
            cout << "1. Tambah\n2. Ubah\n3. Hapus\n4. Tampilkan\n5.Keluar" << endl;
            cout << "============" << endl;
    cout << "Pilih : ";
    cin >> pilih;
    switch(pilih){
        case 1:
            tambah();
            break;
        case 2:
            ubah();
            break;
        case 3:
            hpus();
            break;
        case 4:
            do{
                tampilkn();
                cout << "Kembali? <y/n> : ";
                cin >> ulang;
            } while(ulang != "y");

            break;
        case 5:
            break;
        default:
            cout << "Pilih 1 - 5" << endl;
            break;
        }
    } while(pilih != 5);
    cout << "===============" << endl;
    cout << "Program selesai\n";
    cout << "===============" << endl;
}
