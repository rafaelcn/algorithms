package main

import (
	"fmt"
	"math/rand"
	"time"
)

func Fill(vector []int) {

	rand.Seed(time.Now().UnixNano())

	for i := 0; i < len(vector); i++ {
		vector[i] = rand.Intn(len(vector))
	}
}

func Selection(instance []int) []int {

	unsorted := make([]int, len(instance))
	copy(unsorted, instance)

	for i := 0; i < len(instance)-1; i++ {
		min := i
		aux := unsorted[i]

		for j := i + 1; j < len(instance); j++ {
			if unsorted[j] < unsorted[min] {
				min = j
			}
		}

		unsorted[i], unsorted[min] = unsorted[min], aux
	}

	return unsorted
}

func main() {

	instance := make([]int, 20)
	Fill(instance)

	fmt.Println(instance)

	sorted := Selection(instance)

	fmt.Println(sorted)
}
