#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

int getTime() {
	int hour, min, sec;

	printf("시간 입력. ex)\'0\' 시간 \'30\' 분뒤면 \'0\' 이라고 입력.\n");
	printf("입력:");
	scanf_s("%d", &hour);

	printf("분 입력. ex)\'0\' 시간 \'30\' 분뒤면 \'30\' 이라고 입력.\n");
	printf("입력:");
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
		puts("error : 해당 명령어는 없는 명령어 입니다.");
		puts("아무 키나 누를 시 종료됩니다.");
		_getch();
		exit(0);
	}
	if (choice == 1)
	{
		sec = getTime();
		sprintf_s(cmd, sizeof(cmd), "shutdown /s /t %d", sec);
		system(cmd);
		printf("\'종료\'를 예약하셨습니다.\n");
	}
	else if (choice == 2)
	{
		sec = getTime();
		sprintf_s(cmd, sizeof(cmd), "shutdown /r /t %d", sec);
		system(cmd);
		printf("\'다시시작\'을 예약하셨습니다.\n");
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
	puts("  |         컴퓨터 예약종료 프로그램          |");
	puts("   -------------------------------------------");
	puts("   -------------------------------------------");
	puts("  |                                           |");
	puts("  |     <1>종료  <2>다시시작                  |");
	puts("  |                                           |");
	puts("   -------------------------------------------");
	printf("입력 :");
	scanf_s("%d", &choices);
	sec = setCommand(choices);
	printf("%d분 후에 종료됩니다.\n", sec / 60);
	//------------------------------------------------------
	puts("취소 하시겠습니까?");
	puts("press    YES = 1     NO = Any Number Key");
	scanf_s("%d", &choices);
	if (choices == 1) {
		system("shutdown /a");
		puts("취소 되었습니다. 아무 키나 누를 시 프로그램이 종료됩니다.");
	}
	else {
		puts("아무키나 누를 시 프로그램이 종료됩니다.");
	}

	_getch();
	return 0;
}