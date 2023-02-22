import java.util.*;
public class swap_node {
    class Node {
        int data;
        Node next;
 
        public Node(int data)
        {
            this.data = data;
            this.next = null;
        }
    }
    public Node head = null;
    public Node tail = null;
    public void push(int data){
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail.next = newNode;
            tail = newNode;
        }
    }
    public void swap(int n1, int n2)
    {
        Node prevNode1 = null, prevNode2 = null,
             node1 = head, node2 = head;
        if (head == null) {
            return;
        }
        if (n1 == n2)
            return;
        while (node1 != null && node1.data != n1) {
            prevNode1 = node1;
            node1 = node1.next;
        }
        while (node2 != null && node2.data != n2) {
            prevNode2 = node2;
            node2 = node2.next;
        }
 
        if (node1 != null && node2 != null) {
            if (prevNode1 != null)
                prevNode1.next = node2;
            else
                head = node2;
            if (prevNode2 != null)
                prevNode2.next = node1;
            else
                head = node1;
            Node temp = node1.next;
            node1.next = node2.next;
            node2.next = temp;
        }
        else {
            System.out.println("Swapping is not possible");
        }
    }
    public void print(){
        Node current = head;
        if (head == null) {
            System.out.println("List is empty");
            return;
        }
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }
    public static void main(String[] args) {
        swap_node llist = new swap_node();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Size : ");
        int size = sc.nextInt();
        System.out.println("Enter Data");
        for (int i = 0; i < size; i++) {
            int data = sc.nextInt();
            llist.push(data);
        }
        System.out.println("List is : ");
        llist.print();
        System.out.println("\nEnter 1st Value to Swap : ");
        int x = sc.nextInt();
        System.out.println("Enter 2nd Value to Swap : ");
        int y= sc.nextInt();
        llist.swap(x,y);
        System.out.println("After Swap : ");
        llist.print();

        
    }
    
}
