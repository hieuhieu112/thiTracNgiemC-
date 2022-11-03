///===================== Do Hoa ======================= //
#pragma one
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<math.h>
#include<ctime>
#include"mylib.h"
#include"Define.h"

using namespace std;

// ==================== VE KHUNG ==========================
void veKhung(int rong, int dai)
{
	for (int i = 0; i < rong; i++)
	{
		for (int j = 0; j < dai; j++)
		{
			if (i == 0)
			{
				if (j == 0) cout << traitren;
				else if (j == dai - 1) cout << phaitren;
				else cout << ngang;
			}
			else if (i == rong - 1)
			{
				if (j == 0) cout << traiduoi;
				else if (j == dai - 1) cout << phaiduoi;
				else cout << ngang;
			}
			else
			{
				if (j == 0 || j == dai - 1) cout << doc;
				else cout << " ";
			}
		}
		gotoxy(wherex() - dai, wherey() + 1);
	}
}
//======================= VE KHUNG TEN SV =======================
void VeKhungTenSV(int dai, int rong, int socot)
{
	int x = rong / socot;
	int dem = 1;
	for (int i = 0; i < dai; i++)
	{
		for (int j = 0; j < rong; j++)
		{
			if (dem == 1)
			{
				dem = 3;
			}
			if (dem == 4)
			{
				dem = 8;
			}
			if (i == 0)
			{
				if (j == 0) cout << traitren;
				else if (j == rong - 1) cout << phaitren;
				else if (j == (rong / socot) * dem) cout << ngangxuong;
				else cout << ngang;
			}
			else if (i == 2)
			{
				if (j == 0) cout << docphai;
				else if (j == rong - 1) cout << doctrai;
				else if (j == (rong / socot) * dem) cout << giua;
				else cout << ngang;
			}
			else if (i == dai - 1)
			{
				if (j == 0) cout << traiduoi;
				else if (j == rong - 1) cout << phaiduoi;
				else if (j == (rong / socot) * dem) cout << nganglen;
				else cout << ngang;
			}
			else if (j == (rong / socot) * dem)
			{
				cout << doc;
			}
			else
			{
				if (j == 0 || j == rong - 1) cout << doc;
				else cout << " ";
			}
			if (j == dem * (rong / socot)) dem++;
			if (dem == socot) dem = 1;
		}
		gotoxy(wherex() - rong, wherey() + 1);
	}
}
// ====================== VE KHUNG XEM DIEM =======================
void VeKhungXemDiem(int dai, int rong, int socot)
{

	int x = rong / socot;
	int dem = 1;
	for (int i = 0; i < dai; i++)
	{
		for (int j = 0; j < rong; j++)
		{
			if (dem == 1)
			{
				dem++;
			}
			if (dem == 3)
			{
				dem = 8;
			}
			if (dem == 9)
			{
				dem = 10;
			}
			if (i == 0)
			{
				if (j == 0) cout << traitren;
				else if (j == rong - 1) cout << phaitren;
				else if (j == (rong / socot) * dem) cout << ngangxuong;
				else cout << ngang;
			}
			else if (i == 2)
			{
				if (j == 0) cout << docphai;
				else if (j == rong - 1) cout << doctrai;
				else if (j == (rong / socot) * dem) cout << giua;
				else cout << ngang;
			}
			else if (i == dai - 1)
			{
				if (j == 0) cout << traiduoi;
				else if (j == rong - 1) cout << phaiduoi;
				else if (j == (rong / socot) * dem) cout << nganglen;
				else cout << ngang;
			}
			else if (j == (rong / socot) * dem)
			{
				cout << doc;
			}
			else
			{
				if (j == 0 || j == rong - 1) cout << doc;
				else cout << " ";
			}
			if (j == dem * (rong / socot)) dem++;
			if (dem == socot) dem = 1;
		}
		gotoxy(wherex() - rong, wherey() + 1);
	}
}

