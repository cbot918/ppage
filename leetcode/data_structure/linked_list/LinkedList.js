// {
//   data: 'data1',
//   next: {
//     data: 'data2',
//     next: {
//       data: 'data3',
//       next: null
//     }
//   }
// }

class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class LinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
    this.length = 0;
  }

  append(data) {
    const newNode = new Node(data);
    if (this.isEmpty()) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      this.tail.next = newNode;
      this.tail = newNode;
    }
    this.length += 1;
  }

  insert(index, data) {
    if (index >= this.length) {
      this.append(data);
      return;
    }

    const newNode = new Node(data);
    if (index <= 0) {
      newNode.next = this.head;
      this.head = newNode;
    } else {
      const prevNode = this.getNode(index - 1);
      const currNode = prevNode.next;
      prevNode.next = newNode;
      newNode.next = currNode;
    }
    this.length += 1;
  }

  removeAt(index) {
    if (index < 0 || index >= this.length) return;

    if (index === 0) {
      this.head = this.head.next;
    } else {
      const prevNode = this.getNode(index - 1);
      const delNode = prevNode.next;
      const nextNode = delNode.next;
      prevNode.next = nextNode;
      if (nextNode === null) {
        this.tail = prevNode;
      }
    }
    this.length -= 1;
  }

  indexOf(data) {
    let currNode = this.head;
    let currIndex = 0;
    while (currNode) {
      if (currNode.data === data) return currIndex;
      currIndex += 1;
      currNode = currNode.next;
    }
    return -1;
  }

  remove(data) {
    const index = this.indexOf(data);
    return this.removeAt(index);
  }

  getNode(index) {
    if (index < 0 || index >= this.length) return null;
    let currNode = this.head;
    let currIndex = 0;
    while (currIndex < index) {
      currIndex += 1;
      currNode = currNode.next;
    }
    return currNode;
  }

  getData(index) {
    const node = this.getNode(index);
    return node ? node.data : null;
  }

  isEmpty() {
    return this.length === 0;
  }

  clear() {
    this.head = null;
    this.tail = null;
    this.length = 0;
  }

  size() {
    return this.length;
  }

  print() {
    const temp = [];
    let currNode = this.head;
    while (currNode) {
      temp.push(currNode.data);
      currNode = currNode.next;
    }
    return temp.join(', ');
  }
}