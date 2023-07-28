package main

import (
	"fmt"
)

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false

var s1 = "anagram"
var s2 = "nagaram"

// sort string:  Beats 7.51%of users with Go
// func isAnagram(s string, t string) bool {
// 	a := strings.Split(s, "")
// 	b := strings.Split(t, "")
// 	sort.Strings(a)
// 	sort.Strings(b)

// 	return strings.Join(a, "") == strings.Join(b, "")
// }

// hash map: Beats 87.70%of users with Go
func isAnagram(s string, t string) bool {
	count := make(map[rune]int)
	for _, c := range s {
		count[c] += 1
	}
	for _, c := range t {
		count[c] -= 1
	}
	for _, c := range count {
		if c != 0 {
			return false
		}
	}
	return true
}

func main() {
	fmt.Println(isAnagram(s1, s2))
}