//============================DO DAI SO DUONG==================
int DoDaiSoDuong(int a)
{
	if (a == 0) return 1;
	int dem = 0;
	while (a != 0)
	{
		a = a / 10;
		dem++;
	}
	return dem;
}
//=========================LOC LAY SO=================================
int LaySo(int giatri, bool DiChuyenDeThoat, char& a) // Kiem tra Di chuyen co thoat khong va nhan phim vua nhan
{
	int i = DoDaiSoDuong(giatri); // Chong tran bit + khong cho backspace khong hop le
	HienConTro();
	unsigned int so = giatri;
	int b;
	//	if (a <= 0) a = getch(); // clear a
	a = _getch();
	while (a != 13)
	{
		if ((DiChuyenDeThoat && a == -32) || a == 27 || a == 19)
		{
			break;
		}
		if ((a >= 48 && a <= 57) && i < 10) // nuot phim khi khong phai la so
		{
			if (so == 0 && a == 48)
			{

			}
			else
			{
				i++;
				b = a - 48;
				cout << b;
				so = so * 10 + b;
			}
		}
		if (a == 8 && i > 0) // Nguoi dung nhan backspace
		{
			i--;
			so = so / 10;
			int x = wherex();
			int y = wherey();
			gotoxy(x - 1, y);
			cout << " ";
			if (!x) gotoxy(0, 0);
			else gotoxy(x - 1, y);
		}
		a = _getch();
	}
	return so;
}

void InHoaChuoi(string& s)
{
	for (int i = 0; i < s.length(); i++)
	{
		s[i] = toupper(s[i]);
	}
}

