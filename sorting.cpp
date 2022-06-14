#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int hitung_ipk(int a, int b)
{
	return a / b;
}

struct MataKuliah
{
	string NamaMatkul;
	int Nilai;
};

int hitungIpk(vector<MataKuliah *> mataKuliahs)
{
	int nilai = 0;
	int jumlah = 0;
	int hitung_ipk(int a, int b);
	for (MataKuliah *value : mataKuliahs)
	{
		nilai += value->Nilai;
		jumlah++;
	}
	return hitung_ipk(nilai, jumlah);
}

string ipkKeGrade(int ipk)
{
	if (ipk > 90)
	{
		return "A";
	}
	else if (ipk > 80)
	{
		return "B";
	}
	else if (ipk > 70)
	{
		return "C";
	}
	else if (ipk > 60)
	{
		return "D";
	}
	else if (ipk > 50)
	{
		return "E";
	}
	else
	{
		return "tidak lulus";
	}
}

struct Mahasiswa
{
	string NomorIndukMahasiswa;
	string Nama;
	vector<MataKuliah *> Matkul;
};

Mahasiswa *CekMahasiswa(vector<Mahasiswa *> &listMahasiswa, string Nim)
{
	for (Mahasiswa *value : listMahasiswa)
	{
		if (value->NomorIndukMahasiswa == Nim)
		{
			return value;
		}
	}
	return nullptr;
}

void inputMahasiswa(vector<Mahasiswa *> &listMahasiswa)
{
	// Mahasiswa* CekMahasiswa(vector<Mahasiswa*> &listMahasiswa, string nama, int Nim);
	Mahasiswa *mhs = new Mahasiswa;

	MataKuliah *inputMatkul();
	cout << " Nama	: ";
	getline(cin, mhs->Nama);
	cout << " NIM	: ";
	getline(cin, mhs->NomorIndukMahasiswa);
	if (CekMahasiswa(listMahasiswa, mhs->NomorIndukMahasiswa) != nullptr)
	{
		cout << " Data Mahasiswa sudah ada " << endl;
		return;
	}
	// bool done;
	while (true)
	{
		cout << " ============================== " << endl;

		mhs->Matkul.push_back(inputMatkul());
		cout << " lanjutkan input mata kuliah? Y/n ";
		char lakukanInput[1];
		cin >> lakukanInput;
		cin.ignore();
		if (*lakukanInput == 'n' || *lakukanInput == 'N')
		{
			break;
		}
	}
	cout << " ============================== " << endl;
	listMahasiswa.push_back(mhs);
}

MataKuliah *inputMatkul()
{
	MataKuliah *mataKuliah = new MataKuliah;
	cout << " Nama Mata Kuliah: ";
	getline(cin, mataKuliah->NamaMatkul);
	cout << " Nilai Mata Kuliah: ";
	cin >> mataKuliah->Nilai;
	cin.ignore();
	return mataKuliah;
}

void clear()
{
#ifdef _WIN32
	system("cls");
#elif __linux__
	system("clear");
#endif
}

void listMahasiswa(vector<Mahasiswa *> &listMhs)
{
	clear();
	cout << " ================================= " << endl;
	cout << " |        Daftar Mahasiswa       | " << endl;

	for (const Mahasiswa *value : listMhs)
	{
		// cout << "memory address:" << value<<endl;
		cout << " ================================= " << endl;
		cout << " Nama: " << value->Nama << endl;
		cout << " NIM: " << value->NomorIndukMahasiswa << endl;
		int ipk = hitungIpk(value->Matkul);
		cout << " IPK  : " << ipk << endl;
		cout << " Status IPK  : " << ipkKeGrade(ipk) << endl;
	}
	cout << " ================================= " << endl;
}

void editProfileMahasiswa(Mahasiswa *mhs)
{
	// cout << "catatan : kosongkan input bila tidak ingin mengganti isi"<<endl;
	cout << " Masukkan Nama Baru (kosongkan input bila tidak ingin mengganti isi) :";
	string nama;
	getline(cin, nama);
	if (nama != "")
	{
		mhs->Nama = nama;
	}
}


