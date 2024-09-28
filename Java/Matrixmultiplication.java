import java.util.Scanner;
public class Matrixmultiplication 
{
    public static void main(String args[])
    {
        int row1,row2,column1,column2,i,j,k;
        Scanner sc=new Scanner(System.in);
        //Input rows and columns:
        System.out.print("Enter No. of Rows in Matrix A: ");
        row1=sc.nextInt();
        System.out.print("Enter No. of Columns in Matrix A: ");
        column1=sc.nextInt();
        System.out.print("Enter No. of Rows in Matrix B: ");
        row2=sc.nextInt();
        System.out.print("Enter No. of Columns in Matrix B: ");
        column2=sc.nextInt();

        if(column1!=row2)
        {
            System.out.println("Matrix Multiplication not Possible");
        }
        else
        {
            //Matrix Declaration:
            int matrixa[][]=new int [row1][column1];
            int matrixb[][]=new int [row2][column2];
            int matrixc[][]=new int [row1][column2];

            //for input from user- MATRIX A:
            for(i=0;i<row1;i++)
            {
                for(j=0;j<column1;j++)
                {
                    System.out.print("Enter Element of Matrix A ["+(i+1)+"]["+(j+1)+"]: ");
                    matrixa[i][j]=sc.nextInt();
                }
            }

            //for input from user- MATRIX B:
            for(i=0;i<row2;i++)
            {
                for(j=0;j<column2;j++)
                {
                    System.out.print("Enter Element of Matrix B ["+(i+1)+"]["+(j+1)+"]: ");
                    matrixb[i][j]=sc.nextInt();
                }
            }

            //Matrix Multiplication
            for(i=0;i<row1;i++)
            {
                for(j=0;j<column2;j++)
                {
                    matrixc[i][j]=0;
                    for(k=0;k<column1;k++)
                    {
                        matrixc[i][j]+=matrixa[i][k]*matrixb[k][j];
                    }
                }
            }

            //Display MATRIX C
            System.out.println("MATRIX C:");
            for(i=0;i<row1;i++)
            {
                for(j=0;j<column2;j++)
                {
                    System.out.print(matrixc[i][j]+" ");
                }
                System.out.print("\n");
            }
        }
    }    
}