// ==================== VE NUT ==========================
void veNut(int dai, int rong, int x, int y, string text, int mau)
{
	for (int i = 0; i < dai; i++)
	{
		for (int j = 0; j < rong; j++)
		{
			ChangeColor(mau);
			gotoxy(x + j, y + i);
			cout << " ";
		}
	}
	ChangeColor(mau);
	gotoxy(x + (rong - text.length()) / 2, y + (dai / 2));
	cout << text;
	ChangeColor(15);
}
// ==================== VE NUT MAIN MENU ==========================
void veNutMenu(int dai, int x, int y, string text, int mau)
{
	for (int i = 0; i < dai; i++)
	{
		ChangeColor(mau);
		gotoxy(x, y + i);
		cout << "                                        ";

	}
	ChangeColor(mau);
	gotoxy(x + (40 - text.length()) / 2, y + (dai / 2));
	cout << text;
	ChangeColor(15);
}
// ====================== VE KHUNG THEO SO COT =======================
void vekhungDS(int dai, int rong, int socot)
{
	int x = rong / socot;
	int dem = 1;
	for (int i = 0; i < dai; i++)
	{
		for (int j = 0; j < rong; j++)
		{
			if (i == 0)
			{
				if (j == 0) cout << traitren;
				else if (j == rong - 1) cout << phaitren;
				else if (j == (rong / socot) * dem) cout << ngangxuong;
				else cout << ngang;
			}
			else if (i == 2)
			{
				if (j == 0) cout << docphai;
				else if (j == rong - 1) cout << doctrai;
				else if (j == (rong / socot) * dem) cout << giua;
				else cout << ngang;
			}
			else if (i == dai - 1)
			{
				if (j == 0) cout << traiduoi;
				else if (j == rong - 1) cout << phaiduoi;
				else if (j == (rong / socot) * dem) cout << nganglen;
				else cout << ngang;
			}
			else if (j == (rong / socot) * dem)
			{
				cout << doc;
			}
			else
			{
				if (j == 0 || j == rong - 1) cout << doc;
				else cout << " ";
			}
			if (j == dem * (rong / socot)) dem++;
			if (dem == socot) dem = 1;
		}
		gotoxy(wherex() - rong, wherey() + 1);
	}
}
// ====================== VE KHUNG LOP THEO SO COT =======================
void VeKhungDSLop(int dai, int rong, int socot)
{

	int x = rong / socot;
	int dem = 1;
	for (int i = 0; i < dai; i++)
	{
		for (int j = 0; j < rong; j++)
		{
			if (dem == 2)
			{
				dem++;
			}
			if (i == 0)
			{
				if (j == 0) cout << traitren;
				else if (j == rong - 1) cout << phaitren;
				else if (j == (rong / socot) * dem) cout << ngangxuong;
				else cout << ngang;
			}
			else if (i == 2)
			{
				if (j == 0) cout << docphai;
				else if (j == rong - 1) cout << doctrai;
				else if (j == (rong / socot) * dem) cout << giua;
				else cout << ngang;
			}
			else if (i == dai - 1)
			{
				if (j == 0) cout << traiduoi;
				else if (j == rong - 1) cout << phaiduoi;
				else if (j == (rong / socot) * dem) cout << nganglen;
				else cout << ngang;
			}
			else if (j == (rong / socot) * dem)
			{
				cout << doc;
			}
			else
			{
				if (j == 0 || j == rong - 1) cout << doc;
				else cout << " ";
			}
			if (j == dem * (rong / socot)) dem++;
			if (dem == socot) dem = 1;
		}
		gotoxy(wherex() - rong, wherey() + 1);
	}
}
// ====================== VE KHUNG LOP THEO SO COT =======================
void VeKhungDSLop1(int dai, int rong, int socot)
{

	int x = rong / socot;
	int dem = 1;
	for (int i = 0; i < dai; i++)
	{
		for (int j = 0; j < rong; j++)
		{
			if (dem == 1)
			{
				dem++;
			}
			if (dem == 3)
			{
				dem = 8;
			}
			if (dem == 9)
			{
				dem++;
			}
			if (i == 0)
			{
				if (j == 0) cout << traitren;
				else if (j == rong - 1) cout << phaitren;
				else if (j == (rong / socot) * dem) cout << ngangxuong;
				else cout << ngang;
			}
			else if (i == 2)
			{
				if (j == 0) cout << docphai;
				else if (j == rong - 1) cout << doctrai;
				else if (j == (rong / socot) * dem) cout << giua;
				else cout << ngang;
			}
			else if (i == dai - 1)
			{
				if (j == 0) cout << traiduoi;
				else if (j == rong - 1) cout << phaiduoi;
				else if (j == (rong / socot) * dem) cout << nganglen;
				else cout << ngang;
			}
			else if (j == (rong / socot) * dem)
			{
				cout << doc;
			}
			else
			{
				if (j == 0 || j == rong - 1) cout << doc;
				else cout << " ";
			}
			if (j == dem * (rong / socot)) dem++;
			if (dem == socot) dem = 1;
		}
		gotoxy(wherex() - rong, wherey() + 1);
	}
}
// ====================== VE KHUNG THONG BAO =======================
void vekhungTB(int dai, int rong)
{
	for (int i = 0; i < dai; i++)
	{
		for (int j = 0; j < rong; j++)
		{
			if (i == 0)
			{
				if (j == 0) cout << traitren;
				else if (j == rong - 1) cout << phaitren;
				else cout << ngang;
			}
			else if (i == 1)
			{
				if (j == 0 || j == rong - 1) cout << doc;
				else if (j == (rong - 9) / 2)
				{
					cout << "THONG BAO";
					j = j + 8;
				}
				else cout << " ";
			}
			else if (i == 2)
			{
				if (j == 0) cout << docphai;
				else if (j == rong - 1) cout << doctrai;
				else cout << ngang;
			}
			else if (i == dai - 1)
			{
				if (j == 0) cout << traiduoi;
				else if (j == rong - 1) cout << phaiduoi;
				else cout << ngang;
			}
			else
			{
				if (j == 0 || j == rong - 1) cout << doc;
				else cout << " ";
			}
			//sleep(1);
		}
		gotoxy(wherex() - rong, wherey() + 1);
	}
}
// ====================== IN THONG BAO =======================
void InTB(string text, int x, int y)
{
	int i = 0;
	int j = 0;
	int dem = 0;
	string temp;
	gotoxy(x, y);
	if (text.length() <= 33)
	{
		cout << text;
	}
	else
	{
		while (text.length() > 33)
		{
			gotoxy(x, y + dem);
			for (i = 0; i < 33; i++)
			{
				if (text[i] == ' ')
				{
					j = i;
				}
			}
			if (text[32] != ' ')
			{
				temp = text.substr(0, j);
				text.erase(0, j + 1);
				cout << temp;
			}
			else
			{
				temp = text.substr(0, i);
				text.erase(0, i);
				cout << temp;
			}
			dem++;
		}
		gotoxy(x, y + dem);
		cout << text;
	}
}
bool CheckMonNhapChoSuaMon(DSMH dsm, string mamon, string tenmon, MONHOC* mh)
{
	for (int i = 0; i < dsm.SLMH; i++)
	{
		if (dsm.DSMH[i] != mh) {
			if (mamon.compare(dsm.DSMH[i]->MAMH) == 0 || tenmon.compare(dsm.DSMH[i]->TENMH) == 0)
			{
				return false;
			}
		}
	}
	return true;
}
// ====================== XOA THONG BAO =======================
void XoaTB(int x, int y)
{
	for (int i = 0; i < 6; i++)
	{
		gotoxy(x + 1, y + 3 + i);
		cout << "                                  ";
	}
}

