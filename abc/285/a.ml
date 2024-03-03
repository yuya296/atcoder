let () = Scanf.scanf "%d %d" (fun a b ->
    print_endline @@ if (a*2==b || a*2+1==b) then "Yes" else "No")