package main

import (
	"database/sql"
	"fmt"
	"sqlx/sql/util"

	_ "github.com/go-sql-driver/mysql"
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

func initConnection(driver string, connStr string) *sql.DB {
	db, err := sql.Open(driver, connStr)
	util.Checke(err, "mysql connect failed")
	return db
}

func createTable(db *sql.DB) {
	sql := `CREATE TABLE IF NOT EXISTS customer(
		id bigint(20) PRIMARY KEY AUTO_INCREMENT NOT NULL,
		username VARCHAR(64),
		password VARCHAR(64),
		status INT(4),
		create_at timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
		updated_at timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
		);`
	_, err := db.Exec(sql)
	util.Checke(err, "create table failed.")

	util.Logg("create table success")
}

func addCustomer(db *sql.DB) {
	result, err := db.Exec("INSERT INTO customer(username, password) values(?,?)", "test", "123456")
	util.Checke(err, "db insert failed")

	lastInsertId, err := result.LastInsertId()
	util.Checke(err, "get insert id failed")
	fmt.Println("[*] insert data id: ", lastInsertId)

	rowsAffected, err := result.RowsAffected()
	util.Checke(err, "get rowsAffected failed")
	fmt.Println("[*] insert data id: ", rowsAffected)
}

func updateData(db *sql.DB) {

}

func main() {
	connString := fmt.Sprintf("%s:%s@tcp(%s:%d)/%s?charset=%s&parseTime=%s",
		USERNAME, PASSWORD, HOST, PORT, DATABASE, CHARSET, PARSETIME)

	dbConn := initConnection("mysql", connString)

	createTable(dbConn)

	addCustomer(dbConn)
}
