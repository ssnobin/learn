var PF = require('pathfinding');
var matrix = [
    [0, 0, 0, 1, 0],
    [1, 0, 0, 0, 1],
    [0, 0, 1, 0, 0],
];
var grid = new PF.Grid(matrix);
//var grid = new PF.Grid(5, 3);
var finder = new PF.AStarFinder();
var path = finder.findPath(1, 2, 4, 2, grid);
console.log("asdf", path);
