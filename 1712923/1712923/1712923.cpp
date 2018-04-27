#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <io.h> 

typedef struct
{
	wchar_t* MSSV;
	wchar_t* HoTen;
	wchar_t* khoa;
	wchar_t* KhoaHoc;
	wchar_t* NgaySinh;
	wchar_t* HinhAnh;
	wchar_t* MoTaBanThan;
	wchar_t* SoThich;
}SinhVien;

int LayViTri(FILE* f, wchar_t kitu)
{
	wchar_t c;
	int i = 0;
	while (!feof(f))
	{
		c = fgetwc(f);
		if (c != kitu)
		{
			i++;
		}
		else
		{
			return i + 1;
		}
	}
	return i;
}
void DocThongTin(FILE* FileIn, SinhVien DS[], int &BatDau)
{

	int a, b;
	fseek(FileIn, BatDau, SEEK_SET);
	if (fgetwc(FileIn) != L'"')
	{
		fseek(FileIn, BatDau, SEEK_SET);
		a = LayViTri(FileIn, L',');
		DS-> MSSV = (wchar_t*)malloc(a*sizeof(wchar_t));
		fseek(FileIn, BatDau, SEEK_SET);
		fgetws(DS-> MSSV, a, FileIn);
		b = ftell(FileIn);
	}
	else
	{
		fseek(FileIn, BatDau + 1, SEEK_SET);
		a = LayViTri(FileIn, L'"');
		DS-> MSSV = (wchar_t*)malloc(a*sizeof(wchar_t));
		fseek(FileIn, BatDau + 1, SEEK_SET);
		fgetws(DS-> MSSV, a, FileIn);
		b = ftell(FileIn) + 1;
	}
	

	fseek(FileIn, b + 1, SEEK_SET);
	if (fgetwc(FileIn) != L'"')
	{
		fseek(FileIn, b + 1, SEEK_SET);
		a = LayViTri(FileIn, L',');
		DS-> HoTen = (wchar_t*)malloc(a*sizeof(wchar_t));
		fseek(FileIn, b + 1, SEEK_SET);
		fgetws(DS-> HoTen, a, FileIn);
		b = ftell(FileIn);
	}
	else
	{
		fseek(FileIn, b + 2, SEEK_SET);
		a = LayViTri(FileIn, L'"');
		DS-> HoTen = (wchar_t*)malloc(a*sizeof(wchar_t));
		fseek(FileIn, b + 2, SEEK_SET);
		fgetws(DS-> HoTen, a, FileIn);
		b = ftell(FileIn) + 1;
	}
	


	fseek(FileIn, b + 1, SEEK_SET);
	if (fgetwc(FileIn) != L'"')
	{
		fseek(FileIn, b + 1, SEEK_SET);
		a = LayViTri(FileIn, L',');
		DS-> khoa = (wchar_t*)malloc(a*sizeof(wchar_t));
		fseek(FileIn, b + 1, SEEK_SET);
		fgetws(DS-> khoa, a, FileIn);
		b = ftell(FileIn);
	}
	else
	{
		fseek(FileIn, b + 2, SEEK_SET);
		a = LayViTri(FileIn, L'"');
		DS-> khoa = (wchar_t*)malloc(a*sizeof(wchar_t));
		fseek(FileIn, b + 2, SEEK_SET);
		fgetws(DS-> khoa, a, FileIn);
		b = ftell(FileIn) + 1;
	}
	


	fseek(FileIn, b + 1, SEEK_SET);
	if (fgetwc(FileIn) != L'"')
	{
		fseek(FileIn, b + 1, SEEK_SET);
		a = LayViTri(FileIn, L',');
		DS-> KhoaHoc = (wchar_t*)malloc(a*sizeof(wchar_t));
		fseek(FileIn, b + 1, SEEK_SET);
		fgetws(DS-> KhoaHoc, a, FileIn);
		b = ftell(FileIn);
	}
	else
	{
		fseek(FileIn, b + 2, SEEK_SET);
		a = LayViTri(FileIn, L'"');
		DS-> KhoaHoc = (wchar_t*)malloc(a*sizeof(wchar_t));
		fseek(FileIn, b + 2, SEEK_SET);
		fgetws(DS-> KhoaHoc, a, FileIn);
		b = ftell(FileIn) + 1;
	}

	fseek(FileIn, b + 1, SEEK_SET);
	if (fgetwc(FileIn) != L'"')
	{
		fseek(FileIn, b + 1, SEEK_SET);
		a = LayViTri(FileIn, L',');
		DS-> NgaySinh = (wchar_t*)malloc(a*sizeof(wchar_t));
		fseek(FileIn, b + 1, SEEK_SET);
		fgetws(DS-> NgaySinh, a, FileIn);
		b = ftell(FileIn);
	}
	else
	{
		fseek(FileIn, b + 2, SEEK_SET);
		a = LayViTri(FileIn, L'"');
		DS-> NgaySinh = (wchar_t*)malloc(a*sizeof(wchar_t));
		fseek(FileIn, b + 2, SEEK_SET);
		fgetws(DS-> NgaySinh, a, FileIn);
		b = ftell(FileIn) + 1;
	}
	
	fseek(FileIn, b + 1, SEEK_SET);
	if (fgetwc(FileIn) != L'"')
	{
		fseek(FileIn, b + 1, SEEK_SET);
		a = LayViTri(FileIn, L',');
		DS-> HinhAnh = (wchar_t*)malloc(a*sizeof(wchar_t));
		fseek(FileIn, b + 1, SEEK_SET);
		fgetws(DS-> HinhAnh, a, FileIn);
		b = ftell(FileIn);
	}
	else
	{
		fseek(FileIn, b + 2, SEEK_SET);
		a = LayViTri(FileIn, L'"');
		DS-> HinhAnh = (wchar_t*)malloc(a*sizeof(wchar_t));
		fseek(FileIn, b + 2, SEEK_SET);
		fgetws(DS-> HinhAnh, a, FileIn);
		b = ftell(FileIn) + 1;
	}
	


	fseek(FileIn, b + 1, SEEK_SET);
	if (fgetwc(FileIn) != L'"')
	{
		fseek(FileIn, b + 1, SEEK_SET);
		a = LayViTri(FileIn, L',');
		DS-> MoTaBanThan = (wchar_t*)malloc(a*sizeof(wchar_t));
		fseek(FileIn, b + 1, SEEK_SET);
		fgetws(DS-> MoTaBanThan, a, FileIn);
		b = ftell(FileIn);
	}
	else
	{
		fseek(FileIn, b + 2, SEEK_SET);
		a = LayViTri(FileIn, L'"');
		DS-> MoTaBanThan = (wchar_t*)malloc(a*sizeof(wchar_t));
		fseek(FileIn, b + 2, SEEK_SET);
		fgetws(DS-> MoTaBanThan, a, FileIn);
		b = ftell(FileIn) + 1;
	}
	

	fseek(FileIn, b, SEEK_SET);
	if (fgetwc(FileIn) == L','){
		if (fgetwc(FileIn) != L'"')
		{
			fseek(FileIn, b + 1, SEEK_SET);
			a = LayViTri(FileIn, '\n');
			DS-> SoThich = (wchar_t*)malloc(a*sizeof(wchar_t));
			fseek(FileIn, b + 1, SEEK_SET);
			fgetws(DS-> SoThich, a, FileIn);
			b = ftell(FileIn);
			BatDau = b;
		}
		else
		{
			fseek(FileIn, b + 2, SEEK_SET);
			a = LayViTri(FileIn, '"');
			DS-> SoThich = (wchar_t*)malloc(a*sizeof(wchar_t));
			fseek(FileIn, b + 2, SEEK_SET);
			fgetws(DS-> SoThich, a, FileIn);

			b = ftell(FileIn) + 1;

		}
		
		BatDau = b + 2;
	}
	else
	{
		BatDau = b;
	}
	wprintf(L"%ls\n", DS-> MSSV);
	wprintf(L"%ls\n", DS-> HoTen);
	wprintf(L"%ls\n", DS-> khoa);
	wprintf(L"%ls\n", DS-> KhoaHoc);
	wprintf(L"%ls\n", DS-> NgaySinh);
	wprintf(L"%ls\n", DS-> HinhAnh);
	wprintf(L"%ls\n", DS-> MoTaBanThan);
	wprintf(L"%ls\n", DS-> SoThich);
}

