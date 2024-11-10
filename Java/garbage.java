public class garbage 
{

    public garbage() 
    {
        System.out.println("Object Created");
    }

    protected void finalize()
    {
        System.out.println("Object Destroyed");
    }
    
    public static void main(String args[])
    {
        garbage g=new garbage();
        g=null;
        System.gc();
    }    
}
