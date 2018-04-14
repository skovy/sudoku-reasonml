# Sudoku ReasonML 📝 ⚛️

[![Build Status](https://travis-ci.org/Skovy/sudoku-reasonml.svg?branch=master)](https://travis-ci.org/Skovy/sudoku-reasonml)
[![Coverage Status](https://coveralls.io/repos/github/Skovy/sudoku-reasonml/badge.svg?branch=master)](https://coveralls.io/github/Skovy/sudoku-reasonml?branch=master)

A simple Sudoku board and validation implemented with [ReasonML React](https://reasonml.github.io/reason-react/).

![Sudoku Board](/docs/sudoku.png)

## Run this project

```bash
yarn                 # install dependencies
yarn start           # build and watch files
yarn webpack         # in another tab build the bundle
open docs/index.html # open in your browser
```

After you see the webpack compilation succeed (the `yarn webpack` step), open up 
the nested html files in `docs/*` (**no server needed!**). Then modify whichever 
file in `src` and refresh the page to see the changes.

## Board Validation

### Valid Board

![Valid Sudoku Board](/docs/valid-sudoku.gif)

### Invalid Board

![Valid Sudoku Board](/docs/invalid-sudoku.gif)