// ====================== IN NOI DUNG CAU HOI =======================
void InNDCH(string text)
{
	int i = 0;
	int j = 0;
	int k = 0;
	string temp1;
	gotoxy(20, 5);
	if (text.length() < 95)
	{
		gotoxy(20, 5);
		cout << text;
	}
	else
	{
		while (text.length() >= 95)
		{
			for (i = 0; i < 96; i++)
			{
				if (text[i] == ' ')
				{
					j = i;
				}
			}
			if (text[95] != ' ')
			{
				temp1 = text.substr(0, j);
				text.erase(0, j + 1);
				gotoxy(20, 5 + k);
				cout << temp1;
			}
			else
			{
				temp1 = text.substr(0, i);
				text.erase(0, i);
				gotoxy(20, 5 + k);
				cout << temp1;
			}
			k += 2;
			if (k > 5)
			{
				break;
			}
		}
		if (k < 5)
		{
			gotoxy(20, 5 + k);
			cout << text;
		}
	}
}
// ====================== IN NOI DUNG CAU HOI =======================
void InDA_XemCH(string text)
{
	int i = 0;
	int j = 0;
	int k = 0;
	string temp1;
	if (text.length() < 95)
	{
		cout << text;
	}
	else
	{
		while (text.length() >= 95)
		{
			for (i = 0; i < 96; i++)
			{
				if (text[i] == ' ')
				{
					j = i;
				}
			}
			if (text[95] != ' ')
			{
				temp1 = text.substr(0, j);
				text.erase(0, j + 1);
				gotoxy(20, wherey() + k);
				cout << temp1;
			}
			else
			{
				temp1 = text.substr(0, i);
				text.erase(0, i);
				gotoxy(20, wherey() + k);
				cout << temp1;
			}
			k += 2;
			if (k > 3)
			{
				break;
			}
		}
		if (k < 3)
		{
			gotoxy(20, wherey() + k);
			cout << text;
		}
	}
}
// ====================== VE KHUNG CH THEO SO COT =======================
void vekhungDSCH(int dai, int rong, int socot)
{
	int x = rong / socot;
	int dem = 1;
	for (int i = 0; i < dai; i++)
	{
		for (int j = 0; j < rong; j++)
		{
			if (i == 0)
			{
				if (j == 0) cout << traitren;
				else if (j == rong - 1) cout << phaitren;
				else if (j == (rong / socot) * dem) cout << ngangxuong;
				else cout << ngang;
			}
			else if (i == 1)
			{
				if (j == 0 || j == 24 || j == 48 || j == rong - 1) cout << doc;
				else if (j == 11)
				{
					cout << "ID";
					j += 1;
				}
				else if (j == 24 + 10)
				{
					cout << "MA MH";
					j += 4;
				}
				else if (j == 48 + 28)
				{
					cout << "NOI DUNG CAU HOI";
					j += 15;
				}
				else cout << " ";
			}
			else if (i == 2)
			{
				if (j == 0) cout << docphai;
				else if (j == rong - 1) cout << doctrai;
				else if (j == (rong / socot) * dem) cout << giua;
				else cout << ngang;
			}
			else if (i == dai - 1)
			{
				if (j == 0) cout << traiduoi;
				else if (j == rong - 1) cout << phaiduoi;
				else if (j == (rong / socot) * dem) cout << nganglen;
				else cout << ngang;
			}
			else if (j == (rong / socot) * dem)
			{
				cout << doc;
			}
			else
			{
				if (j == 0 || j == rong - 1) cout << doc;
				else cout << " ";
			}
			if (j == dem * (rong / socot)) dem++;
			if (dem == 3) dem = 1;
		}
		gotoxy(wherex() - rong, wherey() + 1);
	}
}
// ====================== DAO CHUOI =======================
string DaoChuoi(string text)
{
	int i = 0;
	string temp = text;
	for (int j = text.length() - 1; j > -1; j--)
	{
		temp[i] = text[j];
		i++;
	}
	return temp;
}

