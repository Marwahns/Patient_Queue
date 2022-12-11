#include<iostream>
#include<ctime>
#include<conio.h>

using namespace std;

int maks = 100;														// Inisialiasi Maksimal Antrian 100
int urutUmum = 0;													// Nomor urut di mulai dari 0
int urutAnak = 0;
int urutBidan = 0;												
	
struct PoliUmum{													// Pendeklarasian Struct
	int idPasien;
	char nama[100];
	int noUrut;
	string tanggalDaftar;
	PoliUmum *next;
};
PoliUmum *head, *tail, *nodeBaru, *cur, *del;

struct PoliAnak{
	int idPasienAnak;
	char namaAnak[100];
	int noUrut;
	string tanggalDaftar;
	PoliAnak *next;
};
PoliAnak *awal, *akhir, *baru, *bantu, *hapus;

struct PoliKebidanan{
	int idPasienIbu;
	char namaIbu[100];
	int noUrut;
	string tanggalDaftar;
	PoliKebidanan *next;
};
PoliKebidanan *depan, *belakang, *news, *bantuan, *hapuskan;

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const string currentDateTime() {								// Function untuk mendapatkan waktu terkini
    time_t     now = time(0);									// tanggal atau waktu sekarang berdasarkan sistem saat ini
    struct tm  tstruct;
    char       buf[80];	
    tstruct = *localtime(&now);									
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);		// mengkonversi datetime ke dalam teks

    return buf;
}

// Function menghitung jumlah antrian
int CountAntrianPoliUmum(){
	if (head == NULL){				
		return 0;	
	} else{							
		int jumlah = 0;				
		cur = head;					
		while(cur != NULL){			
			cur = cur->next;		
			jumlah++;				
		}
		return jumlah;
	}
}

int CountAntrianPoliAnak(){
	if (awal == NULL){
		return 0;
	} else{
		int jumlah = 0;
		bantu = awal;
		while(bantu != NULL){
			bantu = bantu->next;
			jumlah++;
		}
		return jumlah;
	}
}

int CountAntrianPoliKebidanan(){
	if (depan == NULL){
		return 0;
	} else{
		int jumlah = 0;
		bantuan = depan;
		while(bantuan != NULL){
			bantuan = bantuan->next;
			jumlah++;
		}
		return jumlah;
	}
}

// Function mengecek ketidaktersediaan antrian
bool isFullPoliUmum(){
	if(CountAntrianPoliUmum() == maks){
		return true;
	}else {
		return false;
	}
}

bool isFullPoliAnak(){
	if(CountAntrianPoliAnak() == maks){
		return true;
	}else {
		return false;
	}
}

bool isFullPoliKebidanan(){
	if(CountAntrianPoliKebidanan() == maks){
		return true;
	}else {
		return false;
	}
}

// Function menghitung ketersediaan antrian
bool isEmptyPoliUmum(){
	if(CountAntrianPoliUmum() == 0){
		return true;
	}else{
		return false;
	}
}

bool isEmptyPoliAnak(){
	if(CountAntrianPoliAnak() == 0){
		return true;
	}else{
		return false;
	}
}

bool isEmptyPoliKebidanan(){
	if(CountAntrianPoliKebidanan() == 0){
		return true;
	}else{
		return false;
	}
}

// Function Prototype
void enqueuePoliUmum();

void enqueuePoliAnak();

void enqueuePoliKebidanan();

// Function Memanggil antrian = menghapus antrian satu per satu
void dequeuePoliUmum(){
	if(isEmptyPoliUmum()){
		cout<<"Antrian kosong!"<<endl;
	}else{ 
		del = head;
		cout<<"Pasien atas nama "<<head->nama<<" dengan ID "<<head->idPasien<<" silahkan masuk ke ruang dokter untuk pemeriksaan, dengan perkiraan waktu periksa adalah 10 menit"<<endl;
		head= head->next;
		del->next=NULL; //putuskan sambungan / koneksi dengan node berikutnya
		delete del;
	}
}

void dequeuePoliAnak(){
	if(isEmptyPoliAnak()){
		cout<<"Antrian kosong!"<<endl;
	}else{ 
		hapus = awal;
		cout<<"Pasien atas nama "<<awal->namaAnak<<" dengan ID "<<awal->idPasienAnak<<" silahkan masuk ke ruang dokter untuk pemeriksaan, dengan perkiraan waktu periksa adalah 10 menit"<<endl;
		awal= awal->next;
		hapus->next=NULL;
		delete hapus;
	}
}

