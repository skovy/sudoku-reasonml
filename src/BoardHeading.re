let component = ReasonReact.statelessComponent("BoardHeading");

let color = "#0055CC";

let style =
  ReactDOMRe.Style.make(
    ~color,
    ~margin="0",
    ~fontFamily="'Rubik', sans-serif",
    ~fontSize="48px",
    ~fontWeight="900",
    ()
  );

let smallStyle =
  ReactDOMRe.Style.combine(style, ReactDOMRe.Style.make(~fontWeight="400", ()));

let make = _children => {
  ...component,
  render: _self =>
    <h1 style>
      (ReasonReact.stringToElement("Sudoku"))
      <small style=smallStyle>
        (ReasonReact.stringToElement("ReasonML"))
      </small>
    </h1>
};