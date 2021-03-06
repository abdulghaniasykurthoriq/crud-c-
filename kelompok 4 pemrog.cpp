/*
	Nama Kelompok 
        	1. Abdul Ghani Asykur Thoriq
			2. Kholidyah Amna Salimah
			3. Mochamad Adam Nicola
			4. Ibnu Ubaidillah

*/

/*
	Permasalahan yang ada dalam bentuk pertanyaan
	
	kenapa ketika mendelete data yang diinginkan tetapi malahan menghapus semua datanya?


*/

/*
	Team Work
	Abdul -> Mengerjakan fungsi search data berdasarkan nama, dan pembuatan tabel pada outputan
	Ibnu -> Mengerjakan Prosedure untuk menambahkan data ke file txt dan mengimplemantasikan fungsi dari berdasarkan nama
	Kayna -> Mengerjakan Prosedure untuk mebaca data dari file txt dan memperbaiki inputan yang typo
	Adam -> Mengerjakan Prosedure untuk menghapus data dari file txt dan juga membuat data dumy

*/

/*
	Attribut
	-Nama,TanggalLahir,JenisKelamin,Rt/Rw,Kelurahan,Kecamatan,Agama,Status,Pekerjaan,NomorHp
	

*/


#include <iostream>

#include <fstream>

#include <iomanip>



using namespace std;



// sebuah prosedur untuk menyimpan data ke file txt
void create(){
	// membuat variable untuk menulis file txt
	fstream fout;

	// membuka file txt tersebut jika tidak ada maka akan dibuatkan file baru
	fout.open("reportcard.txt", ios::app);

		cout <<"SILAHKAN MASUKAN DATA KEPENDUDUKAN"<< endl <<endl;

	int i;
//		-Nama,TanggalLahir,JenisKelamin,Rt/Rw,Kelurahan,Kecamatan,Agama,Status,Pekerjaan,NomorHp
	string name,tanggalLahir,jenisKelamin,rtRw,kelurahan,kecamatan,agama,status,pekerjaan,nomorHp;

	// Membaca inputan
		
		cin.ignore();
		cout<<"Masukan Name \t : ";
		getline(cin, name);
//		cin>> name;
		cout<<"Masukan Tanggal Lahir \t : ";
		cin>> tanggalLahir;
		cout<<"Masukan Jenis Kelamin \t : ";
		cin>> jenisKelamin;
		
		cout<<"Masukan RT/RW \t : ";
		cin>> rtRw;
		cout<<"Masukan Kelurahan \t : ";
		
		cin.ignore();
		getline(cin, kelurahan);
		cout<<"Masukan kecamatan \t : ";
		cin>> kecamatan;
		cout<<"Masukan agama \t : ";
		cin>> agama;
		cout<<"Masukan status \t : ";
		cin>> status;
		cout<<"Masukan pekerjaan \t : ";
		cin>> pekerjaan;
		cout<<"Masukan nomor hp  \t : ";
		cin>> nomorHp;


		// memasukan inputan tadi ke file txt
		fout << name << ","
			<< tanggalLahir << ","
			<< jenisKelamin << ","
			
			<< rtRw << ","
			<< kelurahan << ","
			<< kecamatan << ","
			<< agama << ","
			<< status << ","
			<< pekerjaan << ","
			<< nomorHp
			<< "\n";

}


// sebuah prosedur untuk menyimpan data ke file txt
void readData(){
	
	// membuat variable untuk membaca file txt
	ifstream read("reportcard.txt");
	if(!read.is_open()){
		cout<<"file Tidak Ditemukan"<<endl;
	//	return 1;
	}
	string nama,tanggalLahir,jenisKelamin,rtRw,kelurahan,kecamatan,agama,status,pekerjaan,nomorHp;
		cout<<"==============================================================================================================================================================================================="<<endl;
	
		cout<<"| "<<setiosflags(ios::left)<<setw(20)<<"Nama"<<'\t'<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(1)<<"Tanggal Lahir"<<'\t'<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(9)<<"Jenis Kelamin"<<'\t'<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(12)<<"RT/RW"<<'\t'<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(18)<<"Kelurahan"<<'\t'<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(18)<<"Kecamatan"<<'\t'<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(12)<<"Agama"<<'\t'<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(12)<<"Status"<<'\t'<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(20)<<"Pekerjaan"<<'\t'<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(12)<<"Nomor Hp"<<"|"<<'\n';

cout<<"==============================================================================================================================================================================================="<<endl;
	
	string str;
//	getline(tdata,str);
	
	
	
	//melukan perulangan sampai program membaca file sampai semuanya yg ada di file
	while(read.peek() !=EOF){
		getline(read, nama, ',');
		getline(read, tanggalLahir, ',');
		getline(read, jenisKelamin, ',');		
		getline(read, rtRw, ',');
		getline(read, kelurahan, ',');
		getline(read, kecamatan, ',');
		getline(read, agama, ',');
		getline(read, status, ',');
		getline(read, pekerjaan, ',');
		getline(read, nomorHp, '\n');
		
		cout<<"| "<<setiosflags(ios::left)<<setw(20)<<nama<<'\t'<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(1)<<tanggalLahir<<'\t'<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(9)<<jenisKelamin<<'\t'<<"|";	
		cout<<" "<<setiosflags(ios::left)<<setw(12)<<rtRw<<'\t'<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(18)<<kelurahan<<'\t'<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(18)<<kecamatan<<'\t'<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(12)<<agama<<'\t'<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(12)<<status<<'\t'<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(20)<<pekerjaan<<'\t'<<"|";
		cout<<" "<<setiosflags(ios::left)<<setw(12)<<nomorHp<<"|"<<'\n';
	}
	
}



