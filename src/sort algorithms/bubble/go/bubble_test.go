package main

import (
	"sort"
	"testing"
)

func TestBubble(t *testing.T) {

	raw := make([]int, 1000)
	Fill(raw, len(raw))

	withSort := make([]int, len(raw))
	withBubble := make([]int, len(raw))

	copy(withSort, raw)
	copy(withBubble, raw)

	withBubble = Bubble(withBubble)

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
