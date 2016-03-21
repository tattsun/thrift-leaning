namespace cpp hello

struct Human {
  1: string name,
  2: i32 age,
}

service Greeter {
  string greet(1: Human h)
}