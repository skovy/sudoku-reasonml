open Jest;

/* An "empty" board of all zeros, considered "incomplete" */
let emptyBoard: StartingBoards.board = Array.make(9, Array.make(9, 0));

/* An "filled" board of all ones, considered "invalid" */
let filledBoard: StartingBoards.board = Array.make(9, Array.make(9, 1));

describe("Validate", () =>
  describe("getStatusForBoard", () => {
    open Expect;
    open! Expect.Operators;
    test("incomplete for an entirely empty board", () =>
      expect(Validate.getStatusForBoard(emptyBoard)) === "incomplete"
    );
    test("not incomplete for an entirely filled board", () =>
      expect(Validate.getStatusForBoard(filledBoard)) === "invalid"
    );
  })
);