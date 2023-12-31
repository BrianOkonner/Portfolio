//���������� ��� 8 ������
package app;

class polynome{

	private double []coeff;
	private int degree;
	
	public polynome()
	{
		this.coeff=new double[2];
		this.degree=1;
	}
	public polynome (int degree,double []elements)
	{
			//������������� �� 1 ������ �������
			this.degree=degree;
			coeff=new double[degree+1];
			for(int i=degree;i>=0;i--)
				coeff[i]=elements[i];
	}
	public polynome (int degree)
	{
			//������������� �� 1 ������ �������
			this.degree=degree;
			coeff=new double[degree+1];
			for(int i=0;i<=degree;i++)
				coeff[i]=0;
	}
	public polynome (double []elements)
	{
			//������������� �� 1 ������ �������
			degree=elements.length-1;
			coeff=new double[degree+1];
			for(int i=0;i<=degree;i++)
				coeff[i]=elements[i];
	}
	public double[] getPoly()
	{
		return this.coeff;
	}
	public int getn()
	{
		return this.degree;
	}
	public void setPoly(double []coeff)
	{
		this.coeff=coeff;
	}
	public void setSpc(int pos,double value)
	{
		this.coeff[pos]=value;
	}
	public double getSpc(int pos)
	{
		return this.coeff[pos];
	}
	public void setn(int degree)
	{
		this.degree=degree;
	}
	public polynome mul(polynome p)
	{
		polynome res=new polynome(p.degree+degree);
		
		for(int i=p.degree;i>=0;i--)
		{
			polynome buff=new polynome(p.degree+degree);
			for(int j=degree;j>=0;j--)
			{
				buff.setSpc(i+j, p.coeff[i]*coeff[j]);
			}
			res=res.sum(buff);
		}	
		return res;
	}
	public polynome sum(polynome p)
	{
		int maxdegree=(p.degree>this.degree)?p.degree:this.degree;
		int mindegree=(p.degree<this.degree)?p.degree:this.degree;
		polynome res=new polynome(maxdegree);
		for(int i=maxdegree;i>=mindegree;i--)
			res.setSpc(i,(p.degree>this.degree)?p.coeff[i]:this.coeff[i]);
		for(int i=mindegree;i>=0;i--)
			res.setSpc(i, p.coeff[i]+this.coeff[i]);
		return res;
	}
	public double value(double x)
	{
		double res=0;
		for(int i=degree;i>=0;i--)
			res+=Math.pow(x, i)*coeff[i];
		return res;
	}
	public String toString() {
		StringBuilder res=new StringBuilder();
		for(int i=degree;i>0;i--)
		{
			String buff=coeff[i]+"x^("+i+")+";
			res.append(buff);
		}
		res.append(coeff[0]);
		return res.toString();
	}
}
public class sr {

	public static void main(String[] args) {

		polynome []mas=new polynome[3];
		double []coeffs1= {1,1,1,1};
		double []coeffs2= {1,1,1};
		double []coeffs3= {2,3,4};
		mas[0]=new polynome(3,coeffs1);
		mas[1]=new polynome(2,coeffs2);
		mas[2]=new polynome(coeffs3);
		System.out.println("������ ���������: "+mas[0].toString()+" �������� ��� �=2: "+mas[0].value(2));
		System.out.println("������ ���������: "+mas[1].toString()+" �������� ��� �=2: "+mas[1].value(2));
		System.out.println("������ ���������: "+mas[2].toString()+" �������� ��� �=2: "+mas[2].value(2));
		System.out.println("������ �� ������: "+mas[0].mul(mas[1]).toString());
		System.out.println("������ �� ������: "+mas[1].mul(mas[2]).toString());
		System.out.println("������ �� ������: "+mas[0].mul(mas[2]).toString());
		System.out.println("������+������: "+mas[0].sum(mas[1]).toString());
		System.out.println("������+������: "+mas[0].sum(mas[2]).toString());
		System.out.println("������+������: "+mas[2].sum(mas[1]).toString());
	}

}
