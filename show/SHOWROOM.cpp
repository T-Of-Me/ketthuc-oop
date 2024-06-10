#include <iostream>
#include <fstream>

using namespace std;
class PhuongTien
{
protected:
	string Id;
	string hangSanXuat;
	int namSanXuat;
	int giaBan;
	string mauXe;

public:
	void display()
	{
		cout << "Id Phuong Tien: " << Id << endl;
		cout << "Hang San Xuat: " << hangSanXuat << endl;
		cout << "Nam San Xuat: " << namSanXuat << endl;
		cout << "Gia Ban: " << giaBan << endl;
		cout << "Mau Xe: " << mauXe << endl;
	}
	string getHangSanXuat()
	{
		return hangSanXuat;
	}
	string getId()
	{
		return Id;
	}
	int getGiaBan()
	{
		return giaBan;
	}
};

class Oto : public PhuongTien
{
private:
	int soChoNgoi;
	string kieuDongCo;

public:
	void display_Oto()
	{
		PhuongTien::display();
		cout << "So Cho Ngoi: " << soChoNgoi << endl;
		cout << "Kieu Dong Co: " << kieuDongCo << endl;
	}

	friend ostream &operator<<(ostream &out, Oto x)
	{
		out << x.Id << endl;
		out << x.hangSanXuat << endl;
		out << x.namSanXuat << endl;
		out << x.giaBan << endl;
		out << x.mauXe << endl;
		out << x.soChoNgoi << endl;
		out << x.kieuDongCo << endl;
		return out;
	}

	friend istream &operator>>(istream &in, Oto &x)
	{
		in >> x.Id >> x.hangSanXuat >> x.namSanXuat >> x.giaBan >> x.mauXe >> x.soChoNgoi >> x.kieuDongCo;
		return in;
	}
};

class XeMay : public PhuongTien
{
private:
	double congSuatDongCo;

public:
	void display_XeMay()
	{
		PhuongTien::display();
		cout << "Cong suat dong co: " << congSuatDongCo << " kW" << endl;
	}

	friend ostream &operator<<(ostream &out, XeMay x)
	{
		out << x.Id << endl;
		out << x.hangSanXuat << endl;
		out << x.namSanXuat << endl;
		out << x.giaBan << endl;
		out << x.mauXe << endl;
		out << x.congSuatDongCo << endl;
		return out;
	}

	friend istream &operator>>(istream &in, XeMay &x)
	{
		in >> x.Id >> x.hangSanXuat >> x.namSanXuat >> x.giaBan >> x.mauXe >> x.congSuatDongCo;
	}
};

class XeTai : public PhuongTien
{
private:
	double trongTai;

public:
	void display_XeTai()
	{
		PhuongTien::display();
		cout << "Trong tai: " << trongTai << " kg" << endl;
	}

	friend ostream &operator<<(ostream &out, XeTai x)
	{
		out << x.Id << endl;
		out << x.hangSanXuat << endl;
		out << x.namSanXuat << endl;
		out << x.giaBan << endl;
		out << x.mauXe << endl;
		out << x.trongTai << endl;
		return out;
	}

	friend istream &operator>>(istream &in, XeTai &x)
	{
		in >> x.Id >> x.hangSanXuat >> x.namSanXuat >> x.giaBan >> x.mauXe >> x.trongTai;
		return in;
	}
};

