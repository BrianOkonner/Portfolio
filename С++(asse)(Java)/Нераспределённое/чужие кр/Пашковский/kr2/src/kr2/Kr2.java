package kr2;
  
import java.util.Arrays;
import java.util.Comparator;
class wrongParams extends Exception{}
class comp implements Comparator<matrix>
{
	@Override
	public int compare(matrix m1,matrix m2)
	{
		if(m1.kolvo()==m2.kolvo())
			return 0;
		if(m1.kolvo()>m2.kolvo())
			return -1;
		return 1;
	}
}

abstract class matrix 
{
	protected int m;
	protected int n;
	private double[][] p;
	matrix()
	{
		
	}
	matrix(int rows, int columns)
	{
		m=rows;
		n=columns;
		p=new double[m][n];
	}
	matrix(int rows, int columns, double init[][])
	{
		m=rows;
		n=columns;
		p=new double[m][n];
	}
	public abstract int kolvo();
}

class matrixBool extends matrix
{
	private int[][]p;
	public matrixBool(int rows, int columns,int [][]mas) throws wrongParams
	{
		super(rows,columns);
		p=new int[rows][columns];
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				{
					if(mas[i][j]==1 || mas[i][j]==0)
						p[i][j]=mas[i][j];
					else
						throw new wrongParams();
				}
	}
	public matrixBool(int rows, int columns,int init) throws wrongParams
	{
		super(rows,columns);
		p=new int[m][n];
		if(init==0 || init==1)
			for(int i=0;i<m;i++)
				for(int j=0;j<n;j++)
						p[i][j]=init;
		else
			throw new wrongParams();
	}
	public matrixBool sum(matrixBool m) throws wrongParams
	{
		
		if (this.m != m.m && this.n!=m.n) 
			{
				throw new wrongParams();
			}
		else
		{
			matrixBool res=new matrixBool(this.m,m.n,0);
			for (int i = 0; i < m.m; i++)
				for (int j = 0; j < this.n; j++)
				{
					if(p[i][j]==0 && m.p[i][j]==0)
						res.p[i][j]=0;
					else
						res.p[i][j]=1;
				}
			return res;
		}
	}
	public matrixBool mul(matrixBool m) throws wrongParams
	{
		
		if (this.m != m.m && this.n!=m.n)
			{
				throw new wrongParams();
			}
		else
		{
			matrixBool res=new matrixBool(this.m,m.n,0);
			for (int i = 0; i < m.m; i++)
				for (int j = 0; j < this.n; j++)
				{
					res.p[i][j]=p[i][j]*m.p[i][j];
				}
			return res;
		}
	}
	public matrixBool invers() throws wrongParams
	{
		matrixBool t=new matrixBool(m,n,p);
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				t.p[i][j]=Math.abs(t.p[i][j]-1);
		return t;
	}
	@Override
	public int kolvo()
	{
		int ed=0;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				if(p[i][j]==1)
					ed++;
		return ed;
	}
	public String toString()
	{
		StringBuilder s=new StringBuilder();
		for(int i=0;i<m;i++)
				s.append(Arrays.toString(p[i])+"\n");
		return s.toString();
	}
}

class matrixInt extends matrix
{
	private int[][]p;
	matrixInt(int rows, int columns,int [][]mas)
	{
		super(rows,columns);
		p=new int[m][n];
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				p[i][j]=mas[i][j];
	}
	matrixInt(int rows, int columns,int init)
	{
		super(rows,columns);
		p=new int[m][n];
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				p[i][j]=init;
	}
	matrixInt mul(matrixInt m)
	{
		
		if (this.n != m.m)
			{
				System.out.println("������ ��������");
				return this;
			}
		else
		{
			matrixInt res=new matrixInt(this.m,m.n,0);
			for (int i = 0; i < this.m; i++)
				for (int j = 0; j < m.n; j++)
					for (int r = 0; r < m.m; r++)
						res.p[i][j] +=this.p[i][r]* m.p[r][j];
			
			return res;
		}
	}
	matrixInt sum(matrixInt m)
	{
		
		if (this.m != m.m && this.n!=m.n)
			{
				System.out.println("������ �������!");
				return this;
			}
		else
		{
			matrixInt res=new matrixInt(this.m,m.n,0);
			for (int i = 0; i < m.m; i++)
				for (int j = 0; j < this.n; j++)
						res.p[i][j]=this.p[i][j]+ m.p[i][j];
			
			return res;
		}
	}
	public void div(int d)
	{
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				p[i][j]=Math.abs(p[i][j]/d);
	}
	@Override
	public int kolvo()
	{
		int ed=0;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				if(p[i][j]==1)
					ed++;
		return ed;
	}
	public String toString()
	{
		StringBuilder s=new StringBuilder();
		for(int i=0;i<m;i++)
				s.append(Arrays.toString(p[i])+"\n");
		return s.toString();
	}
}
public class Kr2 {

	public static void main(String[] args) throws wrongParams{
		int [][]init1={
				{1,3,3},
				{4,9,0},
				{2,1,7}};
		int [][]init2= { {1,2},{4,4},{0,12}};
		matrixInt test1=new matrixInt(3,3,init1);
		matrixInt test2=new matrixInt(3,2,init2);
		System.out.println(test1);
		System.out.println(test2);
		System.out.println("������������ ������:\n"+test1.mul(test2));
		System.out.println("����� ������ ������� � ���������� ��� ������������:\n"+test2.sum(test1.mul(test2))+"��������� �������:");
		int [][]init3={
				{1,0,0},
				{1,1,0},
				{1,0,1}};
		int [][]init4={
				{1,0,1},
				{0,0,1},
				{1,0,1}};
		matrixBool test3=new matrixBool(3,3,init3);
		matrixBool test4=new matrixBool(3,3,init4);
		System.out.println(test3);
		System.out.println(test4);
		System.out.println("������������ ������:\n"+test3.mul(test4));
		System.out.println("����� ������ ������� � ���������� ��� ������������:\n"+test4.sum(test3.mul(test4))+"��������������� �������:");
		System.out.println(test3.invers());
		System.out.println(test4.invers());
		matrix[] mas=new matrix[]{test1,test2,test3,test4};
		Arrays.sort(mas,new comp());
		System.out.println("���������� �� ����� ������:");
		for(matrix t:mas)
			System.out.println("����� ������:"+t.kolvo()+"\n"+t);
}
}
