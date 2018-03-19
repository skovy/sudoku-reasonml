type action =
  | Change(string, int, int);

type state = {board: StartingBoards.board};

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
    board:
      StartingBoards.generateInitialBoard(
        Hashtbl.find(StartingBoards.boards, "(1) Easy")
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
        ReasonReact.Update({board: newBoard});
      | intValue =>
        if (intValue < 1 || intValue > 9) {
          ReasonReact.NoUpdate;
        } else {
          newRow[column] = intValue;
          ReasonReact.Update({board: newBoard});
        }
      };
    },
  render: self => {
    let handleChange = (value: string, row: int, column: int) =>
      self.send(Change(value, row, column));
    <div style> <Board handleChange board=self.state.board /> </div>;
  }
};