int dodai(wchar_t* s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return i;
}

void CopyChuoi(wchar_t* str, wchar_t* s)
{
	int a = dodai(s);
	for (int i = 0; i < a; i++)
	{
		str[i] = s[i];
	}
	str[a] = NULL ;
}
void GhepChuoi(wchar_t* str, wchar_t* s)
{
	int a = dodai(str);
	int b = dodai(str) + dodai(s);
	for (int i = 0; i < b; i++)
	{
		if (i == a)
		{
			for (int j = 0; j < dodai(s); j++)
			{
				str[i] = s[j];
				i++;
			}
		}
	}
	str[b] = NULL;
}
void GhiFile(SinhVien* DS);
void GhiFile(SinhVien* DS)
{
	wchar_t fp[100];
	CopyChuoi(fp, DS-> MSSV);
	GhepChuoi(fp, L".html");
	FILE* f;
	_wfopen_s(&f, fp, L"wt,ccs=UTF-8");
	_setmode(_fileno(f), _O_U8TEXT);
	if (f == NULL)
	{
		wprintf(L"Không Thể Tạo File\n");
	}
	else
	{
		fwprintf(f, L"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
		fwprintf(f, L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
		fwprintf(f, L"<head>\n");
		fwprintf(f, L"<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n");
		fwprintf(f, L"<link rel=\"stylesheet\" type=\"text/css\" href=\"personal.css\" />\n");
		fwprintf(f, L"<title>HCMUS - %ls</title>\n", DS-> HoTen);
		fwprintf(f, L"</head>\n");
		fwprintf(f, L"<body>\n");
		fwprintf(f, L"<div class=\"Layout_container\">\n");
		fwprintf(f, L"<!-- Begin Layout Banner Region -->\n");
		fwprintf(f, L"<div class=\"Layout_Banner\" >\n");
		fwprintf(f, L"<div><img id=\"logo\" src=\"Images/logo.jpg\" height=\"105\" /></div>\n");
		fwprintf(f, L"<div class=\"Header_Title\">TRƯỜNG ÐẠI HỌC KHOA HỌC TỰ NHIÊN</div>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<div class=\"Layout_MainContents\">\n");
		fwprintf(f, L"<div class=\"Personal_Main_Information\">\n");
		fwprintf(f, L"<div class=\"Personal_Location\"> \n");
		fwprintf(f, L"<img src=\"Images/LogoFooter.jpg\" width=\"27\" height=\"33\" />\n");
		fwprintf(f, L"<span class=\"Personal_FullName\">%ls - %ls</span>\n", DS-> HoTen, DS-> MSSV);
		fwprintf(f, L"<div class=\"Personal_Department\">%ls</div>\n", DS-> khoa);
		fwprintf(f, L"<br />\n");
		fwprintf(f, L"<div class=\"Personal_Phone\">\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<br />\n");
		fwprintf(f, L"<br />\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<div class=\"Personal_HinhAnhKhung\">\n");
		fwprintf(f, L"<img src=\"Images/%ls\" class=\"Personal_HinhAnh\" />\n", DS-> HinhAnh);
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<div class=\"MainContain\">\n\n");
		fwprintf(f, L"<div class=\"MainContain_Top\">\n\n");
		fwprintf(f, L"<div class=\"InfoGroup\">Thông tin cá nhân</div>\n");
		fwprintf(f, L"<div>\n");
		fwprintf(f, L"<ul class=\"TextInList\">\n");
		fwprintf(f, L"<li>Họ và tên: %ls </li>\n", DS-> HoTen);
		fwprintf(f, L"<li>MSSV: %ls </li>\n", DS-> MSSV);
		fwprintf(f, L"<li>Sinh viên khoa: %ls </li>\n", DS-> khoa);
		fwprintf(f, L"<li>Khóa Học: %ls </li>\n", DS-> KhoaHoc);
		fwprintf(f, L"<li>Ngày sinh: %ls </li>\n", DS-> NgaySinh);
		fwprintf(f, L"</ul>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<div class=\"InfoGroup\">Sở thích</div>\n");
		fwprintf(f, L"<div>\n");
		fwprintf(f, L"<ul class=\"TextInList\">\n");
		fwprintf(f, L"<li>%ls</li>\n", DS-> SoThich);
		fwprintf(f, L"</ul>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<div class=\"InfoGroup\">Mô tả bản thân</div>\n");
		fwprintf(f, L"<div>\n");
		fwprintf(f, L"<ul class=\"Description\">\n");
		fwprintf(f, L"<li>%ls</li>\n", DS-> MoTaBanThan);
		fwprintf(f, L"</ul>\n");
		fwprintf(f, L"</div>\n\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<!-- Begin Layout Footer -->\n");
		fwprintf(f, L"<div class=\"Layout_Footer\">\n");
		fwprintf(f, L"<div class=\"divCopyright\">\n");
		fwprintf(f, L"<br />\n");
		fwprintf(f, L"<img src=\"Images/LogoFooter_gray.jpg\" width=\"34\" height=\"41\" /><br />\n");
		fwprintf(f, L"<br />\n");
		fwprintf(f, L"@2018</br>\n");
		fwprintf(f, L"Ðồ án giữa kì</br>\n");
		fwprintf(f, L"Kĩ thuật lập trình</br>\n");
		fwprintf(f, L"TH2018/04</br>\n");
		fwprintf(f, L"1712923 - Phạm Lê Hoài Vũ</br>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<!-- End Layout Footer -->\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"</body>\n");
		fwprintf(f, L"</html>");
		fclose(f);
	}
}

void main()
{
	FILE* FileIn;
	fopen_s(&FileIn, "SV.csv", "r, ccs=UTF-8");
	if (FileIn == NULL)
	{
		wprintf(L"Khong the mo File\n");
	}
	else
	{
		SinhVien* DS;
		int n = 0, BatDau = 3;
		while (!feof(FileIn))
		{
			if (fgetwc(FileIn) == L'\n')
			{
				n++;
			}
		}
		DS = (SinhVien*)malloc(n*sizeof(SinhVien));
		for (int i = 0; i <n; i++)
		{
			DocThongTin(FileIn, &DS[i], BatDau);
			GhiFile(&DS[i]);

		}
		free(DS);
		fclose(FileIn);
	}
}