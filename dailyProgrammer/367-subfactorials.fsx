//https://www.reddit.com/r/dailyprogrammer/comments/9cvo0f/20180904_challenge_367_easy_subfactorials_another/
let rec subfac(n : int, lst : int list) : int =
    match n with
        |1 -> 0
        |2 -> 1
        |3 -> 2
        |_ -> match lst.Length with
                  |n -> lst.[(n-1)]
                  |_ -> List.append(lst ((n-1) * (subfac(n-1) + subfac(n-2))) )

let lst = [1, .., 5]
//Lav en fold på listen med subfac som funktion
let x = subfac(5, lst)
printfn "%A" x
