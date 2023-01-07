// 1. readinput
// 2. save to memory -> read from memory
// 3. save to file -> read from file

package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strings"
)

func checke(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

const (
	EXIT_SUCCESS = 0
	EXIT_FAILURE = 1
)

/* InputBuffer */
type InputBuffer struct {
	buffer        string
	buffer_length int
	input_length  int
}

/* MetaCommandResult */
type MetaCommandResult int

const (
	META_COMMAND_SUCCESS MetaCommandResult = iota
	META_COMMAND_UNRECOGNIZED_COMMAND
)

/* StatementType */
type StatementType int

const (
	STATEMENT_INSERT StatementType = iota
	STATEMENT_SELECT
)

/* Row */
type Row struct {
	id       int
	username string
	email    string
}

/* Statement */
type Statement struct {
	stype         StatementType
	row_to_insert Row
}

// define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)

/* PrepareResult */
type PrepareResult int

const (
	PREPARE_SUCCESS PrepareResult = iota
	PREPARE_SYNTAX_ERROR
	PREPARE_UNRECOGNIZED_STATEMENT
)

/* ExecuteResult */
type ExecuteResult int

const (
	EXECUTE_SUCCESS ExecuteResult = iota
	EXECUTE_TABLE_FULL
	EXECUTE_OTHER
)

func logg(obj interface{}) {
	fmt.Println(obj)
}

func logT(obj interface{}) {
	fmt.Printf("%T", obj)
}

func getInput(reader *bufio.Reader) string {
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\r\n", "", -1)
	return input
}

func doMetaCommand(str string) MetaCommandResult {
	if str == ".exit" {
		os.Exit(EXIT_SUCCESS)
		return -1
	} else {
		return META_COMMAND_UNRECOGNIZED_COMMAND
	}
}

func prepare_statement(input_buffer *InputBuffer, statement *Statement) PrepareResult {
	if input_buffer.buffer == "select" {
		statement.stype = STATEMENT_SELECT
		return PREPARE_SUCCESS
	}
	if len([]rune(input_buffer.buffer)) >= 6 && string(input_buffer.buffer)[0:6] == "insert" {
		statement.stype = STATEMENT_INSERT
		_, err := fmt.Sscanf(input_buffer.buffer, "insert %d %s %s",
			&statement.row_to_insert.id,
			&statement.row_to_insert.username,
			&statement.row_to_insert.email)
		if err != nil {
			return PREPARE_SYNTAX_ERROR
		}
		logg(statement.row_to_insert)
		return PREPARE_SUCCESS
	}

	return PREPARE_UNRECOGNIZED_STATEMENT
}

func execute_statement(statement *Statement) ExecuteResult {
	switch statement.stype {
	case STATEMENT_INSERT:
		logg("execute insert")
		return EXECUTE_SUCCESS
	case STATEMENT_SELECT:
		logg("execute select")
		return EXECUTE_SUCCESS
	}
	return EXECUTE_OTHER
}

func main() {
	// initialize reader
	reader := bufio.NewReader(os.Stdin)
	var input_buffer InputBuffer
	for {
		fmt.Printf("db > ")

		// read and process text
		input_buffer.buffer = getInput(reader)

		// deal with meta command
		if string(input_buffer.buffer[0]) == "." {
			switch doMetaCommand(input_buffer.buffer) {
			case META_COMMAND_SUCCESS:
				continue
			case META_COMMAND_UNRECOGNIZED_COMMAND:
				fmt.Printf("Unrecognized command '%s'\n", input_buffer.buffer)
				continue
			}
		}

		// deal with sql command
		var statement Statement
		switch prepare_statement(&input_buffer, &statement) {
		case (PREPARE_SUCCESS):
			break
		case (PREPARE_SYNTAX_ERROR):
			fmt.Println("Syntax error. Could not parse statement.")
			continue
		case (PREPARE_UNRECOGNIZED_STATEMENT):
			fmt.Printf("Unrecognized keyword at start of: " + input_buffer.buffer)
			continue
		}
		// fmt.Printf("%q", input_buffer.buffer)
		switch execute_statement(&statement) {
		case (EXECUTE_SUCCESS):
			fmt.Println("Executed.")
			break
		case (EXECUTE_TABLE_FULL):
			fmt.Println("Error: Table full.")
			break
		case (EXECUTE_OTHER):
			fmt.Println("Execute some situation")
			break
		}
	}

}
