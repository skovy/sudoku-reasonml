type board = array(array(int));

/* Provided values for one sudoku board */
let one = {
  let values = Hashtbl.create(10);

  /* First row */
  Hashtbl.add(values, "0-0", 3);
  Hashtbl.add(values, "0-6", 5);

  /* Second row */
  Hashtbl.add(values, "1-0", 7);
  Hashtbl.add(values, "1-1", 8);
  Hashtbl.add(values, "1-2", 9);
  Hashtbl.add(values, "1-4", 1);
  Hashtbl.add(values, "1-5", 5);
  Hashtbl.add(values, "1-8", 2);

  /* Third row */
  Hashtbl.add(values, "2-1", 1);
  Hashtbl.add(values, "2-6", 8);
  Hashtbl.add(values, "2-8", 6);

  values
};

/* Generate a 9x9 board with empty spaces */
let generateInitialBoard = (providedValues: Hashtbl.t (string, int)) => {
  let board = ref([||]);
  for (i in 0 to 8) {
    let row = ref([||]);
    for (j in 0 to 8) {
      let key = string_of_int(i) ++ "-" ++ string_of_int(j);
      if (Hashtbl.mem(providedValues, key)) {
        row := Array.append(row^, [|Hashtbl.find(providedValues, key)|]);
      } else {
        row := Array.append(row^, [|0|]);
      };
    };
    board := Array.append(board^, [|(row^)|]);
  };
  board^;
};