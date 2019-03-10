package main

import (
	"log"
	"fmt"
	"go-hep.org/x/hep/groot"
	"go-hep.org/x/hep/groot/rtree"
)

func main(){
	f, err := groot.Open("ntup.root")
	if err != nil {
		log.Fatal(err)
	}
	defer f.Close()

	obj, err := f.Get("T")
	if err != nil {
		log.Fatal(err)
	}

	tree := obj.(rtree.Tree)
	fmt.Printf("entries= %v\n", tree.Entries())
}
