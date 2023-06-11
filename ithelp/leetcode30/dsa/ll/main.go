package main

import (
	"fmt"
	"linkedlist/ll"
)

func print(l *ll.LinkedList) {
	for current := l.Head(); current != nil; current = current.Next {
		fmt.Printf("%v -> ", current.Val)
	}
	fmt.Println("nil")
}

func main() {
	myLikedList := ll.New()
	print(myLikedList) // nil

	myLikedList.Append(ll.NewNode("小櫻"))
	print(myLikedList) // 小櫻 -> nil

	myLikedList.Append(ll.NewNode("小狼"))
	print(myLikedList) // 小櫻 -> 小狼 -> nil
	myLikedList.Prepend(ll.NewNode("知世"))
	print(myLikedList) // 知世 -> 小櫻 -> 小狼 -> nil

	node, err := myLikedList.Pop()
	if err != nil {
		fmt.Println(err)
	} else {
		fmt.Println("Pop()", node.Val) // Pop() 小狼
	}
	print(myLikedList) // 知世 -> 小櫻 -> nil

	node, err = myLikedList.PopFirst()
	if err != nil {
		fmt.Println(err)
	} else {
		fmt.Println("PopFirst()", node.Val) // PopFirst() 知世
	}
	print(myLikedList) // 小櫻 -> nil

	node, err = myLikedList.Pop()
	if err != nil {
		fmt.Println(err)
	} else {
		fmt.Println("Pop()", node.Val) // Pop() 小櫻
	}
	print(myLikedList) // nil

	// 故意再取一個
	node, err = myLikedList.Pop()
	if err != nil {
		fmt.Println(err) // Linked-List is empty
	} else {
		fmt.Println("Pop()", node.Val)
	}

	myLikedList.Append(ll.NewNode("小可"))
	myLikedList.Append(ll.NewNode("莓玲"))
	touya := ll.NewNode("桃矢")
	myLikedList.Append(touya)
	myLikedList.Append(ll.NewNode("雪兔"))
	print(myLikedList) // 小可 -> 莓玲 -> 桃矢 -> 雪兔 -> nil

	myLikedList.Remove(touya)
	print(myLikedList) // 小可 -> 莓玲 -> 雪兔 -> nil

	fmt.Println("Head()", myLikedList.Head().Val) // Head() 小可
	fmt.Println("Tail()", myLikedList.Tail().Val) // Tail() 雪兔

	// 故意再移除一次
	err = myLikedList.Remove(touya)
	if err != nil {
		fmt.Println(err) // &{桃矢 0xc00005c500} is not in the linked list
	}
}
