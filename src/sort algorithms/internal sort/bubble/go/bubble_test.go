package main

import (
	"sort"
	"testing"
)

var (
	testSize int = 1000
)

func TestBubble(t *testing.T) {

	raw := make([]int, testSize)
	Fill(raw)

	withSort := make([]int, testSize)
	withBubble := make([]int, testSize)

	copy(withSort, raw)
	copy(withBubble, raw)

	withBubble = Bubble(withBubble)

	sort.Slice(withSort, func(i, j int) bool {
		return withSort[i] < withSort[j]
	})

	for i := 0; i < testSize; i++ {
		if withBubble[i] != withSort[i] {
			t.Logf("Got %d where it should be %d", withBubble[i], withSort[i])
			t.FailNow()
		}
	}
}
