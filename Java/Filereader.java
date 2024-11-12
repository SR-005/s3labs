import java.io.*;

public class Filereader 
{
    public static void main(String[] args) 
    {
        try
        {
            FileReader fr = new FileReader("test.txt");
            FileWriter fw = new FileWriter("copy.txt");
        int i;
            while((i=fr.read())!=-1)
            {
                fw.write(i);
            }
            fr.close();
            fw.close();
        }
        catch(FileNotFoundException e)
        {
            System.out.println(e.getMessage());
        }
        catch(IOException e)
        {
            System.out.println(e.getMessage());
        }
        
    }
}
