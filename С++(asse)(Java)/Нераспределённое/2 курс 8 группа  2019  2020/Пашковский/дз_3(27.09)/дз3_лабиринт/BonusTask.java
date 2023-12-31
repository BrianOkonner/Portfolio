package packAge;

import java.util.Scanner;



import java.io.*;
import java.util.Arrays;



public class BonusTask {
	
	public static char rotater(char r)
	{
		if(r=='d')
			return 'l';
		if(r=='u')
			return 'r';
		if(r=='l')
			return 'u';
		if(r=='r')
			return 'd';
		return r;
	}
	public static char rotatel(char r)
	{
		switch(r)
		{
		case 'l':
			return 'd';
		case 'r':
			return 'u';
		case 'd':
			return 'r';
		case 'u':
			return 'l';
		default:
			return r;
		}
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			Scanner io=new Scanner(System.in);
			FileInputStream InputFile=new FileInputStream("maze.txt");
			Scanner sc=new Scanner(InputFile);
			
			System.out.println("������� ��������� ������� (x,y):");
			
			int x;
			int y;
			int Msize[]=new int[2];
			
			Msize[0]=sc.nextInt();
			Msize[1]=sc.nextInt();
			x=io.nextInt();
			y=io.nextInt();

			int maze[][]=new int[Msize[0]][Msize[1]];
			for(int i=0;i<Msize[0];i++)
				for(int j=0;j<Msize[1];j++)
					maze[i][j]=sc.nextInt();
			
			int mov=0;
			char direction='d';//up down right left
			boolean completed=false;
			
			if(maze[y][x]==0)
			{
				System.out.println("wrong starting location!");
				mov=500;
			}
			for(int i=0;i<Msize[0];i++)
				System.out.println(Arrays.toString(maze[i]));
			
			//������ ������ �� �����������
			while(y+1<Msize[0] && maze[y+1][x]==1)
			{
				y++;
				System.out.println("����");
			}
			
			
			while(completed==false && mov<500)
			{
				
				
				if(x==0 || y==0 || x==Msize[1]-1 || y==Msize[0]-1)
					{
						completed=true;
						break;
					}
				
				switch(direction)
				{
				case 'd':
					if(y+1<Msize[0] && maze[y+1][x]==1)
						{
							y++;
							System.out.println("���� ");
						}
					else
						{
						direction=rotatel(direction);
						
						while(x+1<Msize[1] && y>0 && maze[y][x+1]==0 && maze[y-1][x]==1)
							{
								y--;
								System.out.println("�����");
								
							}
						direction=rotatel(direction);
						}
					break;
				case 'u':
					if(y>0 && maze[y-1][x]==1)
						{
							y--;
							System.out.println("����� ");
						}
					else
						{
						direction=rotatel(direction);
						
						while(x>0 && y+1<Msize[0] && maze[y][x-1]==0 && maze[y+1][x]==1)
							{
								y++;
								System.out.println("����");
							}
						direction=rotatel(direction);
						}
					break;
				case 'l':
					if(x>0 && maze[y][x-1]==1)
						{
							x--;
							System.out.println("����� ");
						}
					else
						{
						direction=rotatel(direction);
						
						while(y+1<Msize[0] && x+1<Msize[1] && maze[y+1][x]==0 && maze[y][x+1]==1)
							{
								x++;
								System.out.println("������");
							}
						direction=rotatel(direction);
						}
					break;
				case 'r':
					if(x+1<Msize[1] && maze[y][x+1]==1)
						{
							x++;
							System.out.println("������ ");
						}
					else
						{
						direction=rotatel(direction);
						
						while(y>0 && x>0 && maze[y-1][x]==0 && maze[y][x-1]==1)
							{
								x--;
								System.out.println("�����");
							}
						direction=rotatel(direction);
						}
					break;
				}
				direction=rotater(direction);
				mov++;
			}
			System.out.println("Maze completed:"+completed);
			if(mov>=99)
				System.out.println("Out of moves.");
			io.close();
			sc.close();
		}
		catch(IOException e)
		{
			System.out.println("���� �� ������!");
		}
	}
}