// sebuah fungsion untuk mencari data dari file txt berdasarkan nama
string searchDataByName(){
	string namaInput;
	cout<<"Masukan Nama yang di cari: ";
	cin >> namaInput;

// membuat variable untuk mebaca file txt
	ifstream read("reportcard.txt");
	if(!read.is_open()){
		cout<<"file Tidak Ditemukan"<<endl;
	//	return 1;
	}
	string nama,tanggalLahir,jenisKelamin,rtRw,kelurahan,kecamatan,agama,status,pekerjaan,nomorHp;
	cout<<endl;
	cout<<setw(12)<<"Nama"<<'\t';
	cout<<setw(12)<<"Tanggal Lahir"<<'\t';
	cout<<setw(12)<<"Jenis Kelamin"<<'\t';
	cout<<setw(12)<<"RT/RW"<<'\t';
	cout<<setw(12)<<"Kelurahan"<<'\t';
	cout<<setw(12)<<"Kecamatan"<<'\t';
	cout<<setw(12)<<"Agama"<<'\t';
	cout<<setw(12)<<"Status"<<'\t';
	cout<<setw(12)<<"Pekerjaan"<<'\t';
	
	cout<<setw(12)<<"nomor"<<'\n';
	cout<<"=========================================================================================================================================================================="<<endl;
	

	
	while(read.peek() !=EOF){
		getline(read, nama, ',');
		getline(read, tanggalLahir, ',');
		getline(read, jenisKelamin, ',');
		getline(read, rtRw, ',');
		getline(read, kelurahan, ',');
		getline(read, kecamatan, ',');
		getline(read, agama, ',');
		getline(read, status, ',');
		getline(read, pekerjaan, ',');
		getline(read, nomorHp, '\n');
		
	
		if(namaInput == nama){
			cout<<setw(12)<<nama<<'\t';
			cout<<setw(12)<<tanggalLahir<<'\t';
			cout<<setw(12)<<jenisKelamin<<'\t';
			cout<<setw(12)<<rtRw<<'\t';
			cout<<setw(12)<<kelurahan<<'\t';
			cout<<setw(12)<<kecamatan<<'\t';
			cout<<setw(12)<< agama<<'\t';
			cout<<setw(12)<< status<<'\t';
			cout<<setw(12)<<pekerjaan <<'\t';
			cout<<setw(12)<<nomorHp<<'\n';
			
			break;
		}
		
//		else{
//			system("cls");
//			cout<<"\nMohon Maaf Data Tidak Ditemukan di Database"<<endl;
//			break;
//		}
		
	}
	return nama;
	
}


// sebuah prosedur untuk menghapus data
void * deleteData()
{	
	string nama,tanggalLahir,jenisKelamin,rtRw,kelurahan,kecamatan,agama,status,pekerjaan,nomorHp;
	string searchnama = searchDataByName();
	
		fstream tempFile;
        tempFile.open("temp.txt", ios::out | ios::app);
        ifstream read;
        read.open("reportcard.txt");
        
        while(read.peek() !=EOF) {
          		
	        getline(read, nama, ',');
			getline(read, tanggalLahir, ',');
			getline(read, jenisKelamin, ',');
			getline(read, rtRw, ',');
			getline(read, kelurahan, ',');
			getline(read, kecamatan, ',');
			getline(read, agama, ',');
			getline(read, status, ',');
			getline(read, pekerjaan, ',');
			getline(read, nomorHp, '\n');
					
			
	        	if (nama != searchnama) {
						tempFile << nama << ","
							<< tanggalLahir << ","
							<< jenisKelamin << ","
							<< rtRw << ","
							<< kelurahan << ","
							<< kecamatan << ","
							<< agama << ","
							<< status << ","
							<< pekerjaan << ","
							<< nomorHp
							<< "\n";
				}
				
				
		}
            

		read.close();
        tempFile.close();
        remove("reportcard.txt");
        rename("temp.txt", "reportcard.txt");

            
}


