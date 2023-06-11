package ll

import "fmt"

type Node struct {
	Val  interface{}
	Next *Node
}

type LinkedList struct {
	head *Node // 指向開始的 Node
	tail *Node // 指向結束的 Node
}

func New() *LinkedList {
	return new(LinkedList)
}

func NewNode(val interface{}) *Node {
	n := new(Node)
	n.Val = val
	return n
}

func (l *LinkedList) isEmpty() bool {
	return l.head == nil
}

func (l *LinkedList) Prepend(n *Node) {
	if l.isEmpty() {
		l.head = n
		l.tail = n
		return
	}
	n.Next = l.head // 將新節點的下個點指向原串列的頭
	l.head = n      // 將開頭改成新節點
}

func (l *LinkedList) Append(n *Node) {
	if l.isEmpty() {
		l.head = n
		l.tail = n
		return
	}
	l.tail.Next = n // 將結尾的下個點指向新節點
	l.tail = n      // 將結尾改成新節點
}

func (l *LinkedList) Pop() (*Node, error) {
	// 串列為空 (噴錯)
	if l.isEmpty() {
		return nil, fmt.Errorf("Linked-List is empty")
	}

	var previous *Node
	// 串列只有一個值
	if l.head == l.tail {
		previous = l.head
		l.head = nil // 恢復成預設值
		l.tail = nil // 恢復成預設值
		return previous, nil
	}

	for current := l.head; current != l.tail; current = current.Next {
		previous = current
	}

	// previous 為倒數第二個節點
	tmp := previous.Next
	previous.Next = nil
	l.tail = previous
	return tmp, nil
}

func (l *LinkedList) PopFirst() (*Node, error) {
	// 串列為空 (噴錯)
	if l.isEmpty() {
		return nil, fmt.Errorf("Linked-List is empty")
	}
	// 串列只有一個值
	if l.head == l.tail {
		l.tail = nil // 恢復成預設值
	}

	tmp := l.head
	l.head = l.head.Next // 將開頭指向第二個節點
	return tmp, nil
}

func (l *LinkedList) Head() *Node {
	return l.head
}

func (l *LinkedList) Tail() *Node {
	return l.tail
}

func (l *LinkedList) Remove(n *Node) error {
	// 欲移除之節點為頭節點
	if n == l.head {
		_, err := l.PopFirst()
		return err
	}

	var previous *Node
	current := l.head
	for ; current != n && current != nil; current = current.Next {
		previous = current
	}

	// 代表 n 不在串列中
	if current == nil {
		return fmt.Errorf("%v is not in the linked list", n)
	}

	// previous 是節點 n 前的一個點
	previous.Next = previous.Next.Next
	return nil
}
