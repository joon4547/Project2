#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

typedef struct _status{
	int Str;
	int Int;
	int Dex;
	int Life;
}status;

typedef struct _character{
	status stat;
	char input;
	void(*skill)(char);
}character;

void use_Skill(char key);
void init_character(character* ch, int Str, int Int, int Dex, int Life);
char _getch(void);

int main(void){
	char key;
	//create a character : magician
	character magician;

	//Initiate the character(str 5, int 10, dex 6, life 30)
	init_character(&magician, 5, 10, 6, 30);

	//Display the character status
	printf("Str : %d\nInt : %d\nDex : %d\nLife : %d\n",
		magician.stat.Str,
		magician.stat.Int,
		magician.stat.Dex,
		magician.stat.Life
		);

	//play game
	while (1){
		printf("Use your skill (q,w,e,r) : ");

		//scanf("%c",&key);
		key = _getch();
		magician.skill(key);
	}
	return 0;
}

void use_Skill(char key){
	switch (key){
	case 'q':
		printf("q skill used!\n");
		break;
	case 'w':
		printf("w skill used!\n");
		break;
	case 'e':
		printf("e skill used!\n");
		break;
	case 'r':
		printf("r skill used!\n");
		break;
	default:
		break;
	}
}

void init_character(character* ch, int Str, int Int, int Dex, int Life){
	ch->skill = use_Skill;

	ch->stat.Str = 5;
	ch->stat.Int = 10;
	ch->stat.Dex = 6;
	ch->stat.Life = 30;
}

char _getch(){
	char buf, ch;
	for (; (buf = getchar()) != 10;)
		ch = buf;
	return ch;
}