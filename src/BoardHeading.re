let component = ReasonReact.statelessComponent("BoardHeading");

let color = "#0055CC";

let style =
  ReactDOMRe.Style.make(
    ~display="flex",
    ~justifyContent="space-between",
    ~alignItems="center",
    ()
  );

let selectStyle = ReactDOMRe.Style.make(~fontSize="16px", ());

let headingStyle =
  ReactDOMRe.Style.make(
    ~color,
    ~margin="0",
    ~fontFamily="'Rubik', sans-serif",
    ~fontSize="48px",
    ~fontWeight="900",
    ()
  );

let smallStyle =
  ReactDOMRe.Style.combine(
    headingStyle,
    ReactDOMRe.Style.make(~fontWeight="400", ())
  );

let make = (~handleSwitchBoard, _children) => {
  ...component,
  render: _self => {
    let onChange = event =>
      handleSwitchBoard(
        ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value
      );
    <div style>
      <h1 style=headingStyle>
        (ReasonReact.stringToElement("Sudoku"))
        <small style=smallStyle>
          (ReasonReact.stringToElement("ReasonML"))
        </small>
      </h1>
      <select style=selectStyle onChange>
        (
          ReasonReact.arrayToElement(
            Array.map(
              boardName =>
                <option value=boardName key=boardName>
                  (ReasonReact.stringToElement(boardName))
                </option>,
              StartingBoards.boardNames
            )
          )
        )
      </select>
    </div>;
  }
};