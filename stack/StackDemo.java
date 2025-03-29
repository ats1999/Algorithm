package stack;

import java.util.ArrayList;
import java.util.List;

class Stack<T> {
  private List<T> it;
  private int curIdx = -1;
  private final int capacity;

  Stack(int capacity) {
    this.capacity = capacity;
    it = new ArrayList<>();
  }

  public void push(T item) throws Exception {
    if (curIdx >= capacity - 1) {
      throw new Exception("Stack overflow");
    }

    it.add(++curIdx, item);
  }

  public T peek() throws Exception {
    if (curIdx >= 0) {
      return it.get(curIdx);
    }
    throw new Exception("Stack underflow");
  }

  public void pop() throws Exception {
    if (curIdx < 0) {
      throw new Exception("Stack underflow");
    }
    curIdx -= 1;
  }

  public int size() {
    return it.size();
  }
}

public class StackDemo {
  public static void main(String[] args) throws Exception {
    Stack<Integer> intStack = new Stack<>(2);

    intStack.push(1);
    intStack.push(2);
    intStack.pop();
    intStack.push(3);
    System.out.println(intStack.peek());
    intStack.pop();
    System.out.println(intStack.peek());
    System.out.println("Done...");
  }
}
