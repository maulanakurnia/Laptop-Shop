#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
using namespace std;

/*Header Struct*/
struct data
{
	char merk[20];
	char tipe[20];
	char harga[20];
};
struct data toko[200], temp, x[200];

struct pesan
{
	char nama[20];
	char alamat[20];
	char ponsel[20];
	char email[20];
	char nambar[20];
	char tipe[20];
};
struct pesan psn[200];
/*Footer Struct*/

void admin();	  //Kelar
void pelanggan();  //Kelar
void adminmenu();  //Kelar
void inputan();	//Kelar
void output();	 //Kelar
void outpemesan(); //Kelar
void cariseq();	//Kelar

/*Header Deklarasi*/
/*dek*/ ifstream keluar;
/*dek*/ ofstream masuk;
/*dek*/ FILE *input;
/*dek*/ int pil, jmlh = 0, jmlh2 = 0, i, j;
/*dek*/ char yt;
/*dek*/ string cari;
/*dek*/ string user, password;
/*dek*/ bool found;
/*Footer Deklarasi*/

int main()
{
	do
	{
		cout << "==================\n";
		cout << "      LOGIN       \n";
		cout << "------------------\n";
		cout << "1. Admin          \n";
		cout << "2. Pelanggan      \n";
		cout << "==================\n";
		cout << "LOGIN = ";
		cin >> pil;
		cout << "\n\n";
		switch (pil)
		{
		case 1:
			admin(); //Menuju ke login admin
			break;
		case 2:
			pelanggan(); //Menuju Ke bagian user
			break;
		default:
			cout << "Input Salah\n";
		}
		cout << "\nKembali ke menu login? (y/t) ";
		cin >> yt;
		cout << endl;
	} while (yt == 'y' || yt == 'Y');
}

void admin()
{
	do
	{
		system("clear");
		cout << "Username : ";
		cin >> user;
		cout << "Password : ";
		cin >> password;
		cout << endl;
		if (user == "root" && password == "admin")
		{
			cout << "Login Berhasil!!\n";
			adminmenu();
		}
		else
		{
			system("clear");
			cout << "username atau Password salah!\n";
			cout << "\nCoba lagi? (y/t)";
			cin >> yt;
		}
	} while (yt == 'y' || yt == 'Y');
}

void adminmenu()
{
	do
	{
		system("clear");
		cout << "====================\n";
		cout << "        MENU        \n";
		cout << "====================\n\n";
		cout << "[1] INPUT DATA      \n";
		cout << "[2] LIHAT DATA      \n";
		cout << "[3] PEMESAN         \n";
		cout << "[4] EXIT            \n\n";
		cout << "====================\n";
		cout << "Pilihan(1...4) = ";
		cin >> pil;

		switch (pil)
		{
		case 1:
		{
			inputan();
		}
		break;

		case 2:
		{
			output();
		}
		break;

		case 3:
		{
			outpemesan();
		}
		break;

		default:
			system("clear");
			cout << "\033[7;31minput salah!! \033[0m\n";
			cin.ignore().get();
		}
		cout << "\nTEKAN APA SAJA UNTUK KEMBALI KE MENU";
		cin.ignore().get();
	} while (pil != 4);
}

void inputan()
{
	system("clear");
	//Keluarkan File Sebelumnya (Jika Tidak ada maka langsung ke input)
	keluar.open("laptop.txt");
	keluar >> jmlh;
	for (i = 0; i < jmlh; i++)
	{
		keluar >> toko[i].merk;
		keluar >> toko[i].tipe;
		keluar >> toko[i].harga;
	}

	//Input File
	masuk.open("laptop.txt");
	cout << "\nJumlah Data : ";
	cin >> jmlh2;
	for (i = jmlh; i < jmlh + jmlh2; i++) //input data2 dengan menambahkan data sebelumnya
	{
		cout << "\nData Ke-" << i + 1 << endl;
		cout << "Merk Laptop       : ";
		cin >> toko[i].merk;
		cout << "Tipe Laptop       : ";
		cin >> toko[i].tipe;
		cout << "Harga             : Rp.";
		cin >> toko[i].harga;
		cout << endl;
	}
	jmlh = jmlh + jmlh2; //mengubah jumlah data sebelumnya dengan jumlah data sekarang
	masuk << jmlh << endl;
	for (i = 0; i < jmlh; i++)
	{
		masuk << toko[i].merk << endl;
		masuk << toko[i].tipe << endl;
		masuk << toko[i].harga << endl;
	}

	for (i = jmlh; i < jmlh + jmlh2; i++)
	{
		masuk << toko[i].merk << endl;
		masuk << toko[i].tipe << endl;
		masuk << toko[i].harga << endl;
	}
	masuk.close();
	cout << "\033[1;32m DATA BERHASIL DITAMBAHKAN\033[0m\n";
}

