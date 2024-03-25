#include <iostream>
#include <string>
#include <limits>

using namespace std;

#define MAX_CARS 10

struct Car {
    string make;
    string model;
};

Car cars[MAX_CARS];
int numCars = 0;
string choice;

bool login() {
    string userName, userPassword;
    int loginAttempt = 0;
    
    while (loginAttempt < 3) {
        cout << "Masukkan Nama Anda : ";
        cin >> userName;
        cout << "Masukkan NIM Anda : ";
        cin >> userPassword;
        
        if (userName == "Ojan" && userPassword == "2309106094") {
            cout << "Selamat Datang Di Program List Data Merk Mobil\n";
            return true;
        } else {
            cout << "NIM/Nama Salah. Silahkan Coba Lagi\n\n";
            loginAttempt++;
        }
    }
    
    cout << "Percobaan Melebihi Batas Yang Ditentukan. Program Berhenti\n";
    return false;
}

void displayCars() {
    system("cls");
    if (numCars > 0) {
        cout << "=============\n";
        cout << "Data Tersimpan\n";
        cout << "=============\n";
        for (int i = 0; i < numCars; i++) {
            cout << i + 1 << ". Mobil : " << cars[i].make << ", Model : " << cars[i].model << endl;
        }
    } else {
        cout << "===========\n";
        cout << "Data Kosong\n";
        cout << "===========\n";
    }
}

void addCar() {
    displayCars();
    if (numCars < MAX_CARS) {
        Car newCar;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Masukkan Mobil : ";
        getline(cin, newCar.make);
        cout << "Masukkan Model : ";
        getline(cin, newCar.model);
        cars[numCars++] = newCar;
        cout << "Tambah Mobil Lagi? (y/n): ";
        cin >> choice;
        if (choice == "y" || choice == "Y") {
            addCar();
        }
    } else {
        cout << "Data Penuh!\n";
        cout << "Tekan E Untuk Kembali : ";
        cin >> choice;
    }
}

void updateCar() {
    int index;
    do {
        displayCars();
        if (numCars > 0) {
            cout << "Ubah indeks ke berapa? : ";
            cin >> index;
            if (index < 1 || index > numCars) {
                cout << "Indeks Tidak Valid. Silahkan Coba Lagi\n";
                continue;
            }
            index--; // adjust for zero-based indexing
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Masukkan Merk Mobil : ";
            getline(cin, cars[index].make);
            cout << "Masukkan Model Mobil : ";
            getline(cin, cars[index].model);
            displayCars();
            cout << "Ubah Mobil Lain? (y/n): ";
            cin >> choice;
        } else {
            cout << "Tidak Ada Data Untuk Di Ubah.\n";
            cout << "Tekan E Untuk Kembali: ";
            cin >> choice;
        }
    } while (choice == "y" || choice == "Y");
}

void deleteCar() {
    int index;
    do {
        displayCars();
        if (numCars > 0) {
            cout << "Masukkan Nomor Data Yang Ingin Di Hapus: ";
            cin >> index;
            if (index < 1 || index > numCars) {
                cout << "Indeks Tidak Valid. Silahkan Coba Lagi\n";
                continue;
            }
            index--; // adjust for zero-based indexing
            for (int i = index; i < numCars - 1; i++) {
                cars[i] = cars[i + 1];
            }
            numCars--;
            displayCars();
            cout << "Ingin Menghapus Lagi? (y/n): ";
            cin >> choice;
        } else {
            cout << "Tidak Ada Data Untuk Dihapus.\n";
            cout << "Tekan E Untuk Kembali: ";
            cin >> choice;
        }
    } while (choice == "y" || choice == "Y");
}

int main() {
    if (login()) {
        int choice;
        do {
            system("cls");
            cout << "======================================\n";
            cout << "Selamat Datang Di Program List Merk Mobil\n";
            cout << "============\n";
            cout << "1. Tambah\n2. Ubah\n3. Hapus\n4. Tampilkan\n5. Keluar\n";
            cout << "============\n";
            cout << "Pilih : ";
            cin >> choice;
            
            switch (choice) {
                case 1:
                    addCar();
                    break;
                case 2:
                    updateCar();
                    break;
                case 3:
                    deleteCar();
                    break;
                case 4:
                    displayCars();
                    cout << "Tekan tombol apa saja untuk melanjutkan...";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    break;
                case 5:
                    cout << "Keluar Dari Program...\n";
                    break;
                default:
                    cout << "Piihan Tidak Valid. Silahkan Coba Lagi.\n";
                    break;
            }
        } while (choice != 5);
    }
    
    cout << "===============\n";
    cout << "Progaram Selesai.\n";
    cout << "===============\n";
    
    return 0;
}