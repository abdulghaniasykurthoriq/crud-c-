#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
//#include <sstream>

using namespace std;


void create(){
	// file pointer
	fstream fout;

	// opens an existing csv file or creates a new file.
	fout.open("reportcard.txt", ios::out | ios::app);

	cout << "Enter the details of 5 students:"
		<< " roll name maths phy chem bio"<< endl;

	int i, roll, phy;
	string name;

	// Read the input

		cout<<"Masukan Name \t : ";
		cin>> name;
		cout<<"Masukan roll \t : ";
		cin>> roll;
		cout<<"Masukan phy \t : ";
		cin>> phy;


		// Insert the data to file
		fout << name << ","
			<< roll << ","
			<< phy
			<< "\n";

}

struct Database{
	int roll, phy ;
	string name;
};
void readData(){
	
	
	ifstream tdata("reportcard.txt");
	if(!tdata.is_open()){
		cout<<"file Tidak Ditemukan"<<endl;
	//	return 1;
	}
	string nama,roll,phy;
	cout<<setw(12)<<"nama"<<'\t';
	cout<<setw(12)<<"roll"<<'\t';
	cout<<setw(12)<<"phy"<<'\n';
	cout<<"============================================="<<endl;
	
	string str;
//	getline(tdata,str);
	
	while(tdata.peek() !=EOF){
		getline(tdata, nama, ',');
		getline(tdata, roll, ',');
		getline(tdata, phy, '\n');
		
		cout<<setw(12)<<nama<<'\t';
		cout<<setw(12)<<roll<<'\t';
		cout<<setw(12)<<phy<<'\n';
	}
	
}


string searchDataByName(){
	string namaInput;
	cout<<"Masukan Nama Kamu : ";
	cin >> namaInput;
	
	ifstream tdata("reportcard.txt");
	if(!tdata.is_open()){
		cout<<"file Tidak Ditemukan"<<endl;
	//	return 1;
	}
	string nama,roll,phy;
	cout<<setw(12)<<"nama"<<'\t';
	cout<<setw(12)<<"roll"<<'\t';
	cout<<setw(12)<<"phy"<<'\n';
	cout<<"============================================="<<endl;
	
	string str;
	
	while(tdata.peek() !=EOF){
		getline(tdata, nama, ',');
		getline(tdata, roll, ',');
		getline(tdata, phy, '\n');
		
		if(namaInput == nama){
			cout<<setw(12)<<nama<<'\t';
			cout<<setw(12)<<roll<<'\t';
			cout<<setw(12)<<phy<<'\n';
			
			break;
		}
		
	}
	return nama;
	
}


void * deleteData()
{	
	string nama,roll,phy;
	string searchnama = searchDataByName();

	
		ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("reportcard.txt");
        
        while(read.eof()) {
        		getline(read, nama, ',');
				getline(read, roll, ',');
				getline(read, phy, '\n');
				
				cout<<nama;
	        	if (nama != searchnama) {
						tempFile << nama << ","
							<< roll << ","
							<< phy
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
	
	loop:
	cout<<"1. Create Data "<<endl;
	cout<<"2. Read All DataBase"<<endl;
	cout<<"3. Search Data By Name"<<endl;
	cout<<"4. Delete"<<endl;
	cout<<"masukan pilihan : ";
	cin>> option;
	
	switch(option){
		case 1 :{
			
			int masukanLagi = 1;
			while(masukanLagi != 0){
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
				readData();
				cout<<"Apakah ingin melihat data penduduk lagi ? [0] Tidak  ||  [1] Ya : ";
				cin>>masukanLagi;
			}
			system("cls");
			
			goto loop;
			break;
		}
		case 3 :{
			searchDataByName();
			break;
		}
		case 4 :{
			
			int masukanLagi = 1;
			while(masukanLagi != 0){
				deleteData();		
				
				cout<<"Apakah ingin menghapus data penduduk lagi ? [0] Tidak  ||  [1] Ya : ";
				cin>>masukanLagi;
			}
			system("cls");
			
			goto loop;
			break;

			break;
		}
	}
	
	return 0;
}

