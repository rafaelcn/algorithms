package main

import (
	"fmt"
	"math/rand"
	"time"
)

func Fill(vector []int, length int) {

	rand.Seed(time.Now().UnixNano())

	for i := 0; i < length; i++ {
		vector[i] = rand.Intn(100)
	}
}

func Bubble(instance []int) []int {

	unsorted := make([]int, len(instance))
	copy(unsorted, instance)

	swapped := true

	for swapped == true {
		swapped = false
		for i := 0; i < len(unsorted); i++ {
			for j := 1; j < len(unsorted); j++ {
				if unsorted[j] < unsorted[j-1] {
					unsorted[j], unsorted[j-1] = unsorted[j-1], unsorted[j]
					swapped = true
				}
			}

			if swapped == false {
				break
			}
		}
	}

	return unsorted
}

func main() {

	var instance [20]int
	Fill(instance[:], len(instance))

	fmt.Println(instance)

	sorted := Bubble(instance[:])

	fmt.Println(sorted)
}