void editNilaiMahasiswa(Mahasiswa *mhs)
{
	cout << " Masukkan NIM : " << endl;
	for (MataKuliah *value : mhs->Matkul)
	{
		cout << "Nama Mata Kuliah : " << value->NamaMatkul << endl;
		cout << "Masukkan Nilai Mata Kuliah : ";
		cin >> value->Nilai;
		cin.ignore();
	}
}

void detailMahasiswa(Mahasiswa *mhs)
{
	cout << " ================================== " << endl;
	cout << " |  Menampilkan detail Mahasiswa  | " << endl;
	cout << " ================================== " << endl;
	cout << " Nama : " << mhs->Nama << endl;
	cout << " NIM  : " << mhs->NomorIndukMahasiswa << endl;
	int ipk = hitungIpk(mhs->Matkul);
	cout << " IPK  : " << ipk << endl;
	cout << " Status IPK  : " << ipkKeGrade(ipk) << endl;
	for (MataKuliah *matkul : mhs->Matkul)
	{
		cout << " ================================== " << endl;
		cout << " Mata Kuliah : " << matkul->NamaMatkul;
		cout << " Nilai 	  : " << matkul->Nilai;
	}
	cout << " ================================== " << endl;
}

bool CompareNim(Mahasiswa *mahasiswa1, Mahasiswa *mahasiswa2){
    return mahasiswa1->NomorIndukMahasiswa.compare(mahasiswa2->NomorIndukMahasiswa) < 0;
}

void SortByNIM(vector<Mahasiswa *> &mahasiswas){
	// for (int i = 0;i < 10;i++){
	// 	if CompareNim(mahasiswas->)
	// }
	sort(mahasiswas.begin(), mahasiswas.end(),CompareNim);
}

int pause()
{
	cout << "\n"
		 << " press enter to continue";
	string wait;
	getline(cin, wait);
	clear();
	return 0;
}

int main()
{
	vector<Mahasiswa *> mhs;
	cout << " ================================== " << endl;
	cout << " | Menghitung nilai IPK Mahasiswa | " << endl;
	cout << " ================================== " << endl;
	// void inputMahasiswa(vector<Mahasiswa*> &listMahasiswa);
	auto menu = []()
	{
		cout << " ================================== " << endl;
		cout << " |           Pilih Menu           | " << endl;
		cout << " ================================== " << endl;
		cout << " 1. Tampilkan Menu " << endl;
		cout << " 2. Input Data Mahasiswa " << endl;
		cout << " 3. Sunting Data Mahasiswa " << endl;
		cout << " 4. Tampilkan Detil Mahasiswa " << endl;
		cout << " 5. Tampilkan Daftar Seluruh Mahasiswa " << endl;
		cout << " masukkan angka [1-5]. pilih nomor lainnya untuk keluar" << endl;
	};

	while (true)
	{
		int menuInput = 0;
		menu();
		cout << " ";
		cin >> menuInput;
		cin.ignore();
		string nomorIndukMahasiswa;
		Mahasiswa *mahasiswa;
		switch (menuInput)
		{
		case 1:
			clear();
			continue;
		case 2:
			clear();
			inputMahasiswa(mhs);
			pause();
			continue;
		case 3:
			clear();
			cout << " masukkan NIM : " << endl;
			getline(cin, nomorIndukMahasiswa);
			mahasiswa = CekMahasiswa(mhs, nomorIndukMahasiswa);
			if (mahasiswa == nullptr)
			{
				cout << " Data Mahasiswa Tidak Ditemukan" << endl;
				pause();
				continue;
			}
			editProfileMahasiswa(mahasiswa);
			pause();
			continue;
		case 4:
			clear();
      getline(cin, nomorIndukMahasiswa);
			mahasiswa = CekMahasiswa(mhs, nomorIndukMahasiswa);
			if (mahasiswa == nullptr)
			{
				cout << " Data Mahasiswa Tidak Ditemukan " << endl;
				pause();
				continue;
			}
    		  SortByNIM(mhs);
			detailMahasiswa(mahasiswa);
			pause();
			continue;
		case 5:
			clear();
      		SortByNIM(mhs);
			listMahasiswa(mhs);
			pause();
			continue;
		default:
			break;
		}
		break;

		
	}
	
	return 0;
}