void dequeuePoliKebidanan(){
	if(isEmptyPoliKebidanan()){
		cout<<"Antrian kosong!"<<endl;
	}else{ 
		hapuskan = depan;
		cout<<"Pasien atas nama "<<depan->namaIbu<<" dengan ID "<<depan->idPasienIbu<<" silahkan masuk ke ruang dokter untuk pemeriksaan, dengan perkiraan waktu periksa adalah 10 menit"<<endl;
		depan= depan->next;
		hapuskan->next=NULL;
		delete hapuskan;
	}
}

// Function Reset Antrian
void destroyPoliUmum(){
	if(isEmptyPoliUmum()){
		cout<<"Antrian kosong!"<<endl;
	}else{
		cur = head;
		while(cur != NULL){
			del = cur;
			cur = cur->next;
			del->next = NULL;
			delete del;
		}
		head = NULL;
		tail = NULL;
		cout<<"Antrian telah dikosongkan"<<endl;
	}
}

void destroyPoliAnak(){
	if(isEmptyPoliAnak()){
		cout<<"Antrian kosong!"<<endl;
	}else{
		bantu = awal;
		while(bantu != NULL){
			hapus = bantu;
			bantu = bantu->next;
			hapus->next = NULL;
			delete bantu;
		}
		awal = NULL;
		akhir = NULL;
		cout<<"Antrian telah dikosongkan"<<endl;
	}
}

void destroyPoliKebidanan(){
	if(isEmptyPoliKebidanan()){
		cout<<"Antrian kosong!"<<endl;
	}else{
		bantuan = depan;
		while(bantuan != NULL){
			hapuskan =bantuan;
			bantuan = bantuan->next;
			hapuskan->next = NULL;
			delete bantuan;
		}
		depan = NULL;
		belakang = NULL;
		cout<<"Antrian telah dikosongkan"<<endl;
	}
}

// Function Credit By
void label(){
	cout<<"=======================================================\n";
    cout<<"| Nama  : Marwah Nur Shafira                          |\n";
    cout<<"| NIM   : 2107411008                                  |\n";
    cout<<"| Kelas : TI 2A                                       |\n";
    cout<<"| Project UAS Mata Kuliah Algoritma dan Struktur Data |\n";
	cout<<"======================================================="<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
}

// Function Menampilkan Data
void TampilPoliUmum(){
	int i = 1, waktu = 10, perkiraan = 10;
	cur = head;
	cout<<" \t\t====================================="<<endl;
	cout<<" \t\t|   Data Antrian Pasien Poli Umum   |"<<endl;
	cout<<" \t\t====================================="<<endl<<endl<<endl<<endl<<endl;
	cout<<" ----------------------------------------------------------------"<<endl;
	while(cur != NULL){
		cout<<" Urutan Panggilan: "<<i; i++;
		cout<<"\n ID Pasien       : "<<cur->idPasien<<endl;
		cout<<" Nama Pasien     : "<<cur->nama<<endl;
		cout<<" Nomor Urut      : "<<cur->noUrut<<endl;
		cout<<" Waktu Tunggu    : "<<waktu<<" menit dari pemeriksaan pasien terdepan"<<endl;
		cout<<" Tanggal Daftar  : "<<cur->tanggalDaftar<<endl;
		waktu*i;
		waktu+=perkiraan;
		cout<<" ----------------------------------------------------------------"<<endl;
		cur = cur->next;
	}
	cout<<endl<<endl;
	cout<<" ========================"<<endl;
	cout<<" | Jumlah Antrian: "<<CountAntrianPoliUmum()<<"    |"<<endl;
	cout<<" ========================"<<endl<<endl;
	cout<<" "<<currentDateTime()<<endl;					//menampilkan waktu akses user, ketika user memilih menu tampil
}

void TampilPoliAnak(){
	int i = 1, waktu = 10, perkiraan = 10;
	cout<<" \t\t====================================="<<endl;
	cout<<" \t\t|   Data Antrian Pasien Poli Anak   |"<<endl;
	cout<<" \t\t====================================="<<endl<<endl<<endl<<endl<<endl;
	cout<<" ----------------------------------------------------------------"<<endl;
	bantu = awal;
	while(bantu != NULL){
		cout<<" Urutan Panggilan: "<<i; i++;
		cout<<"\n ID Pasien       : "<<bantu->idPasienAnak<<endl;
		cout<<" Nama Pasien     : "<<bantu->namaAnak<<endl;
		cout<<" Nomor Urut      : "<<bantu->noUrut<<endl;
		cout<<" Waktu Tunggu    : "<<waktu<<" menit dari pemeriksaan pasien terdepan"<<endl;
		cout<<" Tanggal Daftar  : "<<bantu->tanggalDaftar<<endl;
		waktu*i;
		waktu+=perkiraan;
		cout<<" ----------------------------------------------------------------"<<endl;
		
		bantu = bantu->next;
	}
	cout<<endl<<endl;
	cout<<" ========================"<<endl;
	cout<<" | Jumlah Antrian: "<<CountAntrianPoliAnak()<<"    |"<<endl;
	cout<<" ========================"<<endl<<endl;
	cout<<" "<<currentDateTime()<<endl;
}

