import java.util.Scanner;
public class Palindrome 
{
    public static void main(String args[])
    {
        int i,j,count=0;
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter String: ");
        String str=sc.nextLine();
        
        j=str.length();
        for(i=0;i<j/2;i++,j--)
        {
            if(str.charAt(i)!=str.charAt(j-1))
            {
                System.out.println("String is not Palindrome");
                count=1;
                break;
            }
        }
        if(count==0)
        {
            System.out.println("String is Palindrome");
        }
    }    
}
