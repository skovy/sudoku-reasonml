type action =
  | Change(string, int, int);

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
    startingBoard: Hashtbl.find(StartingBoards.boards, "Intermediate"),
    board:
      StartingBoards.generateInitialBoard(
        Hashtbl.find(StartingBoards.boards, "Intermediate")
      )
  },
  reducer: (action, state) =>
    switch action {
    | Change(value, row, column) =>
      let newBoard = Array.copy(state.board);
      let newRow = Array.copy(newBoard[row]);
      newBoard[row] = newRow;
      switch (int_of_string(value)) {
      | exception (Failure("int_of_string")) =>
        newRow[column] = 0;
        ReasonReact.Update({...state, board: newBoard});
      | intValue =>
        if (intValue < 1 || intValue > 9) {
          ReasonReact.NoUpdate;
        } else {
          newRow[column] = intValue;
          ReasonReact.Update({...state, board: newBoard});
        }
      };
    },
  render: self => {
    let handleChange = (value: string, row: int, column: int) =>
      self.send(Change(value, row, column));
    <div style>
      <Board
        handleChange
        board=self.state.board
        startingBoard=self.state.startingBoard
      />
    </div>;
  }
};