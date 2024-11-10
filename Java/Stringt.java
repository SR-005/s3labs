import java.util.*;
public class Stringt
{
    public static void main(String[] args) 
    {
        int sum=0;
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the Numbers [with Space]: ");
        String str=sc.nextLine();
        StringTokenizer st=new StringTokenizer(str," ");
        while(st.hasMoreTokens())
        {
            String temp=st.nextToken();
            int n=Integer.parseInt(temp);
            sum=sum+n;
        }
        System.out.println("SUM: "+sum);
    }    
}
