let component = ReasonReact.statelessComponent("BoardFooter");

let color = "#0055CC";

let style =
  ReactDOMRe.Style.make(
    ~color,
    ~margin="8px 0",
    ~fontFamily="'Rubik', sans-serif",
    ~fontSize="16px",
    ~fontWeight="400",
    ~textAlign="center",
    ()
  );

let linkStyle = ReactDOMRe.Style.make(~color, ());

let make = _children => {
  ...component,
  render: _self =>
    <div style>
    (ReasonReact.stringToElement("Created by "))
      <a href="https://github.com/skovy" style=linkStyle target="_blank">
        (ReasonReact.stringToElement("Skovy"))
      </a>
      (ReasonReact.stringToElement(" on "))
      <a href="https://github.com/skovy/sudoku-reasonml" style=linkStyle target="_blank">
        (ReasonReact.stringToElement("GitHub"))
      </a>
      (ReasonReact.stringToElement("."))
    </div>
};