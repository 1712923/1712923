#include <stdio.h>
#include <string.h>

struct Student{
	char *MSSV;
	char *HoTen;
	char *Khoa;
	char *KHoc;
	char *NgaySinh;
	char *HACN;
	char *MTBT;
	char **SoThich;
};

struct Student Students[256];
int readStudentFile();


int main(int argc, char **argv)
{
	readStudentFile();
	return 0;
}

int readStudentFile()
{

	FILE *StudentFile;
	char *buf = new char[256];
	char *tmp;

	//Lỗi nếu không cấp phát được bộ nhớ cho buf
	if (buf == NULL) {
		printf("No memory\n");
		return 1;
	}

	if ((StudentFile = fopen("ac.csv", "r")) == NULL) //Đọc file
	{
		printf("File could not be opened.\n");
	}

	int i = 0;
	int j = 0;
	int flag = 0;
	while (fgets(buf, 255, StudentFile) != NULL)
	{
		if ((strlen(buf)>0) && (buf[strlen(buf) - 1] == '\n'))
			buf[strlen(buf) - 1] = '\0';

		tmp = strtok(NULL, ",");
		Students[i].MSSV = tmp;

		tmp = strtok(NULL, ",");
		Students[i].HoTen = tmp;

		tmp = strtok(NULL, ",");
		Students[i].Khoa = tmp;

		tmp = strtok(NULL, ",");
		Students[i].KHoc = tmp;

		tmp = strtok(NULL, ",");
		Students[i].NgaySinh = tmp;

		tmp = strtok(NULL, ",");
		Students[i].HACN = tmp;

		tmp = strtok(NULL, ",");
		for (j; strcpy(tmp, '\0') != 0; j++)
		{
			Students[i].SoThich[j] = tmp;
		}
		//tempStudent.ID = atoi(buf);

		i++;
		flag = -1;
	}
	//free(buf);
	fclose(StudentFile);
	if (flag == -1)
	for (i = 0; i <= sizeof(Students); i++)
	{
		if (Students[i].MSSV != 0)
			printf("MSSV: %s\n", Students[i].MSSV);
		printf("Ho ten: %s\n", Students[i].HoTen);
		printf("Khoa: %s\n", Students[i].Khoa);
		printf("Khoa' hoc: %d\n", Students[i].KHoc);
		printf("Ngay sinh: %s\n", Students[i].NgaySinh);
		for (int k = 0; k<j; k++)
			printf("So thich: %s\n", Students[i].SoThich);
	}
	return 0;
}