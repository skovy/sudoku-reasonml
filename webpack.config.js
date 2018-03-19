const path = require('path');
const CopyWebpackPlugin = require('copy-webpack-plugin');

module.exports = {
  entry: './src/index.bs.js',
  output: {
    path: path.join(__dirname, "docs"),
    filename: 'index.js',
  },
  plugins: [
    new CopyWebpackPlugin([{
      from: './src/index.html'
    }])
  ]
};