void updateData()
{
	string nama,tanggalLahir,jenisKelamin,rtRw,kelurahan,kecamatan,agama,status,pekerjaan,nomorHp;
	string searchnama = searchDataByName();
		
		// membuat variable untuk menulis file txt
		fstream tempFile;
		
        tempFile.open("temp.txt", ios::out | ios::app);
        ifstream read;
        // membuat variable untuk membaca file txt
        read.open("reportcard.txt");
        
        
        // di bawah ini terdapat looping untuk memindahkan data yg ada di file lama ke file baru
        // yang nantinya file baru telah terupdate dari data yang telah diubah
        
        while(read.peek() !=EOF) {
        	
        	getline(read, nama, ',');
			getline(read, tanggalLahir, ',');
			getline(read, jenisKelamin, ',');
			getline(read, rtRw, ',');
			getline(read, kelurahan, ',');
			getline(read, kecamatan, ',');
			getline(read, agama, ',');
			getline(read, status, ',');
			getline(read, pekerjaan, ',');
			getline(read, nomorHp, '\n');
				
				if(nama == searchnama){
					cin.ignore();
					cout<<"Masukan Name \t : ";
					getline(cin, nama);
					cout<<"Masukan Tanggal Lahir \t : ";
					cin>> tanggalLahir;
					cout<<"Masukan Jenis Kelamin \t : ";
					cin>> jenisKelamin;
					cout<<"Masukan RT/RW \t : ";
					cin>> rtRw;
					cout<<"Masukan Kelurahan \t : ";
					cin.ignore();
					getline(cin, kelurahan);
					cout<<"Masukan kecamatan \t : ";
					cin>> kecamatan;
					cout<<"Masukan agama \t : ";
					cin>> agama;
					cout<<"Masukan status \t : ";
					cin>> status;
					cout<<"Masukan pekerjaan \t : ";
					cin>> pekerjaan;
					cout<<"Masukan nomor hp  \t : ";
					cin>> nomorHp;
				}
			
	        	if (nama != searchnama) {
						tempFile << nama << ","
							<< tanggalLahir << ","
							<< jenisKelamin << ","
							<< rtRw << ","
							<< kelurahan << ","
							<< kecamatan << ","
							<< agama << ","
							<< status << ","
							<< pekerjaan << ","
							<< nomorHp
							<< "\n";
				}	
		}
            

		read.close();
        tempFile.close();
        remove("reportcard.txt");
        rename("temp.txt", "reportcard.txt");
        cout << "\n\tData deleted successfuly";

}

int main(){
	
	int option;
	
	
	// terdapat laebel loop untuk melakukan perulangan agar programnya bisa berjalan terus menerus
	loop:
		
		
	cout<<"1. Tambah Data Penduduk :"<<endl;
	cout<<"2. Tampilkan semua Data Penduduk :" <<endl;
	cout<<"3. Mencari Data berdasarkan Nama :"<<endl;
	cout<<"4. Memperbarui Data :"<<endl;
	cout<<"5. Menghapus Data :"<<endl;
	cout<<"masukan pilihan 1-5 : ";
	
	cin>> option;
	
	
	//terdapat pengkondisian dan akan menjalankan fungsi atau prosedur yang sesaui perintah dibawah
	switch(option){
		case 1 :{
			
			int masukanLagi = 1;
			while(masukanLagi != 0){
				system("cls");
				create();
				
				cout<<"Apakah ingin input data penduduk lagi ? [0] Tidak  ||  [1] Ya : ";
				cin>>masukanLagi;
			}
			system("cls");
			
			goto loop;
			break;
		}
		case 2 :{
			int masukanLagi =1;
			
			while(masukanLagi != 0){
				system("cls");
				readData();
				cout<<"[0] untuk kembali ";
				cin>>masukanLagi;
			}
			system("cls");
			
			goto loop;
			break;
		}
		case 3 :{
			int masukanLagi = 1;
			while(masukanLagi != 0){
			system("cls");
			searchDataByName();
			cout<<"Apakah ingin mencari data penduduk lagi ? [0] Tidak  ||  [1] Ya : ";
				cin>>masukanLagi;
			}
			system("cls");
			
			goto loop;

			break;
		}
		case 4 : {
			int masukanLagi = 1;
			while(masukanLagi != 0){
			system("cls");
			updateData();
			
			cout<<"Apakah ingin memperbarui data penduduk lagi ? [0] Tidak  ||  [1] Ya : ";
				cin>>masukanLagi;
			
			}
			system("cls");
			goto loop;

			break;
		}
		case 5 :{
			
			int masukanLagi = 1;
			while(masukanLagi != 0){
				system("cls");
				deleteData();		
				
				cout<<"Apakah ingin menghapus data penduduk lagi ? [0] Tidak  ||  [1] Ya : ";
				cin>>masukanLagi;
			}
			system("cls");
			
			goto loop;

			break;
		}
		
		default : {
			system("cls");
			goto loop;
			break;
		}
	}
	
	return 0;
}
