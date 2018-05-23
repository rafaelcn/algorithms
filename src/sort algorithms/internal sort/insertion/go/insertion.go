package main

import (
	"fmt"
	"math/rand"
	"time"
)

func Fill(vector []int) {

	rand.Seed(time.Now().Unix())

	for i := 0; i < len(vector); i++ {
		vector[i] = rand.Intn(len(vector))
	}
}

func InsertionSort(instance []int) []int {

	unsorted := make([]int, len(instance))
	copy(unsorted, instance)

	for i := 1; i < len(unsorted); i++ {
		aux := unsorted[i]
		j := i - 1

		for j >= 0 && aux < unsorted[j] {
			unsorted[j+1] = unsorted[j]
			j--
		}

		unsorted[j+1] = aux
	}

	return unsorted
}

func main() {

	var instance = make([]int, 10)
	Fill(instance[:])

	fmt.Println(instance)

	sorted := InsertionSort(instance[:])

	fmt.Println(sorted)
}
