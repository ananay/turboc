/* FLAPPY BIRD BY SHREYAS KISHORE */

// NOTE: Please try restarting TurboC++ if
//       the game does not respond to a keypress.

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<constrea.h>
#include<stdio.h>
#include<time.h>

double timems(){
	float tc = CLK_TCK;
	long cl = clock();
	double re = (cl/tc)*1000;
	return re;
}

double timemssince(double checkpoint){
	float tcd = CLK_TCK;
	long cld = clock();
	double red = (cld/tcd)*1000;
	double re = (red - checkpoint);
	return re;
}

void box(int xpos = 0, int ypos = 0, int xsize = 77, int ysize = 24, int speed = 50, int style = 0){
  char sym[6][8] = {
  {'Щ', 'Э', 'Л', 'К', 'М', 'Э', 'Ш', 'К'},
  {'к', 'Ф', 'П', 'Г', 'й', 'Ф', 'Р', 'Г'},
  {'е', 'Э', 'И', 'Г', 'О', 'Э', 'д', 'Г'},
  {'ж', 'Ф', 'З', 'К', 'Н', 'Ф', 'г', 'К'},
  {'л', 'п', 'л', 'о', 'л', 'м', 'л', 'н'},
  {'В', 'Б', 'В', 'Б', 'В', 'Б', 'В', 'Б'}
  };
  style%=6;
  xsize+=2;
  ysize+=2;

  int xdel = 100/speed;
  int ydel = 200/speed;

  gotoxy(xpos+1, ypos+1);
  cout<<sym[style][0];
  for(int i=(xpos+2);i<(xpos + xsize );i++){
    gotoxy(i, ypos + 1);
    cout<<sym[style][1];
    delay(xdel);
  }
  gotoxy((xpos + xsize ), (ypos +1));
  cout<<sym[style][2];

  for(int j=(ypos + 2); j<(ysize + ypos - 1);j++){
    gotoxy((xpos + xsize),j);
    cout<<sym[style][3];
    delay(ydel);
  }
  gotoxy((xpos + xsize  ), (ypos + ysize - 1 ));
  cout<<sym[style][4];

  for(i=(xpos + xsize - 1);i>(xpos + 1);i--){
    gotoxy(i,(ypos + ysize -1));
    cout<<sym[style][5];
    delay(xdel);
  }
  gotoxy(xpos+1 , ypos + ysize -1);
  cout<<sym[style][6];

  for(j=(ypos + ysize -2);j>(ypos + 1);j--){
    gotoxy(xpos + 1,j);
    cout<<sym[style][7];
    delay(ydel);
  }
}

void line(int xi = 0, int yi = 0, int xf= 79, int yf= 0, int speed = 75, int style = 0){
	int xdel = 100/speed;
    int ydel = 200/speed;
    style%=4;

    char sym[4][2] = {
	{'Э', 'К'},
	{'Ф', 'Г'},
	{'м', 'н'},
	{'Б', 'Б'}
    };

    if(xi == xf){
	for(int i = yi; i<=yf; i++){
		gotoxy(xi, i);
		cout<<sym[style][1];
		delay(ydel);
	}
    }

    else{
	for(int i = xi; i<=xf; i++){
		gotoxy(i, yi);
		cout<<sym[style][0];
		delay(xdel);
	}
    }

}

void linewphase(int xi = 0, int yi = 0, int xf= 79, int yf= 0, int speed = 75, int phase = 0){
    //constream cout;
    int xdel = 100/speed;
    int ydel = 200/speed;
    phase%=3;

    char sym[3] = {'л', 'В', 'Б'};
    //cout<<setclr(YELLOW);
    if(xi == xf){
	for(int i = yi; i<=yf; i++){
		gotoxy(xi, i);
		cout<<sym[phase];
		phase++;
		phase%=3;
		delay(ydel);
	}
    }

    else{
	for(int i = xi; i<=xf; i++){
		gotoxy(i, yi);
		cout<<sym[phase];
		phase++;
		phase%=3;
		delay(xdel);
	}
    }

}

int getchn(){
	return kbhit()? getch() : 0;
}

char banner1[8][60] = {
{"  ______ _                            ____  _         _ \0"},
{" |  ____| |                          |  _ \\(_)       | |\0"},
{" | |__  | | __ _ _ __  _ __  _   _   | |_) |_ _ __ __| |\0"},
{" |  __| | |/ _` | '_ \\| '_ \\| | | |  |  _ <| | '__/ _` |\0"},
{" | |    | | (_| | |_) | |_) | |_| |  | |_) | | | | (_| |\0"},
{" |_|    |_|\\__,_| .__/| .__/ \\__, |  |____/|_|_|  \\__,_|\0"},
{"                | |   | |     __/ |                     \0"},
{"                |_|   |_|    |___/                      \0"}
};