void output()
{
	system("clear");
	keluar.open("laptop.txt");
	keluar >> jmlh;
	for (i = 0; i < jmlh; i++)
	{
		keluar >> toko[i].merk;
		keluar >> toko[i].tipe;
		keluar >> toko[i].harga;
	}

	for (i = 0; i < jmlh - 1; i++) //Sorting Menggunakan Bubble Sort
	{
		for (j = 0; j < jmlh - 1 - i; j++)
		{
			if (strcmp(toko[j].merk, toko[j + 1].merk) > 0)
			{
				temp = toko[j];
				toko[j] = toko[j + 1];
				toko[j + 1] = temp;
			}
		}
	}

	cout << "========================================================" << endl;
	cout << "                       DAFTAR LAPTOP                    " << endl;
	cout << "========================================================" << endl;
	cout << "No  Nama Laptop\t   Merk Laptop\t\tHarga\n";
	cout << "--------------------------------------------------------" << endl;

	for (i = 0; i < jmlh; i++)
	{
		cout << i + 1 << "   ";
		cout << setiosflags(ios::left) << setw(15) << toko[i].merk << setw(21) << toko[i].tipe << toko[i].harga;
		cout << endl;
	}
	cout << "========================================================" << endl;
	keluar.close();
	cout << "Ingin Mencari Barang? (y/t) ";
	cin >> yt;
	if (yt == 'y' || yt == 'Y')
	{
		cariseq();
	}
}

void cariseq()
{
	system("clear");
	keluar.open("laptop.txt");
	keluar >> jmlh;
	for (i = 0; i < jmlh; i++)
	{
		keluar >> toko[i].merk;
		keluar >> toko[i].tipe;
		keluar >> toko[i].harga;
	}

	cout << "Masukkan Nama Sepatu : ";
	cin >> cari;
	found = false;
	if (!found)
	{
		cout << "\033[1;32mDATA DITEMUKAN!\033[0m\n";
	}

	for (i = 0; i < jmlh; i++)
	{
		if (cari == toko[i].merk)
		{
			cout << endl;
			cout << "Merk Laptop  : " << toko[i].merk << endl;
			cout << "Tipe Laptop  : " << toko[i].tipe << endl;
			cout << "Harga        : " << toko[i].harga << endl;
			found = true;
		}
	}
	if (found == false)
	{
		system("clear");
		cout << "\033[1;31mMOHON MAAF DATA YANG ANDA CARI TIDAK DAPAT DITEMUKAN\033[0m\n"
			 << endl;
	}
}

void outpemesan()
{
	input = fopen("pemesan.txt", "r");
	system("clear");
	i = 0;
	while (feof(input) == 0)
	{
		fread(&psn[i], sizeof(psn[i]), 1, input);
		i++;
	}

	for (j = 0; j < i - 1; j++)
	{
		cout << "Nama         : " << psn[j].nama << endl;
		cout << "alamat       : " << psn[j].alamat << endl;
		cout << "nomor ponsel : " << psn[j].ponsel << endl;
		cout << "email        : " << psn[j].email << endl;
		cout << "Merk Laptop  : " << psn[j].tipe << endl;
		cout << "Tipe Laptop  : " << psn[j].nambar << endl;
		cout << endl;
		fclose(input);
	}
}

void pelanggan()
{
	do
	{
		system("clear");
		cout << "====================\n";
		cout << "        MENU        \n";
		cout << "====================\n\n";
		cout << "[1] LIHAT DATA      \n";
		cout << "[2] PESAN           \n";
		cout << "[3] EXIT            \n\n";
		cout << "====================\n";
		cout << "Pilihan(1...4) = ";
		cin >> pil;

		switch (pil)
		{
		case 1:
		{
			output();
		}
		break;

		case 2:
		{

			system("clear");
			input = fopen("pemesan.txt", "r");
			input = fopen("pemesan.txt", "a");

			cout << "Nama         : ";
			cin >> psn[i].nama;
			cin.ignore();
			cout << "alamat       : ";
			cin.getline(psn[i].alamat, sizeof(psn[i].alamat));
			cout << "nomor ponsel : ";
			cin >> psn[i].ponsel;
			cout << "email        : ";
			cin >> psn[i].email;
			cout << "Merk Laptop  : ";
			cin >> psn[i].tipe;
			cout << "Tipe Laptop  : ";
			cin >> psn[i].nambar;
			cout << endl;
			fwrite(&psn[i], sizeof(psn[i]), 1, input);

			fclose(input);

			cout << "\033[1;32m BERHASIL! HARAP MENUNGGU PESANAN SEDANG DIPROSES\033[0m\n";
			break;
		}
		break;

		case 3:
		{
			cout << " ";
		}
		break;
		default:
			system("clear");
			cout << "\033[7;31mMAAF MENU TIDAK DITEMUKAN!! \033[0m\n";
			cin.ignore().get();
		}

	} while (pil != 3);
}
