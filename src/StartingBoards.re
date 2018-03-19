type board = array(array(int));

let boards = {
  let values = Hashtbl.create(1);

  Hashtbl.add(values, "(1) Easy", Easy.one);

  values
};

/* Generate a 9x9 board with empty spaces */
let generateInitialBoard = (startingBoard: Hashtbl.t (string, int)) => {
  let board = ref([||]);
  for (i in 0 to 8) {
    let row = ref([||]);
    for (j in 0 to 8) {
      let key = string_of_int(i) ++ "-" ++ string_of_int(j);
      if (Hashtbl.mem(startingBoard, key)) {
        row := Array.append(row^, [|Hashtbl.find(startingBoard, key)|]);
      } else {
        row := Array.append(row^, [|0|]);
      };
    };
    board := Array.append(board^, [|(row^)|]);
  };
  board^;
};