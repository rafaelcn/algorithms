open Printf

type list =
  | Nil
  | Const of int * list

let rec list_search l k =
  match l with
  | Nil -> false
  | Const (n, l) ->
    if n == k then
      true
    else
      list_search l k

let list_push l k =
  match k with
  | Nil -> l
  | Const (v, l) -> Const (v, l)

let rec list_push_back l v =
  match l with
  | Nil -> Const(v, l)
  | Const(some_value, tail) -> list_push_back tail v


(* TODO: Implement a list_equals function *)


(* A simple linked list *)
let list1 = Const (5, Const (6, Const (7, Nil)))

(* Returns the next element of a list l *)
let rec list_print l =
  match l with
  | Nil -> printf "end "
  | Const(some_val, tail) -> printf "%d " some_val; list_print tail


let () =
  while next list1