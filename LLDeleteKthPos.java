class ListNode {
    int val;
    ListNode next;

    // Constructor
    ListNode() {
        this.val = 0;
        this.next = null;
    }

    ListNode(int data1) {
        this.val = data1;
        this.next = null;
    }

    ListNode(int data1, ListNode next1) {
        this.val = data1;
        this.next = next1;
    }
}

class Solution {
    // Function to delete the k-th node of a linked list
    public ListNode deleteKthNode(ListNode head, int k) {
        // If the list is empty, return null
        if (head == null)
            return null;

        // If k is 1, delete the head node
        if (k == 1) {
            ListNode temp = head;
            head = head.next;
            return head;
        }

        // Initialize a temporary pointer
        ListNode temp = head;

        // Traverse to the (k-1)th node
        for (int i = 0; temp != null && i < k - 2; i++) {
            temp = temp.next;
        }

        /* If k is greater than the number of nodes, 
        return the unchanged list */
        if (temp == null || temp.next == null)
            return head;

        // Delete the k-th node
        ListNode next = temp.next.next;
        temp.next = next;

        // Return head
        return head;
    }
}

class Main {

    // Function to print the linked list
    private static void printLL(ListNode head) {
        ListNode current = head;
        while (current != null) {
            System.out.print(current.val + " ");
            current = current.next;
        }
        System.out.println();
    }
    
    // Main method
    public static void main(String[] args) {
        // Initialize an array with values for the linked list
        int[] arr = {12, 5, 8, 7};

        // Create a linked list with the values from the array
        ListNode head = new ListNode(arr[0]);
        head.next = new ListNode(arr[1]);
        head.next.next = new ListNode(arr[2]);
        head.next.next.next = new ListNode(arr[3]);

        // Print the original linked list
        System.out.print("Original list: ");
        printLL(head);

        // Creating an instance of Solution class
        Solution sol = new Solution();

        // Call the deleteKthNode function to delete the k-th node
        int k = 2;
        head = sol.deleteKthNode(head, k);

        // Print the linked list after deletion
        System.out.print("List after deleting the kth node: ");
        printLL(head);
    }
}class ListNode {
    int val;
    ListNode next;

    // Constructor
    ListNode() {
        this.val = 0;
        this.next = null;
    }

    ListNode(int data1) {
        this.val = data1;
        this.next = null;
    }

    ListNode(int data1, ListNode next1) {
        this.val = data1;
        this.next = next1;
    }
}

class Solution {
    // Function to delete the k-th node of a linked list
    public ListNode deleteKthNode(ListNode head, int k) {
        // If the list is empty, return null
        if (head == null)
            return null;

        // If k is 1, delete the head node
        if (k == 1) {
            ListNode temp = head;
            head = head.next;
            return head;
        }

        // Initialize a temporary pointer
        ListNode temp = head;

        // Traverse to the (k-1)th node
        for (int i = 0; temp != null && i < k - 2; i++) {
            temp = temp.next;
        }

        /* If k is greater than the number of nodes, 
        return the unchanged list */
        if (temp == null || temp.next == null)
            return head;

        // Delete the k-th node
        ListNode next = temp.next.next;
        temp.next = next;

        // Return head
        return head;
    }
}

class Main {

    // Function to print the linked list
    private static void printLL(ListNode head) {
        ListNode current = head;
        while (current != null) {
            System.out.print(current.val + " ");
            current = current.next;
        }
        System.out.println();
    }
    
    // Main method
    public static void main(String[] args) {
        // Initialize an array with values for the linked list
        int[] arr = {12, 5, 8, 7};

        // Create a linked list with the values from the array
        ListNode head = new ListNode(arr[0]);
        head.next = new ListNode(arr[1]);
        head.next.next = new ListNode(arr[2]);
        head.next.next.next = new ListNode(arr[3]);

        // Print the original linked list
        System.out.print("Original list: ");
        printLL(head);

        // Creating an instance of Solution class
        Solution sol = new Solution();

        // Call the deleteKthNode function to delete the k-th node
        int k = 2;
        head = sol.deleteKthNode(head, k);

        // Print the linked list after deletion
        System.out.print("List after deleting the kth node: ");
        printLL(head);
    }
}
