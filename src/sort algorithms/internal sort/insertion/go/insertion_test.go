package main

import (
	"sort"
	"testing"
)

var (
	testSize int = 1000
)

func TestInsertion(t *testing.T) {

	raw := make([]int, testSize)
	Fill(raw)

	withSort := make([]int, testSize)
	withInsertion := make([]int, testSize)

	copy(withSort, raw)
	copy(withInsertion, raw)

	withInsertion = InsertionSort(withInsertion)

	sort.Slice(withSort, func(i, j int) bool {
		return withSort[i] < withSort[j]
	})

	for i := 0; i < testSize; i++ {
		if withSort[i] != withInsertion[i] {
			t.Logf("Got %d where it should be %d", withInsertion[i],
				withSort[i])
			t.FailNow()
		}
	}
}
