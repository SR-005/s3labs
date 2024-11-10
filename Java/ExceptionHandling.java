import java.util.*;
public class ExceptionHandling  
{
    public static void main(String[] args) throws ArithmeticException
    {
        try 
        {
            Scanner sc=new Scanner(System.in);
            System.out.print("Enter the First Number: ");
            int a=sc.nextInt();
            System.out.print("Enter the Second Number: ");
            int b=sc.nextInt();
            
            if(b==0)
            {
                throw new ArithmeticException("Cannot Divide by 0");
            }
            else
            {
                int c=a/b;
                System.out.println("Result: "+c);
            }
        } 
        catch (ArithmeticException e) 
        {
            System.out.println(e.getMessage());
        }
        finally
        {
            System.out.println("Program Ended");
        }
    }
}
