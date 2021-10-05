#include <iostream>
#include <iomanip.h>
#include <stdio.h>
#include <string>
using namespace std;

class giao_vien
{
	private: 
		char ho_ten[30];
		char bang_cap[15];
		char chuyen_nganh[20];
		int tuoi;
		float bac_luong;
	public:	
		giao_vien()
		{};
		giao_vien(char *ho_ten, char *bang_cap, char *chuyen_nganh, int tuoi, float bac_luong){
			strcpy(this->ho_ten, ho_ten);
			strcpy(this->bang_cap, bang_cap);
			strcpy(this->chuyen_nganh, chuyen_nganh);
			this->tuoi, tuoi;
			this->bac_luong, bac_luong;
		}
		~giao_vien()
		{}
		
		float luong_co_ban(){
			return (bac_luong * 610);
		}
		
		friend	giao_vien	&operator >> (istream &is, giao_vien &gv) {
			fflush(stdin);
			cout<<"Nhap vao ten: ";
			is.getline(gv.ho_ten, 30);
			cout<<"Nhap vao tuoi: ";
			is>>gv.tuoi;
			fflush(stdin);
			cout<<"Nhap vao bang cap (1: Kha, 2: Gioi, 3: Xuat sac): ";
			do{
				is.getline(gv.bang_cap, 15);
				if(strcmpi(gv.bang_cap, "1") != 0 && strcmpi(gv.bang_cap, "2") != 0 && strcmpi(gv.bang_cap, "3") != 0){
					cout<<"\n Ban chi duoc nhap tu 1 -> 3: ";
				}
			}while(strcmpi(gv.bang_cap, "1") != 0 && strcmpi(gv.bang_cap, "2") != 0 && strcmpi(gv.bang_cap, "3") != 0);
			cout<<"Nhap vao chuyen nganh: ";
			is.getline(gv.chuyen_nganh, 30);
			cout<<"Nhap vao bac luong: ";
			is>>gv.bac_luong;
			return gv;
		}
		
		friend	giao_vien &operator << (ostream	&os, giao_vien	&gv){
			cout<<endl;
			cout<<setw(30)<<gv.ho_ten;
			cout<<setw(20)<<gv.tuoi;
			if(strcmpi(gv.bang_cap, "1") == 0){
				cout<<setw(12)<<"Kha";
			}
			else if(strcmpi(gv.bang_cap, "2") == 0){
				cout<<setw(12)<<"Gioi";
			}
			
			else{
				cout<<setw(12)<<"Xuat sac";
			}
			cout<<setw(12)<<gv.chuyen_nganh;
			cout<<setw(12)<<gv.bac_luong;
			cout<<setw(14)<<gv.luong_co_ban()<<endl;
			return gv;
		}
		
		bool operator > (giao_vien gv){
			return (strcmpi(bang_cap, gv.bang_cap) > 0);// true
		}
		char* getht(){
			return ho_ten;
		}
		
};

void input(giao_vien gv[], int total){
	for(int index = 0; index < total; index++){
		cout<<"--Thong tin giao vien thu"<< index + 1<<"---"<<endl;
		cin>>gv[index];
	}
}

void tieude(){
	cout<<setw(30)<<"Ho ten"
		<<setw(20)<<"Tuoi"
		<<setw(12)<<"Bang cap"
		<<setw(20)<<"Chuyen nganh"
		<<setw(12)<<"Bac luong"
		<<setw(14)<<"Luong co ban"<<endl;
}

void output(giao_vien gv[], int total){
	for(int index = 0; index < total; index++){
		cout<<gv[index];
	}
}

void sapxep(giao_vien gv[], int total){
	for(int index = 0; index < total; index++){
		for(int index2 = 0; index2 < total; index2++){
			if(gv[index] > gv[index2]){
				giao_vien temp = gv[index];
							gv[index] = gv[index2];
							gv[index2] = temp;
			}
		}
	}
	output(gv, total);
}

int main(int argc, char *argv[])
{
	int total;
	cout<<"Nhap vao so luong giao vien: ";
	do{
		cin>>total;
		if(total <= 0){
			cout<<"Nhap lai: ";
		}
	}while(total <= 0);
	giao_vien *gv = new giao_vien[total];
	input(gv, total);
	cout<<"\n\t\t\t\t----------DANH SACH GV VUA NHAP LA ----------"<<endl;
	tieude();
	output(gv, total);
	cout<<"\n\t\t\t\t----------DANH SACH SAP XEP----------"<<endl;
	tieude();
	sapxep(gv, total);	
	return 0;
}
