let component = ReasonReact.statelessComponent("Board");

let style =
  ReactDOMRe.Style.make(
    ~border="4px solid #292F36",
    ~boxShadow="0px 2px 4px rgba(0, 0, 0, 0.4)",
    ()
  );

/* The entire sudoku board of 9 rows and 9 columns */
let make =
    (
      ~board: StartingBoards.board,
      ~startingBoard: StartingBoards.providedValues,
      ~handleChange,
      _children
    ) => {
  ...component,
  render: _self =>
    <div>
      <BoardHeading />
      <div style>
        (
          ReasonReact.arrayToElement(
            Array.mapi(
              (index, row) =>
                <Row
                  key=(string_of_int(index))
                  handleChange
                  index
                  row
                  startingBoard
                />,
              board
            )
          )
        )
      </div>
      <BoardFooter />
    </div>
};