// Code generated by re2c, DO NOT EDIT.
//line "golang/001_basic.re":1
//go:generate re2go $INPUT -o $OUTPUT 
package main

func Lex(str string) int {
	var cursor, marker int

	
//line "golang/001_basic.go":11
{
	var yych byte
	yych = str[cursor]
	switch (yych) {
	case '0':
		fallthrough
	case '1':
		fallthrough
	case '2':
		fallthrough
	case '3':
		fallthrough
	case '4':
		fallthrough
	case '5':
		fallthrough
	case '6':
		fallthrough
	case '7':
		fallthrough
	case '8':
		fallthrough
	case '9':
		goto yy4
	default:
		goto yy2
	}
yy2:
	cursor += 1
yy3:
//line "golang/001_basic.re":17
	{
		return -1
	}
//line "golang/001_basic.go":46
yy4:
	cursor += 1
	marker = cursor
	yych = str[cursor]
	switch (yych) {
	case 0x00:
		goto yy5
	case '0':
		fallthrough
	case '1':
		fallthrough
	case '2':
		fallthrough
	case '3':
		fallthrough
	case '4':
		fallthrough
	case '5':
		fallthrough
	case '6':
		fallthrough
	case '7':
		fallthrough
	case '8':
		fallthrough
	case '9':
		goto yy7
	default:
		goto yy3
	}
yy5:
	cursor += 1
//line "golang/001_basic.re":21
	{
		return 1
	}
//line "golang/001_basic.go":83
yy7:
	cursor += 1
	yych = str[cursor]
	switch (yych) {
	case 0x00:
		goto yy5
	case '0':
		fallthrough
	case '1':
		fallthrough
	case '2':
		fallthrough
	case '3':
		fallthrough
	case '4':
		fallthrough
	case '5':
		fallthrough
	case '6':
		fallthrough
	case '7':
		fallthrough
	case '8':
		fallthrough
	case '9':
		goto yy7
	default:
		goto yy9
	}
yy9:
	cursor = marker
	goto yy3
}
//line "golang/001_basic.re":24

}

func main() {
	if Lex("123\000") != 1 {
		panic("expected 123")
	}
}