int main()
{
	Oto a;
	XeMay b;
	XeTai c;
	string s;
	int lc;
	do
	{
		ofstream outputfile("Showroom.txt", ios::app);
		cout << "\t\t==========MENU==========" << endl;
		cout << "1. Them Oto" << endl;
		cout << "2. Them Xe May" << endl;
		cout << "3. Them Xe Tai" << endl;
		cout << "4. Danh cac phuong tien trong showroom" << endl;
		cout << "5. Tim kiem phuong tien theo Hang san xuat" << endl;
		cout << "6. Tim kiem phuong tien theo Loai Phuong Tien" << endl;
		cout << "7. Tong gia tri cua tat ca cac phuong tien trong showroom" << endl;
		cout << "8. Xoa Phuong tien" << endl;
		cout << "0. Exit" << endl;
		cout << "\t\t========================" << endl;
		cout << "Nhap lua chon: ";
		cin >> lc;
		switch (lc)
		{
		case 1:
		{
			cout << "Nhap lan luot: HangSanXuat-NamSanXuat-GiaBan-MauXe-SoChoNgoi-KieuDongCo" << endl;

			while (cin >> a)
			{
				outputfile << "Oto" << endl;
				outputfile << a << endl;
				break;
			}
			break;
		}
		case 2:
		{
			cout << "Nhap lan luot: HangSanXuat-NamSanXuat-GiaBan-MauXe-CongSuatDongCo" << endl;
			while (cin >> b)
			{
				outputfile << "XeMay" << endl;
				outputfile << b << endl;
				break;
			}
			break;
		}
		case 3:
		{
			cout << "Nhap lan luot: HangSanXuat-NamSanXuat-GiaBan-MauXe-TrongTai" << endl;
			while (cin >> c)
			{
				outputfile << "XeTai" << endl;
				outputfile << c << endl;
				break;
			}
			break;
		}
		case 4:
		{
			cout << "Danh sach cac phuong tien trong showroom: " << endl;
			ifstream inputfile("Showroom.txt", ios::in);
			while (inputfile >> s)
			{
				if (s == "Oto")
				{
					inputfile >> a;
					a.display_Oto();
					cout << "\n";
				}
				else if (s == "XeMay")
				{
					inputfile >> b;
					b.display_XeMay();
					cout << "\n";
				}
				else if (s == "XeTai")
				{
					inputfile >> c;
					c.display_XeTai();
					cout << "\n";
				}
			}
			inputfile.close();
			break;
		}
		case 5:
		{
			cout << "Nhap hang xe can tim: " << endl;
			string canTim;
			cin >> canTim;
			ifstream inputfile("Showroom.txt", ios::in);
			while (inputfile >> s)
			{
				if (s == "Oto")
				{
					inputfile >> a;
					if (canTim == a.getHangSanXuat())
					{
						a.display_Oto();
						cout << "\n";
					}
				}
				else if (s == "XeMay")
				{
					inputfile >> b;
					if (canTim == b.getHangSanXuat())
					{
						b.display_XeMay();
						cout << "\n";
					}
				}
				else if (s == "XeTai")
				{
					inputfile >> c;
					if (canTim == c.getHangSanXuat())
					{
						c.display_XeTai();
						cout << "\n";
					}
				}
			}
			inputfile.close();
			break;
		}
		case 6:
		{
			cout << "Nhap loai phuong tien can tim: " << endl;
			string canTim;
			cin >> canTim;
			ifstream inputfile("Showroom.txt", ios::in);
			if (canTim == "Oto")
			{
				while (inputfile >> s)
				{
					if (s == "Oto")
					{
						inputfile >> a;
						a.display_Oto();
						cout << "\n";
					}
				}
			}
			else if (canTim == "XeMay")
			{
				while (inputfile >> s)
				{
					if (s == "XeMay")
					{
						inputfile >> b;
						b.display_XeMay();
						cout << "\n";
					}
				}
			}
			else if (canTim == "XeTai")
			{
				while (inputfile >> s)
				{
					if (s == "XeTai")
					{
						inputfile >> c;
						c.display_XeTai();
						cout << "\n";
					}
				}
			}
			inputfile.close();
			break;
		}
		case 7:
		{
			int tongGiaTri = 0;
			int tongGiaTriOto = 0;
			int tongGiaTriXeMay = 0;
			int tongGiaTriXeTai = 0;
			ifstream inputfile("Showroom.txt", ios::in);
			while (inputfile >> s)
			{
				if (s == "Oto")
				{
					inputfile >> a;
					tongGiaTriOto += a.getGiaBan();
				}
				else if (s == "XeMay")
				{
					inputfile >> b;
					tongGiaTriXeMay += b.getGiaBan();
				}
				else if (s == "XeTai")
				{
					inputfile >> c;
					tongGiaTriXeTai += c.getGiaBan();
				}
			}
			tongGiaTri = tongGiaTriOto + tongGiaTriXeMay + tongGiaTriXeTai;
			cout << "Tong gia tri cua tat ca cac phuong tien trong showroom la:  " << tongGiaTri << endl;
			inputfile.close();
			break;
		}
		case 8:
		{
			cout << "Nhap ID muon xoa: " << endl;
			string ID;
			cin >> ID;
			ifstream inputfile("Showroom.txt", ios::in);
			ofstream outputfile("Showroom_temp.txt", ios::out);
			while (inputfile >> s)
			{
				if (s == "Oto")
				{
					inputfile >> a;
					if (a.getId() != ID)
					{
						outputfile << "Oto" << endl;
						outputfile << a << endl;
					}
				}
				else if (s == "XeMay")
				{
					inputfile >> b;
					if (b.getId() != ID)
					{
						outputfile << "XeMay" << endl;
						outputfile << b << endl;
					}
				}
				else if (s == "XeTai")
				{
					inputfile >> c;
					if (c.getId() != ID)
					{
						outputfile << "XeTai" << endl;
						outputfile << c << endl;
					}
				}
			}
			inputfile.close();
			outputfile.close();
			remove("Showroom.txt");
			rename("Showroom_temp.txt", "Showroom.txt");
			break;
		}
		case 0:
		{
			cout << "Thoat chuong trinh." << endl;
			break;
		}
		default:
			cout << "Lua chon khong hop le. Vui long thu lai." << endl;
			break;
		}
	} while (lc != 0);
	return 0;
}

