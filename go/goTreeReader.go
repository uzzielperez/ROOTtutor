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
	
	//fmt.Printf("keys: %#v\n", f.Keys())

	// Get Tree T 
	obj, err := f.Get("T")
	if err != nil {
		log.Fatal(err)
	}

	tree := obj.(rtree.Tree)
	fmt.Printf("entries= %v\n", tree.Entries())

	branches := tree.Branches()
	
	for i, b := range branches{
		fmt.Printf("b[%d]: %v\n", i, b.Name())
	}
}