void TampilPoliKebidanan(){
	int i = 1, waktu = 10, perkiraan = 10;
	cout<<" \t\t=========================================="<<endl;
	cout<<" \t\t|   Data Antrian Pasien Poli Kebidanan   |"<<endl;
	cout<<" \t\t=========================================="<<endl<<endl<<endl<<endl<<endl;
	cout<<" ----------------------------------------------------------------"<<endl;
	bantuan = depan;
	while(bantuan != NULL){
		cout<<" Urutan Panggilan: "<<i; i++;
		cout<<"\n ID Pasien       : "<<bantuan->idPasienIbu<<endl;
		cout<<" Nama Pasien     : "<<bantuan->namaIbu<<endl;
		cout<<" Nomor Urut      : "<<bantuan->noUrut<<endl;
		cout<<" Waktu Tunggu    : "<<waktu<<" menit dari pemeriksaan pasien terdepan"<<endl;
		cout<<" Tanggal Daftar  : "<<bantuan->tanggalDaftar<<endl;
		waktu*i;
		waktu+=perkiraan;
		cout<<" ---------------------------------------------------------------------"<<endl;
		
		bantuan = bantuan->next;
	}
	cout<<endl<<endl;
	cout<<" ========================"<<endl;
	cout<<" | Jumlah Antrian: "<<CountAntrianPoliKebidanan()<<"    |"<<endl;
	cout<<" ========================"<<endl<<endl;
	cout<<" "<<currentDateTime()<<endl;
}

void menuAntrianPoliUmum();

void menuAntrianPoliAnak();

void menuAntrianPoliKebidanan();

int main() {
	int pilihan, pilih, kode;
	int n = 1;
    cout<<"=======================================================\n";
    cout<<"| Nama  : Marwah Nur Shafira                          |\n";
    cout<<"| NIM   : 2107411008                                  |\n";
    cout<<"| Kelas : TI 2A                                       |\n";
    cout<<"| Project UAS Mata Kuliah Algoritma dan Struktur Data |\n";
	cout<<"======================================================="<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    do {
    	cout<<endl;
    	cout<<"+-------------------------------------------------------+\n";
        cout<<"|                   Layanan Klinik ABC                  |\n";
        cout<<"+-------------------------------------------------------+\n";
        cout<<"| Pilih Pelayanan :\t\t\t\t\t|\n";
        cout<<"| [1]. Poli Umum\t\t\t\t\t|\n";
        cout<<"| [2]. Poli Anak\t\t\t\t\t|\n";
        cout<<"| [3]. Poli Kebidanan\t\t\t\t\t|"<<endl;
        cout<<"|\t\t\t\t\t\t\t\|\n";
        cout<<"| Lain-lain >> EXIT\t\t\t\t\t|\n";
        cout<<"+-------------------------------------------------------+"<<endl<<endl;
        cout<<"Pilihan : ";
        cin>>pilihan;
        cout<<endl;
        switch (pilihan){
        case 1 :
        	getch();
        	system("cls");
        	menuAntrianPoliUmum();
            break;
        case 2 :
        	getch();
        	system("cls");
			menuAntrianPoliAnak();
        	break;
        case 3 :
        	getch();
        	system("cls");
        	menuAntrianPoliKebidanan();
        	break;
        default :
            cout << "---------EXIT---------"<<endl<<endl;
            exit(0);
            break;
        }
    }while(pilihan <= 3);
}

