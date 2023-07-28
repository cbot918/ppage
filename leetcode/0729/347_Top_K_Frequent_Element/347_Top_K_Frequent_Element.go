package main

import (
	"fmt"
	"sort"
)

/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
Medium


Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]
*/

// Beats 48.86%of users with Go

func topKFrequent(nums []int, k int) []int {
	count := make(map[int]int)
	for _, num := range nums {
		count[num] += 1
	}

	keys := []int{}
	for key := range count {
		keys = append(keys, key)
	}
	sort.SliceStable(keys, func(i int, j int) bool {
		return count[keys[i]] > count[keys[j]]
	})

	i := 0
	res := []int{}
	for i < k {
		res = append(res, keys[i])
		i += 1
	}

	return res
}

// var nums = []int{1, 1, 1, 2, 2, 3}
var nums = []int{1, 1, 1, 2, 2, 3}
var k = 3

func main() {
	fmt.Println(
		topKFrequent(nums, k),
	)
}
