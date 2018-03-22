let component = ReasonReact.statelessComponent("Box");

let color = "#1E2D24";

let box =
  ReactDOMRe.Style.make(
    ~color,
    ~width="64px",
    ~height="64px",
    ~border="1px solid " ++ color,
    ~display="flex",
    ~alignItems="center",
    ~justifyContent="center",
    ~fontFamily="'Rubik', sans-serif",
    ~background="#fff",
    ()
  );

let baseStyles =
  ReactDOMRe.Style.make(
    ~fontFamily="'Rubik', sans-serif",
    ~background="#fff",
    ~width="64px",
    ~height="64px",
    ~lineHeight="64px",
    ~border="0",
    ~textAlign="center",
    ~padding="0",
    ~fontSize="32px",
    ()
  );

let invalidStyles =
  ReactDOMRe.Style.make(
    ~color="#CC0011",
    ~background="#FFB3B9",
    ~boxShadow="inset 0 0 6px #CC0011",
    ()
  );

let validStyles =
  ReactDOMRe.Style.make(
    ~color="#008055",
    ~background="#DAF2EA",
    ~boxShadow="inset 0 0 6px #008055",
    ()
  );

let defaultProvidedStyles =
  ReactDOMRe.Style.combine(
    baseStyles,
    ReactDOMRe.Style.make(
      ~color,
      ~fontWeight="bold",
      ~cursor="not-allowed",
      ~userSelect="none",
      ~display="flex",
      ~alignItems="center",
      ~justifyContent="center",
      ()
    )
  );

let defaultInputStyles =
  ReactDOMRe.Style.combine(
    baseStyles,
    ReactDOMRe.Style.make(~color="#0055CC", ~display="block", ())
  );

let invalidProvidedStyles =
  ReactDOMRe.Style.combine(defaultProvidedStyles, invalidStyles);

let invalidInputStyles =
  ReactDOMRe.Style.combine(defaultInputStyles, invalidStyles);

let validProvidedStyles =
  ReactDOMRe.Style.combine(defaultProvidedStyles, validStyles);

let validInputStyles =
  ReactDOMRe.Style.combine(defaultInputStyles, validStyles);

let make =
    (
      ~value: int,
      ~provided=false,
      ~handleChange,
      ~row,
      ~column,
      ~status,
      _children
    ) => {
  let onChange = event =>
    handleChange(
      ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value,
      row,
      column
    );
  {
    ...component,
    render: _self => {
      let inputStyles =
        switch status {
        | "invalid" => invalidInputStyles
        | "valid" => validInputStyles
        | _ => defaultInputStyles
        };
      let providedStyles =
        switch status {
        | "invalid" => invalidProvidedStyles
        | "valid" => validProvidedStyles
        | _ => defaultProvidedStyles
        };
      <div className="box">
        <div style=box>
          <span>
            (
              provided ?
                /* Render the provided value, but don't allow editing it */
                <span style=providedStyles>
                  (ReasonReact.stringToElement(string_of_int(value)))
                </span> :
                <input
                  value=(value > 0 ? string_of_int(value) : "")
                  style=inputStyles
                  onChange
                />
            )
          </span>
        </div>
      </div>;
    }
  };
};