type action =
  | Change(string, int, int)
  | SwitchBoard(string);

type state = {
  board: StartingBoards.board,
  startingBoard: StartingBoards.providedValues,
  status: string
};

let component = ReasonReact.reducerComponent("Page");

let initialState = (~boardName="Easy", ()): state => {
  startingBoard: Hashtbl.find(StartingBoards.boards, boardName),
  board:
    StartingBoards.generateInitialBoard(
      Hashtbl.find(StartingBoards.boards, boardName)
    ),
  status: "incomplete"
};

let reducer = (action: action, state: state) =>
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
    ReasonReact.Update(initialState(~boardName=boardName, ()));
  };

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
  initialState,
  reducer,
  render: self => {
    let handleChange = (value: string, row: int, column: int) =>
      self.send(Change(value, row, column));
    let handleSwitchBoard = (board: string) => self.send(SwitchBoard(board));
    let {status, board, startingBoard} = self.state;
    <div style>
      <div>
        <BoardHeading handleSwitchBoard />
        <Board status handleChange board startingBoard />
        <BoardFooter />
      </div>
    </div>;
  }
};