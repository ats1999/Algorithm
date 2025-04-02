
class Node<T extends Comparable<T>>{
  private T data;
  private Node<T> next;

  Node(T data) {
    this.data = data;
  }

  @Override
  public boolean equals(Object compareTo) {
    if(compareTo == null || this.getClass() != compareTo.getClass()) {
      return false;
    }

    Node<T> compareToNode = (Node<T>) compareTo;

    return data.compareTo(compareToNode.getData()) == 0;
  }

  public void next(Node<T> node) {
    this.next = node;
  }

  public Node<T> next() {
    return this.next;
  }


  public T getData() {
    return this.data;
  }
}

class LinkedList<T extends Comparable<T>> {
  private Node<T> head;

  public void addNode(Node<T> nodeToAdd){
    if(head == null){
      head = nodeToAdd;
      return;
    }


    Node<T> tempNode = head;

    while(tempNode.next() != null){
      tempNode = tempNode.next();
    }

    tempNode.next(nodeToAdd);
  }

  public void removeNode(Node<T> nodeToRemove) throws Exception{
    if(head == null){
      throw new Exception("Linked List is empty!");
    }

    if(nodeToRemove.equals(head)){
      // head node to be removed
      this.head = head.next();
      return;
    }

    Node<T> prev = head;
    Node<T> next = head.next();

    while(next != null && !next.equals(nodeToRemove)){
      prev = prev.next();
      next = next.next();
    }

    // no node found
    if(next == null){
      return;
    }

    // remove the node
    prev.next(next.next());
    next.next(null);
  }

  public boolean searchNode(Node<T> nodeToSearch){
    Node<T> temp = head;
    while(temp != null && !temp.equals(nodeToSearch)){
      temp = temp.next();
    }

    return temp == null ? false : true;
  }

  public void print(){
    Node<T> temp = head;

    while(temp != null){
      System.out.println(temp.getData() + " ");
      temp = temp.next();
    }

    System.out.println("\n\n");
  }
}

public class LinkedListDemo{
  public static void main(String[] args) throws Exception{
    LinkedList<Integer> ll = new LinkedList<>();

    for(int i=0; i<5; i++){
      Node<Integer> n = new Node(i+1);
      ll.addNode(n);
    }

    ll.print();

    System.out.println("Search 5: "+ ll.searchNode(new Node(5)));
    System.out.println("Search 5: "+ ll.searchNode(new Node(6)));

    ll.removeNode(new Node<Integer>(3));
    System.out.println("Removed 3");
    System.out.println("Search 3: "+ ll.searchNode(new Node(3)));

    ll.print();

    ll.addNode(new Node<Integer>(1));

    ll.print();

    ll.addNode(new Node<Integer>(100));
    ll.print();
    System.out.println("Search 100: "+ ll.searchNode(new Node<Integer>(100)));
    ll.removeNode(new Node<Integer>(100));
    ll.print();

  }
}