void menuAntrianPoliUmum(){
	int pilihan;
	label();
    do {
    	cout<<endl;
    	cout<<"+-------------------------------------------------------+\n";
        cout<<"|     Program Antrian Pasien Poli Umum Klinik ABC       |\n";
        cout<<"+-------------------------------------------------------+\n";
        cout<<"| Pilih menu :\t\t\t\t\t\t|\n";
        cout<<"| 1. Tambah Antrian\t\t\t\t\t|\n";
        cout<<"| 2. Panggil Antrian\t\t\t\t\t|\n";
        cout<<"| 3. Tampilkan data antrian\t\t\t\t|\n";
        cout<<"| 4. Kosongkan Antrian\t\t\t\t\t|"<<endl;
        cout<<"|\t\t\t\t\t\t\t\|\n";
        cout<<"| Lain-lain >> KEMBALI\t\t\t\t\t|\n";
        cout<<"+-------------------------------------------------------+"<<endl<<endl;
        cout<<"Pilihan : ";
        cin>>pilihan;
        cout<<endl;
        switch (pilihan){
        case 1 :
        	enqueuePoliUmum();
        	getch();
			system("cls");
			label();
            break;
        case 2 :
        	dequeuePoliUmum();
        	getch();
			system("cls");
			label();
        	break;
        case 3 :
        	TampilPoliUmum();
        	getch();
			system("cls");
			label();
        	break;
		case 4 :
        	destroyPoliUmum();
        	getch();
			system("cls");
			label();
        	break;
        default :
        	cin.clear();
        	cin.ignore();
            getch();
            system("cls");
            main();
            break;
        }
    }while(pilihan <= 4);
}

void enqueuePoliUmum(){
	if(isFullPoliUmum()){
		cout<<"Antrian penuh!"<<endl;
	}else{
		urutUmum++;
		if(isEmptyPoliUmum()){
			head = new PoliUmum();
			cout<<"ID Pasein: ";cin>>head->idPasien;
			cin.ignore();
			cout<<"Nama Pasien: "; gets(head->nama);
			head->tanggalDaftar = currentDateTime();
			head->noUrut = urutUmum;
			head->next = NULL;
			tail = head;
		} else{
			nodeBaru = new PoliUmum();
			cout<<"ID Pasein: ";cin>>nodeBaru->idPasien;
			if(head->idPasien == nodeBaru->idPasien){
				cout<<"ID sudah ada"<<endl;
				urutUmum -=1;
				getch();
				system("cls");
				menuAntrianPoliUmum();
			}
			else if(tail->idPasien == nodeBaru->idPasien){
					cout<<"ID sudah ada"<<endl;
					urutUmum -=1;
					getch();
					system("cls");
					menuAntrianPoliUmum();
			}
			cin.ignore();
			cout<<"Nama Pasien: "; gets(nodeBaru->nama);
			nodeBaru->noUrut = urutUmum;
			nodeBaru->tanggalDaftar = currentDateTime();
			nodeBaru->next = NULL;
			tail->next = nodeBaru;
			tail = nodeBaru;
		}
		
		cout<<"Kedatangan Passien : "<<currentDateTime()<<endl;
	}
}

void menuAntrianPoliAnak(){
	int pilihan;
	label();
    do {
    	cout<<endl;
    	cout<<"+-------------------------------------------------------+\n";
        cout<<"|     Program Antrian Pasien Poli Anak Klinik ABC       |\n";
        cout<<"+-------------------------------------------------------+\n";
        cout<<"| Pilih menu :\t\t\t\t\t\t|\n";
        cout<<"| 1. Tambah Antrian\t\t\t\t\t|\n";
        cout<<"| 2. Panggil Antrian\t\t\t\t\t|\n";
        cout<<"| 3. Tampilkan data antrian\t\t\t\t|\n";
        cout<<"| 4. Kosongkan Antrian\t\t\t\t\t|"<<endl;
        cout<<"|\t\t\t\t\t\t\t\|\n";
        cout<<"| Lain-lain >> KEMBALI\t\t\t\t\t|\n";
        cout<<"+-------------------------------------------------------+"<<endl<<endl;
        cout<<"Pilihan : ";
        cin>>pilihan;
        cout<<endl;
        switch (pilihan){
        case 1 :
        	enqueuePoliAnak();
        	getch();
			system("cls");
			label();
            break;
        case 2 :
        	dequeuePoliAnak();
        	getch();
			system("cls");
			label();
        	break;
        case 3 :
        	TampilPoliAnak();
        	getch();
			system("cls");
			label();
        	break;
        case 4 :
        	destroyPoliAnak();
        	getch();
			system("cls");
			label();
        	break;
        default :
        	cin.clear();
        	cin.ignore();
            getch();
            system("cls");
            main();
            break;
        }
    }while(pilihan <= 4);
}