char banner2[9][73] = {
{"   млллллллл  мл          млллллллл    млллллллм    млллллллм млл   м  \0"},
{"  ллл    ллл ллл         ллл    ллл   ллл    ллл   ллл    ллл ллл   ллм\0"},
{"  ллл    лп  ллл         ллл    ллл   ллл    ллл   ллл    ллл лллмммллл\0"},
{" млллммм     ллл         ллл    ллл   ллл    ллл   ллл    ллл ппппппллл\0"},
{"пплллппп     ллл       пллллллллллл плллллллллп  плллллллллп  млл   ллл\0"},
{"  ллл        ллл         ллл    ллл   ллл          ллл        ллл   ллл\0"},
{"  ллл        ллл     м   ллл    ллл   ллл          ллл        ллл   ллл\0"},
{"  ллл        лллллммлл   ллл    лп   мллллп       мллллп       плллллп \0"},
{"             п                                                         \0"}
};

char banner3[9][42] = {
{"плллллллллм   мл     млллллллл ллллллллм \0"},
{"  ллл    ллл ллл    ллл    ллл ллл   пллл\0"},
{"  ллл    ллл лллн   ллл    ллл ллл    ллл\0"},
{" млллмммллп  лллн  млллммммллп ллл    ллл\0"},
{"пплллпппллм  лллн пплллппппп   ллл    ллл\0"},
{"  ллл    ллм ллл  пллллллллллл ллл    ллл\0"},
{"  ллл    ллл ллл    ллл    ллл ллл   мллл\0"},
{"млллллллллп  лп     ллл    ллл ллллллллп \0"},
{"                    ллл    ллл           \0"}
};

char sym[11] = {'к', 'Ф', 'П', 'Г', 'й', 'Р', 'К', 'г', 'ж', 'Н', 'З'};
char screen[22][90];
int data[22][90];
int score = 0, selection = 0;

void makecyl(){
	int pos = (random(7) + 5), start = 79;

	for(int u=0; u<=(pos-2); u++){
		screen[u][start+1] = sym[3];
	}
	screen[pos-1][start+1] = sym[4];
	screen[pos-1][start] = sym[0];
	screen[pos][start] = sym[5];

	for(int v=1; v<=8; v++){
		screen[pos][start + v] = sym[1];
	}

	screen[pos][start+9] = sym[9];
	screen[pos-1][start+9] = sym[10];
	screen[pos-1][start+8] = sym[7];

	for(int w = (pos-2); w>=0; w--){
		screen[w][start+8] = sym[6];
	}
	int width = 8;
	for(int b = 22; b>= pos+width; b--){
		screen[b][start+1] = sym[3];
	}

	screen[pos+width-1][start+1] = sym[2];
	screen[pos+width-1][start] = sym[5];
	screen[pos+width-2][start] = sym[0];

	for(int c = 1; c <=8; c++){
		screen[pos+width-2][start+c] = sym[1];
	}

	screen[pos+width-2][start+9] = sym[10];
	screen[pos+width-1][start+9] = sym[9];
	screen[pos+width-1][start+8] = sym[8];


	for(int d = (pos + width); d<=22; d++){
		screen[d][start+8] = sym[6];
	}
	//score++;
}


void display(){
	_setcursortype(_NOCURSOR);
	constream cout;
	for(int j=2; j<=23; j++){
		for(int k=2; k<=78; k++){
			gotoxy(k,j);
			if(selection == 1)cout<<setclr(random(15)+1);
			cout<<screen[j-2][k-2];
			cout<<setclr(WHITE);
			//cprintf();

		}
	}
	gotoxy(67,25);
	cout<<"[Score:"<<score<<"]";
}

void data_assign(){
	for(int j=2; j<=21; j++){
		for(int k=1; k<=89; k++){
			if((int)screen[j-2][k-3] != 0){
				data[j][k] = 1;
			}
		else{
				data[j][k] = 0;
			}
		}
	}
}

void shift(){
	//char TEMP[22][90];
	for(int j=0; j<=21; j++){
		for(int k=0; k<=88; k++){
			screen[j][k] = screen[j][k+1];
			data[j][k] = data[j][k+1];
			//delay(1);
		}
	}
}


