#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

void ShutdownCommand(int sec) {
	char S_cmd[100];
	
}
void RestartCommand(int sec) {
	char R_cmd[100];
	
}

void Cancel() {
	int cancelCommand;
	


}
void error() {
	puts("error : �ش� ��ɾ�� ���� ��ɾ� �Դϴ�");
	puts("�ƹ�Ű�� ���� �� ����˴ϴ�.");
	_getch();
	exit(0);
}
int main(void) {
	int hour = 0;
	int min = 0;
	int ch = 0;
	int sec = 0;
	system("title TimerExit");
	system("mode con:cols=60 lines=40");
	system("shutdown /a");
	system("cls");

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
	scanf_s("%d", &ch);
	if (ch != 1 && ch != 2) {
		error();
	}
	system("cls");
	printf("�������Ḧ �����մϴ�...\n\n");

	printf("�ð� �Է�. ex)0�ð� 30�еڸ� 0�̶�� �Է�.\n");
	printf("�Է�:");
	scanf_s("%d", &hour);

	printf("�� �Է�. ex)0�ð� 30�еڸ� 30�̶�� �Է�.\n");
	printf("�Է�:");
	scanf_s("%d", &min);
	puts("\n...\n");
	hour *= 3600;
	min *= 60;
	sec = hour + min;

	if (ch == 1) {
		ShutdownCommand(sec);
		printf("\'����\'�� �����ϼ����� \'%u\'�� �Ŀ� ����˴ϴ�.\n\n\n", sec);
	}
	else if (ch == 2) {
		RestartCommand(sec);

	}

	Cancel();

	

	return 0;
}