// ====================== VE KHUNG NHAP CAU HOI =======================
void vekhungThemCH()
{
	gotoxy(5, 2);
	veKhung(36, 125);
	gotoxy(6, 7 - 2);
	cout << "NOI DUNG CH: ";
	gotoxy(18, 6 - 2);
	veKhung(7, 101);
	gotoxy(6, 16 - 2);
	cout << "DAP AN A: ";
	gotoxy(18, 15 - 2);
	veKhung(5, 101);
	gotoxy(6, 22 - 2);
	cout << "DAP AN B: ";
	gotoxy(18, 21 - 2);
	veKhung(5, 101);
	gotoxy(6, 28 - 2);
	cout << "DAP AN C: ";
	gotoxy(18, 27 - 2);
	veKhung(5, 101);
	gotoxy(6, 34 - 2);
	cout << "DAP AN D: ";
	gotoxy(18, 33 - 2);
	veKhung(5, 101);
	veNut(3, 11, 59, 38, "LUU", 30);
}
void vekhungNhapTG()
{
	gotoxy(45, 16);
	veKhung(9, 80);
	gotoxy(52, 20);
	cout << "NHAP THOI GIAN: ";
	gotoxy(67, 19);
	veKhung(3, 7);
	gotoxy(75, 20);
	cout << "(PHUT)";
	gotoxy(95, 20);
	cout << "NHAP SO CAU THI: ";
	gotoxy(111, 19);
	veKhung(3, 7);
}
//========================================== Khung Dang Nhap =================================//

