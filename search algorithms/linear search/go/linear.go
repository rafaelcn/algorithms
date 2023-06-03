package main

import (
	"fmt"
	"math/rand"
)

// Returns a boolean indicating if the value was or wasn't found on instance
func LinearSearch(instance []int, value int) bool {

	returnValue := false

	for i := 0; i < len(instance); i++ {
		if instance[i] == value {
			returnValue = true
			break
		}
	}

	return returnValue
}

// Returns an index that points to the index of value on the instance or
// a -1 if it wasn't found
func LinearSearch2(instance []int, value int) int {

	index := -1

	for i := 0; i < len(instance); i++ {
		if instance[i] == value {
			index = i
			break
		}
	}

	return index
}

func main() {

	instance := make([]int, 15)

	for i := 0; i < len(instance); i++ {
		instance[i] = rand.Intn(len(instance))
	}

	var value int

	fmt.Print("A small instance: ")
	fmt.Println(instance)
	fmt.Print("Enter a number to be searched: ")
	fmt.Scanf("%d", &value)

	fmt.Printf("LinearSearch: %v\n", LinearSearch(instance, value))
	fmt.Printf("LinearSearch2: %d\n", LinearSearch2(instance, value))
}
