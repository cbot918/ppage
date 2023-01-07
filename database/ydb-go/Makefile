test: ydb-go.exe
	rspec
	rm ./ydb-go.exe

run: ydb-go.exe
	./ydb-go.exe

ydb-go.exe: main.go
	echo build
	go build .