void KhungDangNhap()
{
	SetBGColor(0);
	SetColor(15);
	gotoxy(43, 3); cout << "_________         _________  _________ _______  _______  _______    _        _______          _________ _______  _______ ";
	gotoxy(43, 4); cout << "\\__   __/|\\     /|\\__   __/  \\__   __/(  ____ )(  ___  )(  ____ \\  ( (    /|(  ____ \\|\\     /|\\__   __/(  ____ \\(       )";
	gotoxy(43, 5); cout << "   ) (   | )   ( |   ) (        ) (   | (    )|| (   ) || (    \\/  |  \\  ( || (    \\/| )   ( |   ) (   | (    \\/| () () |";
	gotoxy(43, 6); cout << "   | |   | (___) |   | |        | |   | (____)|| (___) || |        |   \\ | || |      | (___) |   | |   | (__    | || || |";
	gotoxy(43, 7); cout << "   | |   |  ___  |   | |        | |   |     __)|  ___  || |        | (\\ \\) || | ____ |  ___  |   | |   |  __)   | |(_)| |";
	gotoxy(43, 8); cout << "   | |   | (   ) |   | |        | |   | (\\ (   | (   ) || |        | | \\\   ||  \\_  )|| (   ) |   | |   | (      | |   | |";
	gotoxy(43, 9); cout << "   | |   | )   ( |___) (___     | |   | ) \\ \\__| )   ( || (____/\\  | )  \\  || (___) || )   ( |___) (___| (____/\\| )   ( |";
	gotoxy(43, 10); cout << "   )_(   |/     \\|\\_______/     )_(   |/   \\__/|/     \\|(_______/  |/    )_)(_______)|/     \\|\\_______/(_______/|/     \\|";

	SetBGColor(9);
	for (int i = 0; i < 23; i++)
	{
		gotoxy(80, 15 + i);
		cout << "                         ";
		cout << "                         ";
	}

	SetBGColor(9);
	SetColor(15);
	for (int i = 0; i < 50; i++)
	{
		gotoxy(80 + i, 15);
		cout << char(205);
		gotoxy(80 + i, 38);
		cout << char(205);
	}
	for (int i = 1; i < 23; i++)
	{
		gotoxy(79, 15 + i);
		cout << char(186);
		gotoxy(130, 15 + i);
		cout << char(186);
	}
	gotoxy(79, 15);
	cout << char(201);
	gotoxy(130, 15);
	cout << char(187);
	gotoxy(79, 38);
	cout << char(200);
	gotoxy(130, 38);
	cout << char(188);

	SetBGColor(9);
	SetColor(15);
	gotoxy(88, 16 + 1); cout << " __                    __         ";
	gotoxy(88, 16 + 2); cout << "|  |    ____    ____  |__|  ____  ";
	gotoxy(88, 16 + 3); cout << "|  |   / __ \\  / __ \\ |  | /    \\ ";
	gotoxy(88, 16 + 4); cout << "|  |__( \\__\\ )/ /_/  \\|  ||   |  \\";
	gotoxy(88, 16 + 5); cout << "|____/ \\____/ \\___  / |__||___|  /";
	gotoxy(88, 16 + 6); cout << "             /_____/           \\/ ";

	SetColor(15);
	SetBGColor(15);
	for (int i = 0; i < 3; i++)
	{
		gotoxy(87, 26 + i); cout << "                                    ";
		gotoxy(87, 30 + i); cout << "                                    ";
	}

	SetBGColor(15);
	SetColor(0);
	gotoxy(90, 27);
	cout << "MSSV : ";
	gotoxy(90, 31);
	cout << "PASS : ";

	SetBGColor(9);
	SetColor(15);
	//-----
	gotoxy(100, 34);
	cout << char(201);
	cout << char(205);
	cout << char(205);
	cout << char(205);
	cout << char(205);
	cout << char(205);
	cout << char(205);
	cout << char(187);
	//-----
	gotoxy(100, 35);
	cout << char(186);
	cout << "  " << char(196) << ">  ";
	cout << char(186);
	//-----
	gotoxy(100, 36);
	cout << char(200);
	cout << char(205);
	cout << char(205);
	cout << char(205);
	cout << char(205);
	cout << char(205);
	cout << char(205);
	cout << char(188);
	SetBGColor(0);
	SetColor(15);
}

//========================== IN TEN ======================//

void InTen()
{
	gotoxy(120, 45);
	cout << "N20DCCN059-NGUYEN VIET SI \n";
	gotoxy(120, 46);
	cout << "N20DCN102-NGUYEN HUU HIEU \n";
}

