#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <csignal>
#include <iomanip>

using namespace std;

int main()
{
    const int MAX_CUSTOMERS = 100;
        struct Customer {
            string name;
            string phone;
            string email;
            string alamat;
            string vehicle;
            string item;
            string bengkel;
            string wilayahBengkel;
            string keluhan;
            string tod;
            int totalPrice;
        };

    string n;
    string m;
    string no;
    string wilayahBengkel;
    string bengkel;

    fstream customerFile;
    customerFile.open("customers.txt");

    ofstream customerStruck;
    customerStruck.open("struct.txt");

    //Daftaar Layanan
    string layanan[5][2]={
    {"1", "Servis Cepat"},
    {"2", "Servis By Booking"},
    {"3", "Light Servis"},
    {"4", "Heavy Repair"},
    {"5", "Claim Servis "},
    };
    // Daftar harga sparepart
    string num[20] = {
      "1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
      "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
    };

    string nRegion[6] = {
      "1", "2", "3", "4", "5", "6"
    };

    string Region[6]= {
        "Kecamatan Purwokerto Barat",
        "Kecamatan Purwokerto Timur",
        "Kecamatan Purwokerto Selatan",
        "Kecamatan Purwokerto Utara",
        "Kecamatan Karanglewas",
        "Kecamatan Sokaraja",
    };
    string sRegion[6] = {
        "Bengkel Mas Faaris",
        "Bengkel AA Nopal",
        "Bengkel Mamang Jidan",
        "Bengkel Neng Anggi",
        "Astra Tiga Berlian Motor -Toyota, -Daihatsu, -Suzuki, -Mitsubishi",
        "Jasatec Enginering Banyumas II"
    };

    string spareparts[20]= {
        "Ban-mobil",
        "Rem-mobil",
        "Aki-mobil",
        "Busi-mobil",
        "Filter-mobil",
        "Oli-mobil",
        "Lampu-mobil",
        "Kampas-mobil",
        "Ban-motor",
        "Rem-motor",
        "Aki-motor",
        "Busi-motor",
        "Filter-motor",
        "Oli-motor",
        "Rantai-motor",
        "Lampu-motor",
        "Karburator-motor",
        "Ring-piston-motor",
        "Kampas-rem-motor",
        "Spion-motor",
    };
    int prices[20] = {
        100000,
        150000,
        200000,
        25000,
        30000,
        50000,
        125000,
        365000,
        250000,
        50000,
        155000,
        25000,
        18000,
        80000,
        65000,
        50000,
        1200000,
        300000,
        175000,
        150000,
    };

    string nMetode[6] = {
      "1", "2"
    };

    string metode[2] = {
        "Cash", "Debit"
    };

    Customer customers[MAX_CUSTOMERS];
    int numCustomers = 0;
    string input;


    HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hstdout,10);

    string namaBengkel[6][6] = {
        //array [] 1
        {
        "1. Kecamatan Purwokerto Barat",
        "2. Kecamatan Purwokerto Timur",
        "3. Kecamatan Purwokerto Selatan",
        "4. Kecamatan Purwokerto Utara",
        "5. Kecamatan Karanglewas",
        "6. Kecamatan Sokaraja",
        },
        //array [] 2
        {
            "Bengkel Mas Faaris",
            "Bengkel AA Nopal",
            "Bengkel Mamang Jidan",
            "Bengkel Neng Anggi",
            "Astra Tiga Berlian Motor -Toyota, -Daihatsu, -Suzuki, -Mitsubishi",
            "Jasatec Enginering Banyumas II"
        }
    };

    //loading
    cout << "\n\n\n\n\n\n\n\n";
    for (int i = 1; i <= 100; i++) {
        cout << "\t\t\t\t\tLoading [" << string(i / 5, '=') << string(20 - i / 5, ' ') << "] " << i << "%\r";
        cout.flush();

        this_thread::sleep_for(chrono::milliseconds(20));
    }
    cout << "\n\n";
    cout << "\t\t\t\tTekan Tombol Untuk Melanjutkan (Press Key To Continue)";
    getch();
    system("cls");
    //akhir loading

    //DEKLARASI
    char menu;
    string opsi;

    do{
    //MENU

    cout << "\n\t===== NgaPack AutoFixer =====\n" << endl;
    cout<<"\t     1. Daftar Layanan dan Inventori" << endl;
    cout<<"\t     2. Input Pelanggan" << endl;
    cout<<"\t     3. List Pelanggan" << endl;
    cout<<"\t     4. List Bengkel Terdekat" << endl;
    cout<<"\t     5. Keluar" << endl;
    cout << "\n\t===== ================= =====\n" << endl;
    cout << "\t> Pilih menu : ";
    cin >> menu;
    cout << endl << endl;

    //PERCABANGAN MENU
        switch (menu){

        case '1' :
        //Tampil Layanan
        cout << "\t" << "Daftar Layanan" << endl;
        for (int i=0; i<5; i++){
            cout << "\t" << layanan[i][0]<< ". " <<layanan[i][1] << endl;
        }
        cout << endl;
        //Tampil Array
        cout << "\t" << "Daftar Inventori" << endl ;
        for (int j=0; j<20; j++){
            if(spareparts[j]== "Kampas-rem-motor" || spareparts[j]== "Ring-piston-motor" ||  spareparts[j]== "Karburator-motor" || spareparts[j]== "Rantai-motor" || spareparts[j]== "Filter-motor" ){
                cout << "\t" << num[j] << ". " << spareparts[j] << "\t : \tRp." << prices[j] << endl;
            }
            else{
                cout << "\t" << num[j] << ". " << spareparts[j] << "\t\t : \tRp." << prices[j] << endl;
            }
        }
        cout << "\n";

        break;

        case '5' :
        //KELUAR
        cout << "\tsee You :(\n";
        break;

        case '4' :
        //CARI WILAYAH
        char cariWilayah;

        cout << "\tCari Bengkel Terdekat\n";
        cout << "\t1. Kecamatan Purwokerto Barat" << endl;
        cout << "\t2. Kecamatan Purwokerto Timur" << endl;
        cout << "\t3. Kecamatan Purwokerto Selatan" << endl;
        cout << "\t4. Kecamatan Purwokerto Utara" << endl;
        cout << "\t5. Kecamatan Karanglewas" << endl;
        cout << "\t6. Kecamatan Sokaraja" << endl;
        cout << "\n\t> Pilih Bengkel Terdekat : ";
        cin >> cariWilayah;


        switch (cariWilayah){
            case '1':
            cout << "\n\t" << namaBengkel[0][0] << " - " << namaBengkel[1][0] << endl;
            break;

            case '2':
            cout << "\n\t" << namaBengkel[0][1] << " - " << namaBengkel[1][1] << endl;
            break;

            case '3':
            cout << "\n\t" << namaBengkel[0][2] << " - " << namaBengkel[1][2] << endl;
            break;

            case '4':
            cout << "\n\t" << namaBengkel[0][3] << " - " << namaBengkel[1][3] << endl;
            break;

            case '5':
            cout << "\n\t" << namaBengkel[0][4] << " - " << namaBengkel[1][4] << endl;
            break;

            case '6':
            cout << "\n\t" << namaBengkel[0][5] << " - " << namaBengkel[1][5] << endl;
            break;
        }
        break;


        case '3' :
        //TAMPIL LIST PELANGGAN
        cout << "\tList Pelanggan : \n" << endl;
            for (int i = 0; i < numCustomers; i++) {
                cout << "\n";
                cout << "\t" << "Nomor antrian : " << i + 1 << endl;
                cout << "\t" << customers[i].name << endl;
                cout << "\t" << customers[i].phone << endl;
                cout << "\t" << customers[i].email << endl;
                cout << "\t" << wilayahBengkel << "\n" << "\t--> " << bengkel << endl;
                cout << "\t" << customers[i].alamat << endl;
                cout << "\t" << customers[i].vehicle << endl;
                cout << "\t" << customers[i].tod<< endl;
            }
        break;

        case '2' :
        //INPUT PELANGGAN
            string item;

            cout << "\t<i> Masukkan nama pelanggan : ";
            getline(cin, customers[numCustomers].name);
            getline(cin, customers[numCustomers].name);

            cout << "\t<i> Masukkan nomor telepon : ";
            getline(cin, customers[numCustomers].phone);

            cout << "\t<i> Masukkan E-mail : ";
            getline(cin, customers[numCustomers].email);

            cout << "\n\tRegion : \n";

            for (int i=0; i<6; i++){
                cout << "\t" << nRegion[i] << ". " << Region[i] << endl ;
            }

            cout << "\n\t<i> Masukkan Region : ";
            cin >> no;

            // Pencarian bengkel
            for (int i = 0; i < 6; i++) {
                if (nRegion[i] ==  no) {
                    wilayahBengkel = Region[i];
                    bengkel = sRegion[i];
                    customers[i].wilayahBengkel = Region[i];
                    customers[i].bengkel = sRegion[i];
                    break;
                }
            }

            cout << "\n\t<o> " << wilayahBengkel << "\n" << "\t--> " << bengkel << endl << endl;

            cout << "\t<i> Masukkan alamat lengkap : ";
            getline(cin, customers[numCustomers].alamat);
            getline(cin, customers[numCustomers].alamat);

            cout << "\t<i> Masukkan nama kendaraan : ";
            getline(cin, customers[numCustomers].vehicle);

            cout << "\n";
            for (int j=0; j<20; j++){
                if(spareparts[j]== "Kampas-rem-motor" || spareparts[j]== "Ring-piston-motor" ||  spareparts[j]== "Karburator-motor" || spareparts[j]== "Rantai-motor" || spareparts[j]== "Filter-motor" ){
                    cout << "\t" << num[j] << ". " << spareparts[j] << "\t : \tRp." << prices[j] << endl;
                }
                else{
                    cout << "\t" << num[j] << ". " << spareparts[j] << "\t\t : \tRp." << prices[j] << endl;
                }
            }
            cout << "\n";

            // Variabel untuk menyimpan total harga
            int totalPrice = 0;

            // Loop untuk menerima input nama barang
            do {
                // Input nomor barang
                cout << "\t" << "<i> Pilih item : ";
                cin >> n;

                // Pencarian harga barang
                int price = 0;
                for (int i = 0; i < 20; i++) {
                    if (num[i] ==  n) {
                        item = spareparts[i];
                        price = prices[i];
                        break;
                    }
                }

                // Output harga barang
                if (price > 0) {
                    cout << "\t    Harga " << item << " : " << price << endl;
                    customerStruck << "===================================" << endl;
                    customerStruck << "Item : " << item << " - Rp." << price << endl;
                    totalPrice += price;
                } else {
                    cout << "\tBarang tidak ditemukan" << endl;
                }

                cout << "\t\t> Tambah item lagi?[Y/n]\n";
                item = getch();
                cout << endl;
            }
            while (item == "y" || item == "Y");
            if (item == "n" || item == "N") {
                cout << endl;
            }

            // Output total harga
            cout << "\tTotal harga : Rp." << totalPrice << endl;

            cout << "\n\tMetode pembayaran : \n";

            for (int i=0; i<2; i++){
                cout << "\t" << nMetode[i] << ". " << metode[i] << endl ;
            }

            // Input metode
            cout << "\n\t" << "<i> Pilih Metode Pembyaran : ";
            cin >> m;
            cout << "\n";

            // Pencarian metode
            for (int i = 0; i < 2; i++) {
                if (nMetode[i] ==  m) {
                    customers[i].tod = metode[i];
                    break;
                }
            }

            customerStruck << "===================================" << endl;
            customerStruck << "Total harga : Rp." << totalPrice << endl;
            customerStruck << "===================================" << endl;

            numCustomers++;

            for (int i = 0; i < numCustomers; i++) {
                customerStruck << endl ;
                customerStruck << "Nomor antrian     : " << i + 1 << endl;
                customerStruck << "Nama              : " << customers[i].name << endl;
                customerStruck << "No HP             : " << customers[i].phone << endl;
                customerStruck << "Email             : " << customers[i].email << endl;
                customerStruck << "Region            : " << wilayahBengkel << endl;
                customerStruck << "Bengkel           : " << bengkel << endl;
                customerStruck << "Alamat            : " << customers[i].alamat << endl;
                customerStruck << "Kendaraan/Model   : " << customers[i].vehicle << endl;
                customerStruck << "Metode Pembayaran : " << customers[i].tod << endl;
            }
            customerStruck.close();  // menutup file setelah selesai menulis

            // membuka file untuk ditulis
            ofstream customerFile("customers.txt");
            // menulis data pelanggan ke file
            for (int i = 0; i < numCustomers; i++) {
                customerFile << endl << endl;
                customerFile << "Nomor antrian     : " << i + 1 << endl;
                customerFile << "Nama              : " << customers[i].name << endl;
                customerFile << "No HP             : " << customers[i].phone << endl;
                customerFile << "Email             : " << customers[i].email << endl;
                customerFile << "Region            : " << wilayahBengkel << endl;
                customerFile << "Bengkel           : " << bengkel << endl;
                customerFile << "Alamat            : " << customers[i].alamat << endl;
                customerFile << "Kendaraan/Model   : " << customers[i].vehicle << endl;
                customerFile << "Metode Pembayaran : " << customers[i].tod << endl;
            }
            customerFile.close();  // menutup file setelah selesai menulis
            cout << "\n\t[!] Data pelanggan telah disimpan dalam file 'customers.txt'" << endl;
            cout << "\t[!] Nota pelanggan telah dicetak dalam file 'struct.txt'" << endl;
        break;
    }

    cout << endl << "\t> Kembali ke menu utama?[Y/n]\n";
    opsi=getch();
    cout << endl;
    system("cls");

    }
    while (opsi=="y"||opsi=="Y");
              if (opsi=="n"||opsi=="N"); {
                  cout << endl;
                  cout << "See you ;) \n";
            }
    return 0;
}
