let getStatusForBoard = (board: StartingBoards.board) : string => {
  let status = ref("valid");
  /* First, validate that all boxes have an input. We don't want to show an
     invalid or valid state if every field has not been completed  */
  let i = ref(0);
  while (status^ === "valid" && i^ < 9) {
    let row = board[i^];
    let j = ref(0);
    while (status^ === "valid" && j^ < 9) {
      let column = row[j^];
      if (column === 0) {
        status := "incomplete";
      };
      j := j^ + 1;
    };
    i := i^ + 1;
  };
  /* Second, validate that every row has the correct value, 1 through 9 */
  i := 0;
  while (status^ === "valid" && i^ < 9) {
    let row = board[i^];
    /* Keep track of every value that occurs in this row */
    let currentRowValues = Array.make(Array.length(board), 0);
    for (j in 0 to 8) {
      currentRowValues[row[j] - 1] = 1;
    };
    /* Validate that this row has every value 1 through 9 */
    let list = Array.to_list(currentRowValues);
    let missingValues = List.filter(i => i == 0, list);
    if (List.length(missingValues) > 0) {
      status := "invalid";
    };
    i := i^ + 1;
  };
  /* Third, validate that every column has the correct value, 1 through 9 */
  i := 0;
  while (status^ === "valid" && i^ < 9) {
    /* Keep track of every value that occurs in this column */
    let currentRowValues = Array.make(Array.length(board), 0);
    for (j in 0 to 8) {
      currentRowValues[board[j][i^] - 1] = 1;
    };
    /* Validate that this column has every value 1 through 9 */
    let list = Array.to_list(currentRowValues);
    let missingValues = List.filter(i => i == 0, list);
    if (List.length(missingValues) > 0) {
      status := "invalid";
    };
    i := i^ + 1;
  };
  status^;
};