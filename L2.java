/*You are working on a real-time inventory management system where you need to maintain a list of product IDs in a linked list. As new products are added to the inventory, their IDs are appended at the end of the list. You have been tasked with writing a program to handle this operation.

Write a program to insert a new product ID at the end of the linked list. After the completion of insertion, print the entire linked list to confirm that the new ID has been added.

Input Format

The first line contains an integer N, the number of product IDs to be initially added to the linked list.
The second line contains N space-separated integers, representing the product IDs.
Constraints

NA

Output Format

After inserting the product ID, print the current linked list, with elements separated by a space.

Sample Input 0

5
101 102 103 104 105
Sample Output 0

101 102 103 104 105
Explanation 0

Initially the linked list is empty. The first product ID 101 is inserted at the end, and the list becomes 101. The second product ID 102 is inserted at the end, and the list becomes 101 102. The third product ID 103 is inserted at the end, and the list becomes 101 102 103. The fourth product ID 104 is inserted at the end, and the list becomes 101 102 103 104. The fifth product ID 105 is inserted at the, and the list becomes 101 102 103 104 105.

Sample Input 1

3
101 102 103
Sample Output 1

101 102 103*/

import java.io.*;
import java.util.*;
class Node {
    int data;     
    Node next;     
    Node(int data1, Node next1) {
        this.data = data1;  
        this.next = next1;  
    }
    Node(int data1) {
        this.data = data1;  
        this.next = null;   
    }
}

public class Solution {
    public static Node convertAll(List<Integer> arr){
        Node head = new Node(arr.get(0));
        Node current = head;
        for(int i = 1;i<arr.size();i++){
            Node temp = new Node(arr.get(i));
            current.next = temp;
            current = temp;
        }
        return head;
    }
     public static void print(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }


    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> arr = new ArrayList<>(n);
        for(int i = 0;i<n;i++){
            arr.add(sc.nextInt());
        }
        Node head = convertAll(arr);
        print(head);
    }
}
