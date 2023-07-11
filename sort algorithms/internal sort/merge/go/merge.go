package main

import ( 
		"fmt"
		s "sort"
)

// merge sort
//
// [2,3,1,3,5,9,7]
//
// [2,3,1] + [3,5,9,7]
// 
// 2 3 3 1 5 9 7
//
// [2,3,3] + [1,5,9,7]
//
// [1,2,3,3,5,9,7]
//
// [1,2,3] + [3,5,    9,7]
//           [3,5] + [9,7]
//           [3,5] + [7,9]
//           [3,5,    7,9]


func sort(a []int) []int {
		l := len(a)
		h := l/2

		if h == 1 {
				return merge([]int{a[0]}, []int{a[1]})
		}

		pa := a[0:h]
		pb := a[h:l]

		fmt.Printf("starting part sorting pa: %v pb: %v\n", pa, pb)

		return merge(sort(pa), sort(pb))
}

func merge(a, b []int) []int {
		s := []int{}

		la := len(a)
		lb := len(b)

		l := 0
		r := 0

		// two pointers solution
		for ; l < la && r < lb; {
				if a[l] < b[r] {
						s = append(s, a[l])
						l++
				} else {
						s = append(s, b[r])
						r++
				}
		}

		for l < la {
				s = append(s, a[l])
				l++
		}

		for r < lb {
				s = append(s, b[r])
				r++
		}

		fmt.Printf("after merge a: %v b: %v -> s: %v\n", a, b, s)

		return s
}

func main() {
		a := []int{2,5,1,3,6,8,2,1}
		b := []int{2,5,1,3,6,8,2,1}

		s.Ints(b)

		fmt.Println(b)
		fmt.Println(sort(a), a)
}
