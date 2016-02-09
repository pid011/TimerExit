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
	puts("error : 해당 명령어는 없는 명령어 입니다");
	puts("아무키나 누를 시 종료됩니다.");
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
	puts("  |         컴퓨터 예약종료 프로그램          |");
	puts("   -------------------------------------------");
	puts("   -------------------------------------------");
	puts("  |                                           |");
	puts("  |     <1>종료  <2>다시시작                  |");
	puts("  |                                           |");
	puts("   -------------------------------------------");
	printf("입력 :");
	scanf_s("%d", &ch);
	if (ch != 1 && ch != 2) {
		error();
	}
	system("cls");
	printf("예약종료를 실행합니다...\n\n");

	printf("시간 입력. ex)0시간 30분뒤면 0이라고 입력.\n");
	printf("입력:");
	scanf_s("%d", &hour);

	printf("분 입력. ex)0시간 30분뒤면 30이라고 입력.\n");
	printf("입력:");
	scanf_s("%d", &min);
	puts("\n...\n");
	hour *= 3600;
	min *= 60;
	sec = hour + min;

	if (ch == 1) {
		ShutdownCommand(sec);
		printf("\'종료\'를 예약하셨으며 \'%u\'초 후에 종료됩니다.\n\n\n", sec);
	}
	else if (ch == 2) {
		RestartCommand(sec);

	}

	Cancel();

	

	return 0;
}