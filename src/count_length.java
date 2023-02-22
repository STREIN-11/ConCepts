import java.util.*;
public class count_length {
    Node head;
    static class Node{
        int data;
        Node next;
        Node(int d){
            data = d;
            next=null;
        }
    }
    public void push(int data){
        Node new_node = new Node(data);
        new_node.next = head;
        head = new_node;
    }
    public int getcount(Node node){
        if(node==null)
            return 0;
        else
            return 1+getcount(node.next);
    }
    public int count(){return getcount(head);}
    public void print(){
        Node n = head;
        while (n!=null) {
            System.out.print(n.data+" ");
            n=n.next;
        }
    }
    public static void main(String[] args) {
        count_length llist = new count_length();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Length : ");
        int l = sc.nextInt();
        System.out.println("Enter Data : ");
        for (int i = 0; i < l; i++) {
            int dt = sc.nextInt();
            llist.push(dt);
        }
        llist.print();
        System.out.print("\nLength is : "+llist.count());
    }
}