#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

int getTime() {
	int hour, min, sec;

	printf("�ð� �Է�. ex)\'0\' �ð� \'30\' �еڸ� \'0\' �̶�� �Է�.\n");
	printf("�Է�:");
	scanf_s("%d", &hour);

	printf("�� �Է�. ex)\'0\' �ð� \'30\' �еڸ� \'30\' �̶�� �Է�.\n");
	printf("�Է�:");
	scanf_s("%d", &min);
	puts("\n...\n");
	hour *= 3600;
	min *= 60;
	return sec = hour + min;
}

int setCommand(int choice) {
	int sec = 0;
	char cmd[100];

	if (choice != 1 && choice != 2)
	{
		puts("error : �ش� ��ɾ�� ���� ��ɾ� �Դϴ�.");
		puts("�ƹ� Ű�� ���� �� ����˴ϴ�.");
		_getch();
		exit(0);
	}
	if (choice == 1)
	{
		sec = getTime();
		sprintf_s(cmd, sizeof(cmd), "shutdown /s /t %d", sec);
		system(cmd);
		printf("\'����\'�� �����ϼ̽��ϴ�.\n");
	}
	else if (choice == 2)
	{
		sec = getTime();
		sprintf_s(cmd, sizeof(cmd), "shutdown /r /t %d", sec);
		system(cmd);
		printf("\'�ٽý���\'�� �����ϼ̽��ϴ�.\n");
	}
	return sec;
}

int main(void) {
	int choices = 0;
	int sec = 0;

	system("title TimerExit");
	system("mode con:cols=70 lines=40");
	system("shutdown /a");
	system("cls");
	//------------------------------------------------------
	puts("   -------------------------------------------");
	puts("  |                                           |");
	puts("  |               [TimerExit]                 |");
	puts("  |         ��ǻ�� �������� ���α׷�          |");
	puts("   -------------------------------------------");
	puts("   -------------------------------------------");
	puts("  |                                           |");
	puts("  |     <1>����  <2>�ٽý���                  |");
	puts("  |                                           |");
	puts("   -------------------------------------------");
	printf("�Է� :");
	scanf_s("%d", &choices);
	sec = setCommand(choices);
	printf("%d�� �Ŀ� ����˴ϴ�.\n", sec / 60);
	//------------------------------------------------------
	puts("��� �Ͻðڽ��ϱ�?");
	puts("press    YES = 1     NO = Any Number Key");
	scanf_s("%d", &choices);
	if (choices == 1) {
		system("shutdown /a");
		puts("��� �Ǿ����ϴ�. �ƹ� Ű�� ���� �� ���α׷��� ����˴ϴ�.");
	}
	else {
		puts("�ƹ�Ű�� ���� �� ���α׷��� ����˴ϴ�.");
	}

	_getch();
	return 0;
}