import java.util.*;
class linsearch
{
	public static void main(String a[])
	{
		int i,flag=0,n,e;
		int b[]=new int[100];
		System.out.println("enter the limit");
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		System.out.println("enter the array");
		for(i=0;i<n;i++)
		{
			b[i]=sc.nextInt();
		}
		System.out.println("Enter the element to be searched");
		e=sc.nextInt();
		for(i=0;i<n;i++)
		{
			if(b[i]==e)
			{
				flag=1;
				break;	
			}
		}
		if(flag==1)
		{
			System.out.println("element is found");
		}
		else
		{
			System.out.println("element is not found");
		}
	}
}