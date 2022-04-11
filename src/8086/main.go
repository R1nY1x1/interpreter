package main

import (
  "fmt"
  "os"
  "os/user"
  "8086/repl"
)

func main() {
  user, err := user.Current()
  if err != nil {
    panic(err)
  }
  fmt.Printf("Hello %s! This is the 8086 assemble language!\n",
    user.Username)
  fmt.Printf("Feel free to type in commands\n")
  repl.Start(os.Stdin, os.Stdout)
}
