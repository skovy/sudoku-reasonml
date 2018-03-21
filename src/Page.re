type action =
  | Change(string, int, int)
  | SwitchBoard(string);

type state = {
  board: StartingBoards.board,
  startingBoard: StartingBoards.providedValues
};

let component = ReasonReact.reducerComponent("Page");

let style =
  ReactDOMRe.Style.make(
    ~height="100%",
    ~display="flex",
    ~justifyContent="center",
    ~alignItems="center",
    ()
  );

let make = _children => {
  ...component,
  initialState: () => {
    startingBoard: Hashtbl.find(StartingBoards.boards, "Easy"),
    board:
      StartingBoards.generateInitialBoard(
        Hashtbl.find(StartingBoards.boards, "Easy")
      )
  },
  reducer: (action, state) =>
    switch action {
    | Change(value, row, column) =>
      /* Make a copy of the board, so we can make changes to the row */
      let newBoard = Array.copy(state.board);
      /* Make a copy of the row, so we can make changes to the column */
      let newRow = Array.copy(newBoard[row]);
      newBoard[row] = newRow;
      /* Convert the input to an integer, convert any invalid input to a 0 */
      switch (int_of_string(value)) {
      | exception (Failure("int_of_string")) =>
        newRow[column] = 0;
        ReasonReact.Update({...state, board: newBoard});
      | intValue =>
        /* Only allow valid values 1-9 */
        if (intValue < 1 || intValue > 9) {
          ReasonReact.NoUpdate;
        } else {
          newRow[column] = intValue;
          ReasonReact.Update({...state, board: newBoard});
        }
      };
    | SwitchBoard(boardName) =>
      /* Update the currently selected board to another starting board */
      let board = Hashtbl.find(StartingBoards.boards, boardName);
      ReasonReact.Update({
        startingBoard: board,
        board: StartingBoards.generateInitialBoard(board)
      });
    },
  render: self => {
    let handleChange = (value: string, row: int, column: int) =>
      self.send(Change(value, row, column));

    let handleSwitchBoard = (board: string) =>
      self.send(SwitchBoard(board));

    <div style>
      <div>
        <BoardHeading handleSwitchBoard />
        <Board
          handleChange
          board=self.state.board
          startingBoard=self.state.startingBoard
        />
        <BoardFooter />
      </div>
    </div>;
  }
};