//Выполнил Говоров Артем 8 группа
#include "carta.h"
const int TIME_SHOW=500;
const int MY=91;
const int ALL=36;
static int cxclient=0,cyclient=0;
time_t startgame,nowgame;
double different=0;
carta c[6][6];
int gen[6][6];
bool ex[6][6];
bool picnum[12];
void knowgeneration(int numoftypecart)
{
	srand(time(0));
	for(int i=0;i<12;i++)
		picnum[i]=false;
	int t=0;
	while(t<numoftypecart)
	{
		int q=rand()%12;
		if(picnum[q]!=true)   
		{
			picnum[q]=true;
			t++;
		}
	}
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
			ex[i][j]=false;
	}
	for(int i=0;i<12;i++)
	{
		if(picnum[i]==false)  continue;
		int l=0;
		while(l<36/numoftypecart)
		{
			int x_gen=rand()%6;
			int y_gen=rand()%6;
			if(!ex[x_gen][y_gen])  
			{
				ex[x_gen][y_gen]=true;
				l++;
				gen[x_gen][y_gen]=i;
			}
		}
	}		
}
para p1,p2;
int ID_BUTTON1=1,ID_BUTTON2=2;
int point=0,vibr=0,otgadano;
bool zapret=false,firstraz=false;
int gamebegin=0;
char str_point[]="Очки :                ",str_time[]="Время :              ",str_otgadano[]="Отгадано :        ",str_aftor[40]="@Govorov Artem.2010.All rights reserved",str_t[20],str_p[20];
char str_gamegood[]="Поздравляем! Вы прошли игру! Очки : ",str_gamebad[]="К сожалению вам не удалось пройти игру.Попробуйте еще раз.",str_gb[80],str_gg[80];
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevinstance, 
				   LPSTR lpCmdLine,int nCmdShow)
{
	HWND hMainWnd;
	char szClassName[] = "Myclass";
	MSG msg;
	WNDCLASSEX wc;

	wc.cbSize		= sizeof(wc);
	wc.style		= CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc  = WndProc;
	wc.cbClsExtra   = 0;
	wc.cbWndExtra	= 0;
	wc.hInstance	= hInstance;
	wc.hIcon		= LoadIcon(NULL,IDI_APPLICATION);
	wc.hCursor		= LoadCursor(NULL,IDC_ARROW);
	wc.hbrBackground= (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName	= 0;
	wc.lpszClassName= szClassName;
	wc.hIconSm		= LoadIcon(NULL, IDI_APPLICATION);

	
	if(!RegisterClassEx(&wc))
	{
		MessageBox(NULL,"Cannot register class","Error",MB_OK);
		return 0;
	}

	hMainWnd = CreateWindow(
		szClassName,"Веселые картинки",WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,0,CW_USEDEFAULT,0,
		(HWND)NULL,(HMENU)NULL,
		(HINSTANCE)hInstance,NULL
		);
	if(!hMainWnd){
		MessageBox(NULL," Cannot create main in window","Error",MB_OK);
		return 0;
	}
//-----------------------------------------------------------------------------------------//

	knowgeneration(3);
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			c[i][j].prisv(20+100*i,20+100*j,110+100*i,110+100*j,gen[i][j],false,false);

		}
	}
