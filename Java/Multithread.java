import java.util.Random;
import java.util.random.*;

public class EvenThread extends Thread
{
    int num;
    public EvenThread(int n)
    {
        this.num=n;
    }
    public void run()
    {
        System.out.println("Square of "+num+": "+num*num);
    }
}

public class OddThread extends Thread
{
    int num;
    public OddThread(int n)
    {
        this.num=n;
    }
    public void run()
    {
        System.out.println("Cube of "+num+": "+num*num*num);
    }
}

public class Randomt extends Thread
{
    public void run()
    {
        int number=0;
        int i;
        Random r=new Random();
        for(i=0;i<10;i++)
        {
            number=r.nextInt(100);
            if(number%2==0)
            {
                new EvenThread(number).start();
            }
            else
            {
                new OddThread(number).start();
            }
        }
    }
}
public class Multithread 
{
    public static void main(String[] args) 
    {
        Randomt rt=new Randomt();
        rt.start();
    }
}
