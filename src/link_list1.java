import java.util.Scanner;
public class link_list1 {
    Node head;
    static class Node{
        int data;
        Node next;
        Node(int d){
            this.data = d;
            next=null;
        }
    }
    public void push(int data){
        Node new_node = new Node(data);
        new_node.next = head;
        head = new_node;
    }
    public void printlist(){
        Node n = head;
        while (n!=null) {
            System.out.print(n.data+" ");
            n = n.next;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        link_list1 llist = new link_list1();
        System.out.println("Enter Size : ");
        int s = sc.nextInt();
        System.out.println("Enter Data : ");
        for (int i = 0; i < s; i++) {
            int dt = sc.nextInt();
            llist.push(dt);
        }
        llist.printlist();
    }
}