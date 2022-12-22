// Code generated by re2c, DO NOT EDIT.
//go:generate re2go $INPUT -o $OUTPUT -i --type-header src/lexer/lexer.go
package main

import (
	"lexer" // generated by re2c
	"testing"
)



func lex(st *lexer.State) int {
	
{
	var yych byte
	yych = st.Data[st.Cur]
	switch (yych) {
	case 'x':
		goto yy4
	default:
		goto yy2
	}
yy2:
	st.Cur++
yy3:
	{ return 1 }
yy4:
	st.Cur++
	st.Mar = st.Cur
	yych = st.Data[st.Cur]
	switch (yych) {
	case 'x':
		st.Tag1 = st.Cur
		goto yy5
	default:
		goto yy3
	}
yy5:
	st.Cur++
	yych = st.Data[st.Cur]
	switch (yych) {
	case 'x':
		st.Tag2 = st.Cur
		goto yy7
	default:
		goto yy6
	}
yy6:
	st.Cur = st.Mar
	goto yy3
yy7:
	st.Cur++
	yych = st.Data[st.Cur]
	switch (yych) {
	case 'x':
		st.Tag3 = st.Cur
		goto yy8
	default:
		goto yy6
	}
yy8:
	st.Cur++
	yych = st.Data[st.Cur]
	switch (yych) {
	case 'x':
		st.Tag1 = st.Cur
		goto yy10
	default:
		goto yy9
	}
yy9:
	st.Cur = st.Tag1
	{ return 0 }
yy10:
	st.Cur++
	yych = st.Data[st.Cur]
	switch (yych) {
	case 'x':
		goto yy11
	default:
		st.Tag1 = st.Tag2
		goto yy9
	}
yy11:
	st.Cur++
	yych = st.Data[st.Cur]
	switch (yych) {
	case 'x':
		goto yy12
	default:
		st.Tag1 = st.Tag3
		goto yy9
	}
yy12:
	st.Cur++
	yych = st.Data[st.Cur]
	switch (yych) {
	case 'x':
		goto yy13
	default:
		goto yy9
	}
yy13:
	st.Cur++
	yych = st.Data[st.Cur]
	switch (yych) {
	case 'x':
		goto yy14
	default:
		goto yy9
	}
yy14:
	st.Cur++
	goto yy9
}

}

func TestLex(t *testing.T) {
	st := &lexer.State{
		Data: "xxxxxxxx\x00",
	}
	if !(lex(st) == 0 && st.Cur == 4) {
		t.Error("failed")
	}
}
// Code generated by re2c, DO NOT EDIT.

package lexer

type State struct {
	Data string
	Cur, Mar, Tag1, Tag2, Tag3 int
}
go/headers/header.re:33:21: warning: trailing context has 4th degree of nondeterminism [-Wnondeterministic-tags]
