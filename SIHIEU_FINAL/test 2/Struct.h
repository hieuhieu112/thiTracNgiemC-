#pragma once
#include<string>
#include<iostream>
#define MAXMONHOC 100
#define MAXLOP 100
#define MAXDSCTDT 1000

using namespace std;
//=======================================MÔN HỌC==========================================
struct MonHoc
{
	string MAMH;
	string TENMH;
};
typedef struct MonHoc MONHOC;

struct DanhSachMonHoc
{
	int SLMH = 0;
	MONHOC* DSMH[MAXMONHOC];
};
typedef struct DanhSachMonHoc DSMH;

//=========================DIEM===========================================
struct DiemThi {
	string MAMH;
	float DIEM;
	DiemThi* pNext;
};
typedef struct DiemThi NODEDIEMTHI;

struct DanhSachDiem {
	int SLDiem = 0;
	NODEDIEMTHI* pHead = NULL;
	NODEDIEMTHI* pLast = NULL;
};
typedef struct DanhSachDiem DSDIEM;
// =============================SINH VIEN==================================
struct SinhVien {
	string MASV;
	string TEN;
	string HO;
	string PHAI;
	string PASSWORD;
	DSDIEM ds_Diem;
	SinhVien* pNext;
};
typedef struct SinhVien NODESV;

struct DanhSachSinhVien {
	int SLSV = 0;
	NODESV* pHead = NULL;
	NODESV* pLast = NULL;
};
typedef struct DanhSachSinhVien DSSV;

//==================================LOP==============================================
struct Lop {
	string MALOP;
	string TENLOP;
	DSSV ds_SV;
};
typedef struct Lop LOP;

struct DanhSachLop {
	int SLLOP = 0;
	LOP DS_LOP[MAXLOP];
};
typedef struct DanhSachLop DSLOP;

// =============================CAU HOI============================================
struct CauHoi {

	string MAMH;
	string NOIDUNG;
	string A;
	string B;
	string C;
	string D;
	string DA;
};

struct nodecauhoi
{
	int ID;		//khoa
	int height;
	CauHoi data;
	struct nodecauhoi* pLeft, * pRight;
};
typedef nodecauhoi* Tree;
struct DanhSachCauHoi {
	int SLCH = 0;
	Tree DSCH = NULL;
};
typedef DanhSachCauHoi DSCH;

//======================CAU TRUC DE THI=================================
struct CauTrucDeThi
{
	string MASV;
	string MAMH;
	float DIEM;
	int sct;
	int tg;
	int* bode;
	int* dapan;
};
typedef struct CauTrucDeThi CTDT;

struct DanhSachDeThi {
	CTDT DS_CTDT[MAXDSCTDT];
	int SLDSDT = 0;
};
typedef struct DanhSachDeThi DSDT;
struct ThoiGian {
	int Gio;
	int Phut;
	int Giay;
};
typedef struct ThoiGian TG;