void main(){
	_setcursortype(_NOCURSOR);
	randomize();

	clrscr();

	for(int o = 0; o<9; o++){
		gotoxy(3, 3+o);
		//puts(banner2[o]);
		cprintf("%s",banner2[o]);
		delay(50);
	}
	for(int p = 0; p<9; p++){
		gotoxy(20, 15+p);
		cprintf("%s",banner3[p]);
//		puts(banner3[p]);
		delay(50);
	}
	gotoxy(55, 25);
	cout<<"by Shreyas Kishore, XI-F";
	getch();
	clrscr();

	char ch;
	int  selprev;

	box(0,0,77,24,50);
	gotoxy(35,1);
	char name[] = "ЕFlappy BirdЦ";
	int n = 0;

	for(int l = 0; l<=7; l++){
		gotoxy(12,16 +l);
//		cprintf("%s",banner1[p]);
		puts(banner1[l]);
	}
	gotoxy(35,1);
	while(name[n] != '\0'){
		cout<<name[n];
		n++;
		delay(25);
	}
		box(30, 4, 17, 10, 30);
	gotoxy(35, 7);
	cout<<"Choose Mode:";
		gotoxy(35,10);
		cout<<"Normal Mode";
		gotoxy(35,13);
		cout<<"Disco Mode";

	while((int)ch != 13){

		if((int)ch == 72){selprev = selection; selection = 0;}
		if((int)ch == 80){selprev = selection; selection = 1;}
		if(selprev != selection){
			for(int i = 32; i<=48; i++){
				for( int j = 7; j<= 14; j++){
					gotoxy(i,j);
					cout<<" ";
				}
			}
		}
		if(selection == 0) box(32,8,13,2);
		if(selection == 1) box(32,11,13, 2);
		box(0,0,77,24,1000);
	gotoxy(35,1);
	cout<<"ЕFlappy BirdЦ";
		box(30, 4, 17, 10, 300);
	gotoxy(35, 7);
	cout<<"Choose Mode:";
		gotoxy(35,10);
		cout<<"Normal Mode";
		gotoxy(35,13);
		cout<<"Disco Mode";
		ch = getch();
	}


	//SetConsoleCursorInfo(_NOCURSOR);
	int x = 25, y = 2, xprev, yprev, con = 0, scorecalc = 0, phase= 0;
	float del = 200;
	makecyl();
	box();
	gotoxy(35,1);
	//name = "Flappy Bird";
	n = 0;
	while(name[n] != '\0'){
		cout<<name[n];
		n++;
		delay(25);
	}
	line(2, 24, 78, 24, 60, 3);
	long event_fall = timems(), press, event_makecyl = timems(), event_display = timems(), event_shift = timems();
    while(y<=24 && data[yprev][xprev]==0){
	gotoxy(x,y);
	//cout<<setclr(9);
	cout<<"";
	gotoxy(xprev, yprev);
	cout<<" ";

	   if(timemssince(event_display)>50){
		display();
		event_display = timems();
		linewphase(2, 24, 78, 24, 1000, phase);
	   }
	   if(timemssince(event_shift)>50){
		shift();
		scorecalc++;
		event_shift = timems();
		data_assign();
		phase++;
		score= (scorecalc-35)/30;
		if(score<0)score = 0;
	   }
	   if(timemssince(event_makecyl)>1500){
		makecyl();
		event_makecyl = timems();
	   }
	   if(timemssince(event_fall)>del){
		del-=30;
		xprev = x;
		yprev = y;
		y++;
		if(del<40) del = 40;
		event_fall = timems();
	   }
	   if(getchn()){
		if(con == 0){
		xprev = x;
		yprev = y;
		//if(y<2) y = 2;
		del = 200;
		con = 1;
		press = timems();
	   } }
	   if(con==1 && timemssince(press)>0 && timemssince(press)<=30){yprev=y; y--; con++;}
	   else if(con==2 && timemssince(press)>30 && timemssince(press)<=80){yprev=y;y--; con++;}
	   else if(con==3 && timemssince(press)>80 && timemssince(press)<=150){yprev=y;y--; con++;}
	   else if(con==4 && timemssince(press)>150 && timemssince(press)<=240){yprev=y;y--; con++;}
	   else if(con==5 && timemssince(press)>240 && timemssince(press)<=350){yprev=y;y--; con=0;}
	   if(y<2)y=2;
	}

	for(int xx=34; xx<=46; xx++){
		for(int yy = 11; yy<=15; yy++){
			gotoxy(xx,yy);
			cout<<" ";
		}
	}
	box(32, 9, 13, 6, 5, 4);
	gotoxy(36,12);
	cout<<"GAME OVER!";
	gotoxy(36,14);
	cout<<"Score: "<<score;
	getch();
}