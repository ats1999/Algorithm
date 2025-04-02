package queue;

import java.util.ArrayList;
import java.util.List;

public class Queue<T> {
  private int length;
  private List<T> queue;

  Queue(int length) {
    this.length = length;
    this.queue = new ArrayList<>();
  }


}
