public class garbage 
{
    public static void main(String args[])
    {
        Test1 t1=new Test1();
        Test2 t2=new Test2();
        t1=null;
        System.gc();
        t2=null();

    }    
}
