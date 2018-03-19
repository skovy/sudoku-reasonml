let component = ReasonReact.statelessComponent("Box");

let color = "#1E2D24";

let baseStyles =
  ReactDOMRe.Style.make(
    ~color,
    ~width="64px",
    ~height="64px",
    ~border="1px solid " ++ color,
    ~fontSize="32px",
    ~display="flex",
    ~alignItems="center",
    ~justifyContent="center",
    ~fontFamily="'Rubik', sans-serif",
    ~background="#fff",
    ()
  );

let providedStyles =
  ReactDOMRe.Style.combine(
    baseStyles,
    ReactDOMRe.Style.make(
      ~fontWeight="bold",
      ~cursor="not-allowed",
      ~userSelect="none",
      ()
    )
  );

let inputStyles =
  ReactDOMRe.Style.make(
    ~color="#0055CC",
    ~width="100%",
    ~height="64px",
    ~lineHeight="64px",
    ~fontSize="32px",
    ~display="block",
    ~fontFamily="'Rubik', sans-serif",
    ~border="0",
    ~textAlign="center",
    ~background="transparent",
    ~padding="0",
    ()
  );

let make =
    (~value: int, ~provided=false, ~handleChange, ~row, ~column, _children) => {
  let onChange = event =>
    handleChange(
      ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value,
      row,
      column
    );
  {
    ...component,
    render: _self =>
      <div className="box">
        <div style=(provided ? providedStyles : baseStyles)>
          <span>
            (
              /* Render the provided value, but don't allow editing it */
              provided ?
                ReasonReact.stringToElement(string_of_int(value)) :
                <input
                  value=(value > 0 ? string_of_int(value) : "")
                  style=inputStyles
                  onChange
                />
            )
          </span>
        </div>
      </div>
  };
};