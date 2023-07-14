package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

var lg = fmt.Println

func main() {

	l1, l2 := initNode3()

	node := addTwoNumbers(l1, l2)

	logNode(node)

}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	carry := false
	ans := &ListNode{}

	head := ans

	counter := 0
	for {

		// if l2 == nil {
		// 	l2 = &ListNode{}
		// 	l2.Val = 0
		// }
		adder := l1.Val + l2.Val

		if adder >= 10 {
			adder -= 10
			carry = true
		}

		ans.Val = adder

		if l1 != nil && l2 != nil {
			l1 = l1.Next
			l2 = l2.Next
		}
		// if counter == 4 {
		// 	// lg("here")
		// 	fmt.Printf("%+v\n", l1)
		// 	return head
		// }
		if l1 == nil && l2 != nil {
			l1 = &ListNode{
				Val: 0,
			}
		}
		if l1 != nil && l2 == nil {
			l2 = &ListNode{
				Val: 0,
			}
		}
		if l1 == nil && l2 == nil {
			if carry {
				ans.Next = &ListNode{
					Val: 1,
				}
			}
			return head
		}

		ans.Next = &ListNode{}
		ans = ans.Next

		if carry {

			l1.Val += 1
			carry = false
		}

		counter += 1
	}
}

func logNode(n *ListNode) {
	for {
		if n == nil {
			return
		}
		lg(n.Val)
		n = n.Next
	}
}

func initNode3() (*ListNode, *ListNode) {
	l1 := &ListNode{}

	l1.Val = 2
	l1.Next = &ListNode{
		Val: 4,
	}
	l1.Next.Next = &ListNode{
		Val: 9,
	}

	l2 := &ListNode{}
	l2.Val = 5
	l2.Next = &ListNode{
		Val: 6,
	}
	l2.Next.Next = &ListNode{
		Val: 4,
	}
	l2.Next.Next.Next = &ListNode{
		Val: 9,
	}
	return l1, l2
}

func initNode2() (*ListNode, *ListNode) {
	l1 := &ListNode{}

	l1.Val = 9
	l1.Next = &ListNode{
		Val: 9,
	}
	l1.Next.Next = &ListNode{
		Val: 9,
	}
	l1.Next.Next.Next = &ListNode{
		Val: 9,
	}
	l1.Next.Next.Next.Next = &ListNode{
		Val: 9,
	}
	l1.Next.Next.Next.Next.Next = &ListNode{
		Val: 9,
	}
	l1.Next.Next.Next.Next.Next.Next = &ListNode{
		Val: 9,
	}

	l2 := &ListNode{}
	l2.Val = 9
	l2.Next = &ListNode{
		Val: 9,
	}
	l2.Next.Next = &ListNode{
		Val: 9,
	}
	l2.Next.Next.Next = &ListNode{
		Val: 9,
	}
	return l1, l2
}

func initNode1() (*ListNode, *ListNode) {
	l1 := &ListNode{}

	l1.Val = 2
	l1.Next = &ListNode{
		Val: 4,
	}
	l1.Next.Next = &ListNode{
		Val: 3,
	}
	l2 := &ListNode{}

	l2.Val = 5
	l2.Next = &ListNode{
		Val: 6,
	}
	l2.Next.Next = &ListNode{
		Val: 4,
	}
	return l1, l2
}

// func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
// 	keep := false
// 	ans := &ListNode{}
// 	for l1.Next != nil {
// 		if (l1.Val + l2.Val) >= 10 {
// 			keep = true
// 		}
// 		ans.Val = l1.Val + l2.Val
// 		if keep {
// 			l1 = l1.Next
// 			l2 = l2.Next
// 			l1.Val += 1
// 		} else {
// 			l1 = l1.Next
// 			l2 = l2.Next
// 		}
// 	}
// 	return ans
// }