//-----------------------------------------------------------------------------------------//
	ShowWindow(hMainWnd,nCmdShow);
	UpdateWindow(hMainWnd);

	while(GetMessage(&msg,NULL,0,0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	int userReply=0;
	static HWND hbutton1,hbutton2,hbutton3;
	switch(uMsg)
	{
//--------------------------------------------------------------------------------------//
	case WM_CREATE:
		hdc=GetDC(hWnd);
		GetClientRect(hWnd, &rect);
		SetClassLong(hWnd, GCL_HBRBACKGROUND,(LONG) CreateSolidBrush(RGB(220,220,220)));
		hbutton1=CreateWindow("button","Новая игра",WS_VISIBLE|WS_CHILD,max(LOWORD(lParam)-135,675),70,130,25,hWnd,(HMENU)ID_BUTTON1,NULL,NULL);
		hbutton2=CreateWindow("button","Выход",WS_VISIBLE|WS_CHILD,max(LOWORD(lParam)-135,675),110,130,25,hWnd,(HMENU)ID_BUTTON2,NULL,NULL);	
		ReleaseDC(hWnd,hdc);
		break;
//-------------------------------------------------------------------------------------//
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd,&rect);
		DrawBoard(hdc);
		DrawRectangleMenu(hdc,rect);
		for(int i=0;i<6;i++)
		{
			for(int j=0;j<6;j++)
			{
				c[i][j].Draw(hdc);
			}
		}
		TextOut(hdc,max(rect.right-280,675),rect.bottom-20,str_aftor,strlen(str_aftor));
		TextOut(hdc,max(rect.right-130,680),rect.top+200,str_point,strlen(str_point));
		TextOut(hdc,max(rect.right-130,680),rect.top+240,str_time,strlen(str_time));
		TextOut(hdc,max(rect.right-130,680),rect.top+280,str_otgadano,strlen(str_otgadano));
		EndPaint(hWnd, &ps);
		break;
	}

//------------------------------------------------------------------------------------//
	case WM_RBUTTONDOWN:
	case WM_LBUTTONDOWN:
	{
		hdc=GetDC(hWnd);
		GetClientRect(hWnd,&rect);
		int x,y;
		x=LOWORD(lParam)-20;
		y=HIWORD(lParam)-20;
		para p=provbuttom(x,y);
		if(p.good()&&!zapret)
		{	

			if(!c[p.x][p.y].getexist())		break;
			p.color=c[p.x][p.y].getcolor();
		//
			if(vibr<=1)
			{
				p1=p2;
				p2=p;
				vibr++;
				c[p2.x][p2.y].changeside();
				c[p2.x][p2.y].Draw(hdc);
			}
			if(vibr==2)
			{
				
				if((p1!=p2)&& p1.color==p2.color&&p1.color>=0&&p2.color>=0)
				{
					point+=10;
					c[p2.x][p2.y].sideopen();
					c[p2.x][p2.y].Draw(hdc);
					Sleep(TIME_SHOW/2);
					c[p1.x][p1.y].changeexist();
					c[p2.x][p2.y].changeexist();
					c[p1.x][p1.y].Draw(hdc);
					c[p2.x][p2.y].Draw(hdc);
					vibr=0;
					otgadano+=2;
				}
				else 
				{
					if(p1!=p2)   point -= 3;
					Sleep (TIME_SHOW/2);
					c[p1.x][p1.y].changeside();
					c[p2.x][p2.y].changeside();
					c[p1.x][p1.y].Draw(hdc);
					c[p2.x][p2.y].Draw(hdc);
					vibr=0;
					/*char l[20];
					sprintf(l,"%d",point);
					TextOut(hdc,max(rect.right-130,700),rect.top+200,l,strlen(l));*/
				}
			}
		char l[20];
		if(point<10)  sprintf(l,"%d   ",point);
		if(point>=10&&point<100)  sprintf(l,"%d  ",point);
		if(point>=100)   sprintf(l,"%d ",point);
		TextOut(hdc,max(rect.right-55,775),rect.top+200,l,strlen(l));
		char t[20];
		sprintf(t," %d  ",otgadano);
		TextOut(hdc,max(rect.right-55,775),rect.top+280,t,strlen(t));
	//
	/*	char e[20];
		sprintf(e,"%d",vibr);
		TextOut(hdc,max(rect.right-55,775),rect.top+390,e,strlen(e));
		char v[20];
		sprintf(v,"  %d  %d  ",p1.color,p2.color);
		TextOut(hdc,max(rect.right-55,775),rect.top+410,v,strlen(v));
	//*/
		if(otgadano>=ALL)
		{
			point+=(int)different*2;
			strcpy(str_gg,str_gamegood);		 
			char l[20];
			if(point<10)  sprintf(l,"%d   ",point);
			if(point>=10&&point<100)  sprintf(l,"%d  ",point);
			if(point>=100)   sprintf(l,"%d ",point);
			TextOut(hdc,max(rect.right-55,775),rect.top+200,l,strlen(l));
			KillTimer(hWnd,2);
			char p[20];
			sprintf(p,"%d  ",point);
			strcat(str_gg,p);
			zapret=true;
			userReply=MessageBox(hWnd,str_gg,"Веселые картинки",MB_OK);
			if(userReply==IDOK)
			{
				/*for(int i=0;i<6;i++)
				{
					for(int j=0;j<6;j++)
					{
						c[i][j].noexist();
						c[i][j].sideclose();
						c[i][j].Draw(hdc);
					}
				}*/
			}		
		}
		    ReleaseDC(hWnd,hdc);
		}
	}
	//
		
	break;
//--------------------------------------------------------------------------------------------//
	case WM_COMMAND:
	{
		hdc=GetDC(hWnd);
		//DrawRam(hdc,rect);
		if(wParam==ID_BUTTON1)
		{
			if(!firstraz)     
			{
				firstraz=true;
			}
			else  
			{
				time(&nowgame);
				double different1=difftime(nowgame,startgame);
				if(different1<60) 
				{
					userReply=MessageBox(hWnd,"Вы действительно хотите закончить текущую\n и начать новую игру?","Веселые картинки",MB_YESNO|MB_ICONQUESTION);
					if(IDNO==userReply)    goto r1;  
				}
			}
			srand(time(0));
			point=0;
			vibr=0;
			otgadano=0;
			p1.color=-1;
			p2.color=-1;
			SetTimer(hWnd,1,1000,0);
			time(&startgame);
			SetTimer(hWnd,2,1000,0);
			zapret=true;	
			knowgeneration(9);
			for(int i=0;i<6;i++)
			{
				for(int j=0;j<6;j++)
				{
					c[i][j].exists();
					c[i][j].changecolor(gen[i][j]);
					c[i][j].sideopen();
					c[i][j].Draw(hdc);
				}
			}
		}
		if(wParam==ID_BUTTON2)
		{
			userReply=MessageBox(hWnd,"Неужели вам действительно захотелось выйти?              ","Веселые картинки",MB_YESNO |MB_ICONQUESTION);
			if(IDYES==userReply)
			{
				DestroyWindow(hWnd);
				//ReleaseDC(hWnd,hdc);
			}
		}
r1:;
		ReleaseDC(hWnd,hdc);
		
	}
	break;
//--------------------------------------------------------------------------------------//
	case WM_TIMER:
		hdc=GetDC(hWnd);
		GetClientRect(hWnd,&rect);
		if(wParam==1)
		{	
			zapret=false;
			for(int i=0;i<6;i++)
			{
				for(int j=0;j<6;j++)
				{
					c[i][j].exists();
					c[i][j].sideclose();
					c[i][j].Draw(hdc);
				}
			}
			KillTimer(hWnd,1);
			hdc=GetDC(hWnd);
			GetClientRect(hWnd,&rect);
			char l[20];
			if(point<10)  sprintf(l,"%d   ",point);
			if(point>=10&&point<100)  sprintf(l,"%d  ",point);
			if(point>=100)   sprintf(l,"%d ",point);
			TextOut(hdc,max(rect.right-55,775),rect.top+200,l,strlen(l));
			char t[20];
			sprintf(t," %d  ",otgadano);
			TextOut(hdc,max(rect.right-55,775),rect.top+280,t,strlen(t));
		}
		if(wParam==2)
		{
			char l[20];
			if(point<10)  sprintf(l,"%d   ",point);
			if(point>=10&&point<100)  sprintf(l,"%d  ",point);
			if(point>=100)   sprintf(l,"%d ",point);
			TextOut(hdc,max(rect.right-55,775),rect.top+200,l,strlen(l));
			char t[20];
			sprintf(t," %d  ",otgadano);
			TextOut(hdc,max(rect.right-55,775),rect.top+280,t,strlen(t));

			time(&nowgame);
			different=difftime(nowgame,startgame);
			int x=(MY-different)/60;
			int a=(int)(MY-different)%60;
			char q[20];
			if(a>=10)  sprintf(q,"%d : %d",x,a);
			else  sprintf(q,"%d : 0%d",x,a);
			TextOut(hdc,max(rect.right-65,775),rect.top+240,q,strlen(q));
			
			if(different>=91)
			{
				KillTimer(hWnd,2);
				zapret=true;
				userReply=MessageBox(hWnd,str_gamebad,"Веселые картинки",MB_OK);
				if(userReply==IDOK)
				{
					/*for(int i=0;i<6;i++)
					{
						for(int j=0;j<6;j++)
						{
							c[i][j].noexist();
							c[i][j].sideclose();
							c[i][j].Draw(hdc);
						}
					}*/
				}
			}	
		}
		ReleaseDC(hWnd,hdc);
		break;
//-----------------------------------------------------------------------------//
	case WM_SIZE:
		{
			cxclient=LOWORD(lParam);
			cyclient=HIWORD(lParam);
			MoveWindow(hbutton1,max(LOWORD(lParam)-135,675),70,130,25,TRUE);
			MoveWindow(hbutton2,max(LOWORD(lParam)-135,675),110,130,25,TRUE);
		}
		break;
//-------------------------------------------------------------------------------//
	case WM_CLOSE:
		userReply=MessageBox(hWnd,"Неужели вам действительно захотелось выйти?              ","Веселые картинки",MB_YESNO |MB_ICONQUESTION);
		if(IDYES==userReply)
		{
			DestroyWindow(hWnd);	
		}
		break;
//-------------------------------------------------------------------------------//
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
//------------------------------------------------------------------------------//
	default:
		return DefWindowProc(hWnd,uMsg,wParam,lParam);
	}
	return 0;
}

