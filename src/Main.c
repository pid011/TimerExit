#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

int main(void) {
	int choices = 0;
	int sec = 0;

	system("title TimerExit");
	system("mode con:cols=70 lines=40");
	system("shutdown /a");
	system("cls");
	//------------------------------------------------------
	puts("[Console]    -------------------------------------------");
	puts("[Console]   |                                           |");
	puts("[Console]   |               [TimerExit]                 |");
	puts("[Console]   |         ��ǻ�� �������� ���α׷�          |");
	puts("[Console]    -------------------------------------------");
	puts("[Console]    -------------------------------------------");
	puts("[Console]   |                                           |");
	puts("[Console]   |     <1>����  <2>�ٽý���                  |");
	puts("[Console]   |                                           |");
	puts("[Console]    -------------------------------------------");
	printf("[Console] �Է� :");
	scanf_s("%d", &choices);
	sec = setCommand(choices);
	printf("[Console] %d�� �Ŀ� ����˴ϴ�.\n", sec / 60);
	//------------------------------------------------------
	puts("[Console] ��� �Ͻðڽ��ϱ�?");
	puts("[Console] press    YES = 1     NO = Any Number Key");
	scanf_s("%d", &choices);
	if (choices == 1) {
		system("shutdown /a");
		puts("[Console] ��� �Ǿ����ϴ�. �ƹ� Ű�� ���� �� ���α׷��� ����˴ϴ�.");
	}
	else {
		puts("[Console] �ƹ�Ű�� ���� �� ���α׷��� ����˴ϴ�.");
	}

	_getch();
	return 0;
}

int setCommand(int choice) {
	int sec = 0;
	char cmd[100];

	if (choice != 1 && choice !=2)
	{
		puts("[Console] error : �ش� ��ɾ�� ���� ��ɾ� �Դϴ�.");
		puts("[Console] �ƹ� Ű�� ���� �� ����˴ϴ�.");
		_getch();
		exit(0);
	}
	if (choice == 1)
	{
		sec = getTime();
		sprintf_s(cmd, sizeof(cmd), "shutdown /s /t %d", sec);
		system(cmd);
		printf("[Console] \'����\'�� �����ϼ̽��ϴ�.\n");
	}
	else if (choice == 2)
	{
		sec = getTime();
		sprintf_s(cmd, sizeof(cmd), "shutdown /r /t %d", sec);
		system(cmd);
		printf("[Console] \'�ٽý���\'�� �����ϼ̽��ϴ�.\n");
	}
	return sec;
}

int getTime() {
	int hour, min, sec;

	printf("[Console] �ð� �Է�. ex)\'0\' �ð� \'30\' �еڸ� \'0\' �̶�� �Է�.\n");
	printf("[Console] �Է�:");
	scanf_s("%d", &hour);

	printf("[Console] �� �Է�. ex)\'0\' �ð� \'30\' �еڸ� \'30\' �̶�� �Է�.\n");
	printf("[Console] �Է�:");
	scanf_s("%d", &min);
	puts("[Console] \n...\n");
	hour *= 3600;
	min *= 60;
	return sec = hour + min;
}