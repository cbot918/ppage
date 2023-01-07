package main

import (
	"fmt"
	"log"

	_ "github.com/go-sql-driver/mysql"
	"github.com/jmoiron/sqlx"
)

const (
	USERNAME     string = "root"
	PASSWORD     string = "12345"
	HOST         string = "127.0.0.1"
	PORT         int    = 3306
	DATABASE     string = "test"
	MAXLIFETIME  int    = 10
	MAXOPENCONNS int    = 20
	MAXIDLECONNS int    = 10
	CHARSET      string = "utf8mb4"
	PARSETIME    string = "True"
)

var db *sqlx.DB

func initDB() (err error) {
	connString := fmt.Sprintf("%s:%s@tcp(%s:%d)/%s?charset=%s&parseTime=%s",
		USERNAME, PASSWORD, HOST, PORT, DATABASE, CHARSET, PARSETIME)
	// dsn := "root:12345@tcp(127.0.0.1:3306)/test?charset=utf8mb4&parseTime=True"
	db, err = sqlx.Connect("mysql", connString)
	if err != nil {
		fmt.Printf("connect DB failed, err:%v\n", err)
		return
	}
	db.SetMaxOpenConns(20)
	db.SetMaxIdleConns(10)
	err = db.Ping()
	if err != nil {
		log.Fatal("db ping failed")
	}
	fmt.Println("db connect success!")
	return
}

func main() {
	initDB()
}
