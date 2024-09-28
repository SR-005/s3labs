import java.util.Scanner;
class Employee
{
    String name;
    int age;
    long phone;
    String address;
    float salary;
    public void setall(String n,int a,long p,String ad,float s)
    {
        this.name=n;
        this.age=a;
        this.phone=p;
        this.address=ad;
        this.salary=s;
    }
    public float printSalary()
    {
        return salary;
    }
    public String printName()
    {
        return name;
    }
    public int printAge()
    {
        return age;
    }
    public long printNumber()
    {
        return phone;
    }
    public String printAddress()
    {
        return address;
    }
}
class Officer extends Employee
{
    String specialization;
    String department;
    public void setspdep(String sp,String dep)
    {
        this.specialization=sp;
        this.department=dep;
    }
    public String printSpecialization()
    {
        return specialization;
    }
    public String printDepartment()
    {
        return department;
    }
}
class Manager extends Employee
{
    String specialization;
    String department;
    public void setspdep(String sp,String dep)
    {
        this.specialization=sp;
        this.department=dep;
    }
    public String printSpecialization()
    {
        return specialization;
    }
    public String printDepartment()
    {
        return department;
    }
}
class Inheritance
{
    public static void main(String args[])
    {
        int a;
        long p;
        String n,ad,sp,dep;
        float s;

        //object declaration
        Scanner sc=new Scanner(System.in);
        Officer op=new Officer();
        Manager man=new Manager();
        
        //User Input- Officer
        System.out.println("ENTER OFFICER DETAILS: ");
        System.out.print("Enter Name: ");
        n=sc.nextLine();
        System.out.print("Enter Age: ");
        a=sc.nextInt();
        System.out.print("Enter Phone: ");
        p=sc.nextLong();
        sc.nextLine();
        System.out.print("Enter Address: ");
        ad=sc.nextLine();
        System.out.print("Enter Salary: ");
        s=sc.nextFloat();
        sc.nextLine();
        System.out.print("Enter Specialization: ");
        sp=sc.nextLine();
        System.out.print("Enter Department: ");
        dep=sc.nextLine();

        //passing values
        op.setall(n,a,p,ad,s);
        op.setspdep(sp,dep);
        System.out.print("\n");

        //printing Officer Details
        System.out.println("OFFICER DETAILS:");
        System.out.println("Name: "+op.printName());
        System.out.println("Age: "+op.printAge());
        System.out.println("Phone Number: "+op.printNumber());
        System.out.println("Address: "+op.printAddress());
        System.out.println("Salary: "+op.printSalary());
        System.out.println("Specialization: "+op.printSpecialization());
        System.out.println("Department: "+op.printDepartment());
        System.out.print("\n");

        //User Input- Manager
        System.out.println("ENTER MANAGER DETAILS: ");
        System.out.print("Enter Name: ");
        n=sc.nextLine();
        System.out.print("Enter Age: ");
        a=sc.nextInt();
        System.out.print("Enter Phone: ");
        p=sc.nextLong();
        sc.nextLine();
        System.out.print("Enter Address: ");
        ad=sc.nextLine();
        System.out.print("Enter Salary: ");
        s=sc.nextFloat();
        sc.nextLine();
        System.out.print("Enter Specialization: ");
        sp=sc.nextLine();
        System.out.print("Enter Department: ");
        dep=sc.nextLine();
        System.out.print("\n");

        //passing values
        man.setall(n,a,p,ad,s);
        man.setspdep(sp,dep);
        System.out.print("\n");

        //printing Manager Details
        System.out.println("MANAGER DETAILS:");
        System.out.println("Name: "+man.printName());
        System.out.println("Age: "+man.printAge());
        System.out.println("Phone Number: "+man.printNumber());
        System.out.println("Address: "+man.printAddress());
        System.out.println("Salary: "+man.printSalary());
        System.out.println("Specialization: "+man.printSpecialization());
        System.out.println("Department: "+man.printDepartment());
    }
}