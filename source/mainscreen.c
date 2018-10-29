#pragma warning(disable:4996)
#pragma comment(lib, "winmm.lib")

#include "mainscreen.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <process.h>
#include <stdlib.h>
#include <mmsystem.h>

#define TITLE_SPACE 55
#define TITLE_ENTER 10

#define decision_change "C:\\Users\\chanho\\source\\repos\\Team-9-Project\\main\\resource\\decision_change.wav"

void start_screen_intro(int time); //시작화면 재생 출력 함수
void start_screen_standby(int time, int keybind); // 시작화면 입력대기 함수
void set_color(int text_color); //화면에 출력되는 글자의 색을 조정하는 함수
void space_num(int space);
void enter_num(int enter);
void title_print(int control_num, int line); //시작화면
void chicken_right_wingup_eyeopened(int space); //오른쪽을 보는 날개를 펴고 눈을 뜬 닭을 출력한다
void chicken_right_wingup_eyeclosed(int space); //오른쪽을 보는 날개를 펴고 눈을 감은 닭을 출력한다
void chicken_right_wingdown_eyeopened(int space); //오른쪽을 보는 날개를 접고 눈을 뜬 닭을 출력한다
void chicken_right_wingdown_eyeclosed(int space); //오른쪽을 보는 날개를 접고 눈을 감은 닭을 출력한다
void chicken_left_wingup_eyeopened(int line); //왼쪽을 보는 날개를 펴고 눈을 뜬 닭을 출력한다
void chicken_left_wingup_eyeclosed(int line); //왼쪽을 보는 날개를 펴고 눈을 감은 닭을 출력한다
void chicken_left_wingdown_eyeopened(int line); //왼쪽을 보는 날개를 접고 눈을 뜬 닭을 출력한다
void chicken_left_wingdown_eyeclosed(int line); //왼쪽을 보는 날개를 접고 눈을 감은 닭을 출력한다

