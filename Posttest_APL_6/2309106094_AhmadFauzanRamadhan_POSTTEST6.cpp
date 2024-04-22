#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

#define MAX_CARS 10

struct Car {
    string make;
    string model;
};

bool compareByMake(const Car& a, const Car& b) {
    return a.make < b.make;
}

Car cars[MAX_CARS];
int numCars = 0;
string choice;


void selectionSort() {
    for (int i = 0; i < numCars - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < numCars; j++) {
            if (cars[j].make < cars[minIndex].make) {
                minIndex = j;
            }
        }
        swap(cars[i], cars[minIndex]);
    }
}

void insertionSort() {
    for (int i = 1; i < numCars; i++) {
        Car key = cars[i];
        int j = i - 1;
        while (j >= 0 && cars[j].make > key.make) {
            cars[j + 1] = cars[j];
            j--;
        }
        cars[j + 1] = key;
    }
}

void bubbleSort() {
    for (int i = 0; i < numCars - 1; i++) {
        for (int j = 0; j < numCars - i - 1; j++) {
            if (cars[j].make > cars[j + 1].make) {
                swap(cars[j], cars[j + 1]);
            }
        }
    }
}


int sequentialSearch(const string& make) {
    for (int i = 0; i < numCars; i++) {
        if (cars[i].make == make) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const string& make) {
    sort(cars, cars + numCars, compareByMake);
    int left = 0, right = numCars - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (cars[mid].make == make) {
            return mid;
        } else if (cars[mid].make < make) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

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

void tampilkan() {
    system("cls");
    if (numCars > 0) {
        cout << "=============\n";
        cout << "Data Tersimpan\n";
        cout << "=============\n";
        for (int i = 0; i < numCars; i++) {
            cout << i + 1 << ". Mobil : " << cars[i].make << endl << "   Model : " << cars[i].model << endl;
        }
    } else {
        cout << "===========\n";
        cout << "Data Kosong\n";
        cout << "===========\n";
    }
}

void tambah(Car* newCar) {
    tampilkan();
    if (numCars < MAX_CARS) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Masukkan Mobil : ";
        getline(cin, newCar->make);
        cout << "Masukkan Model : ";
        getline(cin, newCar->model);
        cars[numCars++] = *newCar;
        cout << "Tambah Mobil Lagi? (y/n): ";
        cin >> choice;
        if (choice == "y" || choice == "Y") {
            tambah(newCar);
        }
    } else {
        cout << "Data Penuh!\n";
        cout << "Tekan E Untuk Kembali : ";
        cin >> choice;
    }
}

void ubah() {
    int index;
    do {
        tampilkan();
        if (numCars > 0) {
            cout << "Ubah indeks ke berapa? : ";
            cin >> index;
            if (index < 1 || index > numCars) {
                cout << "Indeks Tidak Valid. Silahkan Coba Lagi\n";
                continue;
            }
            index--;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Masukkan Merk Mobil : ";
            getline(cin, cars[index].make);
            cout << "Masukkan Model Mobil : ";
            getline(cin, cars[index].model);
            tampilkan();
            cout << "Ubah Mobil Lain? (y/n): ";
            cin >> choice;
        } else {
            cout << "Tidak Ada Data Untuk Di Ubah.\n";
            cout << "Tekan E Untuk Kembali: ";
            cin >> choice;
        }
    } while (choice == "y" || choice == "Y");
}

void hapus() {
    int index;
    do {
        tampilkan();
        if (numCars > 0) {
            cout << "Masukkan Nomor Data Yang Ingin Di Hapus: ";
            cin >> index;
            if (index < 1 || index > numCars) {
                cout << "Indeks Tidak Valid. Silahkan Coba Lagi\n";
                continue;
            }
            index--;
            for (int i = index; i < numCars - 1; i++) {
                cars[i] = cars[i + 1];
            }
            numCars--;
            tampilkan();
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
            cout << "1. Tambah\n2. Ubah\n3. Hapus\n4. Tampilkan\n5. Urutkan\n6. Cari\n7. Keluar\n";
            cout << "============\n";
            cout << "Pilih : ";
            cin >> choice;
            
            switch (choice) {
                case 1: {
                    Car newCar;
                    tambah(&newCar);
                    break;
                }
                case 2:
                    ubah();
                    break;
                case 3:
                    hapus();
                    break;
                case 4:
                    tampilkan();
                    cout << "Tekan tombol apa saja untuk melanjutkan...";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    break;
                case 5: {
                    int sortChoice;
                    cout << "Pilih Metode Sorting:\n";
                    cout << "1. Selection Sort\n2. Insertion Sort\n3. Bubble Sort\n";
                    cout << "Pilihan: ";
                    cin >> sortChoice;
                    
                    switch (sortChoice) {
                        case 1:
                            selectionSort();
                            break;
                        case 2:
                            insertionSort();
                            break;
                        case 3:
                            bubbleSort();
                            break;
                        default:
                            cout << "Pilihan Tidak Valid.\n";
                            break;
                    }
                    
                    cout << "Data Setelah Diurutkan:\n";
                    tampilkan();
                    cout << "Tekan tombol apa saja untuk melanjutkan...";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    break;
                }
                case 6: {
                    string searchMake;
                    int searchChoice;
                    cout << "Masukkan Merk Mobil yang Ingin Dicari: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, searchMake);
                    
                    cout << "Pilih Metode Pencarian:\n";
                    cout << "1. Sequential Search\n2. Binary Search\n";
                    cout << "Pilihan: ";
                    cin >> searchChoice;
                    
                    int index;
                    switch (searchChoice) {
                        case 1:
                            index = sequentialSearch(searchMake);
                            break;
                        case 2:
                            index = binarySearch(searchMake);
                            break;
                        default:
                            cout << "Pilihan Tidak Valid.\n";
                            index = -1;
                            break;
                    }
                    
                    if (index != -1) {
                        cout << "Mobil ditemukan pada indeks " << index << ":\n";
                        cout << "Merk: " << cars[index].make << "\nModel: " << cars[index].model << "\n";
                    } else {
                        cout << "Mobil dengan merk " << searchMake << " tidak ditemukan.\n";
                    }
                    
                    cout << "Tekan tombol apa saja untuk melanjutkan...";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    break;
                }
                case 7:
                    cout << "Keluar Dari Program...\n";
                    break;
                default:
                    cout << "Piihan Tidak Valid. Silahkan Coba Lagi.\n";
                    break;
            }
        } while (choice != 7);
    }
    
    cout << "===============\n";
    cout << "Progaram Selesai.\n";
    cout << "===============\n";
    
    return 0;
}