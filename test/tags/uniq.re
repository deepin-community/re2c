// re2c $INPUT -o $OUTPUT -i --tags
// all tags collapse to one variable, and so should commands

/*!re2c

("a" @u @v @w @x @y @z "b")* "a" {}
"" {}

*/
