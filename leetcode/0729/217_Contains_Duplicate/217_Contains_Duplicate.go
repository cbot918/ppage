// # Example 1:

// # Input: nums = [1,2,3,1]
// # Output: true

// # Input: nums = [1,2,3,4]
// # Output: false

// # Input: nums = [1,1,1,3,3,4,3,2,4,2]
// # Output: true
package main

import "fmt"

var (
	in1 = []int{1, 2, 3, 4}
)

// set : O(n)
func containsDuplicate(nums []int) bool {
	s := make(map[int]bool)
	for _, num := range nums {
		s[num] = true
	}
	return len(s) < len(nums)
}

func main() {
	fmt.Println(
		containsDuplicate(in1),
	)
}

// two pointer: O(n^2)
// func containsDuplicate(nums []int) bool {
// 	i := 0
// 	j := 0
// 	for i < len(nums) {
// 		j = i + 1
// 		for j < len(nums) {
// 			if nums[j] == nums[i] {
// 				return true
// 			}
// 			j += 1
// 		}
// 		i += 1
// 	}
// 	return false
// }
