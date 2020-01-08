

#include <iostream>
#include <cstring>
#include <cstdlib>

#pragma warning( disable : 4996 )



using namespace std;

char* MilitaryTimeToRegularTime(char* militaryTime)
{
	int i = 0, x = 0, y = 0, z = 0;

	//必須符合格式
	char* str = new char[8];
	char* str1 = new char[2];
	char* str2 = new char[1];
	char* str3 = new char[2];

	char* str4 = new char[3];
	char* temp = new char[2];
	char* temp1 = new char[1];
	char* temp2 = new char[1];


	strcpy(str, militaryTime);
	//長度是5
	for (i = 0; i < 5; i++)
	{
		if (i >= 0 && i <= 1)
		{
			str1[x++] = str[i];
		}
		else if (i == 2) {
			str2[y++] = str[i];
		}
		else if (i >= 3 && i <= 4) {
			str3[z++] = str[i];
		}

	}
	str1[2] = '\0'; // 字串結束
	str2[1] = '\0'; // 字串結束
	str3[2] = '\0'; // 字串結束

	// 長度不是5、不含冒號，則此副程式應回傳 error 字串
	if (strlen(str) != 5) {
		cout << "error" << endl;
		exit(1);
	}
	if (strcmp(str2, ":") != 0) {
		cout << "error" << endl;
		exit(1);
	}


	// 不是數字字元，則此副程式應回傳 error 字串
	for (i = 0; i < 5; i++) {
		if ((i >= 0 && i <= 1) || (i >= 3 && i <= 4)) {
			if (str[i] < '0' || str[i] > '9') {
				cout << "error" << endl;
				exit(1);
			}

		}

	}

	// 時間不合理，則此副程式應回傳 error 字串
	if (atoi(str1) > 24 || atoi(str3) > 59) {
		cout << "error" << endl;
		exit(1);

	}

	if (atoi(str1) >= 0 && atoi(str1) < 12) { // AM 時間
		strcpy(str4, " AM");
		if (strcmp(str1, "00") == 0) { // 00:xx 輸出 12:xx AM
			strcpy(str1, "12");
		}
	}
	else if (atoi(str1) >= 12 && atoi(str1) <= 24) { // PM 時間
		strcpy(str4, " PM");
		if (strcmp(str1, "24") == 0) { // 24:xx 輸出 12:xx PM
			strcpy(str1, "12");
		}
		else if (atoi(str1) >= 13 && atoi(str1) <= 21) { // 轉成小時小於10
			temp1[0] = ' ';
			itoa(atoi(str1) - 12, temp2, 10);
			str1[0] = temp1[0];
			str1[1] = temp2[0];
		}
		else if (atoi(str1) >= 22 && atoi(str1) <= 23) { // 轉成小時大於10
			itoa(atoi(str1) - 12, temp, 10);
			strcpy(str1, temp);
		}
	}

	str4[3] = '\0'; // 字串結束
	x = 0;y = 0;z = 0;

	int w = 0;
	// 組合時間
	for (i = 0; i < 8; i++) {
		if (i >= 0 && i <= 1) { // 12小時制的時間
			str[i] = str1[x++];
		}
		else if (i >= 5 && i <= 7) { // AM 或 PM 的時間
			str[i] = str4[w++];
		}

	}
	str[8] = '\0'; // 字串結束
	return str;

}

int main(void)
{
	char* str = new char[5];
	cout << "時間:";
	cin >> str;
	cout << MilitaryTimeToRegularTime(str) << endl; // 輸出 12:00 AM
	return 0;
}

