package main

import (
	"bufio"
	"fmt"
	"os"
)

type InputBuffer struct {
	buffer        string
	buffer_length int
}

func log(obj interface{}) {
	fmt.Println(obj)
}

func readInput(input *InputBuffer, reader *bufio.Reader) {
	input.buffer, _ = reader.ReadString('\n')
}

func main() {
	var input_buffer InputBuffer
	reader := bufio.NewReader(os.Stdin)
	readInput(&input_buffer, reader)
	// input_buffer.buffer, _ = reader.ReadString('\n')
	log(input_buffer.buffer)

	str := "insert into"
	str2 := str[0:6]
	log(str2)
}
