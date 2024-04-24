#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <cstdlib> // Untuk menggunakan system("cls")
#include <vector>

using namespace std;

#define MAX_CARS 10

struct Car {
    string make;
    string model;
    int year;
};

bool compareByMakeDescending(const Car& a, const Car& b) {
    return a.make > b.make; // Sorting huruf secara descending
}

bool compareByYearAscending(const Car& a, const Car& b) {
    return a.year < b.year; // Sorting angka secara ascending
}

int interpolationSearch(const Car cars[], int numCars, int year) {
    int low = 0, high = numCars - 1;
    
    while (low <= high && year >= cars[low].year && year <= cars[high].year) {
        if (low == high) {
            if (cars[low].year == year) return low;
            return -1;
        }
        
        int pos = low + ((double)(high - low) / (cars[high].year - cars[low].year)) * (year - cars[low].year);
        
        if (cars[pos].year == year) return pos;
        if (cars[pos].year < year) low = pos + 1;
        else high = pos - 1;
    }
    
    return -1;
}

void sortInterpolation(Car arr[], int n) {
    int minYear = arr[0].year;
    int maxYear = arr[0].year;
    
    for (int i = 1; i < n; i++) {
        if (arr[i].year < minYear) minYear = arr[i].year;
        if (arr[i].year > maxYear) maxYear = arr[i].year;
    }
    
    int range = maxYear - minYear + 1;
    vector<Car> temp[n];
    
    for (int i = 0; i < n; i++) {
        int index = (float)(arr[i].year - minYear) / range * (n - 1);
        temp[index].push_back(arr[i]);
    }
    
    for (int i = 0; i < n; i++) {
        sort(temp[i].begin(), temp[i].end(), compareByYearAscending);
    }
    
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < temp[i].size(); j++) {
            arr[index++] = temp[i][j];
        }
    }
}

Car cars[MAX_CARS];
int numCars = 0;
string choice;

// Sorting Methods
void sortByMake() {
    sort(cars, cars + numCars, compareByMakeDescending);
}

void sortByYear() {
    sort(cars, cars + numCars, compareByYearAscending);
}

int binarySearchDescending(const Car arr[], int numCars, const string& make) {
    int left = 0, right = numCars - 1, foundIndex = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].make == make) {
            foundIndex = mid; // Simpan indeks jika merk ditemukan
            right = mid - 1; // Tetap cari ke kiri untuk menemukan merk yang lebih rendah
        } else if (arr[mid].make < make) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return foundIndex;
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
            cout << i + 1 << ". Mobil : " << cars[i].make << endl << "   Model : " << cars[i].model << endl << "   Tahun : " << cars[i].year << endl;
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
        do {
            cout << "Masukkan Tahun : ";
            cin >> newCar->year;
            if (cin.fail()) {
                cout << "Input Tidak Valid. Harap Masukkan Angka.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (cin.fail());
        cars[numCars++] = *newCar;
        sortByMake(); // Urutkan data setelah menambahkan mobil baru
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
            do {
                cout << "Masukkan Tahun Mobil : ";
                cin >> cars[index].year;
                if (cin.fail()) {
                    cout << "Input Tidak Valid. Harap Masukkan Angka.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (cin.fail());
            sortByMake(); // Urutkan data setelah mengubah mobil
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
            if (cin.fail() || index < 1 || index > numCars) {
                cout << "Indeks Tidak Valid. Silahkan Coba Lagi\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            index--;
            for (int i = index; i < numCars - 1; i++) {
                cars[i] = cars[i + 1];
            }
            numCars--;
            sortByMake(); // Urutkan data setelah menghapus mobil
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
                    cout << "1. Urutkan Berdasarkan Merk (Descending)\n";
                    cout << "2. Urutkan Berdasarkan Tahun (Ascending)\n";
                    cout << "3. Metode Sorting Interpolation\n"; // Pilihan baru
                    cout << "Pilihan: ";
                    cin >> sortChoice;
                    switch (sortChoice) {
                        case 1:
                            sortByMake();
                            break;
                        case 2:
                            sortByYear();
                            break;
                        case 3:
                            // Panggil fungsi sorting interpolation di sini
                            cout << "Sorting menggunakan metode interpolation...\n";
                            sortInterpolation(cars, numCars);
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
                    int searchChoice;
                    cout << "Pilih Metode Pencarian:\n";
                    cout << "1. Cari Berdasarkan Tahun (Ascending)\n";
                    cout << "2. Cari Berdasarkan Merk (Descending)\n";
                    cout << "Pilihan: ";
                    cin >> searchChoice;

                    int index;
                    switch (searchChoice) {
                        case 1: {   
                            int searchYear;
                            cout << "Masukkan Tahun Mobil yang Ingin Dicari: ";
                            cin >> searchYear;
                            index = interpolationSearch(cars, numCars, searchYear);
                            break;
                        }
                        case 2: {
                            string searchMake;
                            cout << "Masukkan Merk Mobil yang Ingin Dicari: ";
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            getline(cin, searchMake);
                            sortByMake(); // Perlu diurutkan terlebih dahulu
                            index = binarySearchDescending(cars, numCars, searchMake); // Panggil fungsi pencarian biner yang sudah didefinisikan
                            break;
                        }
                        default:
                            cout << "Pilihan Tidak Valid.\n";
                            index = -1;
                            break;
                    }

                    if (index != -1) {
                        cout << "Mobil ditemukan pada indeks " << index + 1 << ":\n"; // Mengubah indeks dari 0-based menjadi 1-based
                        cout << "Merk: " << cars[index].make << "\nModel: " << cars[index].model << "\nTahun: " << cars[index].year << "\n";
                    } else {
                        cout << "Mobil tidak ditemukan.\n";
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
                    cout << "Pilihan Tidak Valid. Silahkan Coba Lagi.\n";
                    break;
            }
        } while (choice != 7);
    }

    cout << "===============\n";
    cout << "Progaram Selesai.\n";
    cout << "===============\n";

    return 0;
}
