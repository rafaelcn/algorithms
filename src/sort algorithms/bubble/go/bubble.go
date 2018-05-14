package main

import (
	"fmt"
	"math/rand"
	"time"
)

func Bubble(instance []int) []int {

	swapped := true

	for swapped == true {
		swapped = false
		for i := 0; i < len(instance); i++ {
			for j := 1; j < len(instance); j++ {
				if instance[j] < instance[j-1] {
					instance[j], instance[j-1] = instance[j-1], instance[j]
					swapped = true
				}
			}

			if swapped == false {
				break
			}
		}
	}

	return instance
}

func main() {

	var instance [100]int

	rand.Seed(time.Now().UnixNano())

	for i := 0; i < len(instance); i++ {
		instance[i] = rand.Intn(110)
	}

	fmt.Println(instance)

	sorted := Bubble(instance[:])

	fmt.Println(sorted)
	fmt.Println(instance)
}
