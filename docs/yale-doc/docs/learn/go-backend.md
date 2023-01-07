---
sidebar_position: 2
---

# go-backend

## docker
install docker
```
$ docker pull postgres:12-alpine
$ docker run --name postgres12 -p 5432:5432 -e POSTGRES_USER=root -e POSTGRES_PASSWORD=secret -d postgres:12-alpine

$ docker images

$ docker exec -it postgres12 psql -U root
```

## db gui
table-plus
https://tableplus.com/

## db cli
install migrate
https://github.com/golang-migrate/migrate
```
$ migrate -version
$ migrate -help
```

```
$ migrate create -ext sql -dir db/migration -seq init_schema
```
in postgres12 shell
```
createdb --username=root --owner=root simple_bank
```
### sqlc-example
1. sqlc.yaml
```
version: "1"
packages:
  - name: "db"
    path: "./db/query/"
    queries: "./db/query/"
    schema: "./db/migration/"
    engine: "postgresql"
    emit_json_tags: true
    emit_prepared_queries: false
    emit_interface: false
    emit_exact_table_names: false
```
2. db/query/account.sql
```
-- name: CreateAccount :one
INSERT INTO accounts (
  owner, 
  balance,
  currency
) VALUES (
  $1, $2, $3
) RETURNING *;
```
3. generate go function
```
$ docker run --rm -v "%cd%:/src" -w /src kjconroy/sqlc generate
```
migrate all table to sqlc-generated code

### db-test
1. main_test.go
```
dependency: lib/pq
https://github.com/lib/pq

var testQueries *Queries

func TestMain(m *testing.M) {
	conn, err := sql.Open(dbDriver, dbSource)
	if err != nil {
		log.Fatal("connect connect to db:", err)
	}

	testQueries = New(conn)

	os.Exit(m.Run())
}

```
2. account_test.go

dependency: testify

https://github.com/stretchr/testify 
3. 