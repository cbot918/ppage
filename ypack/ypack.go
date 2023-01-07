package main

import (
	"fmt"
	"os"
	"strconv"

	"github.com/evanw/esbuild/pkg/api"
	"github.com/spf13/viper"
)

func main() {

	viper.SetConfigFile(".env")
	viper.ReadInConfig()

	fmt.Println(viper.Get("PORT"))

	viper.AddConfigPath("./")
	viper.SetConfigName("config")
	viper.SetConfigType("json")
	viper.ReadInConfig()

	// port := viper.Get("prod.port")
	EntryPoints := viper.Get("prod.EntryPoints")
	Outfile := viper.Get("prod.Outfile")
	Bundle := viper.Get("prod.Bundle")
	Write := viper.Get("prod.Write")

	bundle, _ := strconv.ParseBool(fmt.Sprintf("%v", Bundle))
	write, _ := strconv.ParseBool(fmt.Sprintf("%v", Write))

	fmt.Println("hi")

	jsx := `
		import * as React from 'react'
		import * as ReactDOM from 'react-dom'

		ReactDOM.render(
			<h1>Hello, world!</h1>,
			document.getElementById('root')
		);
	`
	r := api.Transform(jsx, api.TransformOptions{
		Loader: api.LoaderJSX,
	})
	if len(r.Errors) > 0 {
		fmt.Println(r.Errors)
		os.Exit(1)
	}
	os.Stdout.Write(r.Code)

	result := api.Build(api.BuildOptions{
		EntryPoints: []string{fmt.Sprintf("%v", EntryPoints)},
		Outfile:     fmt.Sprintf("%v", Outfile),
		Bundle:      bundle,
		Write:       write,
		External:    []string{"*.png", "/images/*"},
		Loader:      map[string]api.Loader{".js": api.LoaderJSX},
	})
	if len(result.Errors) > 0 {
		fmt.Println(result.Errors)
		os.Exit(1)
	}
	// result := api.Transform("let x: number = 1", api.TransformOptions{
	// 	Loader: api.LoaderTS,
	// })

	// if len(result.Errors) == 0 {
	// 	fmt.Printf("%s", result.Code)
	// }
}
