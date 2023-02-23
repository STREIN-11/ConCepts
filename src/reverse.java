import java.util.*;
class Node {
    int data;
    Node next;
    Node(int a)
    {
        data = a;
        next = null;
    }
}





















class reverse {
    static Node push(Node head, int val)
    {
        Node newNode = new Node(val);
        if (head == null) {
            head = newNode;
            return head;
        }
  
        Node temp = head;
        while (temp.next != null)
            temp = temp.next;
  
        temp.next = newNode;
        return head;
    }
    static Node reverse(Node head, int k){
        if (head == null || head.next == null)
            return head;

        Node dummy = new Node(-1);
        dummy.next = head;

        Node prev = dummy;
        Node curr = dummy;
        Node next = dummy;

        int count = 0;
        while (curr != null) {
            count++;
            curr = curr.next;
        }
        while (next != null) {
            curr = prev.next; 
            next = curr.next; 
            int toLoop= count > k? k: count - 1; 

            for (int i = 1; i < toLoop; i++) {
                curr.next = next.next;
                next.next = prev.next;
                prev.next = next;
                next = curr.next;
            }
            prev = curr; 
            count -= k; 
        }
        return dummy.next;
    }
    static void print(Node head)
    {
        while (head.next != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println(head.data);
    }
    public static void main(String[] args) {
        Node head =null;
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Enter Length : ");
        int l = sc.nextInt();
        System.out.println("Enter Data : ");
        for (int i = 0; i < l; i++) {
            int da = sc.nextInt();
            head = push(head, da);
        }

        System.out.println("List is : ");
        print(head);

        System.out.println("Enter Number : ");
        int k = sc.nextInt();

        System.out.println("After Reverse : ");
        Node newhead = reverse(head, k);
        print(newhead); 
    }
}
