let component = ReasonReact.statelessComponent("Row");

let style =
  ReactDOMRe.Style.make(
    ~display="flex",
    ~alignItems="center",
    ~justifyContent="flex-start",
    ()
  );

/* A single row of the sudoku board containing 9 boxes */
let make =
    (
      ~handleChange,
      ~index: int,
      ~row: array(int),
      ~startingBoard: StartingBoards.providedValues,
      _children
    ) => {
  ...component,
  render: _self =>
    <div style className="row">
      (
        ReasonReact.arrayToElement(
          Array.mapi(
            (j, column) =>
              <Box
                value=column
                provided=(
                  Hashtbl.mem(
                    startingBoard,
                    string_of_int(index) ++ "-" ++ string_of_int(j)
                  )
                )
                handleChange
                row=index
                column=j
                key=(string_of_int(j))
              />,
            row
          )
        )
      )
    </div>
};