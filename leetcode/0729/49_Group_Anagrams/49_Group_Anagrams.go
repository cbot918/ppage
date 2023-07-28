package main

import (
	"fmt"
	"sort"
	"strings"
)

/*

49. Group Anagrams
Medium

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]

*/

var strs = []string{"eat", "tea", "tan", "ate", "nat", "bat"}

// normal: Beats 61.21%of users with Go
func groupAnagrams(strs []string) [][]string {

	var sort = func(str string) string {
		s := strings.Split(str, "")
		sort.Strings(s)
		return strings.Join(s, "")
	}

	t := make(map[string][]string)
	for _, str := range strs {
		key := sort(str)
		if _, ok := t[key]; !ok {
			t[key] = []string{}
		}
		t[key] = append(t[key], str)
	}

	res := make([][]string, len(t))
	i := 0
	for _, item := range t {
		res[i] = item
		i += 1
	}

	return res
}

func main() {
	fmt.Println(groupAnagrams(strs))
}
