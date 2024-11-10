import java.util.Scanner;
class LinkedList
{
    private Node head;
    class Node
    {
        private int data;
        private Node left;
        private Node right;
        public Node(int data)
        {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    public void insert(int data)
    {
        Node temp = new Node(data);
        if(head == null)
        {
            head = temp;
        }
        else
        {
            Node ptr = head;
            while(ptr.right != null)
            {
                ptr = ptr.right;
            }
            ptr.right = temp;
            temp.left = ptr;
        }
    }

    public void delete()
    {
        int x = head.data;
        head = head.right;
        head.left = null;
        System.out.println("Element "+x +" got deleted");
    }

    public void display()
    {
        if(head == null)
        System.out.println("List is Empty");
        else
        {
            Node ptr = head;
            while(ptr != null)
            {
                System.out.print(ptr.data +"\t");
                ptr = ptr.right;
            }
            System.out.println();
        }
    }
}

class Doublylinkedlist
{
    public static void main(String [] args)
    {
        LinkedList list = new LinkedList();
        Scanner sc = new Scanner(System.in);
        
        while(true)
        {
            System.out.print("1. Insert at End \n2. Delete From Front \n3. Display\n4.Exit\n");
            System.out.print("Enter the choice:");
            int choice = sc.nextInt();
            if (choice==1)
            {
                System.out.print("Enter the number to insert: ");
                int data = sc.nextInt();
                sc.nextLine(); // Consume the newline character
                list.insert(data);
                System.out.println("Data inserted Successfully");
            } 
            else if (choice == 2) 
            {
                list.delete();
            } 
            else if (choice == 3) 
            {
                list.display();
            } 
            else if (choice == 4) 
            {
                break;
            } 
            else 
            {
                System.out.println("Invalid Choice");
            }
        }
    }
}
