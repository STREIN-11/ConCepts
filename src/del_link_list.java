import java.util.*;
public class del_link_list {
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
    public void print(){
        Node n = head;
        while(n!=null){
            System.out.print(n.data+" ");
            n=n.next;
        } 
    }
    public void delete_list(int data){
        if(head==null)
            return;
        Node temp = head;
        if(data==0){
            head = temp.next;
            return;
        }
        for (int i = 0; temp!=null&&i < data-1; i++) {
            temp=temp.next;
        }
        if(temp==null || temp.next==null)
            return;

        Node next = temp.next.next;
        temp.next=next;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        del_link_list llist = new del_link_list();
        System.out.println("Enter Size : ");
        int s = sc.nextInt();
        System.out.println("Enter Data : ");
        for (int i = 0; i < s; i++) {
            int dt = sc.nextInt();
            llist.push(dt);
        }
        llist.print(); 
        System.out.println("Enter Position to delete : ");
        int d = sc.nextInt();
        llist.delete_list(d);
        System.out.println("After Delete The Answer is : ");
        llist.print(); 
    }    
}
