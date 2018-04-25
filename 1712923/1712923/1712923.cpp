#include <stdio.h>
#include <string.h>
typedef struct
{
	char *MSSV;
	char *HoVaTen;
	char *Khoa;
	char *KhoaHoc;
	char *NgaySinh;
	char *HinhAnhCaNhan;
	char *MoTaBanThan;
	char *SoThich;
}SinhVien;

char * DocThongTin(FILE*fp, char*s)
{
	if (feof(fp))
	{
		return NULL;
	}
	fseek(fp,1,0);
	s[0] = 0; 
	int i = 0, c;

	do
	{
		c = fgetc(fp);
		if (c == '"')
		{
			break;
		}
		s[i] = c;
		i++;
	} while (1);
	s[i] = 0;
	return s;
}

int LayThongTin(FILE*fp, SinhVien& sv)
{
	DocThongTin(fp, sv.MSSV);
	DocThongTin(fp, sv.HoVaTen);
	DocThongTin(fp, sv.Khoa);
	DocThongTin(fp, sv.KhoaHoc);
	DocThongTin(fp, sv.NgaySinh);
	DocThongTin(fp, sv.SoThich);
	return 1;
}

void LaySinhVien(FILE*fp, SinhVien DS[], int&n)
{
	SinhVien sv; n = 0;
	while (!feof(fp))
	{
		if (LayThongTin(fp, sv))
		{
			DS[n] = sv;
			n++;
		}
		else break;
	}
}

void In(FILE*fp, SinhVien DS[], int n)
{
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%s/t%15s %7s\t %s\t %s\t %s\n", DS[i].MSSV, DS[i].HoVaTen, DS[i].Khoa, DS[i].KhoaHoc, DS[i].NgaySinh, DS[i].SoThich);
	}
}

void main()
{
	SinhVien DS[10]; int n;
	FILE*fp = fopen("Book1.csv", "rt");
	if (fp == NULL)
	{
		return;
	}
	LaySinhVien(fp, DS, n);
	In(fp, DS, n);
}