void enqueuePoliAnak(){
	if(isFullPoliAnak()){
		cout<<"Antrian penuh!"<<endl;
	}else{
		urutAnak++;
		if(isEmptyPoliAnak()){
			awal = new PoliAnak();
			cout<<"ID Pasein: ";cin>>awal->idPasienAnak;
			cin.ignore();
			cout<<"Nama Pasien: "; gets(awal->namaAnak);
			awal->noUrut = urutAnak;
			awal->tanggalDaftar = currentDateTime();
			awal->next = NULL;
			akhir = awal;
		} else{
			baru = new PoliAnak();
			cout<<"ID Pasein: ";cin>>baru->idPasienAnak;
			if(awal->idPasienAnak == baru->idPasienAnak){
				cout<<"ID sudah ada"<<endl;
				urutAnak -=1;
				getch();
				system("cls");
				menuAntrianPoliAnak();
			}
			else if(akhir->idPasienAnak == baru->idPasienAnak){
				cout<<"ID sudah ada"<<endl;
				urutAnak -=1;
				getch();
				system("cls");
				menuAntrianPoliAnak();
			}
			cin.ignore();
			cout<<"Nama Pasien: "; gets(baru->namaAnak);
			baru->noUrut = urutAnak;
			baru->tanggalDaftar = currentDateTime();
			baru->next = NULL;
			akhir->next = baru;
			akhir = baru;
		}
		cout<<"Kedatangan Passien : "<<currentDateTime()<<endl;
	}
}

void menuAntrianPoliKebidanan(){
	int pilihan;
	label();
    do {
    	cout<<endl;
    	cout<<"+-------------------------------------------------------+\n";
        cout<<"|   Program Antrian Pasien Poli Kebidanan Klinik ABC    |\n";
        cout<<"+-------------------------------------------------------+\n";
        cout<<"| Pilih menu :\t\t\t\t\t\t|\n";
        cout<<"| 1. Tambah Antrian\t\t\t\t\t|\n";
        cout<<"| 2. Panggil Antrian\t\t\t\t\t|\n";
        cout<<"| 3. Tampilkan data antrian\t\t\t\t|\n";
        cout<<"| 4. Kosongkan Antrian\t\t\t\t\t|"<<endl;
        cout<<"|\t\t\t\t\t\t\t\|\n";
        cout<<"| Lain-lain >> KEMBALI\t\t\t\t\t|\n";
        cout<<"+-------------------------------------------------------+"<<endl<<endl;
        cout<<"Pilihan : ";
        cin>>pilihan;
        cout<<endl;
        switch (pilihan){
        case 1 :
        	enqueuePoliKebidanan();
        	getch();
			system("cls");
			label();
            break;
        case 2 :
        	dequeuePoliKebidanan();
        	getch();
			system("cls");
			label();
        	break;
        case 3 :
        	TampilPoliKebidanan();
        	getch();
			system("cls");
			label();
        	break;
        case 4 :
        	destroyPoliKebidanan();
        	getch();
			system("cls");
			label();
        	break;
        default :
        	cin.clear();
        	cin.ignore();
            getch();
            system("cls");
            main();
            break;
        }
    }while(pilihan <= 4);
}

void enqueuePoliKebidanan(){
	if(isFullPoliKebidanan()){
		cout<<"Antrian penuh!"<<endl;
	}else{
		urutBidan++;
		if(isEmptyPoliKebidanan()){
			depan = new PoliKebidanan();
			cout<<"ID Pasein: ";cin>>depan->idPasienIbu;
			cin.ignore();
			cout<<"Nama Pasien: "; gets(depan->namaIbu);
			depan->noUrut = urutBidan;
			depan->tanggalDaftar = currentDateTime();
			depan->next = NULL;
			belakang = depan;
		} else{
			news = new PoliKebidanan();
			cout<<"ID Pasein: ";cin>>news->idPasienIbu;
			if(depan->idPasienIbu == news->idPasienIbu){
				cout<<"ID sudah ada"<<endl;
				urutBidan -=1;
				getch();
				system("cls");
				menuAntrianPoliKebidanan();
			}
			else if(belakang->idPasienIbu == news->idPasienIbu){
				cout<<"ID sudah ada"<<endl;
				urutBidan -=1;
				getch();
				system("cls");
				menuAntrianPoliKebidanan();
			}
			cin.ignore();
			cout<<"Nama Pasien: "; gets(news->namaIbu);
			news->noUrut = urutBidan;
			news->tanggalDaftar = currentDateTime();
			news->next = NULL;
			belakang->next = news;
			belakang = news;
		}
		cout<<"Kedatangan Passien : "<<currentDateTime()<<endl;
	}
}