int main()
{
	int time = 0;
	int key = 0;
	int keybind = 1;
	system("mode con cols=1000 lines=1000"); //크기 최대 - 화면에 맞춤
	while (1)
	{
		if (kbhit()) //방향키 입력
		{
			key = getch();
			if (key == 224)
			{
				key = getch();
				switch (key)
				{
				case 72:
					if (2 <= keybind && keybind <= 3)
					{
						keybind--;
						PlaySound(TEXT(decision_change), NULL, SND_ASYNC); // 선택 변경시 효과음 재생
					}
					break;
				case 80:
					if (1 <= keybind && keybind <= 2)
					{
						keybind++;
						PlaySound(TEXT(decision_change), NULL, SND_ASYNC); // 선택 변경시 효과음 재생
					}
					break;
				}
			}
		}
		start_screen_intro(time);
		start_screen_standby(time, keybind);

		Sleep(50);
		system("cls");
		time++;
	}
	return 0;
}
void chicken_right_wingup_eyeopened(int space)
{
	int control_num = 1;
	int line_num = 0;
	int char_num = 0;
	//{ _ \\ }
	//{_\\(o>}
	//{\\/V/)}
	//{ V_ _)}
	//{  _|\_}
	char chicken[5][6] = {	{' ', '_', ' ', '\\', '\\', ' '},
							{'_', '\\', '\\', '(', 'o', '>'}, 
							{'\\', '\\', '/', 'V', '/', ')'},
							{' ', 'V', '_', ' ', '_', ')'},
							{' ', ' ', '_', '|', '\\', '_'} };
	for (line_num = 0; line_num <= 4; line_num++)
	{
		for (control_num = 1; control_num <= space; control_num++)
		{
			space_num(2);
		}
		for (char_num = 0; char_num <= 5; char_num++)
		{
			switch (line_num)
			{
			case 0:
				set_color(12);//닭의 볏 색
				if (char_num <= 2)
				{
					set_color(15);
				}
				break;
			case 4:
				set_color(14);//닭의 다리 색
				break;
			case 5:
				set_color(14);//닭의 다리 색
				break;
			default:
				set_color(15);
			}
			if (line_num == 1 && char_num == 5)//닭의 부리 색
			{
				set_color(14);
			}
			printf("%c", chicken[line_num][char_num]);;
		}
		enter_num(1);
	}
}
void chicken_right_wingup_eyeclosed(int space)
{
	int control_num = 1;
	int line_num = 0;
	int char_num = 0;
	//{ _ \\ }
	//{_\\(->}
	//{\\/V/)}
	//{ V_ _)}
	//{  _|\_}
	char chicken[5][6] = { {' ', '_', ' ', '\\', '\\', ' '},
							{'_', '\\', '\\', '(', '-', '>'},
							{'\\', '\\', '/', 'V', '/', ')'},
							{' ', 'V', '_', ' ', '_', ')'},
							{' ', ' ', '_', '|', '\\', '_'} };
	for (line_num = 0; line_num <= 4; line_num++)
	{
		for (control_num = 1; control_num <= space; control_num++)
		{
			space_num(2);
		}
		for (char_num = 0; char_num <= 5; char_num++)
		{
			switch (line_num)
			{
			case 0:
				set_color(12);//닭의 볏 색
				if (char_num <= 2)
				{
					set_color(15);
				}
				break;
			case 4:
				set_color(14);//닭의 다리 색
				break;
			case 5:
				set_color(14);//닭의 다리 색
				break;
			default:
				set_color(15);
			}
			if (line_num == 1 && char_num == 5)//닭의 부리 색
			{
				set_color(14);
			}
			printf("%c", chicken[line_num][char_num]);
		}
		enter_num(1);
	}
}
void chicken_right_wingdown_eyeopened(int space) 
{
	int control_num = 1;
	int line_num = 0;
	int char_num = 0;
	//{   \\ }
	//{_ _(o>}
	//{\\_//)}
	//{ \_V_)}
	//{  _|_ }
	char chicken[5][6] = {	{' ', ' ', ' ', '\\', '\\', ' '},
							{'_', ' ', '_', '(', 'o', '>'},
							{'\\', '\\', '_', '/', '/', ')'},
							{' ', '\\', '_', '/', '_', ')'},
							{' ', ' ', '_', '|', '_', ' '} };
	for (line_num = 0; line_num <= 4; line_num++)
	{
		for (control_num = 1; control_num <= space; control_num++)
		{
			space_num(2);
		}
		for (char_num = 0; char_num <= 5; char_num++)
		{
			switch (line_num)
			{
			case 0 :
				set_color(12);//닭의 볏 색
				break;
			case 4 : 
				set_color(14);//닭의 다리 색
				break;
			case 5:
				set_color(14);//닭의 다리 색
				break;
			default :
				set_color(15);
			}
			if (line_num == 1 && char_num == 5)//닭의 부리 색
			{
				set_color(14);
			}
			printf("%c", chicken[line_num][char_num]);;
		}
		enter_num(1);
	}
}
void chicken_right_wingdown_eyeclosed(int space)
{
	int control_num = 1;
	int line_num = 0;
	int char_num = 0;
	//{   \\ }
	//{_ _(->}
	//{\\_//)}
	//{ \_V_)}
	//{  _|_ }
	char chicken[5][6] = { {' ', ' ', ' ', '\\', '\\', ' '},
							{'_', ' ', '_', '(', '-', '>'},
							{'\\', '\\', '_', '/', '/', ')'},
							{' ', '\\', '_', '/', '_', ')'},
							{' ', ' ', '_', '|', '_', ' '} };
	for (line_num = 0; line_num <= 4; line_num++)
	{
		for (control_num = 1; control_num <= space; control_num++)
		{
			space_num(2);
		}
		for (char_num = 0; char_num <= 5; char_num++)
		{
			switch (line_num)
			{
			case 0:
				set_color(12);//닭의 볏 색
				break;
			case 4:
				set_color(14);//닭의 다리 색
				break;
			case 5:
				set_color(14);//닭의 다리 색
				break;
			default:
				set_color(15);
			}
			if (line_num == 1 && char_num == 5)//닭의 부리 색
			{
				set_color(14);
			}
			printf("%c", chicken[line_num][char_num]);;
		}
		enter_num(1);
	}
}
void chicken_left_wingup_eyeopened(int space)
{
	int control_num = 1;
	int line_num = 0;
	int char_num = 0;
	//{ // _ }
	//{<o)//_}
	//{(\V\//}
	//{(_ _V }
	//{_/|_  }
	char chicken[5][6] = {	{' ', '/', '/', ' ', '_', ' '},
							{'<', 'o', ')', '/', '/', '_'},
							{'(', '\\', 'V', '\\', '/', '/'},
							{'(', '_', ' ', '_', 'V', ' '},
							{'_', '/', '|', '_', ' ', ' '} };
	for (line_num = 0; line_num <= 4; line_num++)
	{
		for (control_num = 1; control_num <= space; control_num++)
		{
			space_num(2);
		}
		for (char_num = 0; char_num <= 5; char_num++)
		{
			switch (line_num)
			{
			case 0:
				set_color(12);//닭의 볏 색
				if (char_num >= 3)
				{
					set_color(15);
				}
				break;
			case 4:
				set_color(14);//닭의 다리 색
				break;
			case 5:
				set_color(14);//닭의 다리 색
				break;
			default:
				set_color(15);
			}
			if (line_num == 1 && char_num == 0)//닭의 부리 색
			{
				set_color(14);
			}
			printf("%c", chicken[line_num][char_num]);;
		}
		enter_num(1);
	}
}
void chicken_left_wingup_eyeclosed(int space)
{
	int control_num = 1;
	int line_num = 0;
	int char_num = 0;
	//{ // _ }
	//{<-)//_}
	//{(\V\//}
	//{(_ _V }
	//{_/|_  }
	char chicken[5][6] = { {' ', '/', '/', ' ', '_', ' '},
							{'<', '-', ')', '/', '/', '_'},
							{'(', '\\', 'V', '\\', '/', '/'},
							{'(', '_', ' ', '_', 'V', ' '},
							{'_', '/', '|', '_', ' ', ' '} };
	for (line_num = 0; line_num <= 4; line_num++)
	{
		for (control_num = 1; control_num <= space; control_num++)
		{
			space_num(2);
		}
		for (char_num = 0; char_num <= 5; char_num++)
		{
			switch (line_num)
			{
			case 0:
				set_color(12);//닭의 볏 색
				if (char_num >= 3)
				{
					set_color(15);
				}
				break;
			case 4:
				set_color(14);//닭의 다리 색
				break;
			case 5:
				set_color(14);//닭의 다리 색
				break;
			default:
				set_color(15);
			}
			if (line_num == 1 && char_num == 0)//닭의 부리 색
			{
				set_color(14);
			}
			printf("%c", chicken[line_num][char_num]);;
		}
		enter_num(1);
	}
}
void chicken_left_wingdown_eyeopened(int space)
{
	int control_num = 1;
	int line_num = 0;
	int char_num = 0;
	//{ //   }
	//{<o)_ _}
	//{(\/|//}
	//{(_V_/ }
	//{ _|_  }
	char chicken[5][6] = {	{' ', '/', '/', ' ', ' ', ' '},
							{'<', 'o', ')', '_', ' ', '_'}, 
							{'(', '\\', '/', '|', '/', '/'}, 
							{'(', '_', 'V', '_', '/', ' '}, 
							{' ', '_', '|', '_', ' ', ' '} };
	for (line_num = 0; line_num <= 4; line_num++)
	{
		for (control_num = 1; control_num <= space; control_num++)
		{
			space_num(2);
		}
		for (char_num = 0; char_num <= 5; char_num++)
		{
			switch (line_num)
			{
			case 0:
				set_color(12);//닭의 볏 색
				break;
			case 4:
				set_color(14);//닭의 다리 색
				break;
			case 5:
				set_color(14);//닭의 다리 색
				break;
			default:
				set_color(15);
			}
			if (line_num == 1 && char_num == 0)//닭의 부리 색
			{
				set_color(14);
			}
			printf("%c", chicken[line_num][char_num]);;
		}
		enter_num(1);
	}
}
void chicken_left_wingdown_eyeclosed(int space)
{
	int control_num = 1;
	int line_num = 0;
	int char_num = 0;
	//{ //   }
	//{<-)_ _}
	//{(\/|//}
	//{(_V_/ }
	//{ _|_  }
	char chicken[5][6] = {	{' ', '/', '/', ' ', ' ', ' '},
							{'<', '-', ')', '_', ' ', '_'}, 
							{'(', '\\', '/', '|', '/', '/'}, 
							{'(', '_', 'V', '_', '/', ' '}, 
							{' ', '_', '|', '_', ' ', ' '} };
	for (line_num = 0; line_num <= 4; line_num++)
	{
		for (control_num = 1; control_num <= space; control_num++)
		{
			space_num(2);
		}
		for (char_num = 0; char_num <= 5; char_num++)
		{
			switch (line_num)
			{
			case 0:
				set_color(12);//닭의 볏 색
				break;
			case 4:
				set_color(14);//닭의 다리 색
				break;
			case 5:
				set_color(14);//닭의 다리 색
				break;
			default:
				set_color(15);
			}
			if (line_num == 1 && char_num == 0)//닭의 부리 색
			{
				set_color(14);
			}
			printf("%c", chicken[line_num][char_num]);;
		}
		enter_num(1);
	}
}
void title_print(int control_num, int line)
{
	int repeat_num = 0; //반복문 제어 변수
	//{ _____ _                              ____ _     _      _                }
	//{|  __|| | ___  _ ___  _ ___  _   _   / ___| |__ ( ) ___| | ______  _ __  }
	//{| |__ | |/ _ `| ' _ \| ' _ \| | | | | |   | '_ \| |/ __| |/ /  _ \| '_ \ }
	//{|  __|| | (_| | ||_) | ||_) | |_| | | |___| | | | | (__| .  <  __/| | | |}
	//{|_|   | |\__,_| .___/| .___/ \__, |  \____|_| |_|_|\___|_|\_\____||_| |_|}
	//{      |_|     |_|    |_|     |___/                                       }
	char title_line[6][73] = {	{' ', '_', '_', '_', '_', '_', ' ', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '_', '_', ' ', '_', ' ', ' ', ' ', ' ', ' ', '_', ' ', ' ', ' ', ' ', ' ', ' ', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
								{'|', ' ', ' ', '_', '_', '|', '|', ' ', '|', ' ', '_', '_', '_', ' ', ' ', '_', ' ', '_', '_', '_', ' ', ' ', '_', ' ', '_', '_', '_', ' ', ' ', '_', ' ', ' ', ' ', '_', ' ', ' ', ' ', '/', ' ', '_', '_', '_', '|', ' ', '|', '_', '_', ' ', '(', ' ', ')', ' ', '_', '_', '_', '|', ' ', '|', ' ', '_', '_', '_', '_', '_', '_', ' ', ' ', '_', ' ', '_', '_', ' ', ' '},
								{'|', ' ', '|', '_', '_', ' ', '|', ' ', '|', '/', ' ', '_', ' ', '`', '|', ' ', '\'', ' ', '_', ' ', '\\', '|', ' ', '\'', ' ', '_', ' ', '\\', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', '|', ' ', '\'', '_', ' ', '\\', '|', ' ', '|', '/', ' ', '_', '_', '|', ' ', '|', '/', ' ', '/', ' ', ' ', '_', ' ', '\\', '|', ' ', '\'', '_', ' ', '\\', ' '},
								{'|', ' ', ' ', '_', '_', '|', '|', ' ', '|', ' ', '(', '_', '|', ' ', '|', ' ', '|', '|', '_', ')', ' ', '|', ' ', '|', '|', '_', ')', ' ', '|', ' ', '|', '_', '|', ' ', '|', ' ', '|', ' ', '|', '_', '_', '_', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '(', '_', '_', '|', ' ', '.', ' ', ' ', '<', ' ', '_', '_', '_', '/', '|', ' ', '|', ' ', '|', ' ', '|'},
								{'|', '_', '|', ' ', ' ', ' ', '|', ' ', '|', '\\', '_', '_', ',', '_', '|', ' ', '.', '_', '_', '_', '/', '|', ' ', '.', '_', '_', '_', '/', ' ', '\\', '_', '_', ',', ' ', '|', ' ', ' ', '\\', '_', '_', '_', '_', '|', '_', '|', ' ', '|', '_', '|', '_', '|', '\\', '_', '_', '_', '|', '_', '|', '\\', '_', '\\', '_', '_', '_', '_', '|', '|', '_', '|', ' ', '|', '_', '|'},
								{' ', ' ', ' ', ' ', ' ', ' ', '|', '_', '|', ' ', ' ', ' ', ' ', ' ', '|', '_', '|', ' ', ' ', ' ', ' ', '|', '_', '|', ' ', ' ', ' ', ' ', ' ', '|', '_', '_', '_', '/', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '} };
	space_num(TITLE_SPACE);
	for (repeat_num = 0; repeat_num <= control_num; repeat_num++)
	{
		printf("%c", title_line[line][repeat_num]);
	}
	enter_num(1);
}
void title_allprint()
{
	int repeat_line_num = 0; //줄 반복문 제어 변수
	int repeat_char_num = 0; //문자 반복문 제어 변수
	int char_num = 72; //문장 제어 함수
	int line_num = 5;
	//{ _____ _                              ____ _     _      _                }
	//{|  __|| | ___  _ ___  _ ___  _   _   / ___| |__ ( ) ___| | ______  _ __  }
	//{| |__ | |/ _ `| ' _ \| ' _ \| | | | | |   | '_ \| |/ __| |/ /  _ \| '_ \ }
	//{|  __|| | (_| | ||_) | ||_) | |_| | | |___| | | | | (__| .  <  __/| | | |}
	//{|_|   | |\__,_| .___/| .___/ \__, |  \____|_| |_|_|\___|_|\_\____||_| |_|}
	//{      |_|     |_|    |_|     |___/                                       }
	char title_line[6][73] = {	{' ', '_', '_', '_', '_', '_', ' ', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', '_', '_', '_', ' ', '_', ' ', ' ', ' ', ' ', ' ', '_', ' ', ' ', ' ', ' ', ' ', ' ', '_', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
								{'|', ' ', ' ', '_', '_', '|', '|', ' ', '|', ' ', '_', '_', '_', ' ', ' ', '_', ' ', '_', '_', '_', ' ', ' ', '_', ' ', '_', '_', '_', ' ', ' ', '_', ' ', ' ', ' ', '_', ' ', ' ', ' ', '/', ' ', '_', '_', '_', '|', ' ', '|', '_', '_', ' ', '(', ' ', ')', ' ', '_', '_', '_', '|', ' ', '|', ' ', '_', '_', '_', '_', '_', '_', ' ', ' ', '_', ' ', '_', '_', ' ', ' '}, 
								{'|', ' ', '|', '_', '_', ' ', '|', ' ', '|', '/', ' ', '_', ' ', '`', '|', ' ', '\'', ' ', '_', ' ', '\\', '|', ' ', '\'', ' ', '_', ' ', '\\', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', '|', ' ', '\'', '_', ' ', '\\', '|', ' ', '|', '/', ' ', '_', '_', '|', ' ', '|', '/', ' ', '/', ' ', ' ', '_', ' ', '\\', '|', ' ', '\'', '_', ' ', '\\', ' '},
								{'|', ' ', ' ', '_', '_', '|', '|', ' ', '|', ' ', '(', '_', '|', ' ', '|', ' ', '|', '|', '_', ')', ' ', '|', ' ', '|', '|', '_', ')', ' ', '|', ' ', '|', '_', '|', ' ', '|', ' ', '|', ' ', '|', '_', '_', '_', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '(', '_', '_', '|', ' ', '.', ' ', ' ', '<', ' ', '_', '_', '_', '/', '|', ' ', '|', ' ', '|', ' ', '|'},
								{'|', '_', '|', ' ', ' ', ' ', '|', ' ', '|', '\\', '_', '_', ',', '_', '|', ' ', '.', '_', '_', '_', '/', '|', ' ', '.', '_', '_', '_', '/', ' ', '\\', '_', '_', ',', ' ', '|', ' ', ' ', '\\', '_', '_', '_', '_', '|', '_', '|', ' ', '|', '_', '|', '_', '|', '\\', '_', '_', '_', '|', '_', '|', '\\', '_', '\\', '_', '_', '_', '_', '|', '|', '_', '|', ' ', '|', '_', '|'},
								{' ', ' ', ' ', ' ', ' ', ' ', '|', '_', '|', ' ', ' ', ' ', ' ', ' ', '|', '_', '|', ' ', ' ', ' ', ' ', '|', '_', '|', ' ', ' ', ' ', ' ', ' ', '|', '_', '_', '_', '/', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '} };
	space_num(60);
	printf("*시작하기 전에 글꼴을 NSimSun으로 바꾸고 F11을 눌러주세요*"); //화면 제일 위에 출력할 시작하기 전 주의사항
	enter_num(TITLE_ENTER);
	for (repeat_line_num = 0; repeat_line_num <= line_num; repeat_line_num++)
	{
		space_num(TITLE_SPACE);
		for (repeat_char_num = 0; repeat_char_num <= char_num; repeat_char_num++)
		{
			printf("%c", title_line[repeat_line_num][repeat_char_num]);
		}
		enter_num(1);
	}
}
void space_num(int space)
{
	int preset;
	for (preset = 1; preset <= space; preset++)
	{
		printf(" ");
	}
}
void enter_num(int enter)
{
	int preset;
	for (preset = 1; preset <= enter; preset++)
	{
		printf("\n");
	}
}
void set_color(int text_color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text_color);
}
void start_screen_intro(int time) //http://patorjk.com/software/taag/#p=display&h=2&v=2&f=Standard&t=Flappy%20Chicken
{
	int control_num = 0; //전체 문장 제어 변수
	int repeat_num = 0; //반복문 제어 변수
		//메인 타이틀 순차적 출력 시작
	if (time == 0)
	{
		for (control_num = 0; control_num <= 72; control_num++) //메인 타이틀의 전체 글자 수는 73글자이다.
		{
			enter_num(TITLE_ENTER); //맨 위쪽부터 30칸 띄우기

			if (control_num % 2 == 1) // 타이틀 색 변경 - 하늘색
			{
				set_color(11);
			}
			else
			{
				set_color(15);
			}

			for (repeat_num = 0; repeat_num <= 5; repeat_num++) // 타이틀 순차적으로 출력
			{

				title_print(control_num, repeat_num);

			}
			if (control_num == 72)
			{
				Sleep(500);
				system("cls");
				break;
			}
			system("cls");
		}
	}
}	//메인 타이틀 순차적 출력 종료
void start_screen_standby(int time, int keybind)
{
	//메인 타이틀 + 닭 추가
	int repeat_num = time % 182; //반복문 제어 변수
	if (repeat_num % 15 <= 4)
	{
		set_color(15);
	}
	else if(repeat_num % 15 <= 9)
	{
		set_color(11);
	}
	else
	{
		set_color(14);
	}
	printf("%d", time);
	title_allprint();

//키바인딩 시작
	enter_num(11);
	space_num(80);
	if (keybind == 1)
	{
		printf("=> 게 임    시 작");
	}
	else
	{
		printf("   게 임    시 작");
	}
	enter_num(2);
	space_num(79);
	if (keybind == 2)
	{
		printf("=> 만 든   사 람 들");
	}
	else
	{
		printf("   만 든   사 람 들");
	}
	enter_num(2);
	space_num(82);
	if (keybind == 3)
	{
		printf("=> 종 료 하 기");
	}
	else
	{
		printf("   종 료 하 기");
	}
//키바인딩 끝
	if (repeat_num <= 90)
	{
		
		
		if (repeat_num % 22 == 12 || repeat_num % 22 == 13 || repeat_num % 22 == 14 || repeat_num % 22 == 20 || repeat_num % 22 == 21 || repeat_num % 22 == 0)
		{
			enter_num(15);
		}
		else if (repeat_num % 22 == 15 || repeat_num % 22 == 16 || repeat_num % 22 == 18 || repeat_num % 22 == 19)
		{
			enter_num(13);
		}
		else if (repeat_num % 22 == 17)
		{
			enter_num(11);
		}
		else
		{
			enter_num(17);
		}
		if (repeat_num % 2 == 0 && repeat_num % 15 <= 10) //시간이 짝수, 전체 시간의 2/3동안에 날개를 펴고 눈을 뜬 닭을 출력
		{
			chicken_right_wingup_eyeopened(repeat_num);
		}
		else if (repeat_num % 2 == 1 && repeat_num % 15 <= 10) //시간이 홀수, 전체 시간의 2/3동안에 날개를 접고 눈을 뜬 닭을 출력
		{
			chicken_right_wingdown_eyeopened(repeat_num);
		}
		else if (repeat_num % 2 == 0) //시간이 짝수, 전체 시간의 1/3동안에 날개를 펴고 눈을 감은 닭을 출력
		{
			chicken_right_wingup_eyeclosed(repeat_num);
		}
		else //시간이 홀수, 전체 시간의 1/3동안에 (나머지 시간) 날개를 펴고 눈을 감은 닭을 출력
		{
			chicken_right_wingdown_eyeclosed(repeat_num);
		}
		
	}

		//닭 방향전환

	if (repeat_num > 90)
	{
		repeat_num = 181 - repeat_num;

		if (repeat_num % 22 == 12 || repeat_num % 22 == 13 || repeat_num % 22 == 14 || repeat_num % 22 == 20 || repeat_num % 22 == 21 || repeat_num % 22 == 0)
		{
			enter_num(15);
		}
		else if (repeat_num % 22 == 15 || repeat_num % 22 == 16 || repeat_num % 22 == 18 || repeat_num % 22 == 19)
		{
			enter_num(13);
		}
		else if (repeat_num % 22 == 17)
		{
			enter_num(11);
		}
		else
		{
			enter_num(17);
		}
		if (repeat_num % 2 == 0 && (repeat_num % 15 <= 4 || repeat_num % 15 >= 9)) //시간이 짝수, 전체 시간의 2/3동안에 날개를 펴고 눈을 뜬 닭을 출력
		{
			chicken_left_wingup_eyeopened(repeat_num);
		}
		else if (repeat_num % 2 == 1 && (repeat_num % 15 <= 4 || repeat_num % 15 >= 9)) //시간이 홀수, 전체 시간의 2/3동안에 날개를 접고 눈을 뜬 닭을 출력
		{
			chicken_left_wingdown_eyeopened(repeat_num);
		}
		else if (repeat_num % 2 == 0) //시간이 짝수, 전체 시간의 1/3동안에 날개를 펴고 눈을 감은 닭을 출력
		{
			chicken_left_wingup_eyeclosed(repeat_num);
		}
		else //시간이 홀수, 전체 시간의 1/3동안에 (나머지 시간) 날개를 펴고 눈을 감은 닭을 출력
		{
			chicken_left_wingdown_eyeclosed(repeat_num);
		}
		
	}
}