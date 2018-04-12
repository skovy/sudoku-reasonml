open Jest;

describe("Validate", () => {
  let board = ref([|[||]|]);
  describe("getStatusForBoard", () => {
    open Expect;
    open! Expect.Operators;
    describe("incomplete board", () => {
      beforeEach(() => board := Array.make(9, Array.make(9, 0)));
      test("when an entirely empty board", () =>
        expect(Validate.getStatusForBoard(board^)) === "incomplete"
      );
      test("when a partially empty board", () => {
        board^[0][0] = 1;
        expect(Validate.getStatusForBoard(board^)) === "incomplete";
      });
    });
    describe("invalid board", () => {
      beforeEach(() => board := Array.make(9, Array.make(9, 1)));
      test("when an entirely filled board with all the same number", () =>
        expect(Validate.getStatusForBoard(board^)) === "invalid"
      );
      test("when only the rows are correct", () => {
        board := Array.make(9, [|5, 6, 7, 2, 1, 4, 3, 8, 9|]);
        expect(Validate.getStatusForBoard(board^)) === "invalid";
      });
      test("when only the columns and rows are correct", () => {
        board :=
          [|
            [|1, 2, 3, 4, 5, 6, 7, 8, 9|],
            [|2, 3, 4, 5, 6, 7, 8, 9, 1|],
            [|3, 4, 5, 6, 7, 8, 9, 1, 2|],
            [|4, 5, 6, 7, 8, 9, 1, 2, 3|],
            [|5, 6, 7, 8, 9, 1, 2, 3, 4|],
            [|6, 7, 8, 9, 1, 2, 3, 4, 5|],
            [|7, 8, 9, 1, 2, 3, 4, 5, 6|],
            [|8, 9, 1, 2, 3, 4, 5, 6, 7|],
            [|9, 1, 2, 3, 4, 5, 6, 7, 8|]
          |];
        expect(Validate.getStatusForBoard(board^)) === "invalid";
      });
    });
    describe("complete board", () => {
      beforeEach(() =>
        board :=
          [|
            [|7, 2, 6, 4, 9, 3, 8, 1, 5|],
            [|3, 1, 5, 7, 2, 8, 9, 4, 6|],
            [|4, 8, 9, 6, 5, 1, 2, 3, 7|],
            [|8, 5, 2, 1, 4, 7, 6, 9, 3|],
            [|6, 7, 3, 9, 8, 5, 1, 2, 4|],
            [|9, 4, 1, 3, 6, 2, 7, 5, 8|],
            [|1, 9, 4, 8, 3, 6, 5, 7, 2|],
            [|2, 3, 8, 5, 7, 9, 4, 6, 1|],
            [|5, 6, 7, 2, 1, 4, 3, 8, 9|]
          |]
      );
      test("when a valid solution", () =>
        expect(Validate.getStatusForBoard(board^)) === "valid"
      );
    });
  });
});