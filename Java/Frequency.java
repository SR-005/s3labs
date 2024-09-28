import java.util.Scanner;
public class Frequency 
{
    public static void main(String args[])
    {
        int count=0,i,len;
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter String: ");
        String str=sc.nextLine();
        System.out.print("Enter Character: ");
        char ch=sc.next().charAt(0);
        len=str.length();
        for(i=0;i<len;i++)
        {
            if(str.charAt(i)==ch)
            {
                count++;
            }
        }
        System.out.println("Frequency of "+ch+": "+count);
    }    
}
