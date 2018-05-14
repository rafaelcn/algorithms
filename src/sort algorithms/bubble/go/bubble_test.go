package main

import (
	"math/rand"
	"sort"
	"testing"
	"time"
)

func fill(vector []int, length int) {

	rand.Seed(time.Now().UnixNano())

	for i := 0; i < length; i++ {
		// might be biased
		vector[i] = rand.Int() % 100
	}
}

func TestBubble(t *testing.T) {

	raw := make([]int, 1000)
	fill(raw, len(raw))

	withSort := make([]int, len(raw))
	withBubble := make([]int, len(raw))

	copy(withSort, raw)
	copy(withBubble, raw)

	Bubble(withBubble)

	sort.Slice(withSort, func(i, j int) bool {
		return withSort[i] < withSort[j]
	})

	for i := 0; i < len(raw); i++ {
		if withBubble[i] != withSort[i] {
			t.Logf("Got %d where it should be %d", withBubble[i], withSort[i])
			t.FailNow()
		}
	}
}
