#include<iostream>
using namespace std;

int login (){
    string userName;
    string userPassword;
    int loginAttempt = 0;

    while (loginAttempt < 3)
    {
        cout << "Silahkan masukkan Username Anda : ";
        cin >> userName;
        cout << "Silahkan masukkan kata sandi Anda : ";
        cin >> userPassword;

        if (userName == "Ojan" && userPassword == "123")
        {
            cout << "Selamat Datang Di Program Konversi Suhu\n";
            break;
        }
        else
        {
            cout << "Kata sandi/username salah. Silahkan coba lagi\n" << '\n';
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


int pilih(){
    string pilih;
    double celcius, kelvin, reamur, fahrenheit;

    cout << "Pilih suhu apa yang mau anda konversi" << endl;
    cout << "1. Celcius" << endl;
    cout << "2. Kelvin" << endl;
    cout << "3. Reamur" << endl;
    cout << "4. Fahrenheit" << endl;
    cout << "Masukkan pilihan Anda : " << endl;
    cin >> pilih;

    if(pilih == "1"){
        cout << "Masukkan suhu celcius yang akan dikonversikan : " << endl;
        cin >> celcius;
        kelvin = celcius + 273;
        reamur = celcius * 4 / 5;
        fahrenheit = (celcius * 9 / 5) + 32;
        cout << celcius << " Celcius = " << kelvin << " Derajat Kelvin" << endl;
        cout << celcius << " Celcius = " << reamur << " Derajat Reamur" << endl;
        cout << celcius << " Celcius = " << fahrenheit << " Derajat Fahrenheit" << endl;
    } else if(pilih == "2"){
        cout << "Masukkan suhu kelvin yang akan dikonversikan : " << endl;
        cin >> kelvin;
        celcius = kelvin - 273;
        reamur = (kelvin - 273 ) * 4 / 5;
        fahrenheit = (kelvin - 273) * 9 / 5 + 32;
        cout << kelvin << " Kelvin = " << celcius << " Derajat Celcius" << endl;
        cout << kelvin << " Kelvin = " << reamur << " Derajat Reamur" << endl;
        cout << kelvin << " Kelvin = " << fahrenheit << " Derajat Fahrenheit" << endl;
    } else if(pilih == "3"){
        cout << "Masukkan suhu reamur yang akan dikonversikan : " << endl;
        cin >> reamur;
        celcius = reamur * 5 / 4;
        kelvin = reamur * 5 / 4 + 32;
        fahrenheit = reamur * 9 / 4 + 32;
        cout << reamur << " Reamur = " << celcius << " Derajat Celcius" << endl;
        cout << reamur << " Reamur = " << kelvin << " Derajat Kelvin" << endl;
        cout << reamur << " Reamur = " << fahrenheit << " Derajat Fahrenheit" << endl;
    } else if (pilih == "4") {
        cout << "Masukkan suhu fahrenheit yang akan dikonversikan : " << endl;
        cin >> fahrenheit;
        celcius = (fahrenheit - 32) * 5 / 9;
        reamur = (fahrenheit - 32) * 4 / 9;
        kelvin = (fahrenheit - 32) * 5 / 9 + 273;
        cout << fahrenheit << " Fahrenheit = " << celcius << " Derajat Celcius" << endl;
        cout << fahrenheit << " Fahrenheit = " << reamur << " Derajat Reamur" << endl;
        cout << fahrenheit << " Fahrenheit = " << kelvin << " Derajat Kelvin" << endl;
    } else {
        cout << "Nomor tersebut tidak ada dalam pilihan, Silahkan coba lagi" << endl;
    }
    return 0;
}

int main(){
    string lanjut;
    login();
    do {
        pilih();
        cout << "Lanjut? <y/n> : ";
        cin >> lanjut;
    } while (lanjut == "y");
    cout << "Program Selesai" << endl;
}