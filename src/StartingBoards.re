type board = array(array(int));

type providedValues = Hashtbl.t(string, int);

type boards = Hashtbl.t(string, providedValues);

/* A hash of all possible sudoku boards to solve */
let boards: boards = {
  let values = Hashtbl.create(1);
  Hashtbl.add(values, "Easy", Easy.one);
  Hashtbl.add(values, "Intermediate", Intermediate.one);
  values;
};

/* An array of all possible board names */
let boardNames: array(string) = {
  let values = ref([||]);
  let addBoardName = (key: string, _) =>
    values := Array.append(values^, [|key|]);
  Hashtbl.iter(addBoardName, boards);
  values^;
};

/* Generate a 9x9 board with empty spaces */
let generateInitialBoard = (startingBoard: providedValues) => {
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